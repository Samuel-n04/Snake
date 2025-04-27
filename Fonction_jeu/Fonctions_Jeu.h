#ifndef FONCTIONS_JEU_H
#define FONCTION_JEU_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "Liste_Section.h"
#include "Matrice.h"

#define ROUGE "\33[41m  \33[00m"
#define VERT "\33[42m  \33[00m"
#define JAUNE "\33[43m  \33[00m"
#define BLEU "\33[44m  \33[00m"
#define VIOLET "\33[45m  \33[00m"
#define CYAN "\33[46m  \33[00m"
#define BLANC "\33[47m  \33[00m"


void bouger_serpent(struct grille *p,struct serpent *s,struct matrice *m, int delai, int nb_joueur); // Cette fonction contient toutes les règles du jeu
int manger(struct grille *p, struct serpent *s,struct matrice *m); // Cette fonction me sert à savoir dès qu'un fruit a été mangé par le serpent
int est_serpent (struct grille *p, struct serpent *s, struct matrice *m); // Cette fonction sert à savoir si le serpent se touche lui-meme
void nv_tirage(struct grille *p, struct serpent *s, struct matrice *m); // Cette fonction sert à retirer un fruit si le fruit tiré est dans une case qui contient deja le serpent

#endif