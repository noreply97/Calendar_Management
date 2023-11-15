#include <stdio.h>
#include "list.h"

int main() {
    int n=7;
    int* tab= createTab(3);
    for(int i=0;i<7;i++){
        printf("%d \n",tab[i]);
    }
    //List* list = createListOfNLevel(7);
    //displayAllCellsFromList(*list);
    return 0;
}
