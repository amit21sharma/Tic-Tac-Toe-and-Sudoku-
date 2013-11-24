/************ TIC TAC TOE ******************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int check_win(char tic[][3]);
int player_move(int X,char tic[][3] );
int comp_move(char tic[][3]);
void display(char tic[][3]);
int main()
{
	int win=0,i,j;
	int ret,retcomp;
	int X;
	char tic[][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	srand(time(NULL));
	do {   
		system("cls");
		display(tic);
		do {                                   // PLAYER MOVE
			printf("\nPlayer 1: ");
			fflush(stdin);
			scanf("%d",&X);
			if(X>=1 && X<=9)
			ret=player_move(X,tic);
			else{
			printf("\nInvalid Move");
			ret=1;
			}
		} while(ret==1);
		win=check_win(tic);
		display(tic);
		do {                                   // PLAYER MOVE
			retcomp=comp_move(tic);
		} while(retcomp==1);
		display(tic);
		win=check_win(tic);
	       //	system("cls");
	} while(!win);
	getch();
	return 0;
}
int player_move(int X,char tic[][3] )
{
	if(tic[(X-1)/3][(X-1)%3]!='X' && tic[(X-1)/3][(X-1)%3]!='O'){
	tic[(X-1)/3][(X-1)%3]='X';
	return 0;
	}
	else{
	    printf("\nIvalid Move!!");
	    return 1;
	    }
}
int comp_move(char tic[][3])
{
	int r,i,j;
	if(tic[1][1]!='X' && tic[1][1]!='O') {
		tic[1][1]='O';
		return 0;
	}
	for(i=0; i<3; i++) {              // ROWS
		if(tic[i][0]==tic[i][1] && tic[i][2]!='X'&& tic[i][2]!='O' ) {
			tic[i][2]='O';
			return 0;
		}
		if(tic[i][0]==tic[i][2] && tic[i][1]!='X'&& tic[i][1]!='O') {
			tic[i][1]='O';
			return 0;
		}
		if(tic[i][1]==tic[i][2] && tic[i][0]!='X'&& tic[i][0]!='O') {
			tic[i][0]='O';
			return 0;
		}
	}
	for(i=0; i<3; i++) {              // COLUMNS
		if(tic[0][i]==tic[1][i]&& tic[2][i]!='X'&& tic[2][i]!='O') {
			tic[2][i]='O';
			return 0;
		}
		if(tic[0][i]==tic[2][i]&& tic[1][i]!='X'&& tic[1][i]!='O') {
			tic[1][i]='O';
			return 0;
		}
		if(tic[1][i]==tic[2][i]&& tic[0][i]!='X'&& tic[0][i]!='O') {
			tic[0][i]='O';
			return 0;
		}
	}
	if(tic[0][0]==tic[1][1] && tic[2][2]!='X' && tic[2][2]!='O') {
		tic[2][2]='O';
		return 0;
	}
	if((tic[1][1]==tic[2][2]) && (tic[0][0]!='X'&& tic[0][0]!='O')) {
		tic[0][0]='O';
		return 0;
	}
	if((tic[0][0]==tic[2][2]|| tic[0][2]==tic[2][0])&& (tic[1][1]!='X')&& tic[1][1]!='O') {
		tic[1][1]='O';
		return 0;
	}
	if(tic[0][2]==tic[1][1] && tic[2][0]!='X'&& tic[2][0]!='O') {
		tic[2][0]='O';
		return 0;
	}
	if(tic[1][1]==tic[2][0] && tic[0][2]!='X'&& tic[0][2]!='O') {
		tic[0][2]='O';
		return 0;
	}
	r = (rand() % 9)+1;
	if(tic[(r-1)/3][(r-1)%3]!='X' && tic[(r-1)/3][(r-1)%3]!='O') {
		tic[(r-1)/3][(r-1)%3]='O';
		return 0;
	} else
		return 1;
}
int check_win(char tic[][3])
{
	int i,j,count=0;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++) {
			if(tic[i][j]=='X' || tic[i][j]=='O')
				count++;
		}
	if (count==9) {
		printf("\nMATCH DRAW!\n");
		return 1;
	}
	for(i=0; i<3; i++) {
		if((tic[i][0]==tic[i][1])&& (tic[i][0]==tic[i][2])) {
			if(tic[i][0]=='X')
				printf("\nYOU WIN!!!");
			else
				printf("\nCOMP WINS");
			return 1;
		}
	}
	for(i=0; i<3; i++) {
		if((tic[0][i]==tic[1][i])&&(tic[0][i]==tic[2][i])) {
			if(tic[0][i]=='X')
				printf("\nYOU WIN!!!");
			else
				printf("\nCOMP WINS");
			return 1;
		}
	}
	if((tic[0][0]==tic[1][1])&&(tic[0][0]==tic[2][2])) {
		if(tic[0][0]=='X')
			printf("\nYOU WIN!!!");
		else
			printf("\nCOMP WINS");
		return 1;
	}
	if((tic[0][2]==tic[1][1])&&(tic[0][2]==tic[2][0])) {
		if(tic[0][2]=='X')
			printf("\nYOU WIN!!!");
		else
			printf("\nCOMP WINS");
		return 1;
	}
	return 0;
}
void display(char tic[][3])
{
	int i,j,k;
	printf("   *****************\n");
	printf("   ");
	printf("   TIC TAC TOE");
	printf("\n   *****************\n\n");
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			for(k=0; k<3; k++)
				printf(" ");
			printf("%c",tic[i][j]);
			for(k=0; k<3; k++)
				printf(" ");
			if(j!=2)
				printf("|");
		}
		if(i!=2)
			printf("\n\n   -----------------\n");
		printf("\n");
	}
}
