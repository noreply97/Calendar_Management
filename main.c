#include "agenda.h"
#include "menu.h"

int main() {
    //Partie 1 :
    /*List *list = createListOfNLevel(3);
    displayAllList(list);
    Cell* cell = createCell(3,1);
    addCellToList(list, cell);
    displayAllList(list);*/
    //Partie 2 :
    //complexityTest(7, 16);
    //Partie 3
    //Meeting *meeting = createMeeting();
    //freeMeeting(meeting);

    /*
    Contact* contact = createContact();
    AgendaList* list  = createAgendaList();
    AgendaEntry* entry = createAgendaEntry(*contact);
    AgendaCell* cell = createAgendaCell(*entry);
    addCellToHeadAgendaList(list, cell);
    displayAllAgendaList(*list);

    Contact* contact2 = createContact();
    AgendaEntry* entry2 = createAgendaEntry(*contact2);
    AgendaCell* cell2 = createAgendaCell(*entry2);
    addAgendaCellToAgendaList(list, cell2);
    displayAllAgendaList(*list);


    //classicAgendaSearch(list, "chab");*/

    displayMenu();



    return 0;
}