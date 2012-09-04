/* -- Programming assignment 2 - Stephen Kelly Section A03

*/
#include <stdio.h>
#include <grids.h>

#define INPUT_TRUE (x>0 && y>0 && gens>0 && (print=='y'||print=='n'||print=='Y'||print=='N') && (pause=='y'||pause=='n'||pause=='Y'||pause=='N'))

int main(void){
  unsigned int x,y, gens;
  char print = 'n';
  char pause = 'n';
  
  //grab inputs
  printf("\t\t\tThe Game of Life\n");
  printf("Please enter the rows for the game. : ");
  scanf("%i", &x);
  printf("Please enter the rows for the game. : ");
  scanf("%i", &y);
  printf("Please enter the generations for the game. : ");
  scanf("%i", &gens);
  printf("Do you want to print each generation? (y/n) : "); 
  scanf("%1s", &print);
  printf("Do you want to pause between each generation? (y/n) : ");
  scanf("%1s", &pause);

  /*
  //if input is invalid, request new values  
  while (!INPUT_TRUE) {
    printf("ERROR: Invalid input(s)!\n");  
    if (x<1) {
      printf("Please enter the rows for the game. : ");
      scanf("%i", &x);
    }
    if (y<1) {
      printf("Please enter the rows for the game. : ");
      scanf("%i", &y);
    }
    if (gens<1) {
      printf("Please enter the generations for the game. : ");
      scanf("%i", &gens);
    }
    if (print=='y'||print=='n'||print=='Y'||print=='N') {
      printf("Do you want to print each generation? (y/n) : "); 
      scanf("%c", &print);
    }
    if (pause=='y'||pause=='n'||pause=='Y'||pause=='N') {
      printf("Do you want to pause between each generation? (y/n) : ");
      scanf("%c", &pause);
    }
  }
  */
  life(x,y,gens,print,pause);
  return 0;
}
