//
// Created by yaelc on 26/10/2023.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef CALENDAR_MANAGEMENT_CELL_H
#define CALENDAR_MANAGEMENT_CELL_H

typedef struct Cell {
    int value;
    int max_level;
    struct Cell **nexts;
} Cell;


Cell *createCell(int, int); // Alloue dynamiquement de la mémoire à une cellule à partir d'une valeur donnée

void freeCell(Cell *cell); // Libère la mémoire allouée à la cellule

void displayCell(Cell *cell); // Afficher une seule cellule

void displayEmptyCell(); // Afficher des "-" lorsque la cellule est vide

void displayCellLevel(Cell *cell, int level); // Afficher un niveau de cellules aligné avec les autres niveaux

#endif //CALENDAR_MANAGEMENT_CELL_H
