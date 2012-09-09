/* -- Programming assignment 2 - Stephen Kelly Section A03

*/
#include "life.h"
#include "board.h"
#include "game.h"

int main(void){
  
  //grab inputs
  printf(WELCOME_MSG);
	scanf("%u%u%u %1[ynYN] %1[ynYN]", &y, &x, &gens, &print, &pause); 
	pause=toupper(pause);
	print=toupper(print);
	board1 = makeBoard(x,y);
	board2 = makeBoard(x,y);
	board3 = makeBoard(x,y);
	getBlankSetup(board1);
	getBlankSetup(board2);
	getBlankSetup(board3);
	getSetup(board1);
	printConfig();
	freopen("/dev/tty", "r", stdin);//reassign stdin to the keyboard stream
	playGame();
  return 0;
}


void printConfig(){
	printf("\nPlaying with a %d by %d grid consisting of %d generations.\n", x, y, gens);
	if(print=='Y'){
		printf("The program will display each generation");
		if(pause=='Y')printf(" and pause for user input between each generation. \n");
		else printf(".\n");
	}
	else printf("\n");
}

void getSetup(char** Array){
	int i,j,rows=2,cols=0,rowst=0,colst=0, samples=0;
	char buf[x*y+y];
	char c, lastc=' ';
	while((c=getchar()) != EOF){
		if(lastc == '\n' && c == '\n')break;
		c = tolower(c);
		lastc = c;
		if (c == '\n') rows++;
		if(c=='x'||c=='o') cols++;
		buf[samples]=c;
		samples++;
	}
	for(i=samples; i>0; i--)ungetc(buf[i],stdin);
	colst = x/2-cols/2;
	rowst = y/2-rows/2;
  for(i = rowst; i<rows; i++){
    for(j = colst; j<cols; j++){
      scanf("%1s", &Array[i][j]);
    }
  }
	fflush(stdin); //flush stin because we are done with it for now.
}

void getBlankSetup(char** Array){
	int i,j;
  for(i = 0; i<x; i++){
    for(j = 0; j<y; j++){
      Array[i][j] = 'o';
    }
  }
}

