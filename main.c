#include "contactandrdv.h"

int main() {
    char* prenom=scanString();
    char* prenom1 = contactDatasToSimpleString(prenom);
    printf("%s\n", prenom);
    printf("%s\n", prenom1);
    return 0;
}
