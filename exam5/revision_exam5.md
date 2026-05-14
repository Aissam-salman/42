# Révision Exam 5 - L'essentiel à retenir

Ce document résume les concepts techniques et les pièges classiques des 4 exercices pour pouvoir les refaire facilement.

## 1. Vect2 (`vect2/`) - Classe de base et Surcharge d'opérateurs
**Objectif :** Créer une classe `Vect2` fonctionnelle avec des mathématiques 2D basiques.
* **La forme canonique (Coplien) :** Pensez à toujours implémenter :
  - Le constructeur par défaut.
  - Le constructeur de copie (`Vect2(const Vect2& other)`).
  - L'opérateur d'affectation (`Vect2& operator=(const Vect2& other)`).
  - Le destructeur (`~Vect2()`).
* **Surcharge d'opérateurs :** 
  - Différencier les opérateurs membres (`operator+`, `operator-`) des opérateurs non-membres.
  - Surcharge de l'affichage : `std::ostream& operator<<(std::ostream& os, const Vect2& v)` doit être externe à la classe.
* **Const-correctness :** Utiliser `const` pour les méthodes qui ne modifient pas l'objet (`void print() const;`) et `const Type&` pour les paramètres.

## 2. BigInt (`bigint/`) - Algorithmique et Gestion de la mémoire
**Objectif :** Calculer avec de très grands nombres, dépassant les limites d'un `int` ou `long`.
* **Stockage :** Représenter les nombres via un tableau ou une `std::string`. **Astuce :** Stockez le nombre à l'envers (l'index `0` pour les unités, l'index `1` pour les dizaines). Cela facilite énormément le prolongement du tableau lors de l'addition.
* **Gestion des retenues (Carry) :** Lors de l'addition (`operator+`), bouclez tant qu'il y a des chiffres dans l'un des nombres OU que la retenue (`carry`) est > 0.
* **Zéros non significatifs :** Après un calcul, pensez à faire une boucle pour supprimer les "zéros de tête" (si stocké dans l'ordre inverse, ce sont les zéros à la fin du conteneur).
* **Optimisation :** Faites attention aux allocations mémoire inutiles en faisant vos boucles de calcul.

## 3. Game of Life (`life/`) - Matrices et C pur
**Objectif :** Coder le Jeu de la Vie de Conway sur une grille 2D.
* **Le Buffer (Double Grille) :** Vous ne pouvez pas modifier la grille en même temps que vous la lisez, car le statut futur d'une cellule dépend du statut actuel de ses voisines. Il faut TOUJOURS lire depuis `grille_actuelle` et écrire le résultat dans `grille_suivante`.
* **Comptage des voisins :** Pour chaque case `[y][x]`, vérifiez les 8 directions (de `[y-1][x-1]` à `[y+1][x+1]`). Ne comptez pas la case courante `[y][x]` !
* **Gestion des bords :** N'oubliez pas de mettre des conditions `if` pour ne pas essayer d'accéder à `[y-1]` si `y == 0` (Out of Bounds / Segfault). 
* **Les 3 règles simples :**
  1. Vivante + 2 ou 3 voisines -> Reste vivante.
  2. Morte + exactement 3 voisines -> Devient vivante.
  3. Tout le reste -> Meurt / Reste morte.

## 4. Polyset (`polyset/`) - Polymorphisme et Héritage (C++)
**Objectif :** Gérer une structure complexe de classes et sous-classes (Bags, Sets, Arrays, Trees).
* **Classes Abstraites et Interfaces :** Une classe mère abstraite (`Bag` ou `SearchableBag`) doit avoir au moins une méthode virtuelle pure (`virtual void insert(int x) = 0;`).
* **Le Destructeur Virtuel :** C'EST LA RÈGLE D'OR EN C++. Toute classe destinée à être héritée DOIT posséder un destructeur virtuel (`virtual ~Bag() = default;`). Sinon, un `delete` sur un pointeur parent ne détruira pas la sous-classe (fuite de mémoire).
* **Override :** Utilisez toujours le mot-clé `override` à la fin de vos méthodes polymorphiques (`void insert(int x) override;`). Ça permet au compilateur de vous avertir si vous ratez la signature de la fonction parente.
* **Constructeurs des parents :** Lors de la création d'une sous-classe, n'oubliez pas d'initialiser correctement la partie mère : `ArrayBag(int cap) : Bag(), _capacity(cap) {}` si nécessaire.
