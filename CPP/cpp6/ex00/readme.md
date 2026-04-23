# Pistes d'amélioration et Corrections Potentielles - Module 06 ex00

Ce fichier contient des pistes de réflexion pour améliorer ton implémentation du `ScalarConverter` et éviter de perdre des points lors de la correction, tout en respectant l'esprit du sujet de l'école 42.

## 1. Instanciation de la classe `ScalarConverter`
**Le problème :** Ton constructeur par défaut, par copie, ton opérateur d'assignation et ton destructeur sont `public` dans ton `.hpp`.
**Piste :** Le sujet stipule généralement que cette classe ne doit contenir qu'une méthode statique et _ne doit pas être instanciée par l'utilisateur_.
*Que se passe-t-il si quelqu'un fait `ScalarConverter a;` dans le main ?*
Pour empêcher cela, déclare ton constructeur par défaut, par copie, ton destructeur et ton opérateur d'assignation dans la section `private`.

## 2. Affichage des caractères (`char`)
**Le problème :** Tu affiches correctement "impossible" ou "not printable", mais quand le caractère est imprimable, tu l'affiches tout seul.
**Piste :** Le sujet de 42 demande que les caractères affichables soient toujours entourés par des guillemets simples (ex: `char: 'a'`). Tu devrais adapter ton `std::cout` pour entourer la variable `c`.

## 3. Précision de l'affichage des `float` et `double`
**Le problème :** Si tu passes la valeur "42", ton programme affiche `float: 42f` et `double: 42`.
**Piste :** Le sujet exige explicitement l'affichage du `.0` pour les nombres ronds (ex: `42.0f` et `42.0`). Renseigne-toi sur la bibliothèque `<iomanip>` et les manipulateurs de flux comme `std::fixed` et `std::setprecision(1)`. (Exactement ce que tu avais noté au début de ce fichier !)

## 4. Rigueur sur les mots-clés d'erreur
**Le problème :** Tu utilises "overflow int".
**Piste :** C'est clair et explicite, mais le sujet indique que si une conversion n'a pas de sens ou est hors bornes, il faut afficher `impossible`. N'hésite pas à le changer si tu veux être "safe" face à la moulinette ou aux correcteurs stricts.

## 5. Makefile dependencies
**Piste :** Ton `Makefile` compile bien les sources. Cependant, tes `.cpp` ne dépendent pas explicitement de tes `.hpp` dans les règles. Si tu modifies `ScalarConverter.hpp`, relancer `make` ne re-compilera pas ton code puisque le Makefile ne voit le changement que sur les `.cpp`. Ajoute les entêtes dans les dépendances de tes objets (`%.o: %.cpp ScalarConverter.hpp`).