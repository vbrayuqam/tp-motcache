#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Déclaration des fonctions
void verificationNbArguments(int nbArguments);
void verificationFichierEntree(char cheminFichier[]);
void lectureFichier(char cheminFichier[], char grille[12][12]);
void initialisationGrilleValeurs(int grille[12][12]);
void parcourirGrille(char cheminFichier[], char lettres[12][12], int valeurs[12][12]);
void rechercheHorizontale(char mot[12], char lettres[12][12], int valeurs[12][12]);
//void rechercheVerticale();

//Implémentation des fonctions
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

void rechercheHorizontale(char mot[12], char lettres[12][12], int valeurs[12][12]) {
   //Section de fonction
   for(int i = 0; i < 12; i++) {
      char ligneTemporaire[12];
      for(int j = 0; j < 12; j++) {
         ligneTemporaire[j] = lettres[i][j];
      }
      printf("\n%s\n", ligneTemporaire);
      char *pos = strstr(ligneTemporaire, mot);
      if(pos) {
         //Ajustement grille
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
         rechercheHorizontale(ligne, lettres, valeurs);
	 //rh2
	 //rv1
	 //rv2
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
   parcourirGrille(argv[1], grilleLettres, grilleValeurs);
   //Definir le mot de sortie
   //Afficher la sortie
}
