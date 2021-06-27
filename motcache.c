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
void rechercheHorizontaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]);
void rechercheVerticale(char mot[12], char lettres[12][12], int valeurs[12][12]);
void rechercheVerticaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]);

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
   for(int i = 0; i < 12; i++) {
      int index = 0;
      char ligneTemporaire[12];
      for(int j = 0; j < 12; j++) {
         ligneTemporaire[j] = lettres[i][j];
      }
      char *position = strstr(ligneTemporaire, mot);
      if(position) {
         index = position - ligneTemporaire;
	 for(int j = index; j < index + strlen(mot); j++) {
	    valeurs[i][j] = 1;
	 }
      }      
   }
}

void rechercheHorizontaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]) {
   for(int i = 0; i < 12; i++) {
      int index = 0;
      char ligneTemporaire[12];
      for(int j = 0; j < 12; j++) {
         int indexInverse = 11 - j;
         ligneTemporaire[j] = lettres[i][indexInverse];
      }
      char *position = strstr(ligneTemporaire, mot);
      if(position) {
         index = position - ligneTemporaire;
         for(int j = 11 - index; j > (11 - index) - strlen(mot); j--) {
            valeurs[i][j] = 1;
         }
      }
   }
}

void rechercheVerticale(char mot[12], char lettres[12][12], int valeurs[12][12]) {
   for(int i = 0; i < 12; i++) {
      int index = 0;
      char ligneTemporaire[12];
      for(int j = 0; j < 12; j++) {
         ligneTemporaire[j] = lettres[j][i];
      }
      char *position = strstr(ligneTemporaire, mot);
      if(position) {
         index = position - ligneTemporaire;
         for(int j = index; j < index + strlen(mot); j++) {
            valeurs[j][i] = 1;
         }
      }
   }
}

void rechercheVerticaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]) {
   for(int i = 0; i < 12; i++) {
      int index = 0;
      char ligneTemporaire[12];
      for(int j = 0; j < 12; j++) {
         int indexInverse = 11 - j;
         ligneTemporaire[j] = lettres[indexInverse][i];
      }
      char *position = strstr(ligneTemporaire, mot);
      if(position) {
         index = position - ligneTemporaire;
         for(int j = 11 - index; j > (11 - index) - strlen(mot); j--) {
            valeurs[j][i] = 1;
         }
      }
   }
}

void parcourirGrille(char cheminFichier[], char lettres[12][12], int valeurs[12][12]) {
   FILE *fptr;
   fptr = fopen(cheminFichier, "r");
   char ligne[13];
   int compteur = 0;
   while((fscanf(fptr, "%s", ligne) != EOF)) {
      if(compteur >= 12) {
         rechercheHorizontale(ligne, lettres, valeurs);
	 rechercheHorizontaleInverse(ligne, lettres, valeurs);
	 rechercheVerticale(ligne, lettres, valeurs);
	 rechercheVerticaleInverse(ligne, lettres, valeurs);
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
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         printf("%c", grilleLettres[i][j]);
      }
      printf("\n");
   }
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         printf("%d", grilleValeurs[i][j]);
      }
      printf("\n");
   }
}
