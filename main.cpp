#include "func.h"
#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu();
void menuTampil();
void menuTambah();
void menuHapus();
void menuTampilLanjut();
void initialize();

int main()
{
//	initialize();
	while(1) menu();
	
	return 0;
}

void menu()
{
// menu
	system("cls");
	cout << "Menu Utama." << endl
		 << endl
		 << "1. Tampilkan Shape" << endl
		 << "2. Tambah Shape" << endl
		 << "3. Hapus Shape" << endl
		 << "4. Exit" << endl
		 << endl
		 << "Pilihan anda: ";

//pilihan
	int x = pilih(4, 14,7);

// pilihan yang muncul
	if(x == 1)
	{
		menuTampil();
	}
	else if(x == 2)
	{
		menuTambah();
	}
	else if(x == 3)
	{
		menuHapus();
	}
	else if(x == 4)
	{
		exit(0);
	}
}

void menuTampil()
{
// menu
	system("cls");
	cout << "Menu Tampilkan Shape" << endl
		 << endl
		 << "1. Tampilkan Semua Shape" << endl
		 << "2. Tampilkan Circle" << endl
		 << "3. Tampilkan Square" << endl
		 << "4. Tampilkan Rectangle" << endl
		 << "5. Kembali ke Menu Utama" << endl
		 << endl
		 << "Pilihan Anda: ";

//pilihan	
	int x = pilih(5, 14, 8);

//pilihan yang muncul
	if(x == 1)
	{
		
	}
	else if(x == 2)
	{
		
	}
	else if(x == 3)
	{
		
	}
	else if(x == 4)
	{
		
	}
	else if(x == 5)
	{
		return;	
	}
}

void menuTambah()
{
//menu
	system("cls")
	cout << "Menu Tambah Shape" << endl
		 << endl
		 << "1. Tambah Circle" << endl
		 << "2. Tambah Square" << endl
		 << "3. Tambah Rectangle" << endl
		 << "4. Kembali ke Menu Utama" << endl
		 << endl
		 << "Pilihan Anda: ";
	int x = pilih(4, 14, 7);

// pilihan yang muncul
	if(x == 1)
	{
		
	}
	else if(x == 2)
	{
		
	}
	else if(x == 3)
	{
		
	}
	else if(x == 4)
	{
		return;
	}
}

void menuHapus()
{
//menu
	system("cls")
	cout << "Menu delete Shape" << endl
		 << endl
		 << "1. Delete Circle" << endl
		 << "2. Delete Square" << endl
		 << "3. Delete Rectangle" << endl
		 << "4. Kembali ke Menu Utama" << endl
		 << endl
		 << "Pilihan Anda: ";
	int x = pilih(4, 14, 7);

// pilihan yang muncul
	if(x == 1)
	{
		
	}
	else if(x == 2)
	{
		
	}
	else if(x == 3)
	{
		
	}
	else if(x == 4)
	{
		return;
	}
}
void menuTampilLanjut(int x)
{
	//menu
	system("cls");
	if(x == 1) cout << "Menu Tambah Circle" << endl;
	else if(x == 2) cout << "Menu Tambah Square" << endl;
	else if(x == 3) cout << "Menu Tambah Rectangle" << endl;
	cout << endl
		 << "1. Tambah Circle" << endl
		 << "2. Tambah Square" << endl
		 << "3. Tambah Rectangle" << endl
		 << "4. Kembali ke Menu Utama" << endl
		 << endl
		 << "Pilihan Anda: ";
	int x = pilih(4, 14, 7);

}
