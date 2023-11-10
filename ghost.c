#include "defs.h"

void initGhostList(GhostListType *list) {
    list->head = NULL;
    list->tail = NULL;
    

}

void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost) {

    GhostType *ghost_addr = *ghost;

    ghost_addr = malloc(sizeof(GhostType));

    //assert(ghost_addr != NULL);

    
    ghost_addr->id = id;
    ghost_addr->ghostType = gt;
    ghost_addr->room = r;
    ghost_addr->likelihood = like;
    
}

void addGhost(GhostListType *list, GhostType *ghost) {

    NodeType *newNode = malloc(sizeof(NodeType));


    list->tail->next = newNode;
    list->tail = newNode;
    newNode->data = ghost;
    newNode->next = NULL;

    

}

void cleanupGhostData(GhostListType *list) {
    NodeType *start = list->head;

    while (start->next != NULL) {
        
        //assert (start->data != NULL);

        free(start->data);
        start = start->next;    

    }
}

void cleanupGhostList(GhostListType *list) {

    while (list->head != NULL) {
        NodeType *temp = list->head;
        list->head = list->head->next;

        //assert (temp != NULL);
        free(temp);
    }
    
}


void printGhost(const GhostType *ghost) {
    char types[5][11] = {"POLTERGEIST", "WRAITH", "PHANTOM", "BULLIES", "OTHER"};
    
    char type[11];
    int index = -1;

    

    if (ghost->ghostType == 1) {
        index = 0;


    } else if (ghost->ghostType == 2) {
        index = 1;
    } else if (ghost->ghostType == 3) {
        index = 2;
    } else if (ghost->ghostType == 4) {
        index = 3;
    } else if (ghost->ghostType == 5) {
        index = 4;
    } 


    strcpy(type, types[index]);

    if (ghost->room == NULL) {
        
        printf("ID: %15d | Type: %-15s | Room: Unknown | Likelihood: %4.2f", ghost->id, type, ghost->likelihood ); 

    } else {
        
        printf("ID: %15d | Type: %-15s | Room: %15s | Likelihood: %4.2f", ghost->id, type,ghost->room->name, ghost->likelihood );
    }
    
    


}
