//
// Created by alban on 22/11/2023.
//
#include "tab.h"
#include <stdlib.h>

//algorithme pour savoir combien de fois un nombre peut être divisé par 2 avant d'être impair
int rankDivideBy2(int value) {
    int result = 0;
    while ((value % 2 == 0) && (value != 0)) {
        result++;
        value = value / 2;
    }
    return result;
}

//pour créer un tableau avec les valeurs du nombre max de niveau par indice
int *createTab(int n) {
    int nbElem = (1 << n) - 1;
    int *levels = (int *) malloc(nbElem * sizeof(int));
    for (int i = 0; i < nbElem; i++) {
        levels[i] = rankDivideBy2(i + 1);
    }
    return levels;
}