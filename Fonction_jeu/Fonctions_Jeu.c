#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Fonctions_Jeu.h"
#include "Grille.h"
#include "Liste_Section.h"
#include "Serpent.h"
#include "Liste_Mouvement.h"
#include "Matrice.h"



int manger(struct grille *p, struct serpent *s,struct matrice *m){
  
  int x = s->tete_serpent->pos.x;
  int y = s->tete_serpent->pos.y;
  
  if( m->tab[x][y] == fruit) return 1;
  return 0;
}





int est_serpent (struct grille *p, struct serpent *s, struct matrice *m){
  int x = s->tete_serpent->pos.x;
    int y = s->tete_serpent->pos.y;
  
  if( m->tab[x][y]== serp) return 1;
  return 0;
  
}


void nv_tirage(struct grille *p, struct serpent *s, struct matrice *m){
  if (m->tab[p->fruit.x][p->fruit.y] == serp) {
    while(m->tab[p->fruit.x][p->fruit.y] == serp){
      grille_tirage_fruit(p);
}
  }
}

void bouger_serpent(struct grille *p,struct serpent *s,struct matrice *m, int delai, int nb_joueur)
{ 

  srand(time(NULL));
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
   
  int touche;
  int derniere_touche;
  
  do{
    derniere_touche = touche ;
    touche = getch(); 
    
    printf("\33[2J"); // Efface tout l'ecran 
    printf("\33[H");

    mouvement_serpent(s,derniere_touche);
    switch (touche){
      
        case KEY_UP:
            s->tete_serpent->pos.x--;
            
            break;
        
        case KEY_DOWN:
          
            s->tete_serpent->pos.x++;
            
            break;

        case KEY_LEFT:
            s->tete_serpent->pos.y--;
           
            break;
        
        case KEY_RIGHT:
        
            s->tete_serpent->pos.y++ ;
            
            break;
    }

    

     
    if(s->tete_serpent->pos.x > p->m-1 || s->tete_serpent->pos.y > p->n-1) break;
    if(s->tete_serpent->pos.x < 0 || s->tete_serpent->pos.y < 0) break;
    
   
    if (est_serpent(p,s,m) == 1) break;


    
    
    
    if(manger(p,s,m) == 1) {

      int nombre = rand()%5 +1;
      grille_tirage_fruit(p);
      nv_tirage(p,s,m);
      grille_vider(p);
      
      for(int i=0; i<nombre; ++i){
        struct section *tmp = creer_section(1);
        tmp ->couleur = couleur_aleatoire();
        ajouter_section_debut_serpent(s,tmp);

        
      }
      
      
    }

      printf("ICI\n");
    
    grille_remplir2(p,s,m); 
    fflush(stdout);


  }while ( touche !='q');


  endwin();
  printf("\33[2J"); /* Efface tout l'ecran */
  printf("\33[H");
  printf("\n\n Fin ! \n");
  desallouer_tete(&s);
  desallouer_liste(&s->move);
  desallouer_serpent(&s);
  grille_desallouer(&p);
  desallouer_matrice(&m);
}