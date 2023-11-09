//
// Created by yaelc on 26/10/2023.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef CALENDAR_MANAGEMENT_CELL_H
#define CALENDAR_MANAGEMENT_CELL_H

typedef struct Cell{
    int value;
    int max_level;
    struct Cell** nexts;
}Cell;


struct Cell* createCell(int, int);
int getMaxLevel(Cell*);

#endif //CALENDAR_MANAGEMENT_CELL_H
