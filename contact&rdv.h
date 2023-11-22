//
// Created by alban on 22/11/2023.
//

#ifndef CALENDAR_MANAGEMENT_CONTACT_RDV_H
#define CALENDAR_MANAGEMENT_CONTACT_RDV_H

typedef struct Contact{
    char* first_name;
    char* last_name;
}Contact;

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

typedef struct durationMeeting{
    int hour;
    int minutes;
} durationMeeting;

typedef struct hourMeeting{
    int hour;
    int minutes;
} hourMeeting;

typedef struct meeting{
    Date date;
    durationMeeting duration;
    hourMeeting hour;
    char* topic;
}Meeting;

char* scanString(void);

#endif //CALENDAR_MANAGEMENT_CONTACT_RDV_H
