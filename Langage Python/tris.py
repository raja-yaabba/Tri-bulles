from typing import List
from utiles import permute

def tri_bulles(tab: List[int]) -> None:
    """Implémentation de l'algorithme de tri à bulles."""
    resultat = tab.copy()
    i = 1
    
    while i < len(resultat):
        if resultat[i] > resultat[i + 1]:
            resultat = permute(resultat, i)
            i = 0
        i += 1
    
    return resultat
