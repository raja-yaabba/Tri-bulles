import time
import random
from typing import List


def generer_tableau_croissant(n):
    """Génère un tableau trié de manière croissante."""
    return [i for i in range(n)]

def generer_nombres_aleatoires(n, limite):
    """Génère n nombres aléatoires entre 0 et limite."""
    return [random.randint(0, limite - 1) for _ in range(n)]

def generer_tableau_decroissant(n):
    """Génère un tableau trié de manière décroissante."""
    return [n - i - 1 for i in range(n)]

def permute(tab: List[int], i: int) -> List[int]:
    """Fonction de permutation."""
    tmp = tab[i]
    tab[i] = tab[i + 1]
    tab[i + 1] = tmp
    return tab

def tri_bulles(tab: List[int]) -> List[int]:
    """Implémentation de l'algorithme de tri à bulles."""
    n = len(tab)
    resultat = tab.copy()
    i = 0

    while i < n - 1:
        if resultat[i] > resultat[i + 1]:
            resultat = permute(resultat, i)
            i = 0
        i += 1

    return resultat

def mesurer_temps_execution(tri, tab, type_cas):
    """Mesure le temps d'exécution d'un tri sur un tableau."""
    debut = int(time.time() * 1000)  # Temps initial en millisecondes
    tri(tab)
    fin = int(time.time() * 1000)  # Temps final en millisecondes
    temps_execution = (fin - debut) / 1000  # Temps CPU en secondes
    return temps_execution

