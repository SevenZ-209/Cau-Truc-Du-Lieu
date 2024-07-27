#include<iostream>
#include <string>
#include <fstream>
using namespace std;

#define MAX 100

struct SinhVien
{
	int MSSV;
	string HovaTen;
	char NgaySinh[11];
	string queQuan;
	double DiemTB;
};

void Nhap1Sv(SinhVien &sv)
{
	cout << "==========\n";
	cout << "Nhap MSSV: "; cin >> sv.MSSV;
	cin.ignore();
	cout << "Nhap Ho va Ten: "; getline(cin, sv.HovaTen);
	cout << "Nhap ngay sinh: "; cin.getline(sv.NgaySinh, 11);
	cout << "Nhap que quan: "; getline(cin, sv.queQuan);
	cout << "Nhap diem TB: "; cin >> sv.DiemTB;
	cout << "==========\n";
}

void Xuat1Sv(const SinhVien sv)
{
	cout << "==========\n";
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho va Ten: " << sv.HovaTen << endl;
	cout << "Ngay sinh: " << sv.NgaySinh << endl;
	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Diem TB: " << sv.DiemTB << endl;
	cout << "==========\n";
}

void NhapDSSV(SinhVien ds[], int &n)
{
	do
	{
		cout << "Nhap so luong sinh vien: "; cin >> n;
		if (n <= 0 || n > MAX)
			cout << "\nNhap lai!\n";
	} while (n <= 0 || n > MAX);

	for (int i = 0; i < n; i++)
	{
		Nhap1Sv(ds[i]);
	}
}

void XuatDSSV(SinhVien ds[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Xuat1Sv(ds[i]);
	}
}

void NhapDSSVTuFile(SinhVien ds[], int &n, const string TenFile)
{
	ifstream inFile(TenFile);
	if (inFile.is_open())
	{
		inFile >> n;
		int i = 0;
		while (i<n)
		{
			SinhVien sv;
			inFile >> sv.MSSV;
			inFile.ignore();
			getline(inFile, sv.HovaTen, '#');
			inFile.getline(sv.NgaySinh, 11, '#');
			getline(inFile, sv.queQuan, '#');
			inFile >> sv.DiemTB;
			ds[i++] = sv;
		}

		inFile.close();
	}
}

int search(SinhVien ds[], const int n, const int key)
{
	for (int i = 0; i < n; i++)
	{
		if (ds[i].MSSV == key)
			return i;
	}
	return -1;
}


int search(SinhVien ds[], const int n, const string key)
{
	for (int i = 0; i < n; i++)
	{
		if (ds[i].queQuan == key || ds[i].HovaTen == key)
			return i;
	}
	return -1;
}



void sapXepDSSV(SinhVien ds[], int n, int choice) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++)
		{
			if (choice == 1 && ds[j].MSSV < ds[j + 1].MSSV)
				swap(ds[j], ds[j + 1]);
			else if (choice == 2 && ds[j].HovaTen > ds[j + 1].HovaTen)
				swap(ds[j], ds[j + 1]);
			else if (choice == 3 && ds[j].queQuan > ds[j + 1].queQuan)
				swap(ds[j], ds[j + 1]);

		}
	}
}

int cmpWithIDDESC(const SinhVien sv1, const SinhVien sv2)
{
	return sv1.MSSV > sv2.MSSV ? 1 : (sv1.MSSV < sv2.MSSV) ? -1 : 0;
}

int cmpWithIDASC(const SinhVien sv1, const SinhVien sv2)
{
	return -(sv1.MSSV > sv2.MSSV ? 1 : (sv1.MSSV < sv2.MSSV) ? -1 : 0);
}

int cmpWithNameASC(const SinhVien sv1, const SinhVien sv2)
{
	return sv1.HovaTen > sv2.HovaTen ? 1 : (sv1.HovaTen < sv2.HovaTen) ? -1 : 0;
}


void sort(SinhVien ds[], const int n, int comparator(SinhVien sv1, SinhVien sv2))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (comparator(ds[j], ds[j + 1]) == -1)
				swap(ds[j], ds[j+1]);
		}
	}
}

int main()
{
	int n;
	//SinhVien sv;
	//Nhap1Sv(sv);
	//Xuat1Sv(sv);

	SinhVien ds[MAX];
	//NhapDSSV(ds, n);
	//XuatDSSV(ds, n);
	

	NhapDSSVTuFile(ds, n, "SinhVien.txt");
	XuatDSSV(ds, n);


	cout << "=================Da Sap Xep Theo Yeu Cau Cua Ban=================\n";
	sort(ds, n, cmpWithIDDESC);
	XuatDSSV(ds, n);




	system("pause");
	return 0;								
}
