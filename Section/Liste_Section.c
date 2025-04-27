

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Serpent.h"
#include "Liste_Section.h"
#include "Grille.h"




struct section * creer_section(int longueur){ //Cree une structure section, une structure maillon de la liste Serpent

  srand(time(NULL));
struct section * s = malloc(sizeof(struct section));
  s->couleur = malloc (8 * sizeof(char));
  s->suivant = NULL;
  s->longueur = longueur;
  return s;
}
  

void ajouter_section_debut_serpent(struct serpent *l,struct section *m){ // Ajoute un maillon section au debut d'une liste Serpent
  if (est_vide_serpent(l)) 
    {  
        l->derniere_sec = m; 
    }
  m->suivant = l->premiere_sec;
  l->premiere_sec = m;
  ++l->longueur_serpent;
}





void detruire_section(struct section **m){ // Permet de desallouer un maillon section 
  if ((*m) != NULL){
    free(*m);
    *m = NULL;
  
}
}


char * couleur_aleatoire(){ // Permet de tirer une couleur aléatoire parmi 7 disponibles
  srand(time(NULL));
  int n = rand() %7;

  if (n==0) return ROUGE;
  if (n==1) return VERT;
  if (n==2) return JAUNE;
  if (n==3) return BLEU;
  if (n==4) return VIOLET;
  if (n==5) return CYAN;
  if (n==6) return BLANC;
  return "a";
}