#include "tris.h"

// D�finition de la fonction triBulles
void triBulles(int tab[], int n) {
    // Boucle externe parcourant le tableau
    for (int i = 0; i < n - 1; i++) {
        // Boucle interne pour les comparaisons et les permutations
        for (int j = 0; j < n - i - 1; j++) {
            // Comparaison entre les �l�ments adjacents du tableau
            if (tab[j] > tab[j + 1]) {
                // Appel de la fonction permute pour �changer les �l�ments
                permute(tab, j);
            }
        }
    }
}
