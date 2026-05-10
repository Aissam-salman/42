Ex02 : PmergeMe
Ici, on évalue ton implémentation de l'algorithme de Ford-Johnson (Merge-Insert Sort) sur deux conteneurs différents.

Limites de parsing :
Des arguments qui ne sont pas des nombres : ./PmergeMe 1 2 a 3.
Des valeurs négatives : ./PmergeMe 1 2 -3 4.
Des valeurs qui dépassent l' INT_MAX (ex: 2147483648).
Cas aux limites (Edge cases) :
Un seul nombre fourni : ./PmergeMe 42.
Deux nombres fournis (déjà triés, ou inversés) : ./PmergeMe 2 1.
Séquence avec des nombres en double (le sujet permet-il les doublons ou doit-on renvoyer une erreur ?).
Performance et respect de l'algorithme :
Teste avec 3000 nombres aléatoires générés via une commande shell (ex: ./PmergeMe `shuf -i 1-10000 -n 3000 | tr '\n' ' '` ).
Vérifie tes temps d'exécution. Les temps d'affichage du résultat doivent être cohérents.
Assure-toi que tu utilises bien deux conteneurs différents (par exemple std::vector et std::list ou std::deque), et que tu ne triches pas en utilisant une fonction std::sort() générique pour tout faire !
Un dernier conseil : Lance tous ces tests avec valgrind (ou compile avec -fsanitize=address -g3) pour t'assurer qu'aucune de ces erreurs ne provoque de fuites mémoire (leaks) quand le programme s'arrête prématurément. Bon courage pour les correctifs !
