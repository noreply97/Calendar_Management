//
// Created by alban on 29/11/2023.
//

#ifndef CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H
#define CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H


typedef struct Contact {
    char *first_name;
    char *last_name;
} Contact;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Time {
    int hour;
    int minutes;
} Time;

typedef struct Meeting {
    Date date;
    Time duration;
    Time hourMeeting;
    char *topic;
} Meeting;

typedef struct AgendaEntry {
    Contact contact;
    Meeting *meetings;
} AgendaEntry;

Contact *createContact(char *, char *);

Date *createDate(int, int, int);

Time *createHour(int, int);

Meeting *createMeeting(Date, Time, Time, char *);

void deleteContact(Contact *);

void deleteDate(Date *);

void deleteHour(Time *);

void deleteMeetings(Meeting *);

void deleteAgenda(AgendaEntry *);

AgendaEntry *createAgendaEntry(Contact, Meeting *, int);

#endif //CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H
