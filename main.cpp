#include "func.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
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
	if(y == 3) return 1;
	Shape.mode(y);
	// circle
	if(x == 1) {
		system("cls");
		
		mycircle.sort();
		
		if(y == 1) {cout << "Tampilkan Circle Berdasarkan Luas" << endl;}// sort mycircle dengan luas
		else if(y == 2) {cout << "Tampilkan Circle Berdasarkan Keliling" << endl;}// sort circle dengan keliling
			
		list<circle>::iterator p;
		int n = 1;
		
		for(p = mycircle.begin();p != mycircle.end();p++) {
			cout << "circle" << n << endl;
			
			if(y == 1) {
				cout << "Luas = " << p->getArea() << " cm^(2)" << endl;
			}
			else if(y == 2) {
				cout << "Keliling = " << p->getPerimeter()  << " cm" << endl;
			}
			cout << "Jari - jari = " << p->getW() << " cm" << endl << endl;
			n++;
		}
		
		getch();
	}
	// square
	else if(x == 2) {
		if(y == 1) {}// sort mysquare dengan luas
		else if(y == 2) {}// sort square dengan keliling
		
		system("cls");
		
		mysquare.sort();
		
		cout << "square" << endl;
		list<square>::iterator p;
		int n = 1;
		
		for(p = mysquare.begin();p != mysquare.end();p++) {
			cout << "square" << n << endl;
			
			if(y == 1) {
				cout << "Luas = " << p->getArea() << " cm^(2)" << endl;
			}
			else if(y == 2) {
				cout << "Keliling = " << p->getPerimeter()  << " cm" << endl;
			}
			cout << "Sisi = " << p->getW() << " cm" << endl << endl;
			n++;
		}
		
		getch();
	}
	// rect
	else if(x == 3) {
		if(y == 1) {}// sort mysquare dengan luas
		else if(y == 2) {}// sort square dengan keliling
		
		system("cls");
		
		myrect.sort();
		
		cout << "rectangle" << endl;
		list<rectangle>::iterator p;
		int n = 1;
		
		for(p = myrect.begin();p != myrect.end();p++) {
			cout << "rectangle" << n << endl;
			
			if(y == 1) {
				cout << "Luas = " << p->getArea() << " cm^(2)" << endl;
			}
			else if(y == 2) {
		//		cout << "Keliling = " <<  << " cm" << endl;
			}
			cout << "Panjang = " << p->getW() << " cm" << endl
				 << "Lebar   = " << p->getH() << " cm" << endl << endl;
			n++;
		}
		
		getch();
	}
	
	
	return 0;
}

void initialize()
{
	ifstream file;

//input circle
	file.open("circle.txt");
	while(!file.eof())
	{
		int x;
		x = 0;
		circle *temp = new circle;
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
		int x;
		x = 0;
		square *temp = new square;
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
		int x, y;
		x = 0;
		rectangle *temp = new rectangle;
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
//	mycircle.sort();
//	myrect.sort();
//	mysquare.sort();
//	myshape.sort();
//	cout << Shape.mode(0); getch();
}

void hapus(int mode)
{
	fstream file,file1;
	int x,y,tempx,tempy, n = -1;
	system("cls");

//menu per mode
	if(mode == 1)
	{
		cout << "Menu Hapus Circle" <<endl
			 << endl
			 << "Masukan Jari-jari: ";
		x = inputInt(19, 2);
		file.open("circle.txt", fstream::in | fstream::out);
	}
	else if(mode == 2)
	{
		cout << "Menu Hapus Square" <<endl
			 << endl
			 << "Masukan Sisi: ";
		x = inputInt(14, 2);
		file.open("square.txt", fstream::in | fstream::out);
	}
	else if(mode == 3)
	{
		cout << "Menu Hapus Rectangle" <<endl
			 << endl
			 << "Masukan Panjang: ";
		x = inputInt(17, 2);
		cout << endl 
			 << "Masukan Lebar: ";
		y = inputInt(15, 3);
		file.open("rectangle.txt", fstream::in | fstream::out);
	}
//baca dari file
	while(!file.eof())
	{
		file >> tempx;
//kalo file abis dengan enter
		if(tempx == 0) break;
		if(mode == 3) file >> tempy;
		if(x == tempx && mode != 3)
		{
			cout << endl
				 << "Data ditemukan." << endl;
			if(mode == 1)cout << "Jari-jari: " << x <<endl;
			if(mode == 2)cout << "Sisi: " << x << endl;
			cout << "Yakin Akan Dihapus?(Y/N) ";
			n = pilihYN(25, 5);
			gotoxy(0,7);
			break;
		}
		if(x == tempx && y == tempy && mode == 3)
		{
			cout << endl
				 << "Data ditemukan." << endl;
			cout << "Panjang: " << x <<endl;
			cout << "Lebar: " << y << endl;
			cout << "Yakin Akan Dihapus?(Y/N) ";
			n = pilihYN(25, 7);
			gotoxy(0,9);
			break;
		}
	}
	if (n == 1)
	{
		file1.open("temp", fstream::out | fstream::trunc);
		file.seekg(fstream::beg);
		if (mode == 1){
			while(!file.eof())
			{
				tempx = 0;
				file >> tempx;
				if(tempx == x)continue;
				else if(tempx == 0) break;
				else file1 << tempx << endl;
			}
			file.close();
			file1.close();
			remove("circle.txt");
			rename("temp", "circle.txt");
			
		}
		if (mode == 2){
			while(!file.eof())
			{
				tempx = 0;
				file >> tempx;
				if(tempx == x)continue;
				else if(tempx == 0) break;
				else file1 << tempx << endl;
			}
			file.close();
			file1.close();
			remove("square.txt");
			rename("temp", "square.txt");
			
		}
		if (mode == 3){
			while(!file.eof())
			{
				tempx = 0;
				file >> tempx >> tempy;
				if(tempx == x && tempy == y)continue;
				else if(tempx == 0) break;
				else file1 << tempx << '\t' << tempy << endl;
			}
			file.close();
			file1.close();
			remove("rectangle.txt");
			rename("temp", "rectangle.txt");
			
		}
		cout << "Data dihapus.";
		mycircle.clear();
		mysquare.clear();
		myrect.clear();
		myshape.clear();
		initialize();
		getch();return;
	}
	else if(n == 0)
	{
		file.close();
		cout << "Hapus data dibatalkan." << endl
			 << endl
			 << "Ketik apa saja untuk kembali";
		getch(); return;
	}
	cout << endl
		 << "Data Tidak Ditemukan." << endl
		 << endl
		 << "Ketik apa saja untuk kembali";
	getch(); return;
}


