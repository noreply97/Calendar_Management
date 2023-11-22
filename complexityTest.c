//
// Created by alban on 22/11/2023.
//

#include "complexityTest.h"
#include "math.h"
#include "time.h"

void complexityTest(int level_min, int level_max){
    srand(time(NULL));
    for(int currentLevel=level_min;currentLevel<level_max;currentLevel++){
        printf("On test le niveau %d :",currentLevel);
        List* list= createListOfNLevel(currentLevel);
        int limite_sup=(1 << currentLevel)-1;
        startTimer();
        for(int numResearch=0;numResearch<10000;numResearch++){
            classicSearch(list, rand() % limite_sup + 1);
        }
        stopTimer();
        displayTime();

        startTimer();
        for(int numResearch=0;numResearch<10000;numResearch++){
            searchFromLevelN(list, rand() % limite_sup + 1, currentLevel);
        }
        stopTimer();
        displayTime();
    }
}