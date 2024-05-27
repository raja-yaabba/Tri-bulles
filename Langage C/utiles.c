#include "utiles.h"
#include "tris.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour g�n�rer un tableau tri� de mani�re croissante
void genererTableauCroissant(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = i;
    }
}

// Fonction pour g�n�rer un tableau de nombres al�atoires entre 0 et limite
void genererNombresAleatoires(int tab[], int n, int limite) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % limite;
    }
}

// Fonction pour g�n�rer un tableau tri� de mani�re d�croissante
void genererTableauDecroissant(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = n - i - 1;
    }
}

// Fonction pour �changer deux �l�ments d'un tableau
void permute(int tab[], int i) {
    int temp = tab[i];
    tab[i] = tab[i + 1];
    tab[i + 1] = temp;
}

// Fonction pour mesurer le temps d'ex�cution d'un algorithme de tri sur un tableau
double MesurerTempsExecution(void (*triBulles)(int[], int), int tableau[], int taille) {
    // Enregistrement du temps de d�but
    clock_t debut = clock();
    // Appel de la fonction de tri
    triBulles(tableau, taille);
    // Enregistrement du temps de fin
    clock_t fin = clock();
    // Calcul et retour du temps d'ex�cution en secondes
    return ((double)(fin - debut)) / CLOCKS_PER_SEC;
}
