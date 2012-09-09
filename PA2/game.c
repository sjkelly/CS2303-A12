/* -- Programming assignment 2 - Stephen Kelly Section A03

*/
#include "game.h"
#include "board.h"
#include <time.h>


void playGame(void){
	int l,k=1, term=0;
	char grab;
	extern unsigned int gens;
	extern char pause,print;
	extern char** board1;
	extern char** board2;
	extern char** board3;
	printBoard(board1,0);
	//board3[0][0]='x'; //make sure board 2 and 3 are different at some point
	for(l = 1; l<=gens; l++){
		if(pause == 'Y' && print =='Y')scanf("%c", &grab);
		if(k==1){
			term=playOne(board1,board2,board3);
			if((print == 'Y' || l == gens) && term==0)printBoard(board2,l);
			k=2;
		}
		else if(k==2){
			term=playOne(board2,board3,board1);
			if((print == 'Y' || l == gens) && term==0)printBoard(board3,l); 
			k=3;
		}
		else if(k==3){
			term=playOne(board3,board1,board2);
			if((print == 'Y' || l == gens) && term==0)printBoard(board1,l); 
			k=1;
		}
		if(term){
		 	printf("Life has reached a termination condition at generation %d ",l);
			if(term==1)printf("by reaching steady state!\n");
			if(term==2)printf("by reaching oscillation!\n");
			if(term==3)printf("by eliminating all life!\n");
			if(k==1)printBoard(board1,l);
			if(k==2)printBoard(board2,l);
			if(k==3)printBoard(board3,l);
			break;
		}
	}
}


int playOne(char** Old, char** New, char** Ref){
	int i,j, steady=0, oscil=0,dead=0;
	extern unsigned int x,y;
	 for(i = 0; i<x; i++){
    for(j = 0; j<y; j++){
			if(DEBUG) printf("\n%d ", neighbors(Old,i,j));
      if(neighbors(Old,i,j) < 2 || neighbors(Old,i,j) > 3) New[i][j] = 'o';
      if(neighbors(Old,i,j) == 3 && Old[i][j] == 'o') New[i][j] = 'x';
			if((neighbors(Old,i,j) == 3 || neighbors(Old,i,j) == 2) && Old[i][j] == 'x') New[i][j] = 'x';
			if(Old[i][j]==New[i][j])steady++;
			if(New[i][j]==Ref[i][j])oscil++;
			if(New[i][j]=='o')dead++;
    }
  }
	return ((steady == x*y)?1:(oscil==x*y)?2:(dead==x*y)?3:0);//return 1 if termination
}


