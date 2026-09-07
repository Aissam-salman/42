#!/usr/bin/env bash
# Harnais de test complet pour mini_serv :
#   compilation stricte, conformite au sujet, protocole, fd leaks, memory
#   leaks (valgrind) et test de charge.
#
# Usage: ./tests/run_tests.sh [chemin/vers/mini_serv.c]

set -u

SRC="${1:-$(dirname "$0")/../mini_serv.c}"
DIR="$(cd "$(dirname "$0")" && pwd)"
BIN="$DIR/mini_serv_test"
PORT="${MS_PORT:-$((20000 + RANDOM % 20000)))}"
PORT="${PORT%)}"
export MS_PORT="$PORT"
ulimit -n 4096 2>/dev/null || true
LOG="$DIR/.out"
mkdir -p "$LOG"

RED=$'\033[31m'; GRN=$'\033[32m'; YEL=$'\033[33m'; BLD=$'\033[1m'; RST=$'\033[0m'
PASS=0; FAIL=0
ok()   { echo "  ${GRN}OK  ${RST} $*"; PASS=$((PASS+1)); }
ko()   { echo "  ${RED}FAIL${RST} $*"; FAIL=$((FAIL+1)); }
warn() { echo "  ${YEL}WARN${RST} $*"; }
title(){ echo; echo "${BLD}=== $* ===${RST}"; }

SERVER_PID=""
cleanup() {
    [ -n "$SERVER_PID" ] && kill -9 "$SERVER_PID" 2>/dev/null
    return 0
}
trap cleanup EXIT

wait_port() {   # attend que le serveur ecoute
    for _ in $(seq 1 100); do
        if (exec 3<>/dev/tcp/127.0.0.1/$PORT) 2>/dev/null; then exec 3<&- 3>&-; return 0; fi
        perl -e 'select(undef,undef,undef,0.05)' 2>/dev/null || sleep 0.05
    done
    return 1
}

start_server() {  # $@ = prefixe eventuel (valgrind ...)
    "$@" "$BIN" "$PORT" >"$LOG/server.out" 2>"$LOG/server.err" &
    SERVER_PID=$!
    if ! wait_port; then
        ko "le serveur n'ecoute pas sur $PORT"
        sed -n '1,20p' "$LOG/server.err"
        return 1
    fi
    return 0
}

stop_server() {
    [ -n "$SERVER_PID" ] || return 0
    kill -TERM "$SERVER_PID" 2>/dev/null
    wait "$SERVER_PID" 2>/dev/null
    SERVER_PID=""
}

# ---------------------------------------------------------------- 1. build
title "1. Compilation"
if gcc -Wall -Wextra -Werror -g3 -o "$BIN" "$SRC" 2>"$LOG/build.err"; then
    ok "gcc -Wall -Wextra -Werror : aucun warning"
else
    ko "compilation stricte echouee :"
    sed -n '1,30p' "$LOG/build.err"
    exit 1
fi

# ---------------------------------------------------------------- 2. sujet
title "2. Conformite au sujet"

if grep -qE '^[[:space:]]*#[[:space:]]*define' "$SRC"; then
    ko "#define present (interdit par le sujet)"
    grep -nE '^[[:space:]]*#[[:space:]]*define' "$SRC" | sed 's/^/       /'
else
    ok "aucun #define"
fi

# fonctions libc appelees vs liste autorisee du sujet
ALLOWED="write close select socket accept listen send recv bind strstr malloc realloc free calloc bzero atoi sprintf strlen exit strcpy strcat memset htons htonl fcntl"
UNDEF=$(nm -u "$BIN" 2>/dev/null | awk '{print $2}' | sed 's/@.*//' | grep -v '^_' | sort -u)
BAD=""
for f in $UNDEF; do
    case " $ALLOWED " in *" $f "*) ;; *) BAD="$BAD $f";; esac
done
if [ -n "$BAD" ]; then
    warn "symboles externes hors liste autorisee :$BAD"
else
    ok "seules des fonctions autorisees sont liees"
fi

# ecoute uniquement sur 127.0.0.1
if grep -qE 'INADDR_ANY|htonl\(0\)|s_addr *= *0' "$SRC"; then
    ko "le serveur semble ecouter sur 0.0.0.0 (INADDR_ANY) au lieu de 127.0.0.1"
else
    ok "bind sur 127.0.0.1"
fi

# argument manquant
OUT=$("$BIN" 2>&1 >/dev/null); RC=$?
if [ "$RC" = "1" ] && [ "$OUT" = "Wrong number of arguments" ]; then
    ok "sans argument : \"Wrong number of arguments\" sur stderr, exit 1"
else
    ko "sans argument : attendu (stderr='Wrong number of arguments', rc=1), obtenu (stderr='$OUT', rc=$RC)"
fi
OUT=$("$BIN" 1 2 2>&1 >/dev/null); RC=$?
if [ "$RC" = "1" ] && [ "$OUT" = "Wrong number of arguments" ]; then
    ok "trop d'arguments : meme comportement"
else
    ko "trop d'arguments : stderr='$OUT', rc=$RC"
fi

# port deja pris -> "Fatal error"
start_server || exit 1
OUT=$("$BIN" "$PORT" 2>&1 >/dev/null); RC=$?
if [ "$RC" = "1" ] && [ "$OUT" = "Fatal error" ]; then
    ok "bind impossible : \"Fatal error\" sur stderr, exit 1"
else
    ko "bind impossible : stderr='$OUT', rc=$RC"
fi

# ------------------------------------------------------- 2bis. id du 1er client
title "2bis. Id du premier client (serveur vierge)"
stop_server
# pas de wait_port ici : toute connexion, meme un simple test de readiness,
# consommerait l'id 0. C'est le client de test lui-meme qui attend le serveur.
FRESH_PORT=$((PORT + 1)); MS_PORT=$FRESH_PORT "$BIN" "$FRESH_PORT" \
    >"$LOG/fresh.out" 2>"$LOG/fresh.err" &
FRESH_PID=$!
if MS_PORT=$FRESH_PORT python3 "$DIR/driver.py" firstid; then
    ok "le premier client recoit bien l'id 0"
else
    ko "les ids ne commencent pas a 0"
fi
kill -9 "$FRESH_PID" 2>/dev/null; wait "$FRESH_PID" 2>/dev/null
start_server || exit 1

# ---------------------------------------------------------------- 3. proto
title "3. Protocole (serveur en cours d'execution, port $PORT)"
if python3 "$DIR/driver.py" proto; then ok "tous les tests protocole passent"; else ko "au moins un test protocole echoue"; fi

# ---------------------------------------------------------------- 4. fds
title "4. Fuites de descripteurs"
FDDIR="/proc/$SERVER_PID/fd"
base=$(ls "$FDDIR" 2>/dev/null | wc -l)
echo "  fds ouverts au repos : $base (attendu 4 : stdin/stdout/stderr + socket d'ecoute)"
if [ "$base" -le 4 ]; then ok "aucun fd residuel apres les tests protocole"
else ko "$base fds ouverts alors que plus aucun client n'est connecte"; ls -l "$FDDIR" | sed 's/^/       /'; fi

python3 "$DIR/driver.py" churn >/dev/null 2>&1
after=$(ls "$FDDIR" 2>/dev/null | wc -l)
if [ "$after" -le "$base" ]; then ok "churn de connexions : fds stables ($base -> $after)"
else ko "fuite de fd : $base -> $after apres le churn"; fi

# pic de fds sous charge concurrente : detecte le depassement de FD_SETSIZE
title "5. Limite FD_SETSIZE (select)"
NCLI=${MS_FDSET_CLIENTS:-1100}
echo "  limite de fd du processus : $(ulimit -n) -- on ouvre $NCLI clients"
if grep -q 'FD_SETSIZE' "$SRC"; then
    ok "garde-fou FD_SETSIZE present dans le code"
else
    ko "aucun garde-fou : FD_SET sur un fd >= FD_SETSIZE (1024) ecrit hors du fd_set"
fi
MS_LOAD_CLIENTS=$NCLI MS_LOAD_MSGS=1 python3 "$DIR/driver.py" load \
    >"$LOG/fdset.out" 2>&1
if ! kill -0 "$SERVER_PID" 2>/dev/null; then
    ko "serveur mort avec $NCLI clients simultanes"
    sed -n '1,10p' "$LOG/server.err" | sed 's/^/       /'
elif [ "$(ulimit -n)" -le 1024 ]; then
    warn "ulimit -n = $(ulimit -n) : impossible de depasser 1024 fds, section peu concluante"
else
    ok "serveur vivant apres $NCLI connexions simultanees (excedent refuse proprement)"
fi
# Le serveur digere encore le backlog du flood (chaque arrivee est diffusee a
# tous : O(n^2)). On attend le retour a l'etat de repos avant de conclure.
settle=0
for i in $(seq 1 60); do
    n=$(ls "/proc/$SERVER_PID/fd" 2>/dev/null | wc -l)
    [ "$n" -le 4 ] && { settle=$i; break; }
    sleep 1
done
if [ "$settle" = "0" ]; then
    ko "le serveur n'est pas revenu au repos 60s apres le flood ($n fds encore ouverts)"
else
    echo "  retour au repos en ${settle}s apres la deconnexion des $NCLI clients"
fi
# le serveur doit rester pleinement fonctionnel une fois l'excedent refuse
if python3 "$DIR/driver.py" proto >"$LOG/after_fdset.out" 2>&1; then
    ok "protocole toujours correct apres saturation des fds"
else
    ko "le serveur est degrade apres saturation des fds"
    grep FAIL "$LOG/after_fdset.out" | head -5 | sed 's/^/       /'
fi
stop_server

# ---------------------------------------------------------------- 6. charge
title "6. Test de charge"
start_server || exit 1
if MS_LOAD_CLIENTS=${MS_LOAD_CLIENTS:-150} MS_LOAD_MSGS=${MS_LOAD_MSGS:-50} \
   python3 "$DIR/driver.py" load; then ok "charge encaissee"; else ko "echec sous charge"; fi
stop_server

# ---------------------------------------------------------------- 7. valgrind
title "7. Fuites memoire et fd (valgrind)"
if ! command -v valgrind >/dev/null; then
    warn "valgrind absent, section ignoree"
else
    start_server valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
                          --error-exitcode=42 --log-file="$LOG/valgrind.log" || exit 1
    MS_LOAD_CLIENTS=40 MS_LOAD_MSGS=20 python3 "$DIR/driver.py" proto  >/dev/null 2>&1
    MS_LOAD_CLIENTS=40 MS_LOAD_MSGS=20 python3 "$DIR/driver.py" load   >/dev/null 2>&1
    python3 "$DIR/driver.py" churn >/dev/null 2>&1
    sleep 1
    stop_server
    sleep 1

    if [ ! -s "$LOG/valgrind.log" ]; then
        warn "pas de rapport valgrind (le serveur n'a pas rendu la main)"
    else
        inuse=$(grep -oP 'in use at exit: \K[0-9,]+' "$LOG/valgrind.log" | tr -d ',')
        defl=$(grep -oP 'definitely lost: \K[0-9,]+' "$LOG/valgrind.log" | tr -d ',')
        indl=$(grep -oP 'indirectly lost: \K[0-9,]+' "$LOG/valgrind.log" | tr -d ',')
        posl=$(grep -oP 'possibly lost: \K[0-9,]+'   "$LOG/valgrind.log" | tr -d ',')
        reach=$(grep -oP 'still reachable: \K[0-9,]+' "$LOG/valgrind.log" | tr -d ',')
        errs=$(grep -oP 'ERROR SUMMARY: \K[0-9]+'    "$LOG/valgrind.log" | tail -1)
        echo "  in-use-at-exit=${inuse:-?}  definitely=${defl:-0}  indirectly=${indl:-0}  possibly=${posl:-0}  still-reachable=${reach:-0}"
        if [ "${inuse:-1}" = "0" ] || { [ "${defl:-0}" = "0" ] && [ "${indl:-0}" = "0" ]; }; then
            ok "aucune fuite memoire (0 octet alloue a la sortie)"
        else
            ko "fuite memoire : ${defl} octets definitely lost, ${indl} indirectly"
            grep -A6 'definitely lost' "$LOG/valgrind.log" | head -25 | sed 's/^/       /'
        fi
        # ERROR SUMMARY inclut le contexte "terminating with signal 15" du kill
        # final : on cherche donc les vraies erreurs memcheck.
        REAL=$(grep -cE 'Invalid (read|write|free)|uninitialised|Conditional jump|Mismatched free|overlap' "$LOG/valgrind.log")
        if [ "$REAL" = "0" ]; then
            ok "aucune erreur memoire (valgrind: ${errs:-0} contexte(s), dont le SIGTERM d'arret)"
        else
            ko "$REAL erreurs memoire reelles"
            grep -E 'Invalid (read|write|free)|uninitialised|Conditional jump|Mismatched free|overlap' "$LOG/valgrind.log" | sort -u | head | sed 's/^/       /'
        fi

        openfds=$(grep -oP 'FILE DESCRIPTORS: \K[0-9]+' "$LOG/valgrind.log" | tail -1)
        if [ -n "$openfds" ]; then
            echo "  fds ouverts a la sortie : $openfds"
            if [ "$openfds" -le 4 ]; then ok "aucun fd client fuite (0,1,2 + socket d'ecoute)"
            else ko "$openfds fds encore ouverts a la sortie"
                 grep -B2 -A6 'Open file descriptor' "$LOG/valgrind.log" | head -30 | sed 's/^/       /'; fi
        fi
        echo "  rapport complet : $LOG/valgrind.log"
    fi
fi

# ---------------------------------------------------------------- bilan
title "Bilan"
echo "  ${GRN}$PASS reussis${RST}, $([ "$FAIL" -gt 0 ] && echo "${RED}$FAIL echoues${RST}" || echo "0 echoue")"
[ "$FAIL" -eq 0 ] || exit 1
