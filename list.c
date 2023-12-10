//
// Created by yaelc on 26/10/2023.
//
#include "list.h"

List *createList(int nbLevels) {
    List *list = (List *) malloc(sizeof(List));
    list->max_level = nbLevels;
    list->heads = (Cell **) malloc(nbLevels * sizeof(Cell *));
    for (int i = 0; i < list->max_level; i++) {
        list->heads[i] = NULL;
    }
    return list;
}

void addCellToHeadList(Cell *cell, List *list) {
    for (int i = 0; i < cell->max_level; i++) {
        cell->nexts[i] = list->heads[i];
    }
    for (int i = 0; i < cell->max_level; i++) {
        list->heads[i] = cell;
    }
}

void addCellToList(List *list, Cell *cell) {
    if (list->heads == NULL) {
        addCellToHeadList(cell, list);
        return;
    }
    Cell *current = list->heads[0];
    Cell *prev = NULL;
    while (current != NULL && current->value < cell->value) {
        prev = current;
        current = current->nexts[0];
    }
    if (prev == NULL) {
        cell->nexts[0] = list->heads[0];
        list->heads[0] = cell;
    } else {
        prev->nexts[0] = cell;
        cell->nexts[0] = current;
    }

    for (int currentLevel = 1; currentLevel < cell->max_level; currentLevel++) {
        current = list->heads[currentLevel];
        prev = NULL;

        while ((current != NULL) && ((current->value) < (cell->value))) {
            prev = current;
            current = current->nexts[currentLevel];
        }
        if (prev == NULL) {
            cell->nexts[currentLevel] = list->heads[currentLevel];
            list->heads[currentLevel] = cell;
        } else {
            prev->nexts[currentLevel] = cell;
            cell->nexts[currentLevel] = current;
        }
    }
}

List *createListOfNLevel(int n) {
    while (n <= 0) {
        printf("N must be bigger than 0 !");
        scanf("%d", &n);
    }
    int *levels = createTab(n);
    List *list = createList(n);
    for (int i = 0; i < ((1 << n) - 1); i++) {
        Cell *cell = createCell(i + 1, levels[i] + 1);
        addCellToList(list, cell);
    }
    free(levels);
    return list;
}

void displayListLevel(List list, int nbLevel) {
    printf("[list head_%d @-]", nbLevel);
    Cell *currentCell = list.heads[0];
    while (currentCell != NULL) {
        printf("--");
        displayCellLevel(currentCell, nbLevel);
        currentCell = currentCell->nexts[0];
    }
    printf("-->NULL\n");
}

void displayAllList(List *list) {
    for (int i = 0; i < list->max_level; ++i) {
        displayListLevel(*list, i + 1);
    }
    printf("\n");
}
