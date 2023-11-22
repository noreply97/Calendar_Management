//
// Created by yaelc on 26/10/2023.
//
#include "cell.h"
#include "tab.h"

#ifndef CALENDAR_MANAGEMENT_LIST_H
#define CALENDAR_MANAGEMENT_LIST_H

typedef struct List{
    Cell** heads;
    int max_level;
}List;

List* createList(int);
void addCellToHeadList(Cell*, List*);
void displayListCellsFromLevel(List, int);
void displayAllCellsFromList(List);
void addCellToList(List*, Cell*);
List* createListOfNLevel(int);

#endif //CALENDAR_MANAGEMENT_LIST_H
