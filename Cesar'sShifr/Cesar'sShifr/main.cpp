#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <stdlib.h>

const char words[]={'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', ' '};
char message[]="�������� ������� ������������� ��� �������������� ����, ������������ ����������� ��������. ����� �����, ������������� �������� ������� ��������� ����������� ������ �� ��������� � �������� ���������. �������� ��������� �������� ��� �������� ����������� ������ ������������ ���������������� � ����������� �������.";
const int messageSize = sizeof message-1;

int reg(char q)
{
	for(int i=0; i<33; i++)
		if(q==words[i]) return i;
	return -1;
}

int ret(int n)
{
	int col=0;
	for(int i=0; i<messageSize; i++)
		if(message[i]==words[n]) col++;
	return col;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	char ch;
	int key=0;
	float wordNum=0;

	for(int i=0; i<messageSize; i++)
		if(reg(message[i])>=0||message[i]==' ') wordNum++;

	printf("��������(%.0f):\n", wordNum);
	puts("�����  �����  �������");
	for(int i=0; i<34; i++)
		printf("%-5c   %-4d  %.5f\n", words[i], ret(i), ret(i)/wordNum);
	getch();
	system("cls");
	printf("%s", message);
	while(true)
	{
		ch=getch();
		system("cls");
		if(ch=='a')
		{
			key++;
			for(int i=0; i<messageSize; i++)
			{
				if(message[i]==' '||message[i]==','||message[i]=='.') continue;
				message[i]=words[(reg(message[i])+32)%33];
				//if(message[i]>='�'&&message[i]<='�') message[i]='�'+(reg(message[i])+31)%32;
			}
		}
		else if(ch=='d')
		{
			key--;
			for(int i=0; i<messageSize; i++)
			{
				if(message[i]==' '||message[i]==','||message[i]=='.') continue;
				message[i]=words[(reg(message[i])+1)%33];
				//if(message[i]>='�'&&message[i]<='�') message[i]='�'+(reg(message[i])+1)%32;
			}
		}
		for(int i=0; i<messageSize; i++)
			printf("%c", message[i]);
		if(key==33||key==-33) key=0;
		printf("\n\n����: %d", key);
	}
	return 0;
}