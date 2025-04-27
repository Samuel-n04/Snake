#include <stdio.h>
#include <stdlib.h>

#include "Liste_Mouvement.h"
#include "Serpent.h"

struct mouvement * creer_mouvement(){
    struct mouvement * nv = malloc ( sizeof (struct mouvement) );
    nv->next = NULL;
    return nv;
}

struct liste_mouvement * creer_liste(){
    struct liste_mouvement * l = malloc ( sizeof (struct liste_mouvement));

    l->premier = NULL;
    l->dernier = NULL;
    l->longueur = 0;
    return l;
}


int est_vide_mouvement(const struct liste_mouvement *l){
    
    return ((l->premier == NULL));
}

void ajouter_mouvement_debut_liste( struct liste_mouvement *l, struct mouvement *m){
    if (est_vide_mouvement(l) == 1) 
    {  
          

        l->dernier = m; 
    }
  

  m->next = l->premier;
  l->premier = m;
  l->longueur ++;
  
  
}

void ajouter_mouvement_fin_liste (struct liste_mouvement *l, struct mouvement *m){
    m->next = NULL;
  if (est_vide_mouvement(l) == 1) {
    l->premier = m;
  }
  printf("AZ\n");
  l->dernier->next = m;
  
  l->dernier = m;
  l->longueur ++;
  
}

struct mouvement * extraire_mouvement_debut_liste(struct liste_mouvement *l){

    struct mouvement *m = l->premier;
  if (m != NULL) {
    l->premier = m->next;
    l->longueur --;
    
    if (est_vide_mouvement(l)) { l->dernier = NULL; }
    m->next = NULL;

  if(m == NULL){
    perror("La liste est vide\n");
    exit(EXIT_FAILURE);
  }
  }
  return m;
}

void desallouer_mouvement(struct mouvement **m){    

     if ((*m) != NULL){
    free(*m);
    *m = NULL;
  
    }
}

void desallouer_liste(struct liste_mouvement **l){

    if (*l != NULL) {
    
    while (((!est_vide_mouvement(*l)) != 1)) {
      
      struct mouvement *m = extraire_mouvement_debut_liste(*l);
      desallouer_mouvement(&m);
    
    }
    free(*l);
    *l = NULL;
  }
}

void mouvement_serpent(struct serpent *s, enum direction dern){
    
    
    struct mouvement *res = creer_mouvement();
    res->x = s->tete_serpent->pos.x;
    res->y = s->tete_serpent->pos.y;
    res->mv = dern;

    ajouter_mouvement_debut_liste(s->move,res);

    
}
