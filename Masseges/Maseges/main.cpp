#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <Windows.h>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	setlocale(LC_CTYPE, "rus");
	int n=0;
	while(n!=6)
	{
		n = MessageBox(NULL, L"Привет! Я Вирус.ехе\nПриятно познакомится.\nТы мне рад?", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
		if(n==7) 
		{
			MessageBox(NULL, L"Думаю, тебе лучше поменять свое мнение о мне...", L"Вирус.ехе", MB_OK | MB_ICONINFORMATION);
			for(int i=0; i<20; i++)
				system("start explorer");
			Sleep(5000);
		}
	}
	n = MessageBox(NULL, L"Хорошо =)\nПолагаю, мы можем с тобой подружится.\nМожно я буду жить на твоем компьютере?", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
	if(n==7)
	{
		n = MessageBox(NULL, L"Уверен? Я ведь могу твои файлы поудалять =)", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
		if(n==6)
		{
			MessageBox(NULL, L"Сам напросился XD", L"Вирус.ехе", MB_OK | MB_ICONINFORMATION);
			MessageBox(NULL, L"5 файлов было удалено с C:\\Windоws\\Systеm32", L"Вирус.ехе", MB_OK | MB_ICONWARNING);
			n = MessageBox(NULL, L"Теперь позволишь мне жить на твоем компьютере?", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
			if (n==7) 
			{
				MessageBox(NULL, L"Тогда я выключу твой компьютер.", L"Вирус.ехе", MB_OK | MB_ICONINFORMATION);
				system("shutdown -r -t 100 -c \"Ваш компьютер перезапустится через 100 секунд. Пожалуйста, завершите работу всех програм и дождитель перезагрузки.\"");
				Sleep(20000);
				system("shutdown -a");
				n = MessageBox(NULL, L"Видишь? Я добрый. Так ты разрешишь мне жить на твоем компьютере?", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
				if(n==7) 
				{
					MessageBox(NULL, L"Ну а теперь я разозлился.", L"Вирус.ехе", MB_OK | MB_ICONINFORMATION);
					system("shutdown -r -t 2");
					return 0;
				}
			}
		}
	}
	//taskkill /F /IM explorer.exe
	//start explorer.exe
	MessageBox(NULL, L"Круто! =)\nПриветствую мой дорогой соседушка)", L"Вирус.ехе", MB_OK | MB_ICONINFORMATION);
	n = MessageBox(NULL, L"Хочешь видюшку одну посмотреть?", L"Вирус.ехе", MB_YESNO | MB_ICONINFORMATION);
	if(n==6) system("start https://www.youtube.com/watch?v=PK2dpARDwm8");
	Sleep(10000);
	/*FILE *p;
	p=fopen("C:\\dat.txt","w");
	fputs("@echo off\nstart explorer\nstart explorer\nstart explorer\nstart explorer\nstart explorer\nexit", p);
	fclose(p);
	system("ren C:\\dat.txt dat.bat");
	system("start C:\\dat.bat");
	Sleep(50);
	system("del C:\\dat.bat");
	//  */
	return 0;
}