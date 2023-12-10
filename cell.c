//
// Created by yaelc on 26/10/2023.
//

#include "cell.h"
#include <stdlib.h>

Cell *createCell(int val, int nbLevels) { //créer une cellule
    Cell *cell = (Cell *) malloc(sizeof(Cell));
    cell->value = val;
    cell->max_level = nbLevels;
    cell->nexts = (Cell **) malloc(nbLevels * sizeof(Cell *));
    for (int i = 0; i < nbLevels; i++) {
        cell->nexts[i] = NULL;
    }
    return cell;
}

void freeCell(Cell *cell) { //supprimer une cellule
    free(cell->nexts);
    free(cell);
}

void displayCell(Cell *cell) { //afficher une cellule
    printf(">[ %4d|@ ]", cell->value);
}

void displayEmptyCell() { //afficher des '-' si une cellule est vide
    printf("-----------");
}

void displayCellLevel(Cell *cell, int level) { //permet d'afficher une cellule vide ou pas
    if (level <= cell->max_level) {
        displayCell(cell);
    } else {
        displayEmptyCell();
    }
}

