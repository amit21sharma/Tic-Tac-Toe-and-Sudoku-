#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void check_row(int);
void check_column(int);
void check_cell(int,int);
void display();
int possible[9];
int sudoku[9][9];
int q;
int solve();
int main()
{
	srand ( time(NULL) );
	int i,j,count=1,precount;
	FILE *fp;
	fp=fopen("D:\\sudoku.txt","r+");
	for(i=0; i<9; i++)
		for(j=0; j<9; j++) {
			sudoku[i][j]=fgetc(fp)-'0';
		}
	display();
	while(count) {
		precount=count;
		count=0;
		for(i=0; i<9; i++)
			for(j=0; j<9; j++)
				if(sudoku[i][j]==0)
					++count;
			solve();
	}
	display();
	return 0;
}
void display()
{
	int i,j;
	printf("+--------------------------------+\n\n");
	for(i=0; i<9; i++) {
		printf("| ");
		for(j=0; j<9; j++) {
			if(j%3==0 && j!=0)
				printf("| ");
			printf("%d  ",sudoku[i][j]);
			if(j==8)
				printf("| ");
		}
		if((i+1)%3==0)
			printf("\n\n+--------------------------------+");
		printf("\n\n");
	}
}
void check_row(int i)
{
	for(int j=0; j<9; j++) {
		if(sudoku[i][j]!=0)
			possible[sudoku[i][j]-1]=0;
	}
}
void check_column(int j)
{
	for(int i=0; i<9; i++) {
		if(sudoku[i][j]!=0)
			possible[sudoku[i][j]-1]=0;
	}
}
void check_cell(int i,int j)
{
	int k,l;
	i=i/3;
	j=j/3;
	for(k=i*3; k<(i*3)+3; k++)
		for(l=j*3; l<(j*3)+3; l++)
			if(sudoku[k][l]!=0) {
				possible[sudoku[k][l]-1]=0;
			}
}
int solve()
{
	int i,j,k,cnt,ipossible[9],count=0;
	for(i=0; i<9; i++)
		for(j=0; j<9; j++)
			if(sudoku[i][j]==0) {
				count++;
				break;
			}
	if(count==0) {
		return 0;
	}
	for(k=1; k<=9; k++)
		possible[k-1]=k;
	for(i=0; i<9; i++)
		for(j=0; j<9; j++)
			if(sudoku[i][j]==0) {
				check_row(i);
				check_column(j);
				check_cell(i,j);
				for(k=0; k<9; k++)
					ipossible[k]=possible[k];
				cnt=0;
				for(k=0; k<9; k++) {
					if(ipossible[k]!=0) {
						cnt++;
						sudoku[i][j]=ipossible[k];
						if(solve()==0) {
							return 0;
						}
					}
				}
				sudoku[i][j]=0;
				if(!cnt) {
					return 1;
				}
			}
}