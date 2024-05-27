#ifndef UTILITES_H
#define UTILITES_H

#include <stdlib.h>

// Déclaration des fonctions utilitaires

// Génère un tableau trié de manière croissante
void genererTableauCroissant(int tab[], int n);

// Génère n nombres aléatoires entre 0 et limite
void genererNombresAleatoires(int tab[], int n, int limite);

// Génère un tableau trié de manière décroissante
void genererTableauDecroissant(int tab[], int n);

// Permute deux éléments d'un tableau
void permute(int tab[], int i);

// Mesure le temps d'exécution d'une fonction de tri sur un tableau
double MesurerTempsExecution(void (*fonction_tri)(int[], int), int tableau[], int taille);

#endif // UTILITES_H_INCLUDED

#endif // UTILITES_H_INCLUDED
