//
// Created by yaelc on 26/10/2023.
//
#include "cell.h"
#include "tab.h"

#ifndef CALENDAR_MANAGEMENT_LIST_H
#define CALENDAR_MANAGEMENT_LIST_H

typedef struct List {
    Cell **heads;
    int max_level;
} List;

List *createList(int); // Alloue de la mémoire dynamiquement à une variable liste
void addCellToHeadList(Cell *, List *); // Ajoute une cellule à la tête de la liste
void displayListLevel(List list, int nbLevel);// Affiche toutes les cellules d'un niveau de la liste
void displayAllList(List *list);// Affiche toute la liste avec tous ses niveaux
void addCellToList(List *, Cell *); // Ajoute une cellule pour qu'elle soit dans l'ordre croissant
List *createListOfNLevel(int); // Crée une liste de niveaux n avec (2^n)-1 cellules

#endif //CALENDAR_MANAGEMENT_LIST_H
