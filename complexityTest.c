//
// Created by alban on 22/11/2023.
//

#include "complexityTest.h"
#include "math.h"
#include "time.h"

void complexityTest(int level_min, int level_max) {
    srand(time(NULL));
    FILE *log_file = fopen("logTestTime100000.txt", "w");
    char format[] = "%d\t%s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;
    for (int currentLevel = level_min; currentLevel < level_max; currentLevel++) {
        printf("On test le niveau %d :", currentLevel);
        List *list = createListOfNLevel(currentLevel);
        int limite_sup = (1 << currentLevel) - 1;
        startTimer();
        for (int numResearch = 0; numResearch < 100000; numResearch++) {
            classicSearch(list, rand() % limite_sup + 1);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        displayTime();

        startTimer();
        for (int numResearch = 0; numResearch < 100000; numResearch++) {
            optimalSearchFromLevelMax(list, rand() % limite_sup + 1);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file, format, currentLevel, time_lvl0, time_all_levels);
        displayTime();
    }
    fclose(log_file);
}