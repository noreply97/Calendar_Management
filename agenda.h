//
// Created by yaelc on 09/12/2023.
//

#ifndef CALENDAR_MANAGEMENT_AGENDA_H
#define CALENDAR_MANAGEMENT_AGENDA_H

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

typedef struct AgendaCell {
    AgendaEntry agendaEntry;
    int max_level;
    struct AgendaCell **nexts;
} AgendaCell;

typedef struct AgendaList {
    AgendaCell **heads;
    int max_level;
} AgendaList;

void displayAgendaCell(AgendaCell*);
void displayEmptyAgendaCell();
void displayAgendaCellLevel(AgendaCell*, int);
void displayAgendaListLevel(AgendaList, int);
void displayAllAgendaList(AgendaList);

void classicAgendaSearch(AgendaList*, char* );
void addAgendaCellToAgendaList(AgendaList*, AgendaCell*);

void addCellToHeadAgendaList(AgendaList*, AgendaCell*);
char *scanStringGestion(); // Permet la saisie d'une chaîne de caractère
Date *createDate(); // Alloue de la mémoire dynamiquement à une variable date
void freeDate(Date *); // Libère la mémoire allouée à une variable date
Time *createHour(); // Alloue de la mémoire dynamiquement à une variable int
void freeHour(Time *); // Libère la mémoire allouée à une variable hour
Meeting *createMeeting(); // Alloue de la mémoire dynamiquement à une variable meeting
void freeMeeting(Meeting *); // Libère la mémoire allouée à une variable meeting
void freeMeetingNode(meetingNode *);
Contact *createContact(); // Alloue de la mémoire dynamiquement à une variable contact
void freeContact(Contact *); // Libère la mémoire allouée à une variable contact
AgendaEntry *createAgendaEntry(Contact); // Alloue de la mémoire dynamiquement à une variable agenda
void freeAgenda(AgendaEntry *); // Libère la mémoire allouée à une variable agenda
AgendaCell *createAgendaCell(AgendaEntry); //créer une cellule
AgendaList* createAgendaList();


#endif //CALENDAR_MANAGEMENT_AGENDA_H
