#ifndef LISTE_MOUVEMENT_H
#define LISTE_MOUVEMENT_H

#include "Grille.h"

enum direction{
    haut,
    bas,
    gauche,
    droite,
};



struct mouvement{
    int x;
    int y;
    enum direction mv;
    struct mouvement *next;
};

struct liste_mouvement{
    struct mouvement *premier;
    struct mouvement *dernier;
    int longueur;
};

struct mouvement * creer_mouvement(); //Cree une structure mouvement, une structure maillon de la liste_mouvement
struct liste_mouvement * creer_liste(); // Crée une liste de mouvement
struct serpent * creer_serpent(); // Fonction placée ici afin d'éviter une erreur lors de la compilation
int est_vide_mouvement(const struct liste_mouvement *l); // Sert à verifier si une liste mouvement est vide
void ajouter_mouvement_debut_liste( struct liste_mouvement *l, struct mouvement *m); // Ajoute un maillon mouvement au debut d'une liste
void ajouter_mouvement_fin_liste (struct liste_mouvement *l, struct mouvement *m); // Ajoute un maillon mouvement à la fin d'une liste
struct mouvement * extraire_mouvement_debut_liste(struct liste_mouvement *l); // Extrait un maillon mouvement au debut d'une liste
void desallouer_mouvement(struct mouvement **m); //Permet de desallouer un maillon Mouvement
void desallouer_liste(struct liste_mouvement **l);   // Permet de desallouer une liste de mouvement
void mouvement_serpent(struct serpent *s, enum direction dern); // Permet de stocker le dernier mouvement effectué par un serpent en l'ajoutant au debut de la liste mouvement les coordonnées de la tete de notre serpent

#endif