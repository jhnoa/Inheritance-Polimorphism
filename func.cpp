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

int pilih(int multichoices, int coordx, int coordy)
{
//char sekarang
	char x = 0;
//char sebelumnya
	char px = 0;

	do {
		gotoxy(coordx,coordy);
//ambil char
		x = getch();
//kalo cocok buang ke layar, balikin cursor
		if (x > '0' && x < ('0' + multichoices + 1))
		{
			cout << x;
			gotoxy(coordx,coordy);
		}
//kalo backspace nol-in
		else if (x == '\b')
		{
			x = 0;
			cout << x;
			gotoxy(coordx,coordy);
		} 
//kalo enter, cek kecocokan x sebelumnya (x yang sekarang == enter)
		else if (x == 13)
		{
			if (px > '0' && px < ('0' + multichoices + 1))
			{
				return (px - '0');
			}
		}
//kalo bukan angka atau enter atau backspace
		else
		{
			x = 0;
			cout << x;
			gotoxy(coordx,coordy);
		}
//x jadiin px
		px = x;
	} while (1);
}

int pilihYN(int coordx, int coordy)
{
//char sekarang
	char x = 0;
//char sebelumnya
	char px = 0;

	do {
//ambil char
		x = getch();
//kalo cocok buang ke layar, balikin cursor
		if (tolower(x) == 'n' || tolower(x) == 'y')
		{
			cout << (char)x;
			gotoxy(coordx,coordy);
		}
//kalo backspace nol-in
		else if (x == '\b')
		{
			x = 0;
			cout << x;
			gotoxy(coordx,coordy);
		} 
//kalo enter, cek kecocokan x sebelumnya (x yang sekarang == enter)
		else if (x == 13)
		{
			if (tolower(px) == 'y')
			{
				return 1;
			}
			else if(tolower(px) == 'n')
			{
				return 0;
			}
		}
//kalo bukan angka atau enter atau backspace
		else
		{
			x = 0;
			cout << x;
			gotoxy(coordx,coordy);
		}
//x jadiin px
		px = x;
	} while (1);
}

int inputInt(int coordx, int coordy)
{
	int a;
	int n = 0;
	do {
		int x = getch();
		if(isdigit(x))
		{
			gotoxy(coordx + n, coordy);
			cout << (char)x;
			n++;
			a = a*10 + x - '0';
		}
		else if(x == '\b' && n > 0)
		{
			a /= 10;
			n--;
			gotoxy(coordx + n, coordy);
			cout << ' ';
			gotoxy(coordx + n, coordy);
		}
		else if(x == 13)
		{
			return a;
		}
	} while(1);
}
