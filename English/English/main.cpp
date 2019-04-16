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
	string ukrText[M]={"вiдмовлятися", "заявляти", "визначення", "точний", "вимога", "кiлькiсть", "дослiджувати", "джерело", "поточний", "оцiнюати", "особливий", "вибирати", "цiлий/повний", "потерпати невдачу", "незначний/тонкий", "негайно", "цiна", "контур/електричне коло", "повертати/вiдновлювати", "вiд початку", "чистий", "точний/вибагливий", "припускати", "пастка", "набiр", "обмежувати", "шлях/дорiжка", "розслiдувати", "нещасний випадок", "охочий", "доводити"};
	string userEntered;
	char answer;
	int randNum, counter=0, words[M]={0};
	srand(time(0));
	while(true)
	{
		cout << "Запам\'ятайте поданi нижче слова. Коли будете готовi - натиснiть Enter." << endl;
		cout << "База слiв:" << endl;
		for(int i=0; i<M; i++)
			cout << i+1 << ") " << engText[i] << " - " << ukrText[i] << endl;
		getch();
		system("cls");
		
		for(int i=0; i<M; i++)
		{
			randNum=rand()%31;
			if(words[randNum]==0) words[randNum]=1; else {i--; continue;}
			cout << "Введiть слово на англiйськiй мовi.\n" << ukrText[randNum] << endl;
			getline(cin, userEntered);
			if(userEntered==engText[randNum]) {cout << "Правильно." << endl; counter++;}
			else cout << "Неправильно, правильне слово: " << engText[randNum] << endl;
			getch();
			system("cls");
		}
		cout << "Ви написали правильно слiв: "<< counter << "/" << M;
		cout << "\nПочати спочатку?(y/n)";
		answer=getch();
		if(answer=='n') return 0;
		counter=0;
		for(int i=0; i<M; i++) words[i]=0;
		system("cls");
	}
}