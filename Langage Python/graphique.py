import pandas as pd
import matplotlib.pyplot as plt

# Charger le DataFrame depuis le fichier CSV
df = pd.read_csv('temps_execution_python.csv')

# Tracer les graphiques
plt.figure(figsize=(10, 6))
plt.plot(df['Taille'], df['Meilleur_Cas'], label='Meilleur Cas')
plt.plot(df['Taille'], df['Moyenne_Cas'], label='Moyenne des Cas')
plt.plot(df['Taille'], df['Pire_Cas'], label='Pire Cas')

# Ajouter des étiquettes et un titre
plt.xlabel('Taille du Tableau')
plt.ylabel('Temps d\'Exécution (s)')
plt.title('Performances du Tri à Bulles en fonction de la Taille du Tableau')

# Afficher la légende
plt.legend()

# Sauvegarder le graphique au format PNG
plt.savefig('graphique_tri_bulles.png')

# Afficher le graphique
plt.show()
