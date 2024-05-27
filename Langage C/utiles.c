#include "utiles.h"
#include "tris.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour générer un tableau trié de manière croissante
void genererTableauCroissant(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = i;
    }
}

// Fonction pour générer un tableau de nombres aléatoires entre 0 et limite
void genererNombresAleatoires(int tab[], int n, int limite) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % limite;
    }
}

// Fonction pour générer un tableau trié de manière décroissante
void genererTableauDecroissant(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = n - i - 1;
    }
}

// Fonction pour échanger deux éléments d'un tableau
void permute(int tab[], int i) {
    int temp = tab[i];
    tab[i] = tab[i + 1];
    tab[i + 1] = temp;
}

// Fonction pour mesurer le temps d'exécution d'un algorithme de tri sur un tableau
double MesurerTempsExecution(void (*triBulles)(int[], int), int tableau[], int taille) {
    // Enregistrement du temps de début
    clock_t debut = clock();
    // Appel de la fonction de tri
    triBulles(tableau, taille);
    // Enregistrement du temps de fin
    clock_t fin = clock();
    // Calcul et retour du temps d'exécution en secondes
    return ((double)(fin - debut)) / CLOCKS_PER_SEC;
}
