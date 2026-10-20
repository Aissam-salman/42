#!/usr/bin/env python3
"""
Batterie de tests pour mini_serv (42).

Usage:
    ./mini_serv 8080 &
    python3 test_mini_serv.py 8080

Chaque test s'affiche avec OK / ERREUR. A la fin, un resume est imprime.
Le serveur n'est jamais lance depuis ce script : demarre-le toi-meme avant.

Important: les IDs clients sont attribues par un compteur global qui ne
redescend jamais (meme apres deconnexion). Ce script ne suppose donc JAMAIS
qu'un client aura l'id 0 ou 1 -- il observe les IDs reels via un socket
"moniteur" qui ecoute les messages "server: client X just arrived" et
construit les messages attendus a partir de ca.
"""

import re
import socket
import subprocess
import sys
import time

HOST = "127.0.0.1"
PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 8080

results = []

ARRIVED_RE = re.compile(rb"server: client (\d+) just arrived\n")


def report(name, ok, detail=""):
    status = "OK" if ok else "ERREUR"
    print(f"[{status}] {name}" + (f" -- {detail}" if detail and not ok else ""))
    results.append((name, ok))


def connect():
    return socket.create_connection((HOST, PORT))


def recv_all_nonblocking(s, timeout=0.5):
    """Recupere tout ce qui est disponible dans la fenetre de temps donnee."""
    s.settimeout(timeout)
    data = b""
    try:
        while True:
            chunk = s.recv(65536)
            if not chunk:
                break
            data += chunk
    except socket.timeout:
        pass
    return data


class IdTracker:
    """
    Garde un socket passif connecte en permanence pour observer les messages
    "server: client X just arrived" et en deduire l'ID reel attribue a
    chaque nouvelle connexion, sans jamais supposer une valeur fixe.
    """

    def __init__(self):
        self.mon = connect()
        self._buf = b""

    def _wait_next_arrived(self, timeout=2.0):
        deadline = time.time() + timeout
        self.mon.settimeout(0.05)
        while time.time() < deadline:
            m = ARRIVED_RE.search(self._buf)
            if m:
                self._buf = self._buf[m.end():]
                return int(m.group(1))
            try:
                chunk = self.mon.recv(65536)
                if chunk:
                    self._buf += chunk
            except socket.timeout:
                pass
        return None

    def connect(self):
        """Connecte un nouveau socket et retourne (socket, id_reel)."""
        s = connect()
        cid = self._wait_next_arrived()
        return s, cid

    def close(self):
        self.mon.close()


# ---------------------------------------------------------------------------
# Test 1 : arguments invalides
# ---------------------------------------------------------------------------
def test_wrong_args():
    try:
        p = subprocess.run(["./mini_serv"], capture_output=True, timeout=2)
        ok = p.returncode == 1 and b"Wrong number of arguments" in (p.stdout + p.stderr)
        report("Sans argument -> erreur + exit 1", ok,
               f"returncode={p.returncode}, out={p.stdout+p.stderr}")
    except FileNotFoundError:
        report("Sans argument -> erreur + exit 1", False,
               "binaire ./mini_serv introuvable (lance le script depuis le meme dossier)")
    except subprocess.TimeoutExpired:
        report("Sans argument -> erreur + exit 1", False,
               "le programme ne s'est pas arrete (boucle infinie ?)")

    try:
        p = subprocess.run(["./mini_serv", "8080", "9090"], capture_output=True, timeout=2)
        ok = p.returncode == 1 and b"Wrong number of arguments" in (p.stdout + p.stderr)
        report("Trop d'arguments -> erreur + exit 1", ok,
               f"returncode={p.returncode}, out={p.stdout+p.stderr}")
    except (FileNotFoundError, subprocess.TimeoutExpired) as e:
        report("Trop d'arguments -> erreur + exit 1", False, str(e))


def test_port_already_in_use():
    try:
        p = subprocess.run(["./mini_serv", str(PORT)], capture_output=True, timeout=2)
        ok = p.returncode == 1 and b"Fatal error" in (p.stdout + p.stderr)
        report("Port deja utilise -> Fatal error", ok,
               f"returncode={p.returncode}, out={p.stdout+p.stderr}")
    except (FileNotFoundError, subprocess.TimeoutExpired) as e:
        report("Port deja utilise -> Fatal error", False, str(e))


# ---------------------------------------------------------------------------
# Test 2 : arrivee / depart (le fameux "test 4")
# ---------------------------------------------------------------------------
def test_arrival_departure(tracker):
    s0, id0 = tracker.connect()
    s1, id1 = tracker.connect()

    msg0 = recv_all_nonblocking(s0)
    expected0 = f"server: client {id1} just arrived\n".encode()
    report("Client 0 voit l'arrivee du client 1", msg0 == expected0,
           f"recu={msg0!r} attendu={expected0!r}")

    s0.close()
    time.sleep(0.3)

    msg1 = recv_all_nonblocking(s1)
    expected1 = f"server: client {id0} just left\n".encode()
    report("Client 1 voit le depart du client 0 (message seul, non fusionne)",
           msg1 == expected1, f"recu={msg1!r} attendu={expected1!r}")

    s1.close()


# ---------------------------------------------------------------------------
# Test 3 : message envoye en plusieurs morceaux (fragmentation TCP)
# ---------------------------------------------------------------------------
def test_fragmented_message(tracker):
    a, id_a = tracker.connect()
    b, _ = tracker.connect()
    recv_all_nonblocking(b)  # purge "just arrived"

    a.sendall(b"hel")
    time.sleep(0.3)
    a.sendall(b"lo")
    time.sleep(0.3)
    a.sendall(b" world\n")
    time.sleep(0.3)

    data = recv_all_nonblocking(b)
    expected = f"client {id_a}: hello world\n".encode()
    report("Message fragmente en plusieurs send() reassemble correctement",
           data == expected, f"recu={data!r} attendu={expected!r}")

    a.close()
    b.close()


# ---------------------------------------------------------------------------
# Test 4 : plusieurs lignes envoyees d'un coup
# ---------------------------------------------------------------------------
def test_multiple_lines(tracker):
    a, id_a = tracker.connect()
    b, _ = tracker.connect()
    recv_all_nonblocking(b)

    a.sendall(b"un\ndeux\ntrois\n")
    time.sleep(0.3)

    data = recv_all_nonblocking(b)
    expected = (
        f"client {id_a}: un\n"
        f"client {id_a}: deux\n"
        f"client {id_a}: trois\n"
    ).encode()
    report("Plusieurs lignes envoyees d'un coup -> plusieurs messages distincts",
           data == expected, f"recu={data!r} attendu={expected!r}")

    a.close()
    b.close()


# ---------------------------------------------------------------------------
# Test 5 : pas de \n -> rien ne doit partir
# ---------------------------------------------------------------------------
def test_no_newline_yet(tracker):
    a, _ = tracker.connect()
    b, _ = tracker.connect()
    recv_all_nonblocking(b)

    a.sendall(b"pas de retour a la ligne")
    data = recv_all_nonblocking(b, timeout=1)
    report("Aucun \\n -> rien n'est envoye aux autres clients",
           data == b"", f"recu={data!r} (devrait etre vide)")

    a.close()
    b.close()


# ---------------------------------------------------------------------------
# Test 6 : gros volume (> 4096 octets, plusieurs recv() cote serveur)
# ---------------------------------------------------------------------------
def test_large_payload(tracker):
    a, id_a = tracker.connect()
    b, _ = tracker.connect()
    recv_all_nonblocking(b)

    payload = b"a" * 100000 + b"\n"
    a.sendall(payload)

    received = recv_all_nonblocking(b, timeout=2)
    expected = f"client {id_a}: ".encode() + payload
    report("Gros message (100000 octets) transmis integralement",
           received == expected,
           f"recu {len(received)} octets, attendu {len(expected)} octets")

    a.close()
    b.close()


# ---------------------------------------------------------------------------
# Test 7 : beaucoup de clients simultanes
# ---------------------------------------------------------------------------
def test_many_clients(tracker, n=50):
    socks = []
    try:
        first, id_first = tracker.connect()
        socks.append(first)
        for _ in range(n - 1):
            s, _ = tracker.connect()
            socks.append(s)

        for s in socks:
            recv_all_nonblocking(s, timeout=0.2)  # purge les "just arrived"

        socks[0].sendall(b"salut tout le monde\n")
        time.sleep(0.3)

        expected = f"client {id_first}: salut tout le monde\n".encode()
        all_ok = True
        for i, s in enumerate(socks[1:], start=1):
            data = recv_all_nonblocking(s, timeout=1)
            if data != expected:
                all_ok = False
                report(f"Broadcast a {n} clients", False,
                       f"client (index {i}) a recu {data!r} au lieu de {expected!r}")
                break
        if all_ok:
            report(f"Broadcast a {n} clients simultanes", True)
    except Exception as e:
        report(f"Broadcast a {n} clients simultanes", False, str(e))
    finally:
        for s in socks:
            try:
                s.close()
            except OSError:
                pass


# ---------------------------------------------------------------------------
# Test 8 : connexions/deconnexions rapides (stress liste chainee)
# ---------------------------------------------------------------------------
def test_rapid_connect_disconnect(tracker, n=100):
    try:
        for _ in range(n):
            s = connect()
            s.close()
        time.sleep(0.3)
        # Purge le bruit genere dans le moniteur par ces 100 connexions/deconnexions
        recv_all_nonblocking(tracker.mon, timeout=0.5)
        tracker._buf = b""

        # le serveur doit repondre normalement apres le stress
        a, id_a = tracker.connect()
        b, _ = tracker.connect()
        recv_all_nonblocking(b)
        a.sendall(b"toujours vivant\n")
        time.sleep(0.3)
        data = recv_all_nonblocking(b)
        expected = f"client {id_a}: toujours vivant\n".encode()
        report(f"{n} connect/disconnect rapides puis serveur toujours fonctionnel",
               data == expected, f"recu={data!r} attendu={expected!r}")
        a.close()
        b.close()
    except Exception as e:
        report(f"{n} connect/disconnect rapides", False, str(e))


# ---------------------------------------------------------------------------
# Test 9 : \0 au milieu du flux (edge case)
# ---------------------------------------------------------------------------
def test_null_byte(tracker):
    a, id_a = tracker.connect()
    b, _ = tracker.connect()
    recv_all_nonblocking(b)

    a.sendall(b"avant\x00apres\n")
    time.sleep(0.3)
    data = recv_all_nonblocking(b)
    # On ne sait pas quel comportement est "correct" a 100%, donc on affiche juste le resultat.
    print(f"[INFO] Octet nul dans le flux (client attendu={id_a}) -> recu={data!r} "
          f"(verifie a l'oeil si c'est le comportement attendu par ta correction)")
    a.close()
    b.close()


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    print(f"=== Tests mini_serv sur {HOST}:{PORT} ===\n")

    print("--- Arguments et erreurs (sans serveur lance sur ce port) ---")
    test_wrong_args()

    print("\n--- IMPORTANT: assure-toi que ./mini_serv est deja lance sur le port", PORT, "---")
    input("Appuie sur Entree une fois le serveur demarre... ")

    test_port_already_in_use()

    print("\n--- Tests fonctionnels (IDs suivis dynamiquement) ---")
    tracker = IdTracker()
    try:
        test_arrival_departure(tracker)
        test_fragmented_message(tracker)
        test_multiple_lines(tracker)
        test_no_newline_yet(tracker)
        test_large_payload(tracker)
        test_many_clients(tracker)
        test_rapid_connect_disconnect(tracker)
        test_null_byte(tracker)
    finally:
        tracker.close()

    print("\n=== Resume ===")
    passed = sum(1 for _, ok in results if ok)
    total = len(results)
    for name, ok in results:
        print(f"  [{'OK' if ok else 'X '}] {name}")
    print(f"\n{passed}/{total} tests passes.")


if __name__ == "__main__":
    main()
