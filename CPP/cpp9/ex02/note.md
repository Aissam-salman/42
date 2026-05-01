

# Prepa
- take av
- check if only digit
- try to convert item to int, check if not overflow INT_MAX
- remplir vector<int>
- create vector<pair<int,int>
- trier les pairs, gauche petit | droite grand
- si item orphelin stocker dans une variable a part

# tri des gagnants
- parcourir origine structure, recup les gagnants
- mettre dans un vector<int> mainChain
- appliquer algo de tri recursif sur cette liste

La récursivité ne sert pas à insérer les perdants. Elle sert uniquement à trier tes gagnants. Voici le flux logique :

    Ta fonction tri(liste) reçoit une liste brute.

    Elle crée les paires.

    Elle sépare les gagnants (winners) et les perdants (pend).

    C'est ici que se trouve la récursivité : Tu appelles tri(winners).

        Ton programme "met en pause" l'insertion des perdants et descend dans un nouveau niveau de récursion pour trier les gagnants du niveau précédent.

        Cela continue jusqu'à ce que la liste soit trop petite (cas de base : taille 0 ou 1, on retourne la liste).

    Retour de récursion : Une fois que tri(winners) a fini son travail et renvoie une liste triée, tu récupères cette liste (ta Main_Chain triée) et tu passes à la phase d'insertion des perdants (le pend).


// Fonction tri(liste_input) :
//     Si taille(liste_input) < 2 :
//         retourner liste_input
//
//     // 1. Pairage et séparation
//     Paires = créer_paires(liste_input)
//     Gagnants = extraire_gagnants(Paires)
//     Perdants = extraire_perdants(Paires)
//
//     // 2. La récursivité
//     Main_Chain = tri(Gagnants) // <--- C'est ici que la magie opère
//
//     // 3. Insertion des perdants (La partie non récursive)
//     Tant que Pend n'est pas vide :
//         // Logique de Jacobsthal + Binary Search
//         ... insérer perdant dans Main_Chain ...
//
//     retourner Main_Chain
- une fois tries, squelette definitif good

# Pre insertion
- prendre le perdant associe au premier gagnant dans main,
et l'inserer directement position 0

# insertion strategique
j'ai ma liste de depart qui devient la pend,  la mainChain
- calcul de Jacobsthal : determiner la suite selon la taille de liste de perdant

- iteration par groupes
Utilise les nombres de Jacobsthal pour définir des "blocs" d'indices.

Pour chaque index de perdant dans ton bloc :

    Localisation : Trouve le gagnant associé au perdant dans la Main_Chain.

    Bornage : Définis la plage de recherche binaire comme étant [début, index_du_gagnant].

    Recherche & Insertion : Exécute la recherche binaire pour trouver l'emplacement exact et insère le perdant.

Le cas de l'Orphelin : Une fois que tous les perdants liés ont été insérés, insère l'orphelin à la fin. Puisqu'il n'a pas de gagnant lié, sa recherche binaire se fait sur l'intégralité de la Main_Chain.

deque
// 1. Créer une structure ou utiliser std::pair pour lier le winner et le loser
// std::pair<int, int> -> first = winner, second = loser

Fontion mergeInsertD_helper(deque< paire<int, int> > pairs) :
    SI pairs.size() < 2:
        retourner pairs

    Nouveau deque< paire<int, int> > nextPairs
    Pour i de 0 à pairs.size() avec pas de 2:
        // Comparer les winners actuels pour créer les paires du niveau suivant
        SI pairs[i].winner > pairs[i+1].winner:
            nextPairs.push( {pairs[i].winner, pairs[i+1].winner} )
        SINON
            nextPairs.push( {pairs[i+1].winner, pairs[i].winner} )

    // Tri récursif
    deque< paire<int, int> > mainChain = mergeInsertD_helper(nextPairs)

    // A ce stade, mainChain est triée par les winners.
    // Magie : Grâce aux structures/paires, on sait EXACTEMENT quel loser
    // appartient à chaque winner sans faire de std::find !

    // On extrait les losers dans l'ordre de la séquence de Jacobsthal
    // Et au lieu de chercher "où est le winner dans la mainChain",
    // on sait que l'itérateur de limite pour le lower_bound est simplement
    // l'index actuel mis à jour du winner qu'on traque par association.

    // ... Logique d'insertion avec lower_bound ...

    Retourner mainChain