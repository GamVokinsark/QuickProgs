#include <iostream>
#include <conio.h>
#include <clocale>
#include <Windows.h>
#include <ctime>
#include <string>
#define M 31
using namespace std;

int main()
{	
	setlocale(LC_CTYPE, "rus");
	string engText[M]={"to give up", "to state", "definition", "exact", "requirement", "amount", "to explore", "source", "current", "to evaluate", "particular", "to choose", "entire", "to fail", "slim", "right away", "price", "circuit", "to retrieve", "from scratch", "pure", "strict", "to guess", "trap", "set", "to restrict", "path", "to investigate", "accident", "willing", "to prove"};
	string ukrText[M]={"�i����������", "��������", "����������", "������", "������", "�i���i���", "����i�������", "�������", "��������", "��i�����", "���������", "��������", "�i���/������", "��������� �������", "���������/������", "�������", "�i��", "������/���������� ����", "���������/�i����������", "�i� �������", "������", "������/����������", "����������", "������", "���i�", "����������", "����/���i���", "�����i������", "�������� �������", "������", "��������"};
	string userEntered;
	char answer;
	int randNum, counter=0, words[M]={0};
	srand(time(0));
	while(true)
	{
		cout << "�����\'������ �����i ����� �����. ���� ������ �����i - ������i�� Enter." << endl;
		cout << "���� ��i�:" << endl;
		for(int i=0; i<M; i++)
			cout << i+1 << ") " << engText[i] << " - " << ukrText[i] << endl;
		getch();
		system("cls");
		
		for(int i=0; i<M; i++)
		{
			randNum=rand()%31;
			if(words[randNum]==0) words[randNum]=1; else {i--; continue;}
			cout << "����i�� ����� �� ����i����i� ���i.\n" << ukrText[randNum] << endl;
			getline(cin, userEntered);
			if(userEntered==engText[randNum]) {cout << "���������." << endl; counter++;}
			else cout << "�����������, ��������� �����: " << engText[randNum] << endl;
			getch();
			system("cls");
		}
		cout << "�� �������� ��������� ��i�: "<< counter << "/" << M;
		cout << "\n������ ��������?(y/n)";
		answer=getch();
		if(answer=='n') return 0;
		counter=0;
		for(int i=0; i<M; i++) words[i]=0;
		system("cls");
	}
}