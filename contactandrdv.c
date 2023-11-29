//
// Created by alban on 22/11/2023.
//
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#include <ctype.h>
#include "contactandrdv.h"

char *scanString(void) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *result = strdup(buffer);
    return result;
}

char* contactDatasToSimpleString(char* name){
    int i=0;
    char *firstName = NULL, *lastName = NULL;
    char* space = " ";
}
