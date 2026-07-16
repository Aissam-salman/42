#!/bin/sh
# Test runner pour bsq2 : compile, lance chaque cas, affiche OK / KO
# Usage: ./test.sh

SRC="bsq2.c"
BIN="./bsq_run"
PASS=0
FAIL=0

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

# ---------------------------------------------------------------------------
# check <nom> <input> <sortie_attendue>
# Envoie <input> sur stdin du binaire et compare la sortie exacte.
# ---------------------------------------------------------------------------
check() {
    name="$1"
    input="$2"
    expected="$3"

    got=$(printf '%s' "$input" | $BIN 2>/dev/null)
    if [ "$got" = "$expected" ]; then
        PASS=$((PASS + 1))
        printf "${GREEN}OK${NC}   %s\n" "$name"
    else
        FAIL=$((FAIL + 1))
        printf "${RED}KO${NC}   %s\n" "$name"
        printf "     --- attendu ---\n%s\n     --- obtenu ---\n%s\n     --------------\n" "$expected" "$got"
    fi
}

# ---------------------------------------------------------------------------
# Compilation
# ---------------------------------------------------------------------------
printf "${YELLOW}== Compilation ==${NC}\n"
if cc -Wall -Wextra -Werror "$SRC" -o "$BIN" 2>"$TMP/cc.log"; then
    printf "${GREEN}OK${NC}   compile sans warning\n"
    PASS=$((PASS + 1))
else
    printf "${RED}KO${NC}   compilation echouee :\n"
    cat "$TMP/cc.log"
    FAIL=$((FAIL + 1))
    printf "\n${RED}Arret : le binaire ne compile pas.${NC}\n"
    exit 1
fi

printf "\n${YELLOW}== Cas valides ==${NC}\n"

check "1x1 vide -> carre 1" \
"1 . o x
." \
"x"

check "1x1 obstacle -> inchange" \
"1 . o x
o" \
"o"

check "2x2 plein -> carre 2x2" \
"2 . o x
..
.." \
"xx
xx"

check "tie-break : premier carre en haut a gauche" \
"3 . o x
...
...
..." \
"xxx
xxx
xxx"

check "obstacle bloque un coin -> carre 2x2 haut/gauche" \
"3 . o x
o..
...
..." \
"oxx
.xx
..."

check "tout obstacle -> aucun carre" \
"2 . o x
oo
oo" \
"oo
oo"

check "rectangle 2x3" \
"2 . o x
...
..." \
"xx.
xx."

check "carre 3x3 possible malgre obstacle a droite" \
"3 . o x
....
....
...o" \
"xxx.
xxx.
xxxo"

check "charset alternatif (Z S #)" \
"1 Z S #
Z" \
"#"

check "derniere ligne sans newline" \
"2 . o x
..
.." \
"xx
xx"

printf "\n${YELLOW}== Cas d'erreur (map error) ==${NC}\n"

check "fichier vide" "" "map error"
check "legende seule sans map" "3 . o x
" "map error"
check "hauteur 0" "0 . o x
" "map error"
check "caracteres dupliques" "3 . . x
...
...
..." "map error"
check "mauvaise largeur" "3 . o x
...
....
..." "map error"
check "trop peu de lignes" "3 . o x
...
..." "map error"
check "trop de lignes" "2 . o x
..
..
.." "map error"
check "caractere invalide dans la map" "3 . o x
..Z
...
..." "map error"
check "premiere ligne vide" "2 . o x

.." "map error"
check "legende invalide" "abc
..." "map error"

# ---------------------------------------------------------------------------
# Test fichiers en argument
# ---------------------------------------------------------------------------
printf "\n${YELLOW}== Test argument fichier ==${NC}\n"
printf '2 . o x\n..\n..\n' > "$TMP/ok.map"
got=$($BIN "$TMP/ok.map" 2>/dev/null)
if [ "$got" = "xx
xx" ]; then
    PASS=$((PASS + 1)); printf "${GREEN}OK${NC}   fichier valide en argument\n"
else
    FAIL=$((FAIL + 1)); printf "${RED}KO${NC}   fichier valide en argument\n"
fi

got=$($BIN "$TMP/does_not_exist.map" 2>/dev/null)
if [ "$got" = "map error" ]; then
    PASS=$((PASS + 1)); printf "${GREEN}OK${NC}   fichier inexistant -> map error\n"
else
    FAIL=$((FAIL + 1)); printf "${RED}KO${NC}   fichier inexistant -> map error\n"
fi

# ---------------------------------------------------------------------------
# Test memoire (si ASan dispo) : pas de fuite / pas de crash
# ---------------------------------------------------------------------------
printf "\n${YELLOW}== Test memoire (ASan) ==${NC}\n"
if cc -Wall -Wextra -Werror -fsanitize=address,undefined -g "$SRC" -o "$TMP/bsq_asan" 2>/dev/null; then
    printf '9 . o x\n' > "$TMP/stress.map"
    awk 'BEGIN{srand(); for(i=0;i<9;i++){s="";for(j=0;j<27;j++){r=rand(); s=s (r<0.15?"o":".")}; print s}}' >> "$TMP/stress.map"
    if ASAN_OPTIONS=detect_leaks=1 "$TMP/bsq_asan" "$TMP/stress.map" >/dev/null 2>"$TMP/asan.log"; then
        PASS=$((PASS + 1)); printf "${GREEN}OK${NC}   aucune fuite / erreur memoire\n"
    else
        FAIL=$((FAIL + 1)); printf "${RED}KO${NC}   erreur memoire detectee :\n"; cat "$TMP/asan.log"
    fi
else
    printf "${YELLOW}--${NC}   ASan indisponible, test memoire ignore\n"
fi

# ---------------------------------------------------------------------------
# Resume
# ---------------------------------------------------------------------------
rm -f "$BIN"
printf "\n${YELLOW}== Resume ==${NC}\n"
printf "Reussis : ${GREEN}%d${NC}   Echoues : ${RED}%d${NC}\n" "$PASS" "$FAIL"
if [ "$FAIL" -eq 0 ]; then
    printf "${GREEN}==> TOUT OK${NC}\n"
    exit 0
else
    printf "${RED}==> DES TESTS ONT ECHOUE (KO)${NC}\n"
    exit 1
fi
