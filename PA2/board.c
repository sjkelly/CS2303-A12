/* -- Programming assignment 2 - Stephen Kelly Section A03

*/
#include "board.h"

char** makeBoard(int sizex, int sizey) {  
	char** ary;
	int i;  
	ary = (char**) malloc(sizex*sizeof(char*));  
	for (i = 0; i < sizex; i++)  
		ary[i] = (char*) malloc(sizey*sizeof(char));  
		return ary;  
}  //from http://pleasemakeanote.blogspot.com/2008/06/2d-arrays-in-c-using-malloc.html


int neighbors(char** Array, int locx, int locy){
  int count = 0, i,j;
	extern unsigned int x,y;
	 for(i = 0; i<x; i++){
    for(j = 0; j<y; j++){   
			if((locx+1)==i && (locy)==j && Array[i][j] == 'x') count++;
			if((locx-1)==i && (locy)==j && Array[i][j] == 'x') count++;
			if((locx)==i && (locy+1)==j && Array[i][j] == 'x') count++;
			if((locx)==i && (locy-1)==j && Array[i][j] == 'x') count++;
			if((locx-1)==i && (locy-1)==j && Array[i][j] == 'x') count++;
			if((locx+1)==i && (locy+1)==j && Array[i][j] == 'x') count++;
			if((locx-1)==i && (locy+1)==j && Array[i][j] == 'x') count++;
			if((locx+1)==i && (locy-1)==j && Array[i][j] == 'x') count++;
    }
  }
  return count;
}

void printBoard(char** Array, int gen){
	int i,j;
	extern unsigned int x,y;
	printf("\t\tGeneration %d:\n\t\t\t", gen);
  for(i = 0; i<x; i++){
    for(j = 0; j<y; j++){
      printf("%c ", Array[i][j]);
    }
    printf("\n\t\t\t");
  }
	printf("\n");
}


