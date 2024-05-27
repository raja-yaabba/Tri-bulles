#ifndef UTILITES_H
#define UTILITES_H

#include <stdlib.h>

// D�claration des fonctions utilitaires

// G�n�re un tableau tri� de mani�re croissante
void genererTableauCroissant(int tab[], int n);

// G�n�re n nombres al�atoires entre 0 et limite
void genererNombresAleatoires(int tab[], int n, int limite);

// G�n�re un tableau tri� de mani�re d�croissante
void genererTableauDecroissant(int tab[], int n);

// Permute deux �l�ments d'un tableau
void permute(int tab[], int i);

// Mesure le temps d'ex�cution d'une fonction de tri sur un tableau
double MesurerTempsExecution(void (*fonction_tri)(int[], int), int tableau[], int taille);

#endif // UTILITES_H_INCLUDED

#endif // UTILITES_H_INCLUDED
