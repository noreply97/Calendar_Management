#include "contactandrdv.h"

int main() {
    char *firstname = scanString();
    char *lastname = scanString();
    char *result = contactDatasToSimpleString(firstname, lastname);
    printf("%s", result);
    return 0;
}
