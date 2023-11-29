//
// Created by alban on 22/11/2023.
//

#include "research.h"
#include "list.h"

void classicSearch(List *list, int val) {  // Recherche au niveau 0
    Cell *temp = list->heads[0];
    while (temp != NULL && temp->value != val) {
        temp = temp->nexts[0];
    }
    if (temp != NULL && temp->value == val) {
        //printf("%d found at level 0\n", val);
    } else {
        printf("%d not found at level 0\n", val);
    }
}

int isAtLevelN(List *list, int val, int level) {  // Recherche dans tous les niveaux en partant du plus haut
    if (level <= list->max_level) {
        Cell *temp = list->heads[level - 1];
        while (temp != NULL && temp->value != val) {
            temp = temp->nexts[level - 1];
        }
        if (temp != NULL && temp->value == val) {
            return 1;
        } else {
            return 0;
        }
    } else {
        printf("Level input is too high");
    }
}

void searchFromLevelN(List *list, int val, int level) {
    if (level <= list->max_level) {
        if (level == 0) {
            classicSearch(list, val);
        } else {
            if (isAtLevelN(list, val, level) == 1) {
                //printf("%d found at level %0d \n", val, level);
            } else {
                searchFromLevelN(list, val, level - 1);
            }
        }
    } else {
        //printf("Level input is too high\n");
    }
}

void optimalSearchFromLevelMax(List *list, int val) {
    unsigned short alwaysAtHead = 1;
    Cell *temp = list->heads[list->max_level - 1];
    while (list->max_level > 0 && temp->value != val) {
        if (temp->nexts[list->max_level - 1] == NULL || temp->nexts[list->max_level - 1]->value > val) {
            list->max_level--;
            if (alwaysAtHead) {
                if ((temp->value > val)) {
                    temp = list->heads[list->max_level - 1];
                } else {
                    alwaysAtHead = 0;
                }
            }
        } else {
            temp = temp->nexts[list->max_level - 1];
            alwaysAtHead = 0;
        }
    }
    if (list->max_level <= 0) {
        //printf("%d not found in any level\n", val);
    } else {
        //printf("%d found at level %d", val, list->max_level);
    }
}