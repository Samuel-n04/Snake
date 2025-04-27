#ifndef _SERPENT_H
#define _SERPENT_H
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>

#include "Grille.h"
#include "Liste_Section.h"
#include "Liste_Mouvement.h"
#include "Matrice.h"


struct serpent{
    struct tete * tete_serpent;
    struct section *premiere_sec;
    struct section *derniere_sec;
    struct liste_mouvement *move;
    int longueur_serpent;
};

struct tete {
    struct coordonnees pos ;
    char * couleur;
    struct section *premiere_section;
};

struct tete * creer_tete(int x, int y ); // Crée une tête de coordonnées x,y
struct serpent * creer_serpent(); // Crée une liste chainée nommée "serpent"
int est_vide_serpent(const struct serpent *l); // Permet de vérifier si une liste Serpent est vide
void ajouter_section_debut_serpent( struct serpent *l, struct section *m); // Ajoute un maillon section au debut de la liste serpent
void ajouter_section_fin_serpent (struct serpent *l,struct section *m); // Ajoute un maillon section a la fin de la liste serpent
struct section * extraire_section_debut_serpent(struct serpent *l);// extrait un maillon section au debut de la liste serpent
void desallouer_tete(struct serpent **l); // Permet de désallouer la structure tete d'un serpent
void desallouer_serpent(struct serpent **l);  // Permet de désallouer une liste chainée "serpent"
void afficher_tete_serpent( struct grille *p, struct serpent *s); // Permet d'afficher uniquement la tête d'un serpent (Fonction Obsolete)
void grille_remplir2(struct grille *p, struct serpent *s,struct matrice *m); // Nouvelle fonction Grille Remplir permettant d'ajouter dans la grille notre liste chainée serpent, ainsi que le fruit, Elle nous sert également à calquer notre grille sur une matrice, Elle ajoute également la notion de mouvement à notre serpent car les sections reprennent les coordonnées de leur prédecesseurs afin que le mouvement puisse être transmis 




#endif