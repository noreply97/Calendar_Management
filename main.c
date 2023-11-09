#include <stdio.h>
#include "list.h"

int main() {
    List* list = createList(3);
    Cell *cell1, *cell2, *cell3, *cell4 ;
    cell1 = createCell(0, 1);
    cell2 = createCell(1, 2);
    cell3 = createCell(2, 3);
    addCellToHeadList(cell1, list);
    addCellToHeadList(cell2, list);
    addCellToHeadList(cell3, list);
    displayAllCellsFromList(*list);
    return 0;
}
