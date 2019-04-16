#include <stdio.h>
#include <windows.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib")
#define N 10
#define M 20

int x(0), y(0), ox(M/2), oy(N/2);
char map[N][M], input;

int main()
{
	PlaySound(L"7.wav", NULL, SND_ASYNC|SND_FILENAME);
	for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				map[i][j]=' ';
	while(true)
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				if(i==y&&j==x) map[i][j]='A';
				else if(i==oy&&j==ox) map[i][j]='@';
			}
		for(int i=-1; i<=N; i++)
		{
			for(int j=-1; j<=M; j++)
			{
				if(i==-1||i==N) printf("#");
				else if(j==-1||j==M) printf("#");
				else printf("%c", map[i][j]);
			}
			printf("\n");
		}
		map[y][x]=' ';

		if(GetAsyncKeyState(87)) {if(y>0&&(map[y-1][x]=='@'||map[y+1][x]=='@')&&oy>0) {y--; map[oy][ox]=' '; oy--;} else if(y>0&&map[y-1][x]!='@') y--;}
		if(GetAsyncKeyState(65)) {if(x>0&&(map[y][x-1]=='@'||map[y][x+1]=='@')&&ox>0) {x--; map[oy][ox]=' '; ox--;} else if(x>0&&map[y][x-1]!='@') x--;}
		if(GetAsyncKeyState(83)) {if(y<N-1&&(map[y+1][x]=='@'||map[y-1][x]=='@')&&oy<N-1) {y++; map[oy][ox]=' '; oy++;} else if(y<N-1&&map[y+1][x]!='@') y++;}
		if(GetAsyncKeyState(68)) {if(x<M-1&&(map[y][x+1]=='@'||map[y][x-1]=='@')&&ox<M-1) {x++; map[oy][ox]=' '; ox++;} else if(x<M-1&&map[y][x+1]!='@') x++;}
		Sleep(70);
		system("cls");	
	}
	return 0;
}