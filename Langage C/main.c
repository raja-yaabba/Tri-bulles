#include <stdio.h>
#include <math.h>
#include "utiles.h"
#include "tris.h"

int main() {

    // Initialisation des variables
    int debut = 300;
    int fin = 3000;
    int pas = 300;
    int Q = 5;  // Nombre de réalisations par taille de données

    // Ouverture du fichier pour enregistrer les temps d'exécution
    FILE *fichier = fopen("temps_execution_c.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier.\n");
        return 1;
    }

    // Boucle sur différentes tailles de tableau
    for (int n = debut; n <= fin; n += pas) {
        printf("--- Taille du tableau : %d ---\n", n);
        fprintf(fichier, "--- Taille du tableau : %d ---\n", n);

        // Initialisation des variables pour les temps d'exécution
        double meilleur_temps = __builtin_inff();
        double total_temps_moyen = 0;
        double pire_temps = 0;

        // Réaliser Q fois pour chaque taille
        for (int q = 0; q < Q; q++) {
            // Générer un tableau trié de manière croissante (meilleur cas)
            int tab_meilleur[n];
            genererTableauCroissant(tab_meilleur, n);
            double temps_meilleur = MesurerTempsExecution(triBulles, tab_meilleur, n);
            meilleur_temps = fmin(meilleur_temps, temps_meilleur);

            // Générer un tableau de nombres aléatoires (cas moyen)
            int tab_moyen[n];
            genererNombresAleatoires(tab_moyen, n, 10000);
            double temps_moyen = MesurerTempsExecution(triBulles, tab_moyen, n);
            total_temps_moyen += temps_moyen;

            // Générer un tableau trié de manière décroissante (pire cas)
            int tab_pire[n];
            genererTableauDecroissant(tab_pire, n);
            double temps_pire = MesurerTempsExecution(triBulles, tab_pire, n);
            pire_temps = fmax(pire_temps, temps_pire);

            // Afficher les temps pour chaque réalisation
            printf("Meilleur cas : %f s\n", temps_meilleur);
            fprintf(fichier, "Meilleur cas : %f s\n", temps_meilleur);

            printf("Temps moyen : %f s\n", temps_moyen);
            fprintf(fichier, "Temps moyen : %f s\n", temps_moyen);

            printf("Pire cas : %f s\n\n", temps_pire);
            fprintf(fichier, "Pire cas : %.3f s\n\n", temps_pire);

        }

        // Calculer la moyenne des temps moyens
        double moyenne_temps_moyen = total_temps_moyen / Q;

        // Afficher les résultats pour la taille de tableau actuelle
        printf("Meilleur temps : %f s\n", meilleur_temps);
        fprintf(fichier, "Meilleur temps : %f s\n", meilleur_temps);

        printf("Moyenne des temps moyens : %f s\n", moyenne_temps_moyen);
        fprintf(fichier, "Moyenne des temps moyens : %f s\n", moyenne_temps_moyen);

        printf("Pire temps : %f s\n\n", pire_temps);
        fprintf(fichier, "Pire temps : %f s\n\n", pire_temps);

    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher un message indiquant la fin du tri
    printf("Le tableau est trie !\n");

    return 0;
}
