

#ifndef _GRILLE_H
#define _GRILLE_H
#define MAX 20

#include <stdlib.h>
#include <stdio.h>







  struct coordonnees{
    unsigned int x;
    unsigned int y;
};


 struct grille {
    unsigned int m;
    unsigned int n;
    char ***tab;
    struct coordonnees fruit;

};



struct grille* grille_allouer(int lon,int lar); //Cette fonction alloue de la memoire pour une grille
void grille_vider(struct grille *p); // Cette fonction remplit une grille de deux espaces de fond noir
void grille_tirage_fruit(struct grille *f); // Cette fonction tire des coordonnées aléatoires pour le fruit
void grille_remplir(struct grille *p); // Fonction obsolete qui servait à placer le fruit dans la grille
void grille_desallouer(struct grille **p); //Fonction qui sert à desallouer totalement la grille
void grille_redessiner(struct grille * g); //Fonction qui sert à afficher la grille



#endif