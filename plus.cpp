#include<stdio.h>
void check_row(int);
void check_column(int);
void check();
void check_cell(int,int);
void display();
int possible[9];
int sudoku[9][9];
int zero_value[81];
void random();
int main()
{
	int a,i,j,q=0,count=1;
		FILE *fp;
	fp=fopen("D:\\sudoku.txt","r+");
	for(i=0; i<9; i++)
		for(j=0; j<9; j++) {
			sudoku[i][j]=fgetc(fp)-'0';
			
		}
	display();
	/*while(count) {
		count=0;
		for(i=0; i<9; i++)
			for(j=0; j<9; j++)
				if(sudoku[i][j]==0)
					++count;
		check();
	}*/
	for(i=0;i<5000;i++)
		check();
		random();
		
	display();
	return 0;
}
void display()
{
	int i,j,q=0;
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
void check()
{
	int i,j,k,count,c,q;
	for(i=0; i<9; i++) {
		for(j=0; j<9; j++) {
			for(k=1; k<=9; k++)
				possible[k-1]=k;
			if(sudoku[i][j]==0) {
				check_row(i);
				check_column(j);
				check_cell(i,j);
			}
			count=0;
			for(c=0; c<9; c++)
				if(possible[c]!=0) {
					++count;
					q=c;
				}
			if(count==1)
				sudoku[i][j]=possible[q];
		}
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
void random()
{
	int i,j,q=0;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
	if(sudoku[i][j]==0) {
				zero_value[q]=(i)*10+(j);
				++q;
			}
for(i=0;i<q;i++)
	printf("%d ",zero_value[i]);
}