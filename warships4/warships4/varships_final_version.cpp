// by Vokinsark
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <clocale>
#define HEAD "-�������--���--v1.3.4----------------------------------------------------|-|0|X|"
using namespace std;
#pragma comment(lib,"Winmm.lib")

int numberOfShips(5),
    flag(0),
    counterFP(0),
    counterDeadShipsFP(0),
	counterSP(0),
	counterDeadShipsSP(0),
	difficult(1),
	variant(0),
	n(5),
	fpx(0),
	fpy(0),
	spx(0),
	spy(0),
	number1, 
	order, 
	firstRandNumber, 
	secondRandNumber, 
	numberOfShots;
char number2,
	 *firstPointer,
	 *secondPointer,
     *firstPositions,
     *secondPositions,
     *firstArrayPositions,
	 *secondArrayPositions,
	 *playerPositions,
	 *computerPositions,
	 *arrayPlayerPositions,
	 *arrayComputerPositions;

void firstPlayerEntersCoordinatesShips(void)
{

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(firstPositions+i*n+j)='0';   //firstPositions[i][j]='0';
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(secondPositions+i*n+j)='0';
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(firstArrayPositions+i*n+j)='?';		
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(secondArrayPositions+i*n+j)='?';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if (i==0&&j==0) *(firstPointer+n*i+j)='>';
			else *(firstPointer+n*i+j)=' ';
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if (i==0&&j==0) *(secondPointer+n*i+j)='>';
			else *(secondPointer+n*i+j)=' ';
		}

	counterFP=0;
	while(true)
	{	
		cout << HEAD << endl;
		cout << "������ ����� ������ ���� �������." << endl << endl;
		for(int i=0; i<=n; i++) cout << i << " "; cout << "       �������� ��������: " << numberOfShips-counterFP << endl;
		for(int i=0; i<n; i++)
		{
			cout << char('a'+i);
			for(int j=0; j<n; j++)
			cout << *(firstPointer+i*n+j) << *(firstPositions+i*n+j);
			cout << endl;
		}
		if (counterFP==numberOfShips) {cout << "������� ������� ������. ������� ����� ������� ��� ����������� . . ."; getch(); system("cls"); break;}

		number2=getch();
		*(firstPointer+fpy*n+fpx)=' ';
		switch(number2)
		{
			case 'w': {if(fpy>0) fpy--; break;}
			case 'a': {if(fpx>0) fpx--; break;}
			case 's': {if(fpy<n-1) fpy++; break;}
			case 'd': {if(fpx<n-1) fpx++; break;}
			case 13: {if(*(firstPositions+n*fpy+fpx)!='X') {*(firstPositions+n*fpy+fpx)='X'; flag=1;} break;}
		}
		*(firstPointer+fpy*n+fpx)='>';
		system("cls");

		if (flag == 1) {flag = 0; counterFP++;}
	}
}
void secondPlayerEntersCoordinatesShips(void)
{
	counterSP=0;
	while(true)
	{	
		cout << HEAD << endl;
		cout << "������ ����� ������ ���� �������." << endl << endl;
		for(int i=0; i<=n; i++) cout << i << " "; cout << "       �������� ��������: " << numberOfShips-counterSP << endl;
		for(int i=0; i<n; i++)
		{
			cout << char('a'+i);
			for(int j=0; j<n; j++)
			cout << *(secondPointer+i*n+j) << *(secondPositions+n*i+j);
			cout << endl;
		}
		if (counterSP==numberOfShips) {cout << "����� ����. ������� ����� ������� ��� ����������� . . ."; getch(); system("cls"); break;}
		
		number2=getch();
		*(secondPointer+spy*n+spx)=' ';
		switch(number2)
		{
			case 'w': {if(spy>0) spy--; break;}
			case 'a': {if(spx>0) spx--; break;}
			case 's': {if(spy<n-1) spy++; break;}
			case 'd': {if(spx<n-1) spx++; break;}
			case 13: {if(*(secondPositions+n*spy+spx)!='X') {*(secondPositions+n*spy+spx)='X'; flag=1;} break;}
		}
		*(secondPointer+spy*n+spx)='>';
		system("cls");

		if (flag == 1) {flag = 0; counterSP++;}
	}
}
void gameInOrder(void)
{
	order=1;
	while(true)
	{
		if (counterDeadShipsSP==numberOfShips) {cout << HEAD << endl; cout << "�����������! ������ ����� �������!" << endl << "������� ����� ������� ��� �����������..."; getch(); break;}
		if (counterDeadShipsFP==numberOfShips) {cout << HEAD << endl; cout << "�����������! ������ ����� �������!" << endl << "������� ����� ������� ��� �����������..."; getch(); break;}
		cout << HEAD << endl;;
		cout << "   ������ ����� " << counterDeadShipsSP << "                                   " << "������ ����� " << counterDeadShipsFP << endl;
		cout << "         ";
		for(int i=0; i<=n; i++) cout << i << " "; 
		for(int i=1; i<=27-2*n; i++) cout << " "; cout << "||"; for(int i=1; i<=28-2*n; i++) cout << " ";
		for(int i=0; i<=n; i++) cout << i << " ";
		cout << endl;
		for(int i=0; i<n; i++)
		{
			cout << "         ";
			cout << char('a'+i);
			for(int j=0; j<n; j++)
			{if(order==1) cout << *(firstPointer+i*n+j); else cout << " "; cout << *(secondArrayPositions+n*i+j);}
			for(int j=1; j<=28-2*n; j++) cout << " "; cout << "||"; for(int j=1; j<=28-2*n; j++) cout << " ";
			cout << char('a'+i);
			for(int j=0; j<n; j++)
			{if(order==2) cout << *(secondPointer+i*n+j); else cout << " "; cout << *(firstArrayPositions+n*i+j);}
			cout << endl;
		}
		if (order==1)
		{
			cout << endl << "               ^������ �����^" << endl;
			number2=getch();
			*(firstPointer+fpy*n+fpx)=' ';
			switch(number2)
			{
				case 'w': {if(fpy>0) fpy--; break;}
				case 'a': {if(fpx>0) fpx--; break;}
				case 's': {if(fpy<n-1) fpy++; break;}
				case 'd': {if(fpx<n-1) fpx++; break;}
				case 13: {if(*(secondArrayPositions+n*fpy+fpx)=='?') flag=1; else flag=0; break;}
			}
			*(firstPointer+fpy*n+fpx)='>';

			if (flag==1&&*(secondPositions+n*fpy+fpx)=='X') 
			{
				*(secondArrayPositions+n*fpy+fpx)='X';
				counterDeadShipsSP++;
				cout << "[+] �� ���������� �������." << endl <<" ������� ����� ������� ��� �����������...";
				getch(); 
				flag=0;
			}
			if (flag==1&&*(secondPositions+n*fpy+fpx)=='0') 
			{
				*(secondArrayPositions+n*fpy+fpx)='0';
				order=4;						
				cout << "[-] �� ���������." << endl <<" ������� ����� ������� ��� �����������...";
				getch(); 
				flag=0;
			}
		}
		if (order==2)
		{
			cout << endl << "                                                    ^������ �����^" << endl;
			number2=getch();
			*(secondPointer+spy*n+spx)=' ';
			switch(number2)
			{
				case 'w': {if(spy>0) spy--; break;}
				case 'a': {if(spx>0) spx--; break;}
				case 's': {if(spy<n-1) spy++; break;}
				case 'd': {if(spx<n-1) spx++; break;}
				case 13: {if(*(firstArrayPositions+n*spy+spx)=='?') flag=1; else flag=0; break;}
			}
			*(secondPointer+spy*n+spx)='>';

			if (flag==1&&*(firstPositions+n*spy+spx)=='X') 
			{
				*(firstArrayPositions+n*spy+spx)='X';
				counterDeadShipsFP++;
				cout << "                                    [+] �� ���������� �������." << endl <<"                                     ������� ����� ������� ��� �����������....";
				getch(); 
				flag=0;
			}
			if (flag==1&&*(firstPositions+n*spy+spx)=='0') 
			{
				*(firstArrayPositions+n*spy+spx)='0';
				order=1;						
				cout << "                                    [-] �� ���������." << endl <<"                                     ������� ����� ������� ��� �����������...";
				getch(); 
				flag=0;
			}
		}
		if (order==4) order=2;
		system("cls");	
	}
	flag = 0;
	counterFP = 0;
	counterDeadShipsFP = 0;
	counterSP = 0;
	counterDeadShipsSP = 0;
	fpy=0;
	fpx=0;
	spy=0;
	spx=0;
}
void multipleGame(void)
{
	system("cls");

	firstPointer=(char*)calloc(n*n, sizeof(char));
	secondPointer=(char*)calloc(n*n, sizeof(char));
	firstPositions=(char*)calloc(n*n, sizeof(char));
	secondPositions=(char*)calloc(n*n, sizeof(char));
	firstArrayPositions=(char*)calloc(n*n, sizeof(char));
	secondArrayPositions=(char*)calloc(n*n, sizeof(char));

	firstPlayerEntersCoordinatesShips();
	secondPlayerEntersCoordinatesShips();
	gameInOrder();
	
	free(firstPointer);
	free(secondPointer);
	free(firstPositions);
	free(secondPositions);
	free(firstArrayPositions);
	free(secondArrayPositions);
}
void singleGame(void)
{
	system("cls");
	numberOfShots=0;

	firstPointer=(char*)calloc(n*n, sizeof(char));
	playerPositions=(char*)calloc(n*n, sizeof(char));
	computerPositions=(char*)calloc(n*n, sizeof(char));
	arrayPlayerPositions=(char*)calloc(n*n, sizeof(char));
	arrayComputerPositions=(char*)calloc(n*n, sizeof(char));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(playerPositions+n*i+j)='0';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(computerPositions+n*i+j)='0';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(arrayPlayerPositions+n*i+j)='?';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			*(arrayComputerPositions+n*i+j)='?';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if (i==0&&j==0) *(firstPointer+n*i+j)='>';
			else *(firstPointer+n*i+j)=' ';
		}

	for(int i=0; i<numberOfShips; i++)
	{
		firstRandNumber=rand()%n;
		secondRandNumber=rand()%n;
		if (*(computerPositions+n*firstRandNumber+secondRandNumber)=='X') i--;
		*(computerPositions+n*firstRandNumber+secondRandNumber)='X';
	}
	counterFP=0;
	while(true)
	{	
		cout << HEAD << endl;
		cout << "��������� ���� ������." << endl << endl;
		for(int i=0; i<=n; i++) cout << i << " "; cout << "       �������� ��������: " << numberOfShips-counterFP << endl;
		for(int i=0; i<n; i++)
		{
			cout << char('a'+i);
			for(int j=0; j<n; j++)
				cout << *(firstPointer+i*n+j) << *(playerPositions+n*i+j);
			cout << endl;
		}
		if (counterFP==numberOfShips) {cout << "����� ����. ������� ����� ������� ��� ����������� . . ."; getch(); system("cls"); break;}
		
		number2=getch();
		*(firstPointer+fpy*n+fpx)=' ';
		switch(number2)
		{
			case 'w': {if(fpy>0) fpy--; break;}
			case 'a': {if(fpx>0) fpx--; break;}
			case 's': {if(fpy<n-1) fpy++; break;}
			case 'd': {if(fpx<n-1) fpx++; break;}
			case 13: {if(*(playerPositions+n*fpy+fpx)!='X') {*(playerPositions+n*fpy+fpx)='X'; flag=1;} else flag=0; break;}
		}
		*(firstPointer+fpy*n+fpx)='>';
		system("cls");

		if (flag == 1) {flag = 0; counterFP++;}
	}
	order=1;
	counterFP = 0;
	while(true)
	{	
		if (counterDeadShipsSP==numberOfShips) {cout << HEAD << endl; cout << "�����������, �� ��������! �� �������� ��������: " << counterDeadShipsSP << ", ��������� ���: " << numberOfShots <<  endl << "������� ����� ������� ��� �����������. . ."; getch(); system("cls"); break;}
		if (counterDeadShipsFP==numberOfShips) {cout << HEAD << endl; cout << "�� ���������. �� �������� ��������:  " << counterDeadShipsSP << " ��������� ���: " << numberOfShots << endl << "������� ����� ������� ��� �����������. . ."; getch(); system("cls"); break;}
		cout << HEAD << endl;;
		cout << "         ����� " << counterDeadShipsSP << "                          " << "��������� " << counterDeadShipsFP << endl;
		cout << "         ";
		for(int i=0; i<=n; i++) cout << i << " "; 
		for(int i=1; i<=27-2*n; i++) cout << " "; cout << "||"; for(int i=1; i<=28-2*n; i++) cout << " ";
		for(int i=0; i<=n; i++) cout << i << " ";
		cout << endl;
		for(int i=0; i<n; i++)
		{
			cout << "         ";
			cout << char('a'+i);
			for(int j=0; j<n; j++) {if(order==1) cout << *(firstPointer+n*i+j); else cout << " "; cout << *(arrayComputerPositions+n*i+j);}
			for(int j=1; j<=28-2*n; j++) cout << " "; cout << "||"; for(int j=1; j<=28-2*n; j++) cout << " ";
			cout << char('a'+i) << " ";
			for(int j=0; j<n; j++) cout << *(arrayPlayerPositions+n*i+j) << " ";
			cout << endl;
		}
		if (order==1)
		{
			cout << endl << endl << "        ^�����^" << endl;
			number2=getch();
			*(firstPointer+fpy*n+fpx)=' ';
			switch(number2)
			{
				case 'w': {if(fpy>0) fpy--; break;}
				case 'a': {if(fpx>0) fpx--; break;}
				case 's': {if(fpy<n-1) fpy++; break;}
				case 'd': {if(fpx<n-1) fpx++; break;}
				case 13: {if(*(arrayComputerPositions+n*fpy+fpx)=='?') flag=1; else flag=0; break;}
			}
			*(firstPointer+fpy*n+fpx)='>';

			if (flag==1&&*(computerPositions+n*fpy+fpx)=='X') 
			{
				*(arrayComputerPositions+n*fpy+fpx)='X';
				counterDeadShipsSP++;
				numberOfShots++;
				cout << "[+] �� �������� �������." << endl <<" ������� ����� ������� ��� �����������...";
				getch(); 
				flag=0;
			}
			if (flag==1&&*(computerPositions+n*fpy+fpx)=='0') 
			{
				*(arrayComputerPositions+n*fpy+fpx)='0';
				order=4;		
				numberOfShots++;				
				cout << "[-] �� ���������. ������� ����������." << endl <<" ������� ����� ������� ��� �����������...";
				getch(); 
				flag=0;
			}
		}
		if (order==2)
		{
			cout << endl << endl << "                                       " << "        ^���������^" << endl;
			firstRandNumber=rand()%100+1;

			if (difficult==1&&firstRandNumber<=5) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='X'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } }
			else { if (difficult==1&&firstRandNumber>5) { if (numberOfShips-counterDeadShipsFP<n*n-counterFP) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='0'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } } else {  while(true) { number1=rand()%n; number2=rand()%n; if (*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } }
			
			if (difficult==2&&firstRandNumber<=50) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='X'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } }
			else { if (difficult==2&&firstRandNumber>50) { if (numberOfShips-counterDeadShipsFP<n*n-counterFP) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='0'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } } else {  while(true) { number1=rand()%n; number2=rand()%n; if (*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } }
			
			if (difficult==3&&firstRandNumber<=80) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='X'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } }
			else { if (difficult==3&&firstRandNumber>80) { if (numberOfShips-counterDeadShipsFP<n*n-counterFP) { while(true) { number1=rand()%n; number2=rand()%n; if (*(playerPositions+n*number2+number1)=='0'&&*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } } else {  while(true) { number1=rand()%n; number2=rand()%n; if (*(arrayPlayerPositions+n*number2+number1)=='?') { flag=1; break; } } } }

			if (flag==1&&*(playerPositions+n*number2+number1)=='X') 
			{
				*(arrayPlayerPositions+n*number2+number1)='X';
				counterDeadShipsFP++;
				counterFP++;
				cout << "                                    [!] ��������� ������� ��� �������." << endl <<"                                     ������� ����� ������� ��� �����������...";
				getch();
				flag=0;
			}
			if (flag==1&&*(playerPositions+n*number2+number1)=='0') 
			{
				*(arrayPlayerPositions+n*number2+number1)='0';
				order=1;			
				counterFP++;			
				cout << "                                    [0] ��������� ��������. ������� ������." << endl <<"                                     ������� ����� ������� ��� �����������...";
				getch();
				flag=0;
			}
		}
		if (order==4) order=2;
		system("cls");	
	}
	fpx=0;
	fpy=0;
	spx=0;
	spy=0;
	flag = 0;
	counterFP = 0;
	counterSP = 0;
	counterDeadShipsFP = 0;
	counterDeadShipsSP = 0;
	free(firstPointer);
	free(playerPositions);
	free(computerPositions);
	free(arrayPlayerPositions);
	free(arrayComputerPositions);	
}
int main(void)
{
	PlaySound(L"7.wav", NULL, SND_FILENAME|SND_ASYNC);
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	while(true)
	{
		cout << HEAD << endl;
		switch(flag)
		{
			case 0: {if(variant==0) cout << "  >> "; else cout << "     "; cout << "�����" << endl << endl; if(variant==1) cout << "  >> "; else cout << "     "; cout << "����������" << endl << endl; if(variant==2) cout << "  >> "; else cout << "     "; cout << "���������" << endl << endl; if(variant==3) cout << "  >> "; else cout << "     "; cout << "�����"; number2=getch(); if(number2=='w'&&variant>0) {variant--; break;} else if(number2=='s'&&variant<3) {variant++; break;} else if(number2=='s'&&variant==3) break; else if(number2==13) if (variant==0) flag=1; else if (variant==1) flag=2; else if (variant==2) flag=3; else if (variant==3) flag=4; variant=0; break;}
			case 1: {if(variant==0) cout << "  >> "; else cout << "     "; cout << "��������� ����" << endl << endl; if(variant==1) cout << "  >> "; else cout << "     "; cout << "2 ������" << endl << endl; if(variant==2) cout << "  >> "; else cout << "     "; cout << "�����"; number2=getch(); if(number2=='w'&&variant>0) {variant--; break;} else if(number2=='s'&&variant<2) {variant++; break;} else if(number2=='s'&&variant==2) break; else if(number2==13) if (variant==0) flag=5; else if (variant==1) flag=6; else if (variant==2) flag=0; variant=0; break;}
			case 2: {cout << "����� ���������� � ������� ��� v1.3.4" << endl << "� ���� ���� �� ������ ������� ������������ ��������� ��������." << endl << "������� ������ ������ ���� �������." << endl << "� ����� ��� �������� �������� ���������." << endl << "� ���� ������������ ��������� � 2-������ ������." << endl << "��������� ���, ��� ����� ��� ��������� �������." << endl << "������� ����." << endl << endl << "                  ������� ����� ������� ��� �����������. . ."; flag=0; getch(); break;}
			case 3: {if(variant==0) cout << "  >> "; else cout << "     "; cout << "���������� ��������: "; if(numberOfShips>1) cout << "< "; else cout << "  "; cout << numberOfShips; if(numberOfShips<n*n) cout << " >"; cout << endl << endl; if(variant==1) cout << "  >> "; else cout << "     "; cout << "���� NxN: "; if(n>3) cout << "< "; else cout << "  "; cout << n << "x" << n; if(n<9) cout << " >"; cout << endl << endl; if(variant==2) cout << "  >> "; else cout << "     "; cout << "���������: "; if(difficult>1) cout << "< "; else cout << "  "; if(difficult==1) cout << "�����"; else if(difficult==2) cout << "������"; else if(difficult==3) cout << "������"; if(difficult<3) cout << " >"; cout << endl << endl; if(variant==3) cout << "  >> "; else cout << "     "; cout << "�����"; number2=getch(); if(number2=='w'&&variant>0) {variant--; break;} else if(number2=='s'&&variant<3) {variant++; break;} else if(number2=='s'&&variant==3) break; else if(number2=='a') {if(variant==0&&numberOfShips>1) numberOfShips--; else if(variant==1&&n>3) {n--; if(numberOfShips>n*n) numberOfShips=n*n;} else if(variant==2&&difficult>1) difficult--;} else if(number2=='d') {if(variant==0&&numberOfShips<n*n) numberOfShips++; else if(variant==1&&n<9) n++; else if(variant==2&&difficult<3) difficult++;} else if(number2==13&&variant==3) flag=0; break;}
			case 4: {cout << "�� �������, ��� ������ �����?" << endl << endl; if(variant==0) cout << "  >> "; else cout << "     "; cout << "��" << endl << endl; if(variant==1) cout << "  >> "; else cout << "     "; cout << "���"; number2=getch(); if(number2=='w'&&variant>0) {variant--; break;} else if(number2=='s'&&variant<1) {variant++; break;} else if(number2=='s'&&variant==1) break; else if(number2==13) if (variant==0) return 0; else if (variant==1) flag=0; variant=0; break;}
			case 5: {flag=0; singleGame(); break;}
			case 6: {flag=0; multipleGame(); break;}
			}
		system("cls");
	}
}