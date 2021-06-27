#include <stdio.h>
#include <stdlib.h>

//Definir les fonctions
void verificationNbArguments(int nbArguments);

//Implementer les fonctions
void verificationNbArguments(int nbArguments) {
   if(nbArguments != 2) {
      perror("\nNombre d'arguments érroné, ce programme n'accepte qu'un argument.\n");
      exit(-1);
   }
}

void main(int argc, char *argv[]) {
   verificationNbArguments(argc);
   //Lecture de la grille
      //Creation grille de mots
      //Creation grille de valeurs
      //Creation table de mots a trouver
   //Parcourir la grille et trouvers les mots
   //Definir le mot de sortie
   //Afficher la sortie
}
