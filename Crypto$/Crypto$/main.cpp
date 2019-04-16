#include <stdio.h>
#include <conio.h>
#include <clocale>
#define MAX_WORD_LENTH 100
#define MAX_KEY_LENTH 70


int reg(char ch) // Возврат столбца\строки в зависимости от регистра буквы
{
	if(ch>='a'&&ch<='z') return ch-'a'; // Если регистр строчной буквы
	else if(ch>='A'&&ch<='Z') return ch-'A'; // Если регистр заглавной буквы
}

int main(void)
{
	setlocale(LC_CTYPE, "rus"); // Русская локализация
	int keyLenth=0, wordLenth=0; // Размеры ключа, входящего слова
	       // массивы входящего, исходящего слов, ключа и временная переменная
	char word[MAX_WORD_LENTH+1]={0}, key[MAX_KEY_LENTH+1]={0}, ch;
	printf("Введите слово: "); // Вывод в консоль
	for(int i=0; i<MAX_WORD_LENTH; i++) // Ввод входящего слова
	{
		ch=getch(); // Берем символ
		if(ch==13) break; // Проверка на Enter
		if(ch==8&&i>0) {i-=2; printf("\b%c\b", ' '); wordLenth--; continue;} // Проверка на Backspace
		if((ch<'A'||ch>'Z')&&(ch<'a'||ch>'z')) {i--; continue;} // Проверка на букву
		printf("%c", ch); // Вывод буквы в консоль
		word[i]=ch; // Запись буквы в массив
		wordLenth++; // Счетчик длины слова
	}
	printf("\n\nВведите ключ: "); // Вывод в консоль
	for(int i=0; i<MAX_KEY_LENTH; i++) // Ввод ключа
	{
		ch=getch(); // Берем символ
		if(ch==13) break; // Проверка на Enter
		if(ch==8&&i>0) {i-=2; printf("\b%c\b", ' '); keyLenth--; continue;} // Проверка на Backspace
		if((ch<'A'||ch>'Z')&&(ch<'a'||ch>'z')) {i--; continue;} // Проверка на букву
		printf("%c", ch); // Вывод буквы в консоль
		key[i]=ch; // Запись буквы в массив
		keyLenth++; // Счетчик длины ключа
	}
	for(int i=0; i<wordLenth; i++) // Кодирование входящего слова
		if(word[i]>='a'&&word[i]<='z') word[i]='a'+(reg(word[i])+reg(key[i%keyLenth]))%26;
		else word[i]='A'+(reg(word[i])+reg(key[i%keyLenth]))%26;
	word[MAX_WORD_LENTH]='\0';
	printf("\n\nКриптограмма: %s", word); // Вывод в консоль
	getch(); // Чтобы консоль не закрылась раньше времени
	return 0;
}