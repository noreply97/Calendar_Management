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

char *contactDatasToSimpleString(char *firstname, char *lastname) {
    if (firstname == NULL || lastname == NULL) {
        return NULL;
    }
    size_t length = strlen(firstname) + strlen(lastname) + 2;
    char *result = (char *) malloc(length * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    snprintf(result, length, "%s_%s", lastname, firstname);
    return result;
}
