//
// Created by alban on 22/11/2023.
//
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#include "contactandrdv.h"

char* scanString(void){
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *result = strdup(buffer);
    return result;
}

char* contactDatasToSimpleString(char* name){
    int i=0;
    char *firstName = NULL, *lastName = NULL;
    char* space = " ";
}

Contact* createContact(char* first_name, char* last_name){
    Contact* contact = (Contact*) malloc(sizeof(Contact));
    contact->first_name = first_name;
    contact->last_name = last_name;
    return contact;
}

Date* createDate(int day, int month, int year){
    Date* date = (Date*) malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

Time* createHour(int hour, int minutes){
    Time* time = (Time*)malloc(sizeof(Time));
    time->hour = hour;
    time->minutes = minutes;
    return time;
}

Meeting* createMeeting(Date date, Time duration, Time hourMeeting, char* topic){
    Meeting* meeting = (Meeting*)malloc(sizeof(Meeting));
    meeting->date = date;
    meeting->duration = duration;
    meeting->hourMeeting = hourMeeting;
    meeting->topic = topic;
    return meeting;
}

AgendaEntry* createAgendaEntry(Contact contact, Meeting* meetings, int nbMeetings){
    AgendaEntry* agendaEntry = (AgendaEntry*)malloc(sizeof(AgendaEntry));
    agendaEntry->contact = contact;
    agendaEntry->meetings = (Meeting*)malloc(nbMeetings*sizeof(Meeting));
    return agendaEntry;
}