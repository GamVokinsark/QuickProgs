#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <clocale>
#pragma comment(lib,"Winmm.lib")
#define W 200
#define H 10

FILE *p;
char location[H][W+1]= {
	"########################################################################################################################################################################################################",
	"#                                                                                                                                                                      X                     K         #",
	"#                                                                                                                                                                      X                     K         #",
	"#                                                                                                                                                                      X                     K         #",
	"#                                                                                                                                                                      X                     K         #",
	"#                                                                                                                                                                      O                     K         #",
	"#           O        O                 O                   O           O           O                                                   O     O                                               K         #",
	"#         O          X     X       X                     X                X               O       O            O           O              X                 X          X               O     K         #",
	"#A      O       O    X     X  O    X        O O O O      X    O  O   O    X              X      X             X  X             X          X         X       X          X     O     X         K         #",
	"########################################################################################################################################################################################################"
};
class Player
{
private:
	int x;
	int y;
	int cur;
	bool onGround;
	int k;
	int points;
public:
	Player() {x=1; y=H-2; cur=0; onGround=true; k=0; points=0;}
	void checkCur() {if(x>5) cur=x-5;}
	void checkCor() {if(location[y][x]=='K') {system("cls"); printf("Поздравляем! Вы победили и собрали монет: %d\n", points); system("PAUSE"); exit(0);} if (location[y][x]=='O') {points++; PlaySound(L"coin.wav", NULL,SND_ASYNC|SND_FILENAME);} if (location[y][x]=='X') {x=1; y=H-2; cur=0;}}
	void jump() {if(!onGround&&k<4) {y--; k++;} if(location[y+1][x]=='#') {onGround=true; k=0;} if(k==4&&!onGround) y++;}
	void keys() {if(GetAsyncKeyState(87)) {if(onGround) onGround=false;}}
	void allDone() {location[y][x]=' '; keys(); jump(); checkCor(); location[y][x]=' '; x++; checkCor(); checkCur(); location[y][x]='A';}
	int getCur() {return cur;}
	int getPoints() {return points;}
};

int main()
{
	setlocale(LC_CTYPE, "rus");
	p=fopen("coin.wav","rb");
	if(!p) {MessageBox(NULL,L"Отсутствует файл сoin.wav!",L"Ошибка", MB_OK); return 0;}
	fclose(p);
	Player player;
	//PlaySound(L"underground.wav", NULL, SND_ASYNC|SND_FILENAME);
	while(true)
	{
		printf("          МОНЕТЫ: %d\n", player.getPoints());
		for(int i=0; i<H; i++)
		{
			for(int j=player.getCur(); j<player.getCur()+18; j++)
				printf("%c", location[i][j]);
			puts("");
		}
		player.allDone();
		Sleep(70);
		system("cls");
	}
}