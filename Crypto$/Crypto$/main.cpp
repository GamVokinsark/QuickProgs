#include <stdio.h>
#include <conio.h>
#include <clocale>
#define MAX_WORD_LENTH 100
#define MAX_KEY_LENTH 70


int reg(char ch) // ������� �������\������ � ����������� �� �������� �����
{
	if(ch>='a'&&ch<='z') return ch-'a'; // ���� ������� �������� �����
	else if(ch>='A'&&ch<='Z') return ch-'A'; // ���� ������� ��������� �����
}

int main(void)
{
	setlocale(LC_CTYPE, "rus"); // ������� �����������
	int keyLenth=0, wordLenth=0; // ������� �����, ��������� �����
	       // ������� ���������, ���������� ����, ����� � ��������� ����������
	char word[MAX_WORD_LENTH+1]={0}, key[MAX_KEY_LENTH+1]={0}, ch;
	printf("������� �����: "); // ����� � �������
	for(int i=0; i<MAX_WORD_LENTH; i++) // ���� ��������� �����
	{
		ch=getch(); // ����� ������
		if(ch==13) break; // �������� �� Enter
		if(ch==8&&i>0) {i-=2; printf("\b%c\b", ' '); wordLenth--; continue;} // �������� �� Backspace
		if((ch<'A'||ch>'Z')&&(ch<'a'||ch>'z')) {i--; continue;} // �������� �� �����
		printf("%c", ch); // ����� ����� � �������
		word[i]=ch; // ������ ����� � ������
		wordLenth++; // ������� ����� �����
	}
	printf("\n\n������� ����: "); // ����� � �������
	for(int i=0; i<MAX_KEY_LENTH; i++) // ���� �����
	{
		ch=getch(); // ����� ������
		if(ch==13) break; // �������� �� Enter
		if(ch==8&&i>0) {i-=2; printf("\b%c\b", ' '); keyLenth--; continue;} // �������� �� Backspace
		if((ch<'A'||ch>'Z')&&(ch<'a'||ch>'z')) {i--; continue;} // �������� �� �����
		printf("%c", ch); // ����� ����� � �������
		key[i]=ch; // ������ ����� � ������
		keyLenth++; // ������� ����� �����
	}
	for(int i=0; i<wordLenth; i++) // ����������� ��������� �����
		if(word[i]>='a'&&word[i]<='z') word[i]='a'+(reg(word[i])+reg(key[i%keyLenth]))%26;
		else word[i]='A'+(reg(word[i])+reg(key[i%keyLenth]))%26;
	word[MAX_WORD_LENTH]='\0';
	printf("\n\n������������: %s", word); // ����� � �������
	getch(); // ����� ������� �� ��������� ������ �������
	return 0;
}