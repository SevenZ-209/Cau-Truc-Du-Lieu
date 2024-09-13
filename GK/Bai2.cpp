#include <iostream>
#include<string>
#include<fstream>
using namespace std;

struct SinhVien
{
	int MSSV;
	string hoVaTen;
	char ngaySinh[11];
	string queQuan;
	double diemTB;
};

void nhap1Sv(SinhVien& sv)
{
	cout << "Nhap MSSV: "; cin >> sv.MSSV;
	cin.ignore();
	cout << "Nhap Ho va Ten: "; getline(cin, sv.hoVaTen, '\n');
	cout << "Nhap ngay sinh: "; cin >> sv.ngaySinh;
	cin.ignore();
	cout << "Nhap que quan: "; getline(cin, sv.queQuan, '\n');
	cout << "Nhap diem trung binh: "; cin >> sv.diemTB;
							
}

void Xuat1Sv(SinhVien sv)
{
	cout << "\n=========================\n";
	cout << "MSSV: " << sv.MSSV;
	cout << "\nHo va Ten: " << sv.hoVaTen;
	cout << "\nNgay sinh: " << sv.ngaySinh;
	cout << "\nQue quan: " << sv.queQuan;
	cout << "\nNhap diem trung binh: " << sv.diemTB << endl;
	
}

struct Node {
	SinhVien info;
	Node* next;
};

void init(Node *&head) {
	head = NULL;
}

Node* createNode(SinhVien sv)
{
	Node* p = new Node;
	p->info = sv;
	p->next = NULL;
	return p;
}

void insertFirst(Node*& head, SinhVien sv)
{
	Node *p= createNode(sv);
	if (head==NULL)
	{
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void insertLast(Node*& head, SinhVien sv)
{
	Node* p = createNode(sv);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		Node* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
}

void nhapDsSv(Node *&head)
{
	int chon = 1;
	while (chon!=0)
	{
		SinhVien sv;
		nhap1Sv(sv);
		insertFirst(head, sv);
		cout << "Tiep tuc: ";
		cin >> chon;
	}
}

void nhapDSSVTuFile(Node *&head, string tenFile)
{
	ifstream inFile(tenFile);
	if (inFile.is_open())
	{
		int i = 0;
		while (!inFile.eof() && i<3)
		{
			SinhVien sv;
			inFile >> sv.MSSV;
			inFile.ignore();
			getline(inFile, sv.hoVaTen, '#');
			inFile.getline(sv.ngaySinh, 11, '#');
			getline(inFile, sv.queQuan, '#');
			inFile >> sv.diemTB;
	

			insertLast(head, sv);
			i++;
		}
		inFile.close();
	}
}

void delNode(Node*& p)
{
	p->next = NULL;
	delete p;
	p = NULL;
}

void xoaDau(Node*& head)
{
	if (head!=NULL)
	{
		Node* p = head;
		head = head->next;
		delNode(p);
	}
}

void XoaCuoi(Node*& head)
{
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			delNode(head);
		}
		else
		{
			Node* p = head;
			while (p->next->next != NULL)
			{
				p = p->next;
			}
			delNode(p->next);

		}
	}
}

void XuatDSSV(Node *head)
{
	if (head != NULL)
	{
		Node* p = head;
		while (p!=NULL)
		{
			Xuat1Sv(p->info);
			p = p->next;
		}
	}
}

void xuatDsSvRutGon(Node* head) {
	if (head == NULL)
	{
		cout << "Danh Sach khong co sinh vien\n";
		return;
	}

	int chon=1;

	do
	{
		
		cout << "\nLua chon xuat sinhVien: \n";
		cout << "1.MSSV\n";
		cout << "2.HoVaTen\n";
		cout << "3.NgaySinh\n";
		cout << "4.QueQuan\n";
		cout << "5.DiemTrungBinh\n";
		cout << "0.Thoat\n";
		cin >> chon;

		Node* p = head;
		cout << "\n=========================\n";

		while (p!=NULL)
		{
			switch (chon)
			{
			case 1:
				cout << "MSSV: " << p->info.MSSV << endl;
				break;
			case 2:
				cout << "Ho va Ten: " << p->info.hoVaTen << endl;
				break;
			case 3:
				cout << "NgaySinh: " << p->info.ngaySinh << endl;
				break;
			case 4:
				cout << "QueQuan: " << p->info.queQuan << endl;
				break;
			case 5:
				cout << "DiemTrungBinh: " << p->info.diemTB << endl;
				break;
			
			}
			p = p->next;
		}
		cout << "\n";
	} while (chon !=0);
}

void TimSinhVien(Node* head)
{
	if (head == NULL) {
		cout << "Khong co sinh vien trong danh sach. \n";
		return;
	}

	string hoTen;
	cout << "Nhap ho va ten: ";

	getline(cin, hoTen, '\n');
	

	Node* p = head;
	bool found = false;

	while (p!=NULL)
	{
		if (hoTen == p->info.hoVaTen) {
			cout << "\n===========Sinh Vien co trong danh sach=============\n ";
			Xuat1Sv(p->info);
			found = true;
			break;
		}
		p = p->next;
	}

}

void xoaSinhVientheoTen(Node*& head)
{
	if (head==NULL)
	{
		cout << "Khong co sinh vien trong danh sach\n";
		return;
	}

	string name;
	cout << "Nhap ten: ";
	getline(cin, name);
	Node* p = head;
	Node* cur = NULL;
	while (p != NULL)
	{
		if (p->info.hoVaTen == name)
		{
			Node* del = p;
			if (cur == NULL)
			{
				head = head->next;
			}
			else
			{
				cur->next = p->next;
				p = p->next;
			}
		}
		else
		{
			cur = p;
			p = p->next;
		}
	}
}

void selectsort(Node*& head)
{
	if (head != NULL)
	{
		for (Node *i = head; i != NULL; i = i->next)
		{
			Node* min = i;
			for (Node* j = i->next; j != NULL ; j=j->next)
			{
				if (j->info.diemTB > min->info.diemTB)
				{
					min = j;
				}
			}
			swap(min->info, i->info);
		}
	}
}

void interchangesort(Node*& head)
{
	if (head !=NULL)
	{
		for (Node *i = head; i != NULL ; i=i->next)
		{
			for (Node *j = i->next; j != NULL; j=j->next)
			{
				if (j->info.diemTB > i->info.diemTB)
				{
					swap(i->info, j->info);
				}
			}
		}
	}
}

void bubblesort(Node*& head)
{
	if (head != NULL)
	{
		for (Node *i = head; i != NULL; i=i->next)
		{
			for (Node *j = head; j->next != NULL; j=j->next)
			{
				if (j->info.diemTB > j->next->info.diemTB)
				{
					swap(j->info, j->next->info);
				}
			}
		}
	}
}



//void insertionSort(Node*& head)
//{
//	if (head != NULL)
//	{
//		
//		for (Node *i = i->next ;i != NULL; i=i->next)
//		{
//			Node* key = i->next;
//			Node* pos = i - 1;
//			while (pos != NULL && pos->info.diemTB < key->info.diemTB)
//			{
//				pos->next->info = pos->info;
//				pos = pos->next;
//			}
//		
//		}
//	}
//}

void xemThongTinSinhVien(Node* head) {
	if (head == NULL) {
		cout << "Khong co sinh vien\n";
		return;
	}

	Node* cur = head;
	while (true)
	{
		cout << "Thong tin sinh vien: ";
		Xuat1Sv(cur->info);
	}

}



int main()	
{
	Node* head;
	init(head);
	nhapDSSVTuFile(head, "SinhVien.txt");
	XuatDSSV(head);
	XoaCuoi(head);
	XuatDSSV(head);
	



	system("pause");
	return 0;
}