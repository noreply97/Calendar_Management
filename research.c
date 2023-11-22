//
// Created by alban on 22/11/2023.
//

#include "research.h"
#include "list.h"

void classicSearch(List* list, int val) {  // Recherche au niveau 0
    Cell* temp = list->heads[0];
    while (temp != NULL && temp->value != val) {
        temp = temp->nexts[0];
    }
    if (temp != NULL && temp->value == val) {
        printf("%d found at level 0\n", val);
    } else {
        printf("%d not found at level 0\n", val);
    }
}

void searchAtLevelN(List* list, int val, int level) {  // Recherche dans tous les niveaux en partant du plus haut
    Cell* temp = list->heads[level];
    while (temp != NULL && temp->value != val) {
        temp = temp->nexts[level];
    }
    if (temp != NULL && temp->value == val) {
        printf("%d found at level %d\n", val,level);
    } else {
        printf("%d not found at level %d\n", val,level);
    }
}
int isAtLevelN(List* list, int val, int level) {  // Recherche dans tous les niveaux en partant du plus haut
    Cell* temp = list->heads[level];
    while (temp != NULL && temp->value != val) {
        temp = temp->nexts[level];
    }
    if (temp != NULL && temp->value == val) {
        return 1;
    } else {
        return 0;
    }
}

void searchFromLevelN(List* list, int val, int level){
    if(level<=list->max_level) {
        if (level == 0) {
            classicSearch(list, val);
        } else {
            if (isAtLevelN(list, val, level) == 1) {
                printf("%d found at level %d", val, level);
            } else {
                searchFromLevelN(list, val, level - 1);
            }
        }
    }else{
        printf("Level input is too high");
    }
}