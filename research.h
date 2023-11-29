//
// Created by alban on 22/11/2023.
//
#include "list.h"

#ifndef CALENDAR_MANAGEMENT_RESEARCH_H
#define CALENDAR_MANAGEMENT_RESEARCH_H

void classicSearch(List *, int); // Recherche une valeur dans la liste au niveau 0

int isAtLevelN(List *, int, int); // Détermine si une valeur est présente à un niveau donnée

void searchFromLevelN(List *, int, int); // Recherche une valeur dans la liste à un niveau donnée

void optimalSearchFromLevelMax(List *, int); // Recherche dichotomique de la valeur dans la liste à partir du niveau max

#endif //CALENDAR_MANAGEMENT_RESEARCH_H
