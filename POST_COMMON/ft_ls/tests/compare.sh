#!/usr/bin/env bash
# Compare ./ft_ls avec le vrai ls du systeme (BSD sur macOS, GNU sur Fedora).
# Usage : tests/compare.sh [-v]   (-v affiche le diff des tests qui echouent)

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FT_LS="$ROOT/ft_ls"
VERBOSE=0
[ "$1" = "-v" ] && VERBOSE=1

# Pas d'alias dans un script, mais on force quand meme le binaire et la locale C
REAL_LS="$(command -v ls)"
export LC_ALL=C
unset CLICOLOR LSCOLORS LS_COLORS

[ -x "$FT_LS" ] || { echo "ft_ls introuvable, lance make"; exit 1; }

# Arborescence de test avec des dates fixes pour que -t soit deterministe
FIX="$(mktemp -d)"
trap 'rm -rf "$FIX"' EXIT
mkdir -p "$FIX/dir/sub/deep" "$FIX/dir/.hidden_dir" "$FIX/empty"
echo a > "$FIX/dir/a"
echo bb > "$FIX/dir/B"
echo ccc > "$FIX/dir/.hidden"
echo x > "$FIX/dir/sub/file"
echo y > "$FIX/dir/sub/deep/file2"
ln -s a "$FIX/dir/link_a"
ln -s nowhere "$FIX/dir/broken_link"
touch -t 202001011200 "$FIX/dir/a"
touch -t 202101011200 "$FIX/dir/B"
touch -t 201901011200 "$FIX/dir/.hidden"
touch -t 202201011200 "$FIX/dir/sub"
chmod 600 "$FIX/dir/B"

PASS=0
FAIL=0

run() {
	local expected actual
	expected="$(cd "$FIX" && "$REAL_LS" "$@" 2>&1; echo "exit=$?")"
	actual="$(cd "$FIX" && "$FT_LS" "$@" 2>&1; echo "exit=$?")"
	# Le nom du programme differe dans les messages d'erreur
	actual="${actual//ft_ls:/ls:}"
	if [ "$expected" = "$actual" ]; then
		PASS=$((PASS + 1))
		printf '\033[32m[OK]\033[0m   ls %s\n' "$*"
	else
		FAIL=$((FAIL + 1))
		printf '\033[31m[KO]\033[0m   ls %s\n' "$*"
		[ $VERBOSE -eq 1 ] && diff <(echo "$expected") <(echo "$actual") | sed 's/^/        /'
	fi
}

run
run dir
run -a dir
run -r dir
run -t dir
run -l dir
run -R dir
run -la dir
run -lt dir
run -ltr dir
run -laRtr dir
run -R -a -r dir
run dir/a dir/B
run dir/a dir
run empty
run empty dir
run dir/link_a
run -l dir/link_a
run -l dir/broken_link
run nonexistent
run nonexistent dir
run -z

echo
echo "$PASS OK, $FAIL KO  (reference : $REAL_LS, $(uname -s))"
[ $FAIL -eq 0 ]
