//
// Created by alban on 29/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "gestionMemContactAndRdv.h"

char *scanStringGestion() {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin); //Utilise la fonction fgets pour lire une ligne de texte à
    // partir de l'entrée standard (stdin) et la stocke dans le tableau
    buffer[strcspn(buffer, "\n")] = '\0'; // supprime le caractère de saut de ligne
    char *result = strdup(buffer); // alloue espace pour result et copie le contenu du buffer dans cette nouvelle chaîne
    return result;
}

Contact *createContact() { //!!!Ne devrait pas prendre un agenda en paramètres pour ajouter le contact a lagenda ?;
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    printf("Please enter your first name : ");
    contact->first_name = scanStringGestion();
    printf("Please enter your last name : ");
    contact->last_name = scanStringGestion();
    contact->meetingList = NULL;
    return contact;
}

Date *createDate() {
    Date *date = (Date *) malloc(sizeof(Date));
    printf("Please enter the day of your meeting : ");
    scanf("%d", &date->day);
    printf("\n");
    while ((date->day < 0) || (date->day > 31)) {
        printf("Please enter a number between 0 and 31 : ");
        scanf("%d", &date->day);
        printf("\n");
    }
    printf("Please enter the month of your meeting : ");
    scanf("%d", &date->month);
    printf("\n");
    while ((date->month < 0) || (date->month > 12)) {
        printf("Please enter a number between 0 and 12 : ");
        scanf("%d", &date->month);
        printf("\n");
    }
    printf("Please enter the year of your meeting : ");
    scanf("%d", &date->year);
    printf("\n");
    while (date->year < 2023) {
        printf("Please enter a number beyond 2023 : ");
        scanf("%d", &date->year);
        printf("\n");
    }
    return date;
}

Time *createHour() {
    Time *time = (Time *) malloc(sizeof(Time));
    printf("Please enter the hour : ");
    scanf("%d", &time->hour);
    printf("\n");
    while ((time->hour > 24) || (time->hour < 0)) {
        printf("Please enter an number between 0 and 24 : ");
        scanf("%d", &time->hour);
        printf("\n");
    }
    printf("Please enter the minutes : ");
    scanf("%d", &time->minutes);
    printf("\n");
    while ((time->minutes > 60) || (time->minutes < 0)) {
        printf("Please enter a number between 0 and 60 : ");
        scanf("%d", &time->minutes);
        printf("\n");
    }
    return time;
}

Meeting *createMeeting() {
    Meeting *meeting = (Meeting *)malloc(sizeof(Meeting));
    meeting->date = createDate();
    printf("You will enter the duration of the meeting.\n");
    meeting->duration = createHour();
    printf("You will enter the hour of the start of the meeting.\n");
    meeting->hourMeeting = createHour();
    printf("Enter the topic of the meeting in one word : \n");
    meeting->topic = scanStringGestion(); //!!!!ERREUR;
    return meeting;
}

void deleteContact(Contact *contact) {
    deleteMeetingNode(contact->meetingList);
    contact->meetingList->next = NULL;
    free(contact);
}

void deleteDate(Date *date) {
    free(date);
}

void deleteHour(Time *time) {
    free(time);
}

void deleteMeeting(Meeting *meeting) {
    deleteDate(meeting->date);
    deleteHour(meeting->duration);
    deleteHour(meeting->hourMeeting);
    free(meeting);
}

void deleteMeetingNode(meetingNode *m) {
    deleteMeeting(&m->meeting);
    m->next = NULL;
}

void deleteAgenda(AgendaEntry *agenda) {
    deleteContact(&agenda->contact);
    agenda->next = NULL;
    free(agenda);
}

AgendaEntry *createAgendaEntry(Contact contact) {
    AgendaEntry *agendaEntry = (AgendaEntry *) malloc(sizeof(AgendaEntry));
    agendaEntry->contact = contact;
    agendaEntry->next = NULL;
    return agendaEntry;
}