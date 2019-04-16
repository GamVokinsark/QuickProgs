#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#include <ctime>
#define M 41
#define N 10
char table[N][M], input;
int lr(4), rr(4), xCor(1), yCor(6), xVec(3), yVec(0), countFP(0), countSP(0);

void clearTable(void)
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if (j==0&&(i==lr||i==lr+1||i==lr+2||i==lr+3||i==lr+4)) table[i][j]='#';
			else if (j==M-1&&(i==rr||i==rr+1||i==rr+2||i==rr+3||i==rr+4)) table[i][j]='#';
			else if (i==yCor&&j==xCor) table[i][j]='@';
			else table[i][j]=' ';
		}
}
void correctCor(void)
{
	if (xCor<=0&&(yCor==lr||yCor==lr+1)) {xVec=(rand()%2+3); yVec=-1;}
	else if (xCor<=0&&yCor==lr+2) {xVec=(rand()%2+3); yVec=0;}
	else if (xCor<=0&&(yCor==lr+3||yCor==lr+4)) {xVec=(rand()%2+3); yVec=1;}
	else if (xCor<=0) {countFP++; printf("\a"); xCor=1; yCor=6; xVec=3; yVec=0; Sleep(100);}
	if (xCor==M-1&&(yCor==rr||yCor==rr+1)) {xVec=(rand()%2+3)*-1; yVec=-1;}
	else if (xCor>=M-1&&yCor==rr+2) {xVec=(rand()%2+3)*-1; yVec=0;}
	else if (xCor>=M-1&&(yCor==rr+3||yCor==rr+4)) {xVec=(rand()%2+3)*-1; yVec=1;}
	else if (xCor>=M-1) {countSP++; printf("\a"); xCor=M-2; yCor=6; xVec=-3; yVec=0; Sleep(100);}
	if (yCor==0||yCor==N-1) yVec*=-1;

	table[yCor][xCor]=' ';
	xCor+=xVec;
	yCor+=yVec;
}
void moving(void)
{
	input=getch();
	switch(input)
	{
		case 'w': {if(lr>0) {table[lr+2][0]=' '; lr--;} break;}
		case 's': {if(lr<N-5) {table[lr][0]=' '; lr++;} break;}
		case 'i': {if(rr>0) {table[rr+2][M-1]=' '; rr--;} break;}
		case 'k': {if(rr<N-5) {table[rr][M-1]=' '; rr++;} break;}
		default: break;
	}
}

int main()
{
	srand(time(0));
	while(true)
	{
		printf("PLAYER1: %d                                  PLAYER2: %d\n", 5-countFP, 5-countSP);
		for(int i=-1; i<N+1; i++)
		{
			for(int j=-1; j<M+1; j++)
			{
				if (i==-1||i==N) printf("$");
				else if (j==-1||j==M) printf("$");
				else printf("%c", table[i][j]);
			}
			printf("\n");
		}
		if(kbhit()) moving();
		correctCor();
		clearTable();
		Sleep(60);
		system("cls");
		if (countFP==5) {printf("First player lose.\n"); getch(); return 0;}
		if (countSP==5) {printf("Second player lose.\n"); getch(); return 0;}
	}
}