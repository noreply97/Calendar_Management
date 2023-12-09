//
// Created by alban on 22/11/2023.
//

#include "complexityTest.h"
#include "math.h"
#include "time.h"

void complexityTest(int level_min, int level_max) { //Permet le test de complexité pour comparer recherche classique et dichotomique
    srand(time(NULL)); //initialisation du générateur de valeurs aléatoires
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;

    for (int currentLevel = level_min; currentLevel < level_max; currentLevel++) {
        printf("On teste le niveau %d :\n", currentLevel);
        List *list = createListOfNLevel(currentLevel);
        int limite_sup = (1 << currentLevel)-1; //Permet de fixer une valeur à ne pas dépasser lors du rand()

        startTimer();
        for (int numResearch = 0; numResearch < 100000; numResearch++) { //recherche classique lancée 100 000 fois
            classicSearch(list, rand() % limite_sup ); //recherche une valeur aléatoire
        }
        stopTimer();
        displayTime(); //affiche le temps nécessaire pour trouver les 100 000 valeurs sur le niveau currentLevel
        time_lvl0 = getTimeAsString(); // fonction du module timer

        startTimer();
        for (int numResearch = 0; numResearch < 100000; numResearch++) { //recherche dichotomique lancée 100 000 fois
            optimalSearchFromLevelMax(list, rand() % limite_sup ); //recherche une valeur aléatoire
        }
        stopTimer();
        displayTime();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,currentLevel,time_lvl0, time_all_levels);
    }
    fclose(log_file);

}