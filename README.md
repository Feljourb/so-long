# So Long
## Introduction
**So Long** est un projet de l'école 42 qui a pour objectif principal de consolider vos compétences en programmation C, tout en vous initiant à la gestion graphique à l'aide de la bibliothèque **MiniLibX**. Ce projet consiste à créer un petit jeu en 2D où un joueur peut se déplacer dans un labyrinthe, collecter des objets, et atteindre une sortie

## Objectifs
Les objectifs pédagogiques du projet So Long sont :

- Renforcer vos compétences en gestion de la mémoire dynamique.
- Comprendre et utiliser des événements graphiques avec la bibliothèque **MiniLibX**.
- Manipuler des fichiers pour la lecture et le traitement d'un plan de jeu en format `.ber`.
- Pratiquer la gestion d'erreurs et assurer une robustesse dans votre code.

## MiniLibX
La bibliothèque **MiniLibX** est un outil fourni par 42 pour créer des interfaces graphiques légères. Elle permet de :

- **Ouvrir une fenêtre**.
- **Afficher des images** (sprites) à partir de fichiers `.xpm`.
- **Gérer les événements utilisateur**, tels que les interactions clavier et souris.

## Fonctionnalités attendues

1. **Lecture de la carte** :

- Le jeu doit lire un fichier au format .ber contenant une carte rectangulaire composée de caractères spécifiques :
    - `1` : Murs.
    - `0` : Espaces libres.
    - `P` : Point de départ (joueur).
    - `C` : Collectibles.
    - `E` : Sortie.
- Validation de la carte :
    - La carte doit être fermée par des murs (`1`).
    - Elle doit inclure **exactement un joueur** (`P`), au moins une sortie (`E`), et un ou plusieurs collectibles (`C`).

2. **Déplacement du joueur** :

- Le joueur peut se déplacer dans les quatre directions : haut, bas, gauche, droite.
- Les déplacements doivent être comptabilisés et affichés dans la console.

3. **Collecte et sortie** :

- Le joueur doit collecter tous les collectibles (`C`) avant de pouvoir accéder à la sortie (`E`) et terminer la partie.

4. **Affichage graphique** :

- Chaque élément de la carte doit être représenté graphiquement à l'aide de sprites (images `.xpm`).
- Utilisation de MiniLibX pour afficher la carte en 2D, où chaque caractère correspond à un élément visuel (mur, joueur, collectible, sortie).

5. **Gestion des erreurs** :

- Le programme doit gérer les erreurs correctement et afficher des messages clairs en cas de problème :
	- Fichier `.ber` manquant ou invalide.
	- Carte mal formatée (non rectangulaire, murs ouverts, etc.).
	- Mémoire insuffisante ou fuite de mémoire.

## Structure du projet

Le projet est organisé de la manière suivante :

```bash
so_long/
│── so_long.c       // Point d'entrée du programme
│── check_map/      // Dossier pour la lecture et validation de la carte
│── game/           // Dossier pour la gestion des mouvements et interactions
│
├── include/        // Contient les fichiers header
│   └── so_long.h        // Fichier header principal
├── Xpm/            // Contient les images pour le rendu graphique
├── Maps/           // Contient les cartes au format `.ber`
├── Makefile        // Fichier de compilation
└── README.md       // Documentation


## Étapes pour Compiler et Lancer le Jeu
1. **Compilation** :

 - Compiler le projet avec Makefile :
    ```bash
    make
2. **Exécution** :

 - Lancer le programme avec une carte .ber :
    ```bash
    ./so_long Maps/map1.ber
3. **Contrôles** :

 - **Touches pour jouer** :
 - `W` : Haut.
 - `A` : Gauche.
 - `S` : Bas.
 - `D` : Droite.

 - **Quitter le jeu** :
	- Appuyer sur la touche ESC ou fermer la fenêtre.
## Algorithme de Validation de Carte
Pour garantir que la carte est jouable, un algorithme de type flood fill est utilisé. Cet algorithme vérifie :

1. Si tous les collectibles (`C`) et la sortie (`E`) sont accessibles depuis la position  nitiale (`P`).
2. S'il y a des murs entourant entièrement la carte.

**Étapes principales** :

- Copier la carte originale.
- Partir de la position initiale du joueur (`P`).
- Parcourir récursivement les cases adjacentes (haut, bas, gauche, droite).
- Vérifier que toutes les positions essentielles (collectibles et sortie) sont accessibles

## Conseils pour la Mémoire
- Utilisez **Valgrind** pour détecter les fuites mémoire et vérifier que votre gestion est correcte :
	```bash
	valgrind ./so_long Maps/map1.ber
- Libérez toutes les ressources allouées dynamiquement (tableaux, images, etc.) avant de quitter le programme.

## Ressources
- [Documentation MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Tutoriel sur l'algorithme Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
