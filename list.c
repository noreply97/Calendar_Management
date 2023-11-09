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

void displayListCellsFromLevel(List list, int level){
    printf("[list head_%d @-]-->", level-1);


}