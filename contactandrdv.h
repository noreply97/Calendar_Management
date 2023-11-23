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

typedef struct hour{
    int hour;
    int minutes;
} Hour;

typedef struct meeting{
    Date date;
    Hour duration;
    Hour hourMeeting;
    char* topic;
}Meeting;

char* scanString(void);

typedef struct agendaEntry {
    Contact contact;
    Meeting* meetings;
} AgendaEntry;

#endif //CALENDAR_MANAGEMENT_CONTACTANDRDV_H
