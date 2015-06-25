#include "func.h"

void put(char * namefile, string x)
{
	FILE * file;
	file = fopen(namefile, "a+");
//	if(file.is_open()) cout << "Open.";
//	else cout << "UnOpened.";
	fseek(file, 0, SEEK_END);
	fprintf(file, "%s\n", x.c_str());
	fclose(file);
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi))
	return -1;
	return result.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi))
	return -1;
	return result.Y;
}
