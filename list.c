//
// Created by yaelc on 26/10/2023.
//

#include "list.h"

List *createEmptyList(int maxLevel) {
    List *mylist = (List *) malloc(sizeof(List));
    mylist->maxLevel = maxLevel;
    mylist->heads = (Cell **) malloc(sizeof(Cell *)*maxLevel);
    for (int i = 0; i < maxLevel; i++) {
        mylist->heads[i] = NULL;
    }
    return mylist;
}//fonctionne

int isEmptyList(List *myList) {
    int res = 0;
    for (int i = 0; i < myList->maxLevel; i++) {
        if(myList->heads[i] == NULL){
            res += 1;
        }
    }
    if(res == myList->maxLevel){
        return 1;
    } else {
        return 0;
    }
}//fonctionne


void insertCellAtHead(List *mylist, Cell *newCell) {
    if (!isEmptyList(mylist)) {
        for (int i = 0; i < newCell->nbLevel; i++) {
            newCell->nexts[i] = mylist->heads[i];
            mylist->heads[i] = newCell;
        }
    }
    printf("Liste vide");
}

//void addCellAtHead(List *mylist, Cell *cell) {
//    if (!isEmptyList(mylist)) {
//        cell->nexts[0] = mylist->heads[0];
//        mylist->heads[0] = cell;
//    }
//}

//void printListLevel(List *mylist, int nbLevel) {
//    if (isEmptyList(mylist)) {
//        printf("Vide");
//    } else {
//        if (nbLevel <= mylist->maxLevel) {
//            printf("[list head_%d-]-->", nbLevel);
//            Cell *temp = mylist->heads[nbLevel];
//            while (temp != NULL) {
//                printf("%d",temp->value);
//                temp = temp->nexts[nbLevel];
//            }
//            printf("NULL");
//        }
//    }
//}

void printList(List *mylist) {
    for (int i = 0; i < mylist->maxLevel; ++i) {
        printListLevel(mylist, i);
    }
}

void deleteList(List *mylist) {
    free(mylist);
}

void printListLevel(List *mylist, int Level) {
    if (!isEmptyList(mylist)) {
        Cell *temp = mylist->heads[Level];
        printf("[list head_%d-]-->", Level);
        while (temp->nexts[Level] != NULL){
            printf("[ %d|@-]-->",temp->value);
            temp=temp->nexts[Level];
        }
        printf("-->NULL");
    } else{
        printf("Liste vide");
    }

}
