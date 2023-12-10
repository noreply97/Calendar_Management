//
// Created by yaelc on 09/12/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "agenda.h"

Contact *createContact() { // Alloue de la mémoire dynamiquement à une variable date
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    printf("Fill your first name : \n");
    contact->first_name = scanStringGestion();
    printf("Fill your last name : \n");
    contact->last_name = scanStringGestion();
    contact->meetingList = NULL;
    printf("Contact added \n");
    return contact;
}

void freeContact(Contact *contact) {
    freeMeetingNode(contact->meetingList);
    contact->meetingList->next = NULL;
    free(contact);
}

Date *createDate() {
    Date *date = (Date *) malloc(sizeof(Date));
    printf("Enter the day date of the meeting : ");
    scanf("%d", &date->day);
    printf("\n");
    while ((date->day < 0) || (date->day > 31)) {
        printf("Enter a date between 1 and 31 : ");
        scanf("%d", &date->day);
        printf("\n");
    }
    printf("Enter the month : ");
    scanf("%d", &date->month);
    printf("\n");
    while ((date->month < 0) || (date->month > 12)) {
        printf("Must be between 1 and 12 : ");
        scanf("%d", &date->month);
        printf("\n");
    }
    printf("Enter the year : ");
    scanf("%d", &date->year);
    printf("\n");
    while (date->year < 2023) {
        printf("Must be at least the current year so 2023 : ");
        scanf("%d", &date->year);
        printf("\n");
    }
    return date;
}

void freeDate(Date *date) { // Libère la mémoire allouée à une variable date
    free(date);
}

Time *createHour() {
    Time *time = (Time *) malloc(sizeof(Time));
    printf("Enter the hour : ");
    scanf("%d", &time->hour);
    printf("\n");
    while ((time->hour > 24) || (time->hour < 0)) {
        printf("Must be between 0 and 24 : ");
        scanf("%d", &time->hour);
        printf("\n");
    }
    printf("Enter the minutes : ");
    scanf("%d", &time->minutes);
    printf("\n");
    while ((time->minutes > 60) || (time->minutes < 0)) {
        printf("Must be between 0 and 60 : ");
        scanf("%d", &time->minutes);
        printf("\n");
    }
    return time;
}

void freeHour(Time *time) {
    free(time);
}

Meeting *createMeeting() {
    Meeting *meeting = (Meeting *) malloc(sizeof(Meeting));
    meeting->date = createDate();
    printf("Enter the duration of the meeting.\n");
    meeting->duration = createHour();
    printf("Enter the hour at which the meeting starts.\n");
    meeting->hourMeeting = createHour();
    printf("Enter the topic of the meeting in one word : \n");
    meeting->topic = scanStringGestion();
    printf("\n");
    return meeting;
}

void freeMeeting(Meeting *meeting) {
    freeDate(meeting->date);
    freeHour(meeting->duration);
    freeHour(meeting->hourMeeting);
    free(meeting);
}

void freeMeetingNode(meetingNode *m) {
    freeMeeting(m->meeting);
    m->next = NULL;
}

AgendaEntry *createAgendaEntry(Contact contact) {
    AgendaEntry *agendaEntry = (AgendaEntry *) malloc(sizeof(AgendaEntry));
    agendaEntry->contact = contact;
    agendaEntry->next = NULL;
    return agendaEntry;
}

void freeAgenda(AgendaEntry *agenda) {
    freeContact(&agenda->contact);
    agenda->next = NULL;
    free(agenda);
}

AgendaCell *createAgendaCell(AgendaEntry entry) { //créer une cellule
    AgendaCell *newCell = (AgendaCell *) malloc(sizeof(AgendaCell));
    int nbLevels = 4;
    newCell->agendaEntry = entry;
    newCell->max_level = nbLevels;
    newCell->nexts = (AgendaCell **) malloc(nbLevels * sizeof(AgendaCell *));
    for (int i = 0; i < nbLevels; i++) {
        newCell->nexts[i] = NULL;
    }
    return newCell;
}

AgendaList *createAgendaList() { //initialiser une liste d'agendas de 4 niveaux
    AgendaList *list = (AgendaList *) malloc(sizeof(AgendaList));
    list->max_level = 4;
    list->heads = (AgendaCell **) malloc(list->max_level * sizeof(AgendaCell *));
    for (int i = 0; i < list->max_level; i++) {
        list->heads[i] = NULL;
    }
    return list;
}

void displayAgendaCell(AgendaCell *cell) { //afficher une cellule
    printf("[%s %s|@]", cell->agendaEntry.contact.last_name, cell->agendaEntry.contact.first_name);
}

void displayEmptyAgendaCell() { //afficher des '-' si une cellule est vide
    printf("-----------");
}

void displayAgendaCellLevel(AgendaCell *cell, int level) { //permet d'afficher une cellule vide ou pas
    if (level <= cell->max_level) {
        displayAgendaCell(cell);
    } else {
        displayEmptyAgendaCell();
    }
}

void displayAgendaListLevel(AgendaList list, int nbLevel) { // Permet d'afficher un niveau aligné
    printf("[list head_%d @-]", nbLevel);
    AgendaCell *currentCell = list.heads[0];
    while (currentCell != NULL) {
        printf("-->");
        displayAgendaCellLevel(currentCell, nbLevel);
        currentCell = currentCell->nexts[0];
    }
    printf("-->NULL\n");
}

void displayAllAgendaList(AgendaList list) { //Permet d'afficher tous les niveaux de la liste alignés
    for (int i = 0; i < list.max_level; ++i) {
        displayAgendaListLevel(list, i + 1);
    }
    printf("\n");
}


void addCellToHeadAgendaList(AgendaList *list, AgendaCell *cell) {
    for (int i = 0; i < list->max_level; i++) {
        cell->nexts[i] = list->heads[i];
        list->heads[i] = cell;
    }
}

void classicAgendaSearch(AgendaList *list, char *string) {  // Recherche au niveau 0
    AgendaCell *temp = list->heads[0];
    while (temp != NULL && strcmp(temp->agendaEntry.contact.last_name, string) != 0) {
        temp = temp->nexts[0];
    }
    if (temp != NULL && strcmp(temp->agendaEntry.contact.last_name, string) == 0) {
        printf("The contact %s has been found at level 0\n", string);
    } else {
        printf("The contact %s has not been found at level 0\n", string);
    }
}

Contact *classicAgendaSearchContact(AgendaList *list, char *string) {  // Recherche au niveau 0
    AgendaCell *temp = list->heads[0];
    while (temp != NULL && strcmp(temp->agendaEntry.contact.last_name, string) != 0) {
        temp = temp->nexts[0];
    }
    if (temp != NULL && strcmp(temp->agendaEntry.contact.last_name, string) == 0) {
        return &(temp->agendaEntry.contact);
    } else {
        printf("The contact %s has not been found at level 0\n", string);
        return NULL;
    }
}


char *scanStringGestion() { // Permet la saisie d'une chaîne de caractère dans la console
    char string[256];
    scanf("%s", string);
    size_t length = strlen(string);
    char *buffer = (char *) malloc((length + 1) * sizeof(char));
    strcpy(buffer, string);

    for (size_t i = 0; i < length; ++i) {
        buffer[i] = tolower(buffer[i]);
    }

    return buffer;
}

void addAgendaCellToAgendaList(AgendaList *list,
                               AgendaCell *cell) { //ajouter une cellule au bon endroit dans une liste triée
    if (list->heads == NULL) {
        addCellToHeadAgendaList(list, cell);
        return;
    }
    AgendaCell *current = list->heads[0];
    AgendaCell *prev = NULL;
    while (current != NULL &&
           (strcmp(current->agendaEntry.contact.last_name, cell->agendaEntry.contact.last_name) < 0)) {
        prev = current;
        current = current->nexts[0];
    }
    if (prev == NULL) {
        cell->nexts[0] = list->heads[0];
        list->heads[0] = cell;
    } else {
        prev->nexts[0] = cell;
        cell->nexts[0] = current;
    }

    for (int currentLevel = 1; currentLevel < cell->max_level; currentLevel++) { //boucle qui répète la fonction pour
        // les niveaux supérieurs si nécessaire
        current = list->heads[currentLevel];
        prev = NULL;

        while ((current != NULL) &&
               (strcmp(current->agendaEntry.contact.last_name, cell->agendaEntry.contact.last_name) < 0)) {
            prev = current;
            current = current->nexts[currentLevel];
        }
        if (prev == NULL) {
            cell->nexts[currentLevel] = list->heads[currentLevel];
            list->heads[currentLevel] = cell;
        } else {
            prev->nexts[currentLevel] = cell;
            cell->nexts[currentLevel] = current;
        }
    }
}

meetingNode *createMeetingNode(Meeting *meeting) {
    meetingNode *meetingN = (meetingNode *) malloc(sizeof(meetingNode));
    meetingN->next = NULL;
    meetingN->meeting = meeting;
    return meetingN;
}

void addMeetingToContact(Contact *contact, Meeting *meeting) {
    meetingNode *meetingN = createMeetingNode(meeting);
    if (contact->meetingList == NULL) {
        contact->meetingList = meetingN;
    } else {
        meetingNode *temp = contact->meetingList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = meetingN;
    }
}

AgendaList *createListFromFile(char *txtfile1, char *txtfile2) {
    FILE *first_Names = fopen(txtfile1, "r");
    FILE *last_Names = fopen(txtfile2, "r");
    AgendaList *agendaList = createAgendaList();

    char firstName[256];
    char lastName[256];

    while (fgets(firstName, sizeof(firstName), first_Names) != NULL &&
           fgets(lastName, sizeof(lastName), last_Names) != NULL) {
        firstName[strcspn(firstName, "\n")] = '\0'; //retirer le \n à chaque fin de ligne
        lastName[strcspn(lastName, "\n")] = '\0';

        Contact *newContact = (Contact *) malloc(sizeof(Contact));
        newContact->first_name = strdup(firstName);
        newContact->last_name = strdup(lastName);

        AgendaEntry *newEntry = createAgendaEntry(*newContact);
        AgendaCell *newCell = createAgendaCell(*newEntry);
        addAgendaCellToAgendaList(agendaList, newCell);
    }
    fclose(first_Names);
    fclose(last_Names);
    return agendaList;
}

int compareTwoMeetings(Meeting *meeting1, Meeting *meeting2) {
    if (meeting1->topic != meeting2->topic) {
        return 0;
    }
    if (meeting1->duration->hour != meeting2->duration->hour) {
        return 0;
    }
    if (meeting1->duration->minutes != meeting2->duration->minutes) {
        return 0;
    }
    if (meeting1->hourMeeting->hour != meeting2->hourMeeting->hour) {
        return 0;
    }
    if (meeting1->hourMeeting->minutes != meeting2->hourMeeting->minutes) {
        return 0;
    }
    if (meeting1->date->day != meeting2->date->day) {
        return 0;
    }
    if (meeting1->date->month != meeting2->date->month) {
        return 0;
    }
    if (meeting1->date->year != meeting2->date->year) {
        return 0;
    }
    return 1;
}