//
// Created by alban on 22/11/2023.
//

#ifndef CALENDAR_MANAGEMENT_CONTACTANDRDV_H
#define CALENDAR_MANAGEMENT_CONTACTANDRDV_H

#include "gestionMemContactAndRdv.h"
#include "complexityTest.h"
#include "research.h"

char *scanString(void); // Permet la saisie d'une chaîne de caractère

char *contactDatasToSimpleString(char *, char *); // Prend deux chaînes de caractère et les met ensemble sous la forme char1_char2

void rechercherContact(AgendaEntry *agenda, char *partialName, int niveau);

void rechercheContactMenu(AgendaEntry *agenda);

void displayMeeting(Meeting *meeting);

void displayMeetingListOfContact(Contact *contact);

#endif //CALENDAR_MANAGEMENT_CONTACTANDRDV_H
