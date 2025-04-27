#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>


#include "Grille.h"
#include "Serpent.h"
#include "Liste_Section.h"


struct grille * grille_allouer(int lon,int lar){
    struct grille *result = malloc(sizeof(struct grille));
    if(result == NULL){
        perror("Erreur d'allocation de la grille\n");
        exit(EXIT_FAILURE);
    }
    
    
    
    
    result->m = lon; 
    result->n = lar;
    
    
    result->tab = malloc(lon * sizeof(char **));
    if(result->tab == NULL){
        perror("Erreur d'allocation pour le tableau\n");
        exit(EXIT_FAILURE);
    }
    int i;
    int e;
    for(i=0; i<lon; ++i){
        result->tab[i] = malloc( lar * sizeof(char *));
        if(result->tab[i] == NULL){
            perror("Erreur d'allocation pour le tableau 2\n");
            exit(EXIT_FAILURE);
        }
    

    

        for (e=0; e<lar; ++e){
            result->tab[i][e] = malloc(8 * sizeof(char));
            if(result->tab[i][e] == NULL){
                perror("Erreur d'allocation pour le tableau 3\n");
                exit(EXIT_FAILURE);
            } 
        }
 
    }

    return result;
}

void grille_vider(struct grille *p){
    int i; 
    int e;

    for(i=0; i < p->m; ++i){
        for(e=0; e < p->n; ++e){
             strcpy(p->tab[i][e], "\33[40m  \33[00m"); // Copie deux espaces dans chaque case
        }
    }
}

void grille_tirage_fruit(struct grille *f){
   
    f->fruit.x = rand() % f->m;
    f->fruit.y = rand() % f->n;
}

void grille_remplir(struct grille *p) {

    strcpy(p->tab[p->fruit.x][p->fruit.y],"\33[41m  \33[00m");
}
void grille_desallouer(struct grille **p){
    if(*p != NULL){
        int i,e;

        for(i=0; i < (*p)->m ; ++i ){
            for(e=0; e < (*p)->n ; ++e){
                free(((*p)->tab[i][e]));
            }
            free((*p)->tab[i]);
        }
        free((*p)->tab);
        free(*p);
        *p = NULL;

    }
}





// Fonction pour redessiner la grille avec les contours (à comprendre)

void grille_redessiner (struct grille *p) {

    // *\33[ = Echap
    printf("\033[2J\033[H");
    // *2J = Effacer ecran
    // *H = Retour haut de page
    int i,e;
    //Affichage coin supérieur

    printf("\033[47m");
    
    for(e=0; e < p->n+2; ++e)
        printf("  ");
    

    printf("\033[0m \33[1E"); //Reinitialiser couleur
    //Afficher lignes de la grille
    

    for(i=0; i < p->m; ++i){
        printf("\033[47m  \033[0m"); // Afficher le contour gauche
    
        for(e=0; e < p->n; ++e)
            printf("%s", p->tab[i][e]);
        
        printf("\033[47m  \033[0m\33[1E"); // Afficher le contour droit
    }
    // Afficher le contour inférieur
    printf("\033[47m");
    for(e=0; e < p->n + 2; ++e)
        printf("  ");
    
    printf("\033[0m\33[1E");
}


 //strcpy(a->tab[i][e], "  "); // Copie deux espaces dans chaque case
 
