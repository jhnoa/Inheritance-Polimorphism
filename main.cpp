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
void printHead(int,int,int);
void initialize();
void hapus(int);

list<shape> myshape;
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
	if(x == 4)
	{
		return 1;
	}
	else
	{
		fstream file;
		system("cls");
		int a,b;
		if(x == 1) 
		{
			cout << "Menu Tambah Circle" << endl 
				 << endl
				 << "Jari-jari: ";
			a = inputInt(11,2);
			file.open("circle.txt", ios::out | ios::app);
			file << a << endl;
		}
		else if(x == 2) 
		{
			cout << "Menu Tambah Square" << endl 
				 << endl
				 << "Sisi: ";
			a = inputInt(6,2);
			
			file.open("square.txt", ios::out | ios::app);
			file << a << endl;
		}
		else if(x == 3)
		{
			cout << "Menu Tambah Rectangle" << endl 
				 << endl
				 << "Panjang: ";
			a = inputInt(9,2);
			cout << endl
				 << "Lebar: ";
			b = inputInt(7,3);
			if (b > a) 
			{
				int *temp = new int;
				*temp = a;
				a = b;
				b = *temp;
				delete temp;
			}
			if (a == b) 
			{
				cout << endl << endl << "Data sama. Gagal Menambahkan.";
				getch();
				return 0;
			} 
			file.open("rectangle.txt", ios::out | ios::app);
			file << a << '\t' << b << endl;
		} 
		file.close();
		myshape.clear();
		initialize();
		cout << endl << endl << "Data dimasukan.";
		getch();
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
	myshape.sort();

	if(x ==0) {
		system("cls");
		list<shape>::iterator p;
		
		cout.setf(ios::left, ios::adjustfield);
		
		if(y == 1) {
			cout << "Tampilkan Semua Shape Berdasarkan Luas" << endl << endl;
			for(int i = 0;i<79;i++) cout << "-";
			cout << endl;
			cout << setw(11) << "Shape" << setw(19) << "Luas (cm2)" << setw(18) << "Attribut (cm)" << endl;
		}
		else if(y == 2) {
			cout << "Tampilkan Semua Shape Berdasarkan Keliling" << endl << endl;
			for(int i = 0;i<79;i++) cout << "-";
			cout << endl;
			cout << setw(11) << "Shape" << setw(19) << "Keliling (cm)" << setw(18) << "Attribut (cm)" << endl;
		}
		for(int i = 0;i<79;i++) cout << "-";
		cout << endl;
		
		for(p = myshape.begin();p != myshape.end();p++) {
			if(y == 1) {
				
				cout << setw(11) << p->getBentuk() << setw(19) << p->getArea() << setw(40) << p->getAttr() << endl;
			}
			else if(y == 2) {
				cout << setw(11) << p->getBentuk() << setw(19) << p->getPerimeter() << setw(40) << p->getAttr() << endl;
			}
		}
		cout.unsetf(ios::adjustfield);
		
		getch();
	}
	else if (x < 3)
	{
		system("cls");
		list<shape>::iterator p;
		printHead(18,x,y);
		cout.setf(ios::left, ios::adjustfield);
		for(p = myshape.begin();p != myshape.end();p++) {
			if(p->getT() == x)
			{
				if(y == 1) {
					cout << setw(19) << p->getArea() << setw(10) << p->getW() << endl;
				}
				else if(y == 2) {
					cout << setw(19) << p->getPerimeter() << setw(10) << p->getW() << endl;
				}
			}
		}
		cout.unsetf(ios::adjustfield);
		getch();
	}
	
	else
	{
		system("cls");
		list<shape>::iterator p;
		
		printHead(18,x,y);
		cout.setf(ios::left, ios::adjustfield);
		for(p = myshape.begin();p != myshape.end();p++) {
			if(p->getT() == x)
			{
				if(y == 1) {
					cout << setw(19) << p->getArea() << setw(18) << p->getW() << setw(10) << p->getH() << endl;
				}
				else if(y == 2) {
					cout << setw(19) << p->getPerimeter() << setw(18) << p->getW() << setw(10) << p->getH() << endl;
				}
			}
		}
		cout.unsetf(ios::adjustfield);
		getch();
	}
	return 0;
}

void printHead(int n,int x, int y) {
	string s,t;
	cout.setf(ios::left, ios::adjustfield);
	//	cout << fixed;
	
	if(x == 1) {s = "Circle"; t = "Jari-jari (cm)";}
	else if(x == 2) {s = "Square"; t = "Sisi (cm)";}
	else if(x == 3) {s = "Rectangle";}
		
	if(y == 1) {
		cout << "Tampilkan " << s << " Berdasarkan Luas" << endl << endl;
		if(x == 3) {
			for(int i = 0;i<79;i++) cout << "-";
			cout << endl;
			cout << setw(n+1) << "Luas (cm2)" << setw(18) << "Panjang (cm)" << setw(10) << "Lebar (cm)" << endl;
			for(int i = 0;i<79;i++) cout << "-";
			cout << endl;
		}
		else {
			for(int i = 0;i<2*n;i++) cout << "-";
			cout << endl;
			cout << setw(n+1) << "Luas (cm2)" << setw(10) << t << endl;
			for(int i = 0;i<2*n;i++) cout << "-";
			cout << endl;
		}
	}
	else if(y == 2) {
		cout << "Tampilkan " << s << " Berdasarkan Keliling" << endl << endl;		
		if(x == 3) {
			for(int i = 0;i<3*n;i++) cout << "-";
			cout << endl;
			cout << setw(n+1) << "Keliling (cm)" << setw(18) << "Panjang (cm)" << setw(10) << "Lebar (cm)" << endl;
			for(int i = 0;i<3*n;i++) cout << "-";
			cout << endl;
		}
		else {
			for(int i = 0;i<2*n;i++) cout << "-";
			cout << endl;
			cout << setw(n+1) << "Keliling (cm)" << setw(10) << t << endl;
			for(int i = 0;i<2*n;i++) cout << "-";
			cout << endl;
		}
	}
	
	cout.unsetf(ios::adjustfield);
	
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
		file >> x;
		if (x == 0) break;
		circle *temp = new circle(x);
//		temp->setValue(x);
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
		file >> x;
		if (x == 0) break;
		square *temp = new square(x);
//		temp->setValue(x);
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
		file >> x >> y;
		if (x == 0) break;
		rectangle *temp = new rectangle(x,y);
//		temp->setValue(y, x);
		myshape.push_back(*temp);
		delete temp;
	}
	file.close();

//sorting	
	Shape.mode(1);
//	myshape.sort();
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
		y = inputInt(17, 2);
		cout << endl 
			 << "Masukan Lebar: ";
		x = inputInt(15, 3);
		if(x>y)
		{
			int t;
			t = x;
			x = y;
			y = t;
		}
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
			cout << "Panjang: " << y <<endl;
			cout << "Lebar: " << x << endl;
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


