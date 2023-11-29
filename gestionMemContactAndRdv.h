//
// Created by alban on 29/11/2023.
//

#ifndef CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H
#define CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H

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

typedef struct MeetingNode {
    Meeting meeting;
    struct MeetingNode *next;
} meetingNode;

typedef struct Contact {
    char *first_name;
    char *last_name;
    struct MeetingNode meetings;
} Contact;

typedef struct AgendaEntry {
    Contact contact;
    struct AgendaEntry *next;
} AgendaEntry;

Contact *createContact(char *, char *); // Alloue de la mémoire dynamiquement à une variable contact

Date *createDate(int, int, int); // Alloue de la mémoire dynamiquement à une variable date

Time *createHour(int, int); // Alloue de la mémoire dynamiquement à une variable int

Meeting *createMeeting(Date, Time, Time, char *); // Alloue de la mémoire dynamiquement à une variable meeting

AgendaEntry *createAgendaEntry(Contact, Meeting *, int); // Alloue de la mémoire dynamiquement à une variable agenda

void deleteContact(Contact *); // Libère la mémoire allouée à une variable contact

void deleteDate(Date *); // Libère la mémoire allouée à une variable date

void deleteHour(Time *); // Libère la mémoire allouée à une variable hour

void deleteMeetings(Meeting *); // Libère la mémoire allouée à une variable meeting

void deleteAgenda(AgendaEntry *); // Libère la mémoire allouée à une variable agenda

#endif //CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H
