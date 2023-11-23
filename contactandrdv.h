//
// Created by alban on 22/11/2023.
//

#ifndef CALENDAR_MANAGEMENT_CONTACTANDRDV_H
#define CALENDAR_MANAGEMENT_CONTACTANDRDV_H

#include "research.h"

typedef struct Contact{
    char* first_name;
    char* last_name;
}Contact;

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

typedef struct Time{
    int hour;
    int minutes;
} Time;

typedef struct Meeting{
    Date date;
    Time duration;
    Time hourMeeting;
    char* topic;
}Meeting;

typedef struct AgendaEntry {
    Contact contact;
    Meeting* meetings;
} AgendaEntry;

char* scanString(void);
char* contactDatasToSimpleString(char*);
Contact* createContact(char*, char*);
Date* createDate(int, int, int);
Time* createHour(int, int);
Meeting* createMeeting(Date, Time, Time, char*);
AgendaEntry* createAgendaEntry(Contact, Meeting*, int);


#endif //CALENDAR_MANAGEMENT_CONTACTANDRDV_H
