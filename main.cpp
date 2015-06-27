#include "func.h"
#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu();
int menuTampil();
int menuTambah();
int menuHapus();
int menuTampilLanjut(int);
void initialize();
void hapus(int);

list<shape> myshape;
list<circle> mycircle;
list<rectangle> myrect;
list<square> mysquare;
shape Shape;
int main()
{
	initialize();
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
		while(menuTampil() != 1);
	}
	else if(x == 2)
	{
		while(menuTambah() != 1);
	}
	else if(x == 3)
	{
		while(menuHapus() != 1);
	}
	else if(x == 4)
	{
		exit(0);
	}
}

int menuTampil()
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
	if(x == 5)
	{
		return 1;	
	}
	else
	{
		int n;
		while (menuTampilLanjut(x-1) != 1);
	}
	return 0;
}

int menuTambah()
{
//menu
	system("cls");
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
		return 1;
	}
	
	return 0;
}

int menuHapus()
{
//menu
	system("cls");
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
	if(x == 4)
	{
		return 1;
	}
	else hapus(x);
	return 0;
}

int menuTampilLanjut(int x)
{
	//menu
	system("cls");
	if (x == 0) cout << "Menu Tampilkan Semua Shape" << endl;
	else if(x == 1) cout << "Menu Tampilkan Circle" << endl;
	else if(x == 2) cout << "Menu Tampilkan Square" << endl;
	else if(x == 3) cout << "Menu Tampilkan Rectangle" << endl;
	
	cout << endl
		 << "1. Urutkan Berdasarkan Luas" << endl
		 << "2. Urutkan Berdasarkan Keliling" << endl
		 << "3. Kembali ke Menu Tampilkan Shape" << endl
		 << endl
		 << "Pilihan Anda: ";
	int y = pilih(3, 14, 6);
	if(y == 1){}
	else if(y == 2){}
	else if(y == 3) return 1;
	return 0;
}

void initialize()
{
	ifstream file;

//input circle
	file.open("circle.txt");
	while(!file.eof())
	{
		circle *temp = new circle;
		int x;
		file >> x;
		if (x == 0) break;
		temp->setValue(x);
		mycircle.push_back(*temp);
		myshape.push_back(*temp);
		delete temp;
	}
	file.close();
	
//input square
	file.open("square.txt");
	while(!file.eof())
	{
		square *temp = new square;
		int x;
		file >> x;
		if (x == 0) break;
		temp->setValue(x);
		mysquare.push_back(*temp);
		myshape.push_back(*temp);
		delete temp;
	}
	file.close();
	
//input rectangle
	file.open("rectangle.txt");
	while(!file.eof())
	{
		rectangle *temp = new rectangle;
		int x, y;
		file >> x >> y;
		if (x == 0) break;
		temp->setValue(x, y);
		myrect.push_back(*temp);
		myshape.push_back(*temp);
		delete temp;
	}
	file.close();

//sorting	
	Shape.mode(1);
	mycircle.sort();
	myrect.sort();
	mysquare.sort();
	myshape.sort();
}

void hapus(int mode)
{
	fstream file;
	int x,y,tempx,tempy;
	system("cls");
	bool found = false;

//menu per mode
	if(mode == 1)
	{
		circle *temp = new circle;
		cout << "Menu Hapus Circle" <<endl
			 << endl
			 << "Masukan Jari-jari: ";
		x = inputInt(19, 2);
		file.open("circle.txt", fstream::in);
	}
	else if(mode == 2)
	{
		square *temp = new square;
		cout << "Menu Hapus Square" <<endl
			 << endl
			 << "Masukan Sisi: ";
		x = inputInt(14, 2);
		file.open("square.txt", fstream::in);
	}
	else if(mode == 3)
	{
		rectangle *temp = new rectangle;
		cout << "Menu Hapus Rectangle" <<endl
			 << endl
			 << "Masukan Panjang: ";
		x = inputInt(17, 2);
		cout << endl 
			 << "Masukan Lebar: ";
		y = inputInt(15, 3);
		file.open("rectangle.txt", fstream::in);
	}
//baca dari file
	while(!file.eof())
	{
		file >> tempx;
//kalo file abis dengan enter
		if(tempx == 0) break;
		if(mode == 3) file >> tempy;
		if(x == tempx && mode != 3 && found == false)
		{
			file.close();
			cout << endl
				 << "Data ditemukan." << endl;
			if(mode == 1)cout << "Jari-jari: " << x <<endl;
			if(mode == 2)cout << "Sisi: " << x << endl;
			cout << "Yakin Akan Dihapus?(Y/N) ";
			int n = pilihYN(25, 5);
			if (n == 1)
			{
				if (mode == 1){
					circle *temp = new circle;
					circle *temp1 = new circle[mycircle.size()];
					int m = 0;
					temp->setValue(x);
					myshape.remove(*temp);
					mycircle.remove(*temp);
					file.open("circle.txt", fstream::out | fstream::trunc);
					for(list<circle>::iterator it = mycircle.begin(); it!=mycircle.end(); it++)
					{
						temp[m] = *it;
						file << temp1[m].getW() << '\t' << temp1[m].getH() << endl;
						m++;
					}
					return;
				}
				if (mode == 2){
					square *temp = new square;
					temp->setValue(x);
					myshape.remove(*temp);
				}
				
				
					
				
//				if (mode == 2) mysquare.remove(temp);
//				delete temp;
			}
			else if(n == 2)
			{
				cout << "Hapus data dibatalkan." << endl
					 << endl
					 << "Ketik apa saja untuk kembali";
				getch(); return;
			}
		}
	}
	
}
