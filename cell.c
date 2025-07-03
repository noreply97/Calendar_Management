//
// Created by yaelc on 26/10/2023.
//

#include "cell.h"

Cell *createCell(int value, int nbLevel) {
    Cell *mycell = (Cell *) malloc(sizeof(Cell));
    mycell->value = value;
    mycell->nbLevel = nbLevel;
    mycell->nexts = (Cell **) malloc(sizeof(Cell*) * nbLevel);
    for (int i = 0; i < nbLevel; i++) {
        mycell->nexts[i] = NULL;
    }
    return mycell;
}

void deleteCell(Cell *mycell) {
    free(mycell);
}

void printCell(Cell* mycell){  // vérification pour la fonction cell
    printf("%d",mycell->value);
    for(int i=0;i<mycell->nbLevel;i++){
        if (mycell->nexts[i]==NULL) {
            printf("NULL");
        }
    }
}
