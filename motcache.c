#include <stdio.h>
#include <stdlib.h>

//Definir les fonctions
void verificationNbArguments(int nbArguments);
void verificationFichierEntree(char cheminFichier[]);
void lectureFichier(char cheminFichier[], char grille[12][12]);
void initialisationGrilleValeurs(int grille[12][12]);
void parcourirGrille(char cheminFichier[], char lettres[12][12], int valeurs[12][12]);

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

void lectureGrille(char cheminFichier[], char grille[12][12]) {
   FILE *fptr;
   fptr = fopen(cheminFichier, "r");
   char ligne[12];
   int compteur = 0;
   while((fscanf(fptr, "%s", ligne) != EOF) && compteur != 12) {
      for(int i = 0; i < 12; i++) {
         grille[compteur][i] = ligne[i];
      }
      compteur++;
   } 
   fclose(fptr);
}

void initialisationGrilleValeurs(int grille[12][12]) {
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         grille[i][j] = 0;
      }
   }
}

void parcourirGrille(char cheminFichier[], char lettres[12][12], int valeurs[12][12]) {
   FILE *fptr;
   fptr = fopen(cheminFichier, "r");
   char ligne[12];
   int compteur = 0;
   while((fscanf(fptr, "%s", ligne) != EOF)) {
      if(compteur >= 12) {
         //rh1
	 //rh2
	 //rv1
	 //rv2
	 
	 //Test de ligne
	 printf("\n%s", ligne);
      }
      compteur++;
   }
   fclose(fptr);
}

//Fonction main
void main(int argc, char *argv[]) {
   char grilleLettres[12][12];
   int grilleValeurs[12][12];

   verificationNbArguments(argc);
   verificationFichierEntree(argv[1]);
   lectureGrille(argv[1], grilleLettres);
   initialisationGrilleValeurs(grilleValeurs);

   //Test de grilleLettres
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         printf("%c", grilleLettres[i][j]);
      }
      printf("\n");
   }
   //Test grilleValeurs
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         printf("%d", grilleValeurs[i][j]);
      }
      printf("\n");
   }
   
   parcourirGrille(argv[1], grilleLettres, grilleValeurs);
   //Definir le mot de sortie
   //Afficher la sortie
}
