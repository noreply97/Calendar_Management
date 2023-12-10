//
// Created by yaelc on 10/12/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"

void displayMenu(){
    AgendaList* list  = createAgendaList();
    printf("Bienvenue dans le menu de cet agenda, que souhaitez-vous faire ? :\n");
    printf("1. Rechercher un contact\n");
    printf("2. Afficher les rendez-vous d'un contact\n");
    printf("3. Creer un contact\n");
    printf("4. Creer un rendez-vous pour un contact\n");
    printf("5. Supprimer un rendez-vous\n");
    printf("6. Sauvegarder le fichier de tous les rendez-vous\n");
    int res = 0;
    while(res < 1 || res>6) {
        scanf("%d", &res);
    }
    switch(res){
        case 1:
            printf("Quel nom souhaitez-vous chercher ? :\n");
            char* string = scanStringGestion();
            classicAgendaSearch(list, string);
            break;

        case 2:
            printf("Vous avez choisi l'option 2.\n");
            // Les instructions spécifiques à l'option 2 vont ici
            break;

        case 3:
            printf("Vous avez choisi l'option 3.\n");
            Contact* contact = createContact();
            break;

        case 4:
            printf("Vous avez choisi l'option 4.\n");
            Meeting* meeting = createMeeting();

        case 5:
            printf("Vous avez choisi l'option 5.\n");

        case 6:
            printf("Vous avez choisi l'option 6.\n");

        default :
            printf("Option invalide.\n");
    }
}
