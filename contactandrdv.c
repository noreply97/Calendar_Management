//
// Created by alban on 22/11/2023.
//
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#include <ctype.h>
#include "contactandrdv.h"

char *scanString(void) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *result = strdup(buffer);
    return result;
}

char *contactDatasToSimpleString(char *firstname, char *lastname) {
    if (firstname == NULL || lastname == NULL) {
        return NULL;
    }
    size_t length = strlen(firstname) + strlen(lastname) + 2;
    char *result = (char *) malloc(length * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    snprintf(result, length, "%s_%s", lastname, firstname);
    return result;
}

void rechercherContact(AgendaEntry *agenda, char *partialName, int niveau) {
    if (agenda == NULL) {
        printf("Aucun contact trouvé.\n");
        return;
    }

    // Comparer la première lettre du nom du contact avec la lettre actuelle
    char currentLetter = partialName[niveau];
    char *contactName = agenda->contact.nom;

    if (contactName[niveau] == currentLetter) {
        // Si on atteint la 3ème lettre, afficher le nom complet
        if (niveau == 2) {
            printf("%s %s\n", agenda->contact.nom, agenda->contact.prenom);
        }
        // Passer au niveau suivant
        rechercherContact(agenda, partialName, niveau + 1);
    } else {
        // Si la lettre ne correspond pas, passer au contact suivant
        rechercherContact(agenda->suivant, partialName, 0);
    }
}

// Fonction principale pour rechercher un contact
void rechercheContactMenu(AgendaEntry *agenda) {
    printf("Entrez le nom à rechercher (3 lettres minimum) : ");
    char *partialName = scanString();
    rechercherContact(agenda, partialName, 0);
    free(partialName); // Libérer la mémoire allouée pour la saisie
}