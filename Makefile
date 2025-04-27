
all: Programme

Programme: Grille.o main.o Serpent.o Liste_Section.o Fonctions_Jeu.o Liste_Mouvement.o Matrice.o
	gcc Liste_Mouvement.o Matrice.o Grille.o main.o Serpent.o Liste_Section.o Fonctions_Jeu.o -lncurses -o Programme



main.o: main.c Grille.h 
	gcc -c -Wall main.c


Grille.o: Grille.c Grille.h 
	gcc -c -Wall Grille.c


Serpent.o: Serpent.c Serpent.h 
	gcc -c -Wall Serpent.c

Liste_Section.o: Liste_Section.c Liste_Section.h
	gcc -c -Wall Liste_Section.c

Fonctions_Jeu.o: Fonctions_Jeu.c Fonctions_Jeu.h
	gcc -c -Wall Fonctions_Jeu.c -lncurses

Liste_Mouvement.o: Liste_Mouvement.c Liste_Mouvement.h
	gcc -c -Wall Liste_Mouvement.c

Matrice.o: Matrice.h Matrice.c
	gcc -c -Wall Matrice.c
clean:
	rm *.o Programme
