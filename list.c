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

/*void displayListCellsFromLevel(List list, int level){
    if(level>=1 && level<=list.max_level) {
        if(level==1){
            printf("[list head_%d @-]--", level - 1);
            Cell* currentCell = list.heads[level-1];
            while(currentCell!=NULL){
                printf(">[%d|@-]--",currentCell->value);
                currentCell=currentCell->nexts[level-1];
            }
            printf(">NULL");
        } else {
            printf("[list head_%d @-]--", level - 1);
            Cell* currentCell = list.heads[level-1];
            Cell* aboveCell=NULL;
            while(currentCell!=NULL){
                if((aboveCell != NULL) && (currentCell->value != aboveCell->value)){
                    printf("---------");
                } else {
                    printf(">[%d|@-]--",currentCell->value);
                }
                aboveCell=currentCell;
                currentCell=currentCell->nexts[level-1];
            }
            printf(">NULL");
        }
    } else{
        return;
    }
}*/

void displayAllCellsFromList(List list){
    for (int i = 0; i <= list.max_level; i++) {
        displayListCellsFromLevel(list, i);
        printf("\n");
    }
}

void displayAllLevelsAligned(List *list) {
    int max = 0;
    for (int i = 0; i < list->max_level; ++i) {
        Cell *current = list->heads[i];
        while (current != NULL) {
            int value= getMaxLevel(current);
            if (value > max) {
                max = value;
            }
            current = current->nexts[i];
        }
    }
    for (int i = 0; i < list->max_level; ++i) {
        printf("[list head_%d @-]--", i);
        Cell *current = list->heads[i];
        while (current != NULL) {
            printf(">[%d|@-]--", current->value);
            current = current->nexts[i];
        }
        if ((i!=0)&&(list->heads[i]->max_level<max)) {
            printf("--------------");
        }
        printf(">NULL \n");
    }
}


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

        // Parcourir la liste au niveau i
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