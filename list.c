//
// Created by yaelc on 26/10/2023.
//

#include "list.h"

List* createList(int nbLevels){
    List* list = (List*)malloc(sizeof(List));
    list->max_level = nbLevels;
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

/*void displayListCellsFromLevel(List list, int level){
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
}*/

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

void displayAllCellsFromList(List list) {
    for (int i = 0; i <= list.max_level; i++) {
        displayListCellsFromLevel(list, i);
        printf("\n");
        if(i>0) {
            for(int j=0;j<;j++){
                if(list.heads[i]->nexts[] == list.heads[i-1]->nexts[]) {
                    printf("----");
                }
            }
        }
    }
}