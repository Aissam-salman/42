Ex00 : BitcoinExchange (btc)
Ce programme est principalement un exercice de parsing (lecture et vérification minutieuse des données).

Les dates impossibles :
Que se passe-t-il si tu mets 2001-02-29 ? (2001 n'est pas bissextile).
Et 2022-13-01 ou 2022-01-32 ?
Une année négative ou formatée bizarrement : -200-01-01 ou 20-01-01.
Les erreurs de formatage du fichier d'entrée :
Des espaces en trop ou manquants autour du | (ex: 2011-01-03|3 ou 2011-01-03  |  3).
Des lignes vides au milieu du fichier.
L'en-tête du fichier est-il strictement respecté ? Que faire s'il n'y a pas d'en-tête ?
Les valeurs numériques :
Une valeur négative : 2012-01-11 | -1.
Une valeur trop grande (le sujet précise généralement une limite comme 1000 pour l'input).
Un texte au lieu d'un nombre : 2012-01-11 | abcd.
La recherche dans la base (data.csv) :
Que fait ton programme si la date demandée dans input.txt est antérieure à la toute première date de data.csv ?
Que fait-il s'il cherche une date qui n'est pas dans le CSV ? Pense à vérifier qu'il prend bien la date inférieure la plus proche (et pas la supérieure).
Ex01 : RPN (Reverse Polish Notation)
L'important ici est la gestion de la pile (stack) et la validité de l'expression.

Erreurs de syntaxe :
Trop d'opérateurs : 1 2 + + (Que se passe-t-il quand tu essaies de dépiler mais qu'il n'y a plus de nombres ?).
Trop de nombres à la fin : 1 2 3 + (L'opération se termine, mais il reste plus d'un élément dans la pile).
Caractères invalides :
La présence de lettres ou de parenthèses : 1 2 + a * ou (1 + 2).
Des nombres à plusieurs chiffres (si le sujet impose des nombres de 0 à 9 uniquement) : 10 2 +.
Mathématiques impossibles :
La division par zéro : 4 0 /.
Arguments vides ou multiples :
Que se passe-t-il si tu lances ./RPN "" ou sans arguments ./RPN ?
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