/* -- Programming assignment 2 - Stephen Kelly Section A03

*/
#include <stdio.h>
#include <malloc.h>

//define
#define DEBUG 1 //Some debugging info

//function prototypes
char** makeBoard(int sizex, int sizey);
int neighbors(char** Array, int locx, int locy);
void printBoard(char **Array, int gen);
