//
// Created by alban on 22/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactandrdv.h"

char *scanString(void) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *result = strdup(buffer);
    return result;
}

char* contactDatasToSimpleString(char *firstname, char *lastname) {
    if (firstname == NULL || lastname == NULL) {
        return NULL;
    }
    size_t length = strlen(firstname) + strlen(lastname) + 2;
    char *result = (char *) malloc(length * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    snprintf(result, length, "%s_%s", lastname, firstname);
    return result;
}

void rechercherContact(AgendaEntry *agenda, char *partialName, int niveau) {
    if (agenda == NULL) {
        printf("No contact found.\n");
        return;
    }
    char *fullname = contactDatasToSimpleString(agenda->contact.first_name, agenda->contact.last_name);
    char currentLetter = partialName[niveau];
    char *contactName = agenda->contact.last_name;
    if (contactName[niveau] == currentLetter) {
        if (niveau == 2) {
            printf("%s\n", fullname);
            exit(0);
        }
        free(fullname);
        rechercherContact(agenda, partialName, niveau + 1);
    } else {
        free(fullname);
        rechercherContact(agenda->next, partialName, 0);
    }
}

void rechercheContactMenu(AgendaEntry *agenda) {
    printf("Entrez le nom a rechercher (3 lettres minimum) : ");
    char *partialName = scanString();
    rechercherContact(agenda, partialName, 0);
    free(partialName);
}

void displayMeeting(Meeting *meeting) {
    printf("Date of the meeting : %d/%d/%d. \n", meeting->date->day, meeting->date->month, meeting->date->year);
    printf("Hour of the meeting : %d:%d. \n", meeting->hourMeeting->hour, meeting->hourMeeting->minutes);
    if (meeting->duration->hour == 1) {
        printf("Duration of the meeting : %d hour and %d minutes. \n", meeting->duration->hour,
               meeting->duration->minutes);
    } else {
        printf("Duration of the meeting : %d hours and %d minutes. \n", meeting->duration->hour,
               meeting->duration->minutes);
    }
    printf("Topic of the meeting : %s.\n", meeting->topic);
}

void displayMeetingListOfContact(Contact *contact) {
    meetingNode *currentNode = contact->meetingList;
    while (currentNode != NULL) {
        displayMeeting(&currentNode->meeting);
        currentNode = currentNode->next;
    }
}