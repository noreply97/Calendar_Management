//
// Created by yaelc on 10/12/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "contactandrdv.h"
#include <unistd.h>

void displayMenu(){
    AgendaList* list  = createAgendaList();
    int clock=1;
    while(clock){
        printf("Welcome in the menu of our agenda, what do you wish to do ? :\n");
        printf("1. Search a contact\n");
        printf("2. Display all the meetings of a contact\n");
        printf("3. Create a new contact\n");
        printf("4. Create a new meeting for a contact\n");
        printf("5. Cancel a meeting\n");
        printf("6. Save the file of all the meetings\n");
        printf("7. Exit\n");
        int res = 0;
        while(res < 1 || res>7) {
            scanf("%d", &res);
        }
        switch(res){
            case 1:
                printf("Which contact are you searching for (enter the last name) ? :\n");
                char* string = scanStringGestion();
                classicAgendaSearch(list, string);
                free(string);
                break;
            case 2:
                printf("Of which contact do you wish to see the meetings (enter the last name) ?\n");
                char* string1 = scanStringGestion();
                Contact* temp= classicAgendaSearchContact(list, string1);
                if(temp!=NULL){
                    if((temp->meetingList)==NULL){
                        printf("%s %s does not have any meeting registered. \n",temp->first_name,temp->last_name);
                        break;
                    }
                    meetingNode* tempMeeting=temp->meetingList;
                    while(tempMeeting!=NULL){
                        displayMeeting(tempMeeting->meeting);
                        tempMeeting=tempMeeting->next;
                    }
                    break;
                }
                break;
            case 3:
                printf("To create a new contact :\n");
                Contact* contact = createContact();
                AgendaEntry *agContact=createAgendaEntry(*contact);
                AgendaCell *agCellContact = createAgendaCell(*agContact);
                addAgendaCellToAgendaList(list, agCellContact);
                break;

            case 4:
                printf("For which contact do you wish to create a meeting (enter the last name) ?\n");
                char* string2 = scanStringGestion();
                Contact* temp1= classicAgendaSearchContact(list, string2);
                if(temp1!=NULL){
                    Meeting *meeting=createMeeting();
                    addMeetingToContact(temp1, meeting);
                    printf("Meeting added for %s %s. \n",temp1->first_name,temp1->last_name);
                    break;
                }
                break;

            case 5:
                printf("Vous avez choisi l'option 5.\n");
                break;

            case 6:
                printf("Vous avez choisi l'option 6.\n");
                break;
            case 7:
                printf("The program is going to shut in five seconds.\n");
                sleep(5);
                return;

            default :
                printf("Invalid option.\n");
        }
    }

}
