////////////////////////////////////TP4////////////////////////////////////////////////

//ex1:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100  // Définir la taille de la liste

// Fonction pour créer une liste de taille donnée avec des entiers aléatoires dans un intervalle spécifié
void creer_liste(int liste[], int taille, int intervalle) {
    srand(time(NULL));  // Initialiser le générateur de nombres aléatoires
    for(int i = 0; i < taille; i++) {
        liste[i] = rand() % intervalle;  // Générer des entiers aléatoires
    }
}

int main() {
    int liste[N];  // Déclarer la liste
    creer_liste(liste, N, 100);  // Créer la liste avec des nombres entre 0 et 99

    // Afficher les éléments de la liste
    for(int i = 0; i < N; i++) {
        printf("%d ", liste[i]);
    }

    return 0;
}

// Complexité : O(n) car chaque élément est traité une seule fois

///////////******************************//////////////////////////////////

//ex2:
#include <stdio.h>

// Fonction pour rechercher une valeur donnée dans une liste
int rechercher_valeur(int liste[], int taille, int valeur) {
    for(int i = 0; i < taille; i++) {
        if(liste[i] == valeur) {
            return 1;  // Retourner 1 si la valeur est trouvée
        }
    }
    return 0;  // Retourner 0 si la valeur n'est pas trouvée
}

int main() {
    int liste[N];  // Déclarer la liste
    creer_liste(liste, N, 100);  // Créer la liste avec des nombres entre 0 et 99

    int valeur_a_rechercher = 50;  // Définir la valeur à rechercher
    int resultat = rechercher_valeur(liste, N, valeur_a_rechercher);  // Rechercher la valeur

    // Afficher le résultat de la recherche
    printf("Valeur %d trouvée: %d\n", valeur_a_rechercher, resultat);

    return 0;
} 

// Complexité : O(n) car chaque élément de la liste peut être comparé une seule fois

////////////**********************************//////////////////////////////////

//ex3:
#include <stdio.h>

// Fonction pour supprimer la valeur minimale d'une liste
void supprimer_minimum(int liste[], int taille) {
    if (taille == 0) return;  // Si la liste est vide, ne rien faire

    int min_valeur = liste[0];
    int min_index = 0;

    // Trouver la valeur minimale dans la liste
    for(int i = 1; i < taille; i++) {
        if(liste[i] < min_valeur) {
            min_valeur = liste[i];
            min_index = i;
        }
    }

    // Supprimer l'élément contenant la valeur minimale
    for(int i = min_index; i <taille - 1; i++) {
        liste[i] = liste[i + 1];
    }

    (*taille)--;  // Réduire la taille de la liste
}

int main() {
    int liste[N];  // Déclarer la liste
    int taille = N;  // Définir la taille initiale de la liste
    creer_liste(liste, taille, 100);  // Créer la liste avec des nombres entre 0 et 99

    supprimer_minimum(liste, &taille);  // Supprimer l'élément contenant la valeur minimale

    // Afficher les éléments de la liste après suppression
    for(int i = 0; i < taille; i++) {
        printf("%d ", liste[i]);
    }

    return 0;
}

// Complexité : O(n) car chaque élément peut être comparé et déplacé une seule fois 



///////////////////////////////////////////////////TP8///////////////////////////////////////////////

//Exercice 1 : Définir une structure pour coder un nœud d'un arbre binaire

typedef struct noeud_s {
    int valeur;
    struct noeud_s *gauche;
    struct noeud_s *droit;
} *noeud_t;

typedef noeud_t arbre_t;

//Exercice 2 : Écrire une fonction cree_arbre()
#include <stdlib.h>

arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit) {
    arbre_t arbre = malloc(sizeof(struct noeud_s));
    arbre->valeur = valeur;
    arbre->gauche = gauche;
    arbre->droit = droit;
    return arbre;
}

//Exercice 3 : Écrire une fonction detruit_arbre()
#include <stdlib.h>

void detruit_arbre(arbre_t arbre) {
    if (arbre == NULL)
        return;
    detruit_arbre(arbre->gauche);
    detruit_arbre(arbre->droit);
    free(arbre);
}

//Exercice 4 : Écrire une fonction nombre_de_noeuds()
int nombre_de_noeuds(arbre_t arbre) {
    if (arbre == NULL)
        return 0;
    return (1 + nombre_de_noeuds(arbre->gauche) + nombre_de_noeuds(arbre->droit));
}

//Exercice 5 : Écrire une fonction affiche_arbre()
#include <stdio.h>

void affiche_arbre_rec(arbre_t arbre) {
    if (arbre != NULL) {
        affiche_arbre_rec(arbre->gauche);
        if (arbre->gauche != NULL)
            printf(", ");
        printf("%d", arbre->valeur);
        if (arbre->droit != NULL)
            printf(", ");
        affiche_arbre_rec(arbre->droit);
    }
}

void affiche_arbre(arbre_t arbre) {
    affiche_arbre_rec(arbre);
    printf("\n");
}

//Exercice 6 : Écrire une fonction affiche_arbre2()
#include <stdio.h>

void affiche_arbre2_rec(arbre_t arbre) {
    if (arbre == NULL)
        printf("_");
    else {
        printf("{");
        affiche_arbre2_rec(arbre->gauche);
        printf(",%d,", arbre->valeur);
        affiche_arbre2_rec(arbre->droit);
        printf("}");
    }
}

void affiche_arbre2(arbre_t arbre) {
    affiche_arbre2_rec(arbre);
    printf("\n");
}

//Exercice 7 : Écrire une fonction compare()
int compare(arbre_t arbre1, arbre_t arbre2) {
    if (arbre1 == NULL)
        return (arbre2 != NULL);
    else {
        if (arbre2 == NULL)
            return 1;
        else
            return ((arbre1->valeur != arbre2->valeur) ||
                    compare(arbre1->gauche, arbre2->gauche) ||
                    compare(arbre1->droit, arbre2->droit));
    }
}

//Exercice 8 : Écrire une fonction insere()
arbre_t insere(arbre_t arbre, int valeur) {
    if (arbre == NULL)
        return cree_arbre(valeur, NULL, NULL);
    else {
        if (valeur < arbre->valeur)
            arbre->gauche = insere(arbre->gauche, valeur);
        else
            arbre->droit = insere(arbre->droit, valeur);
        return arbre;
    }
}

//Exercice 9 : Écrire une fonction trouve_noeud()
noeud_t trouve_noeud(arbre_t arbre, int valeur) {
    if (arbre == NULL)
        return NULL;
    if (valeur == arbre->valeur)
        return arbre;
    if (valeur < arbre->valeur)
        return trouve_noeud(arbre->gauche, valeur);
    else
        return trouve_noeud(arbre->droit, valeur);
}

//Exercice 10 : Écrire une fonction verifie()
int verifie_rec(arbre_t arbre, int *min, int *max) {
    int i;
    *min = *max = arbre->valeur;
    if (arbre->gauche != NULL) {
        if (!verifie_rec(arbre->gauche, &i, max) || !(arbre->valeur > *max))
            return 0;
    }
    if (arbre->droit != NULL) {
        if (!verifie_rec(arbre->droit, min, &i) || !(arbre->valeur <= *min))
            return 0;
    }
    return 1;
}

int verifie(arbre_t arbre) {
    int min, max;
    return ((arbre == NULL) ? 1 : verifie_rec(arbre, &min, &max));
}

//Exercice 11 : Écrire une fonction tri()
int tri_rec(arbre_t arbre, int i, int *tableau) {
    int j = 0;
    if (arbre == NULL)
        return j;
    j = tri_rec(arbre->gauche, i, tableau);
    tableau[i + j] = arbre->valeur;
    j++;
    j += tri_rec(arbre->droit, i + j, tableau);
    return j;
}

void tri(int taille, int *tableau) {
    int i;
    arbre_t arbre = NULL;
    for (i = 0; i < taille; i++)
        arbre = insere(arbre, tableau[i]);
    tri_rec(arbre, 0, tableau);
    detruit_arbre(arbre);
}

//Exercice 12 : Écrire une fonction supprime()
arbre_t supprime(arbre_t arbre, int valeur) {
    noeud_t noeud = arbre, *pere = &arbre;
    noeud_t nouveau_noeud, *nouveau_pere;
    while (noeud != NULL) {
        if (valeur == noeud->valeur)
            break;
        if (valeur < noeud->valeur) {
            pere = &noeud->gauche;
            noeud = noeud->gauche;
        } else {
            pere = &noeud->droit;
            noeud = noeud->droit;
        }
    }
    if (noeud != NULL) {
        if (noeud->gauche == NULL) {
            if (noeud->droit == NULL) {
                *pere = NULL;
                free(noeud);
            } else {
                *pere = noeud->droit;
                free(noeud);
            }
        } else {
            if (noeud->droit == NULL) {
                *pere = noeud->gauche;
                free(noeud);
            } else {
                nouveau_noeud = noeud->droit;
                nouveau_pere = &noeud->droit;
                while (nouveau_noeud != NULL)
                    if (nouveau_noeud->gauche != NULL) {
                        nouveau_pere = &nouveau_noeud->gauche;
                        nouveau_noeud = nouveau_noeud->gauche;
                    }
                noeud->valeur = nouveau_noeud->valeur;
                *nouveau_pere = nouveau_noeud->droit;
                free(nouveau_noeud);
            }
        }
    }
    return arbre;
}

