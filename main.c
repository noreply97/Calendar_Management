#include "research.h"

int main() {
    List* list = createListOfNLevel(3);
    displayAllCellsFromList(*list);
    searchFromLevelN(list, 6, 2);
    return 0;
}
