#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#define N 11
#define M 160
#pragma comment(lib,"Winmm.lib")

char map[N][M+1]={
"################################################################################################################################################################",
"#                                                                                                                                                              #",
"#                                                                                                                                                              #",
"#                  LET'S DO IT!                                                                                                                                #",
"#                                                                                                 ###                       #                                  #",
"###                                                          ##         #####                                      #               ##                          #",
"#                                                  ###   #                                    #         #               #                                      #",
"#                                                                  #               #######                   #                            #                    #",
"#          ########       ###################                                                                                                   #              #",
"#      ##### DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD   K      #",
"################################################################################################################################################################",
};
int xCor(1), yCor(N-2), k(0), input, lux(0), ex(0);
bool onGround(true);

void jump(void)
{
	if(map[yCor-1][xCor]=='#') k=4; // проверка на потолок
	map[yCor][xCor]=' ';
	if(k<4) yCor-=1; // прыжок
	else if(map[yCor+1][xCor]!='#') {yCor+=1; if (map[yCor][xCor]=='D') {yCor=N-2; xCor=1; lux=0; printf("\a");} else if (map[yCor][xCor]=='K') {system("cls"); printf("You won!\a\a"); getch(); ex=true;}}    // падаем
	if (map[yCor][xCor]=='D') {yCor=N-2; xCor=1; lux=0; printf("\a");}
	else if (map[yCor][xCor]=='K') {system("cls"); printf("You won!\a\a"); getch(); ex=true;}
	if(map[yCor+1][xCor]=='#') {k=0; onGround=true; return;} // пока не приземлимся
	k++;
}
void move(void)
{
		if(GetAsyncKeyState(87)) {if (onGround) {onGround=false;} /*if (map[yCor][xCor]=='D') {yCor=N-2; xCor=1; lux=0; printf("\a");} else if (map[yCor][xCor]=='K') {system("cls"); printf("You won!\a\a"); getch(); ex=true;}*/}
		if(GetAsyncKeyState(65)) {if (xCor>1&&map[yCor][xCor-1]!='#') {map[yCor][xCor]=' '; xCor--;} if (map[yCor][xCor]=='D') {yCor=N-2; xCor=1; lux=0; printf("\a");} else if (map[yCor][xCor]=='K') {system("cls"); printf("You won!\a\a"); getch(); ex=true;}}
		if(GetAsyncKeyState(68)) {if (xCor<M-2&&map[yCor][xCor+1]!='#') {map[yCor][xCor]=' '; xCor++;} if (map[yCor][xCor]=='D') {yCor=N-2; xCor=1; lux=0; printf("\a");} else if (map[yCor][xCor]=='K') {system("cls"); printf("You won!\a\a"); getch(); ex=true;}}
		if(GetAsyncKeyState(82)) {map[yCor][xCor]=' '; yCor=N-2; xCor=1; lux=0;} // рестарт		
}

void checkPos(void)
{
	if(xCor>lux+6&&xCor+8<M-1) lux=xCor-7;
	else if(xCor<lux+6&&xCor-4>0) lux=xCor-5;
}
int main()
{
	int svag=0;
	PlaySound(L"7.wav", NULL, SND_FILENAME|SND_ASYNC);
	while(true)
	{
		for(int i=-1; i<=N; i++) //рисуем таблицу
		{
			for(int j=lux-1; j<=lux+17; j++)
			{
				if (i==yCor&&j==xCor) map[i][j]='A';
				if (i==-1||i==N) printf("-");
				else if (j==lux-1||j==lux+17) printf("-");
				else printf("%c", map[i][j]);
			}
			printf("\n");
		}
		if(svag==800) { svag=0; PlaySound(L"7.wav", NULL, SND_FILENAME|SND_ASYNC);}
		if (onGround&&map[yCor+1][xCor]==' ') {onGround=false; k=4;} // если под ногами резко пропал пол
		if (kbhit()) move();
		if (!onGround) jump(); // если в воздухе
		checkPos();
		if (ex) return 0;
		printf("%d,%d", xCor, yCor);
		Sleep(70);
		svag++;
		system("cls");
	}
}