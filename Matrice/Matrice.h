#ifndef _MATRICE_H
#define _MATRICE_H


#include <stdio.h>
#include <stdlib.h>


enum element{
    rien,
    fruit,
    serp,
    
};

struct matrice{
    int m;
    int n;
    enum element **tab;
};


struct matrice *creer_matrice(int m, int n); //Permet de creer une matrice
void desallouer_matrice(struct matrice **m); //Permet de désallouer une matrice
void matrice_vider(struct matrice *m); // Permet de remplir toutes les cases de la matrice par "Rien"

#endif