

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

