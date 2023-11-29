//
// Created by alban on 29/11/2023.
//
#include <stdlib.h>
#include "gestionMemContactAndRdv.h"

Contact *createContact(char *first_name, char *last_name) {
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    contact->first_name = first_name;
    contact->last_name = last_name;
    return contact;
}

Date *createDate(int day, int month, int year) {
    Date *date = (Date *) malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

Time *createHour(int hour, int minutes) {
    Time *time = (Time *) malloc(sizeof(Time));
    time->hour = hour;
    time->minutes = minutes;
    return time;
}

Meeting *createMeeting(Date date, Time duration, Time hourMeeting, char *topic) {
    Meeting *meeting = (Meeting *) malloc(sizeof(Meeting));
    meeting->date = date;
    meeting->duration = duration;
    meeting->hourMeeting = hourMeeting;
    meeting->topic = topic;
    return meeting;
}

void deleteContact(Contact *contact) {
    free(contact);
}

void deleteDate(Date *date) {
    free(date);
}

void deleteHour(Time *time) {
    free(time);
}

void deleteMeetings(Meeting *meeting) {
    deleteDate(&meeting->date);
    deleteHour(&meeting->duration);
    deleteHour(&meeting->hourMeeting);
}

void deleteAgenda(AgendaEntry *agenda) {
    deleteContact(&agenda->contact);
    deleteMeetings(agenda->meetings);
}

AgendaEntry *createAgendaEntry(Contact contact, Meeting *meetings, int nbMeetings) {
    AgendaEntry *agendaEntry = (AgendaEntry *) malloc(sizeof(AgendaEntry));
    agendaEntry->contact = contact;
    agendaEntry->meetings = (Meeting **) malloc(nbMeetings * sizeof(Meeting *));
    for (int i = 0; i < nbMeetings; i++) {
        agendaEntry->meetings[i] = NULL;
    }
    return agendaEntry;
}