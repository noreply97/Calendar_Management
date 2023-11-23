//
// Created by alban on 22/11/2023.
//
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#include "contactandrdv.h"

char* scanString(void){
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *result = strdup(buffer);
    return result;
}