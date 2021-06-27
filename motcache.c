#include <stdio.h>
#include <stdlib.h>

//Definir les fonctions
void verificationNbArguments(int nbArguments);
void verificationFichierEntree(char cheminFichier[]);

//Implementer les fonctions
void verificationNbArguments(int nbArguments) {
   if(nbArguments != 2) {
      perror("\nNombre d'arguments érroné, ce programme n'accepte qu'un argument.\n");
      exit(-1);
   }
}

void verificationFichierEntree(char cheminFichier[]) {
   FILE *fptr;
   fptr = fopen(cheminFichier, "r");
   if(fptr == NULL) {
      perror("\nFichier non existant, fin du programme.\n");
      exit(-1);
   }
   fclose(fptr);
}

void main(int argc, char *argv[]) {
   verificationNbArguments(argc);
   verificationFichierEntree(argv[1]);
   //Lecture de la grille
      //Creation grille de mots
      //Creation grille de valeurs
      //Creation table de mots a trouver
   //Parcourir la grille et trouvers les mots
   //Definir le mot de sortie
   //Afficher la sortie
}
