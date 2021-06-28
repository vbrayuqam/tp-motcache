//Inclusion des librairies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Déclaration des fonctions

/**
* Verifie si le nombre d'argument est adéquat selon les paramètres du logiciel.
*
* @param  nbArguments  Le nombre d'arguments fourni au logiciel
*/
void verificationNbArguments(int nbArguments);

/**
* Verifie si le ficher fourni en entrée existe.
* 
* @param  cheminFichier  Chemin relatif ou absolu menant vers le fichier
*/
void verificationFichierEntree(char cheminFichier[]);

/**
* Lis le fichier est mets la grille de mot cachés dans une grille de char.
*
* @param  grille  Matrice qui recevra les lettres 
* @param  cheminFichier  Chemin relatif ou absolu menant vers le ficher
*/
void lectureFichier(char cheminFichier[], char grille[12][12]);

/**
* Initialise la grille des valeurs.
*
* @param  grille  Matrice de int qui recevra les valeurs
*/
void initialisationGrilleValeurs(int grille[12][12]);

/**
* Parcoure la grille et extrait les mots qui doivent être trouver à l'intérieur.
*
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant représantant si une lettre est utilisée par un mot
* @param  cheminFichier  Chemin relatif ou absolu menant vers le fichier
*/
void parcourirGrille(char cheminFichier[], char lettres[12][12], int valeurs[12][12]);

/**
* Recherche les mots dans la grille du mot caché, de gauche à droite.
*
* @param mot  Mot dont la recherche doit être effectuer
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant des valeurs qui représente l'utilisation des lettres du mot caché
*/
void rechercheHorizontale(char mot[12], char lettres[12][12], int valeurs[12][12]);

/**
* Recherche les mots dans la grille du mot caché, de droite à gauche.
*
* @param  mot  Mot dont la recherche doit être effectuer
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant des valeurs qui représente l'utilisation des lettres du mot caché
*/
void rechercheHorizontaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]);

/**
* Recherche les mots dans la grille du mot caché, de haut en bas.
*
* @param  mot  Mot dont la recherche doit être effectuer
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant des valeurs qui représente l'utilisation des lettres du mot caché
*/
void rechercheVerticale(char mot[12], char lettres[12][12], int valeurs[12][12]);

/**
* Recherche les mots dans la grille du mot caché, de bas en haut.
* 
* @param  mot  Mot dont la recherche doit être effectuer
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant des valeurs qui représente l'utilisation des lettres du mot caché
*/
void rechercheVerticaleInverse(char mot[12], char lettres[12][12], int valeurs[12][12]);

/**
* Affiche la sortie du programme, la solution du mot caché.
* 
* @param  lettres  Matrice contenant les lettres du mot caché
* @param  valeurs  Matrice contenant des valeurs qui représente l'utilisation des lettres du mot caché
*/
void afficherSortie(char lettres[12][12], int valeurs[12][12]);


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
	 for(int j = index; j < index + (int) strlen(mot); j++) {
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
         for(int j = 11 - index; j > (11 - index) - (int) strlen(mot); j--) {
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
         for(int j = index; j < index + (int) strlen(mot); j++) {
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
         for(int j = 11 - index; j > (11 - index) - (int) strlen(mot); j--) {
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

void afficherSortie(char lettres[12][12], int valeurs[12][12]) {
   for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
         if(valeurs[i][j] == 0) {
	    printf("%c", lettres[i][j]);
	 }
      }
   }
   
   printf("\n");
}

int main(int argc, char *argv[]) {
   char grilleLettres[12][12];
   int grilleValeurs[12][12];
   
   verificationNbArguments(argc);
   verificationFichierEntree(argv[1]);
   lectureGrille(argv[1], grilleLettres);
   initialisationGrilleValeurs(grilleValeurs);
   parcourirGrille(argv[1], grilleLettres, grilleValeurs);
   afficherSortie(grilleLettres, grilleValeurs);
   
   return 0;
}
