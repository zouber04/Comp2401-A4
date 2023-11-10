#include "defs.h"

int main()
{

  GhostListType glist;
  GhostType *gp1;
  //GhostType g2;


 
 
  initGhostList(&glist);
  initGhost(11, OTHER, NULL, 11.4, &gp1);

  printf("%2.4f", gp1->likelihood);
  
  //printGhost(gp1);
  //addGhost(&glist, gp1);
  

  //cleanupGhostData(&glist);
  //cleanupGhostList(&glist);



  return 0;
}

void printMenu(int *choice)
{
  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (4) Print most/least likely ghosts\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%2d", choice);
  while (getchar() != '\n');
}

