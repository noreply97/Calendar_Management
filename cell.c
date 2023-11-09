//
// Created by yaelc on 26/10/2023.
//

#include "cell.h"

struct Cell* createCell(int val, int nbLevels){
    struct Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->value = val;
    cell->max_level = nbLevels;
    cell->nexts=(Cell**) malloc(nbLevels*sizeof (Cell*));
    for (int i = 0; i < nbLevels; i++) {
        cell->nexts[i] = NULL;
    }
    return cell;
}

int getMaxLevel(Cell* cell){
    return cell->max_level;
}