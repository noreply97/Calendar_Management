//
// Created by yaelc on 26/10/2023.
//
#include "list.h"

List* createList(int nbLevels){
    List* list = (List*)malloc(sizeof(List));
    list->max_level = nbLevels;
    list->heads = (Cell**)malloc(nbLevels*sizeof(Cell*));
    for(int i=0;i<list->max_level;i++){
        list->heads[i] = NULL;
    }
    return list;
}

void addCellToHeadList(Cell* cell, List* list){
    for(int i=0; i<cell->max_level;i++){
        cell->nexts[i] = list->heads[i];
    }
    for(int i=0; i<cell->max_level;i++){
        list->heads[i] = cell;
    }
}

void displayListCellsFromLevel(List list, int level){
    if(level>=1 && level<=list.max_level) {
        printf("[list head_%d @-]-->", level - 1);
        Cell* currentCell = list.heads[level-1];
        while(currentCell!=NULL){
            printf("[%d|@-]-->",currentCell->value);
            currentCell=currentCell->nexts[level-1];
        }
        printf("NULL");
    } else{
        return;
    }
}

void displayAllCellsFromList(List list){
    for (int i = 0; i <= list.max_level; i++) {
        displayListCellsFromLevel(list, i);
        printf("\n");
    }
}

/*void displayAllLevelsAligned(List *list) {
    int max = getMaxLevelofList(list);
    for (int level = 0; level < list->max_level; ++level) {
        displayOneLevelAligned(list, max, level);
    }
}

void displayOneLevelAligned(const List *list, int max, int level) {
    printf("[list head_%d @-]--", level);
    Cell *current_I = list->heads[level];
    Cell *current_0 = list->heads[0];
    while (current_I != NULL) {
        if (current_I == current_0) {
            printf(">[%d|@-]--", current_I->value);
            current_I = current_I->nexts[level];
        } else {
            printf("--------------");
            current_I = current_I->nexts[level];
        }
    }
    printf(">NULL \n");
}

int getMaxLevelofList(const List *list) {
    int max = 0;
    for (int level = 0; level < list->max_level; ++level) {
        Cell *current = list->heads[level];
        while (current != NULL) {
            int value= getMaxLevel(current);
            if (value > max) {
                max = value;
            }
            current = current->nexts[level];
        }
    }
    return max;
}*/


void addCellToList(List *list, Cell* cell) {
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

    for (int i = 1; i < cell->max_level; i++) {
        current = list->heads[i];
        prev = NULL;

        while ((current != NULL) && ((current->value) < (cell->value))) {
            prev = current;
            current = current->nexts[i];
        }
        if (prev == NULL) {
            cell->nexts[i] = list->heads[i];
            list->heads[i] = cell;
        } else {
            prev->nexts[i] = cell;
            cell->nexts[i] = current;
        }
    }
}

List* createListOfNLevel(int n){
    while(n<=0){
        printf("N must be bigger than 0 !");
        scanf("%d", &n);
    }
    List* list = createList(n);
    int* levels = createTab(n);
    for(int i=0;i<((1 << n)-1);i++){
        Cell* cell = createCell(i+1, levels[i]+1);
        addCellToList(list, cell);
    }
    return list;
}

