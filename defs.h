#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define C_TRUE     1
#define C_FALSE    0
 
#define MAX_ARR  128
#define MAX_STR   32
 
#define NEXT_ROOM_ID    9001
#define NEXT_GHOST_ID  810310
 
/*  Like structures, the enum must be prefixed with `enum`, so we'll typedef it, but 
    Note that this doesn't conflict with the typedef below because we'd refer to this as
    `enum GhostType` or `GhostEnumType`
  */
typedef enum GhostType { POLTERGEIST, WRAITH, PHANTOM, BULLIES, OTHER } GhostEnumType;
 
/* These rename the structures that we'll be creating. It's an alternative to the format we've seen previously. */
typedef   struct Building   BuildingType; 
typedef   struct Ghost      GhostType;
typedef   struct GhostList  GhostListType;
typedef   struct Node       NodeType;
typedef   struct Room       RoomType;
typedef   struct RoomArray  RoomArrayType;

/*** Complete the GhostListType here ***/
struct GhostList {
  NodeType *head;
  NodeType *tail;
 
};

struct Room {
  int     id;
  char    name[MAX_STR];
  struct  GhostList ghosts;
};
 
struct Ghost {
  int           id;
  GhostEnumType ghostType;
  RoomType      *room;
  float         likelihood;
};

/*** Define the RoomArrayType here ***/
struct RoomArray {
  RoomType *elements[MAX_ARR];
  int size; 

 
};
 
/*** Define the NodeType here ***/
struct Node {
  NodeType *next;
  GhostType *data;
  
 
};

/*** Complete the BuildingType here ***/
struct Building {
  struct GhostList *ghosts;
  struct RoomArray rooms[MAX_ARR];
};
 
void printMenu(int*);
void loadBuildingData(struct Building*);

/***  Complete the function prototypes here, using 
      either the typedef version or the struct version for parameter names 
***/

void initGhostList(GhostListType *list);
void initGhost(int id, GhostEnumType gt, RoomType *r, float like,GhostType **ghost);
void addGhost(GhostListType *list, GhostType *ghost);
void cleanupGhostData(GhostListType *list);
void cleanupGhostList(GhostListType *list);
void printGhostList(const GhostListType *list);
void printGhost(const GhostType *ghost);



 
 

