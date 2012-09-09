/* -- Programming assignment 2 - Stephen Kelly Section A03

*/

//Includes
#include <stdio.h>
#include <ctype.h>

//defines
#define VALID_INPUT (x>0 && y>0 && gens>0 && (print=='y'||print=='n'||print=='Y'||print=='N') && (pause=='y'||pause=='n'||pause=='Y'||pause=='N'))

#define WELCOME_MSG "\t\t\tThe Game of Life\n"
#define DEBUG 0 //Some debugging info

//variable declarations
unsigned int x,y, gens;
char print = 'N';
char pause = 'N';
char** board1;
char** board2;
char** board3;

//function prototypes
void printConfig(void);
void getSetup(char**);
void getBlankSetup(char** Array);


