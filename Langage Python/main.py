from typing import List
from utiles import tri_bulles, mesurer_temps_execution, generer_tableau_croissant, generer_tableau_decroissant, generer_nombres_aleatoires
import pandas as pd

if __name__ == "__main__":
    def main():
        n_valeurs = [i for i in range(300, 3100, 300)]  # Tailles du tableau, pour i allant de 300 à 3000 par pas de 300
        Q = 5  # Nombre de réalisations par taille de données

        meilleurs_temps = []
        moyennes_temps = []
        pires_temps = []

        with open("temps_execution_python.txt", "w") as f:
            for n in n_valeurs:
                print(f"\n--- Taille du tableau : {n} ---")
                f.write(f"\n--- Taille du tableau : {n} ---\n")

                meilleur_temps = float('inf')  # Initialise la variable pour le meilleur temps
                total_temps_moyen = 0  # Initialise la variable total_temps_moyen
                pire_temps = float('-inf')  # Initialise la variable pour le pire temps

                # Réaliser Q fois pour chaque taille
                for i in range(Q):
                    # Générer le tableau trié de manière croissante (meilleur cas)
                    tab_meilleur = generer_tableau_croissant(n)
                    temps_meilleur = mesurer_temps_execution(tri_bulles, tab_meilleur.copy(), "meilleur")
                    meilleur_temps = min(meilleur_temps, temps_meilleur)


                    # Générer le tableau aléatoire (cas moyen)
                    tab_moyen = generer_nombres_aleatoires(n, 10000)
                    temps_moyen = mesurer_temps_execution(tri_bulles, tab_moyen.copy(), "moyen")
                    total_temps_moyen += temps_moyen

            
                    # Générer le tableau trié de manière décroissante (pire cas)
                    tab_pire = generer_tableau_decroissant(n)
                    temps_pire = mesurer_temps_execution(tri_bulles, tab_pire.copy(), "pire")
                    pire_temps = max(pire_temps, temps_pire)

                    # Affichage des temps pour chaque réalisation
                    print(f"Meilleur cas : {temps_meilleur}")
                    print(f"Temps moyen : {temps_moyen}")
                    print(f"Pire cas : {temps_pire}\n")

                    # Écrire les temps dans le fichier
                    f.write(f"Iteration {i + 1} - Meilleur cas : {temps_meilleur}\n")
                    f.write(f"Iteration {i + 1} - Temps moyen : {temps_moyen}\n")
                    f.write(f"Iteration {i + 1} - Pire cas : {temps_pire}\n")

                # Calcul de la moyenne des temps moyens par taille de tableau
                moyenne_temps_moyen = total_temps_moyen / Q
                rounded_moyenne_temps_moyen = round(moyenne_temps_moyen, 3)  # Arrondir à 3 décimales

                # Ajout des temps dans les listes
                meilleurs_temps.append(meilleur_temps)
                moyennes_temps.append(rounded_moyenne_temps_moyen)  # Utiliser la moyenne arrondie
                pires_temps.append(pire_temps)

                # Affichage du meilleur temps, pire temps et moyenne des temps moyens
                print(f"Meilleur temps : {min(meilleurs_temps)}")
                print(f"Moyenne des temps moyens : {rounded_moyenne_temps_moyen}")
                print(f"Pire temps : {max(pires_temps)}")

                # Écrire les résultats dans le fichier
                f.write(f"\nMeilleur temps : {min(meilleurs_temps)}\n")
                f.write(f"Moyenne des temps moyens : {rounded_moyenne_temps_moyen}\n")
                f.write(f"Pire temps : {max(pires_temps)}\n")


        # Créer un DataFrame à partir des listes de temps
        df = pd.DataFrame({
            'Taille': n_valeurs,
            'Meilleur_Cas': meilleurs_temps,
            'Moyenne_Cas': moyennes_temps,
            'Pire_Cas': pires_temps
        })

        # Sauvegarder le DataFrame dans un fichier CSV
        df.to_csv('temps_execution_python.csv', index=False)

        print("Le tableau est trié !")

    main()
