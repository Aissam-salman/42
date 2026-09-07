#!/usr/bin/env python3
"""Driver de tests protocole + charge pour mini_serv."""
import socket, sys, time, select, os

HOST = "127.0.0.1"
PORT = int(os.environ.get("MS_PORT", "8080"))
TMO  = float(os.environ.get("MS_TIMEOUT", "2.0"))

fails = []
def check(name, cond, detail=""):
    print(("  OK   " if cond else "  FAIL ") + name + (("  -> " + detail) if (detail and not cond) else ""))
    if not cond:
        fails.append(name)

class ServerDown(Exception):
    pass

def conn():
    try:
        s = socket.create_connection((HOST, PORT), timeout=TMO)
    except ConnectionRefusedError:
        raise ServerDown("aucun serveur n'ecoute sur %s:%d" % (HOST, PORT))
    except OSError as e:
        raise ServerDown("connexion a %s:%d impossible : %s" % (HOST, PORT, e))
    s.setblocking(False)
    return s

def wait_server(timeout=5.0):
    """Attend que le serveur ecoute. Consomme un id : ne pas appeler avant un
    test qui verifie une valeur d'id absolue (cf. t_first_id)."""
    end = time.time() + timeout
    while time.time() < end:
        try:
            s = socket.create_connection((HOST, PORT), timeout=0.3)
            s.close()
            return True
        except OSError:
            time.sleep(0.05)
    return False

def drain(socks, wait=0.35):
    """Lit tout ce qui arrive sur les sockets pendant `wait` secondes.

    poll() et non select() : cote client aussi FD_SETSIZE plafonne a 1024,
    et le test de charge ouvre plus de sockets que ca."""
    out = {s: b"" for s in socks}
    if not socks:
        time.sleep(wait); return {}
    byfd = {s.fileno(): s for s in socks}
    po = select.poll()
    for fd in byfd:
        po.register(fd, select.POLLIN)
    end = time.time() + wait
    while time.time() < end:
        for fd, _ev in po.poll(50):
            s = byfd.get(fd)
            if s is None:
                continue
            try:
                d = s.recv(65536)
            except (BlockingIOError, ConnectionResetError):
                continue
            if d:
                out[s] += d
    return {s: v.decode(errors="replace") for s, v in out.items()}

def send(s, data):
    s.setblocking(True); s.sendall(data.encode()); s.setblocking(False)

# ---------------------------------------------------------------- test 0
def t_first_id():
    """A lancer sur un serveur VIERGE : toute connexion anterieure consomme un id."""
    print("\n[0] le tout premier client recoit l'id 0")
    a = None
    for _ in range(100):                 # la connexion sert aussi de test de readiness
        try:
            a = conn(); break
        except ServerDown:
            time.sleep(0.05)
    if a is None:
        check("connexion au serveur", False, "serveur injoignable"); return
    b = conn(); o = drain([a, b])
    check("le 1er client voit \"server: client 1 just arrived\"",
          o[a] == "server: client 1 just arrived\n",
          "%r (ids decales : le premier client n'a pas l'id 0)" % o[a])
    a.close(); b.close(); drain([], 0.2)

# ---------------------------------------------------------------- test 1
def t_ids_and_arrival():
    """Ids relatifs : ce serveur a deja servi des connexions (readiness, test de
    bind occupe), donc on verifie l'incrementation, pas la valeur absolue.
    La valeur absolue est couverte par t_first_id sur un serveur vierge."""
    print("\n[1] ids sequentiels + message d'arrivee")
    a = conn(); drain([a])
    b = conn(); o = drain([a, b])
    check("client a est notifie de l'arrivee de b",
          o[a].startswith("server: client ") and o[a].endswith(" just arrived\n"), repr(o[a]))
    check("le nouveau client ne recoit pas sa propre arrivee", o[b] == "", repr(o[b]))
    try:
        idb = int(o[a].split()[2])
    except (IndexError, ValueError):
        check("id lisible dans le message d'arrivee", False, repr(o[a])); idb = None
    c = conn(); o = drain([a, b, c])
    if idb is not None:
        check("le client suivant recoit id+1",
              o[a] == "server: client %d just arrived\n" % (idb + 1), repr(o[a]))
        check("tous les clients deja connectes sont notifies",
              o[a] == o[b], "a=%r b=%r" % (o[a], o[b]))
    for s in (a, b, c): s.close()
    drain([], 0.2)

# ---------------------------------------------------------------- test 2
def t_broadcast():
    print("\n[2] broadcast + prefixe 'client %d: '")
    a = conn(); b = conn(); c = conn(); drain([a, b, c])
    send(a, "hello\n")
    o = drain([a, b, c])
    check("l'emetteur ne recoit pas son propre message", o[a] == "", repr(o[a]))
    check("b recoit le message prefixe", o[b].endswith("hello\n") and ": hello\n" in o[b], repr(o[b]))
    check("c recoit la meme chose", o[b] == o[c], "b=%r c=%r" % (o[b], o[c]))
    for s in (a, b, c): s.close()
    drain([], 0.2)

# ---------------------------------------------------------------- test 3
def t_multiline():
    print("\n[3] message multi-lignes en un seul send")
    a = conn(); b = conn(); drain([a, b])
    send(a, "un\ndeux\ntrois\n")
    o = drain([a, b])
    lines = [l for l in o[b].split("\n") if l]
    check("3 lignes prefixees separement", len(lines) == 3, repr(o[b]))
    check("chaque ligne a son prefixe",
          all(l.startswith("client ") and ": " in l for l in lines), repr(lines))
    for s in (a, b): s.close()
    drain([], 0.2)

# ---------------------------------------------------------------- test 4
def t_partial():
    print("\n[4] ligne partielle bufferisee (pas de \\n)")
    a = conn(); b = conn(); drain([a, b])
    send(a, "pas de newline")
    o = drain([a, b])
    check("rien n'est diffuse sans \\n", o[b] == "", repr(o[b]))
    send(a, " encore\n")
    o = drain([a, b])
    check("la ligne complete est diffusee d'un bloc",
          o[b].endswith("pas de newline encore\n") and o[b].count("client") == 1, repr(o[b]))
    for s in (a, b): s.close()
    drain([], 0.2)

# ---------------------------------------------------------------- test 5
def t_leave():
    print("\n[5] message de deconnexion")
    a = conn(); b = conn(); drain([a, b])
    bid = None
    c = conn(); o = drain([a, b, c])
    bid = o[a].strip().split()[2]
    c.close()
    o = drain([a, b])
    check("les autres recoivent 'just left'",
          o[a] == "server: client %s just left\n" % bid, repr(o[a]))
    check("tous les autres le recoivent", o[a] == o[b], "a=%r b=%r" % (o[a], o[b]))
    for s in (a, b): s.close()
    drain([], 0.2)

# ---------------------------------------------------------------- test 6
def t_lazy():
    print("\n[6] client paresseux (ne lit jamais) -> ne doit pas etre deconnecte")
    lazy = conn()                       # ne lira jamais
    a = conn(); drain([a])
    payload = "x" * 900 + "\n"
    for _ in range(400):                # ~360 KB : depasse largement les buffers noyau
        try:
            send(a, payload)
        except (BrokenPipeError, ConnectionResetError) as e:
            check("l'emetteur reste connecte", False, str(e)); break
    time.sleep(0.5)
    # le paresseux doit toujours etre vivant : on verifie via un 3e client
    d = conn(); o = drain([a, d])
    check("le serveur accepte toujours des clients", o[a].startswith("server: client"), repr(o[a][:80]))
    send(d, "ping\n")
    o = drain([a, d])
    check("le serveur diffuse toujours", "ping\n" in o[a], repr(o[a][-60:]))
    # le paresseux se met a lire : il doit retrouver ses donnees
    got = 0
    end = time.time() + 3
    lazy.setblocking(False)
    po = select.poll(); po.register(lazy.fileno(), select.POLLIN)
    while time.time() < end:
        if po.poll(50):
            try:
                d2 = lazy.recv(65536)
            except (BlockingIOError, ConnectionResetError):
                continue
            if not d2: break
            got += len(d2)
    check("le client paresseux recoit ses donnees en retard (%d octets)" % got, got > 100000,
          "%d octets seulement" % got)
    for s in (lazy, a, d): s.close()
    drain([], 0.3)

# ---------------------------------------------------------------- charge
def t_load(nclients=int(os.environ.get("MS_LOAD_CLIENTS", "120")),
           nmsg=int(os.environ.get("MS_LOAD_MSGS", "40"))):
    print("\n[7] test de charge : %d clients x %d messages" % (nclients, nmsg))
    socks = []
    t0 = time.time()
    try:
        for _ in range(nclients):
            socks.append(conn())
    except OSError as e:
        check("connexion de %d clients" % nclients, False, str(e))
        for s in socks: s.close()
        return
    check("%d clients connectes (%.2fs)" % (len(socks), time.time() - t0), len(socks) == nclients)
    drain(socks, 1.0)

    t0 = time.time()
    sent = 0
    for i in range(nmsg):
        for idx, s in enumerate(socks):
            try:
                send(s, "m%d-%d\n" % (idx, i)); sent += 1
            except OSError as e:
                check("envoi soutenu", False, str(e)); break
        # on vide au fur et a mesure pour ne pas bloquer sur les buffers noyau
        drain(socks, 0.02)
    dur = time.time() - t0
    total = drain(socks, 2.0)
    recv_bytes = sum(len(v) for v in total.values())
    print("       %d messages envoyes en %.2fs (%.0f msg/s), %d octets relus" %
          (sent, dur, sent / dur if dur else 0, recv_bytes))
    check("le serveur a tenu la charge sans planter", recv_bytes > 0)

    # toujours vivant apres la charge ?
    try:
        probe = conn(); drain([probe], 0.3); probe.close()
        check("serveur toujours vivant apres la charge", True)
    except OSError as e:
        check("serveur toujours vivant apres la charge", False, str(e))
    for s in socks: s.close()
    drain([], 0.5)

# ---------------------------------------------------------------- churn
def t_churn(n=int(os.environ.get("MS_CHURN", "300"))):
    print("\n[8] churn : %d connexions/deconnexions rapides (detection de fuite de fd)" % n)
    ok = True
    for _ in range(n):
        try:
            s = socket.create_connection((HOST, PORT), timeout=TMO)
            s.close()
        except OSError as e:
            ok = False
            check("churn", False, str(e))
            break
    time.sleep(0.5)
    if ok:
        check("%d cycles connect/close encaisses" % n, True)

ALL = {"firstid": [t_first_id],
       "proto": [t_ids_and_arrival, t_broadcast, t_multiline, t_partial, t_leave, t_lazy],
       "load":  [t_load],
       "churn": [t_churn]}

if __name__ == "__main__":
    which = sys.argv[1] if len(sys.argv) > 1 else "proto"
    if which not in ALL:
        print("usage: %s [%s]" % (sys.argv[0], "|".join(ALL)), file=sys.stderr)
        sys.exit(2)

    # firstid fait sa propre attente : toute connexion prealable consommerait
    # l'id 0 et fausserait le test.
    if which != "firstid" and not wait_server():
        print("ERREUR : aucun serveur n'ecoute sur %s:%d.\n"
              "         Lance-le d'abord :  ./mini_serv %d &\n"
              "         ou passe par le harnais complet :  ./tests/run_tests.sh\n"
              "         (port configurable via MS_PORT)" % (HOST, PORT, PORT),
              file=sys.stderr)
        sys.exit(2)

    for fn in ALL[which]:
        try:
            fn()
        except ServerDown as e:
            print("  FAIL %s -> %s" % (fn.__name__, e))
            print("\nLe serveur a cesse de repondre en cours de test "
                  "(crash ? il a ferme la connexion ?).", file=sys.stderr)
            fails.append(fn.__name__)
            break
        except OSError as e:
            print("  FAIL %s -> erreur reseau : %s" % (fn.__name__, e))
            fails.append(fn.__name__)
    print()
    if fails:
        print("ECHECS (%d): %s" % (len(fails), ", ".join(fails)))
        sys.exit(1)
    sys.exit(0)
