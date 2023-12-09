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
    Date *date;
    Time *duration;
    Time *hourMeeting;
    char *topic;
} Meeting;

typedef struct MeetingNode {
    Meeting meeting;
    struct MeetingNode *next;
} meetingNode;

typedef struct Contact {
    char *first_name;
    char *last_name;
    struct MeetingNode *meetingList;
} Contact;

typedef struct AgendaEntry{
    Contact contact;
    struct AgendaEntry *next;
} AgendaEntry;

char *scanStringGestion(); // Permet la saisie d'une chaîne de caractère

Date *createDate(); // Alloue de la mémoire dynamiquement à une variable date

void deleteDate(Date *); // Libère la mémoire allouée à une variable date

Time *createHour(); // Alloue de la mémoire dynamiquement à une variable int

void deleteHour(Time *); // Libère la mémoire allouée à une variable hour

Meeting *createMeeting(); // Alloue de la mémoire dynamiquement à une variable meeting

void deleteMeeting(Meeting *); // Libère la mémoire allouée à une variable meeting

void deleteMeetingNode(meetingNode *);

Contact *createContact(); // Alloue de la mémoire dynamiquement à une variable contact

void deleteContact(Contact *); // Libère la mémoire allouée à une variable contact

AgendaEntry *createAgendaEntry(Contact); // Alloue de la mémoire dynamiquement à une variable agenda

void deleteAgenda(AgendaEntry *); // Libère la mémoire allouée à une variable agenda

#endif //CALENDAR_MANAGEMENT_GESTIONMEMCONTACTANDRDV_H
