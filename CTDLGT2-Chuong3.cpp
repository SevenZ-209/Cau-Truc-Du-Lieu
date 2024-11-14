#include <iostream>
#include<ctime>

using namespace std;
#define MAX 20

struct Node {
	int info;
	Node *link;
};

Node *first[MAX];
int n;

int random(int limit) {
	return static_cast<int>(time(0) % limit); 
}

void initds() {
	for (int i = 0; i < n; i++)
	{
		first[i] = NULL;
	}
}

void insertFirst(Node*& node, int vl)
{
	Node *p = new Node;
	p->info = vl;
	p->link = node;
	node = p;
}

void inputds() {
	int d, x, m;
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dinh thu " << i << ": ";
		cin >> d;
		insertFirst(first[i], d);
		cout << "Nhap vao so dinh ke cua " << d << ": ";
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			insertFirst(first[j], x);
		}
	}
}




void output_list(Node *f) {
	if (f != NULL) {
		Node *p = f;
		while (p != NULL) {
			cout << p->info << " ";
				p = p->link;
		}
	}
}

void outputds()
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i << ": ";
			output_list(first[i]);
		}
	}
	else
	{
		cout << "Mang rong";
	}
		
}

int A[MAX][MAX];

void initmt() {
	n = 0;
}

void inputmt() {
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "nhap vao dong thu " << i
			<< ": ";
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
}

void outputmt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{
	Node *first[MAX];
	int n;
	initds();
	int chon, choncn;
	initmt();

	do
	{ 
		cout << "\n==========MENU==========\n"
			<< "1. Danh sach ke\n"
			<< "2. Ma tran ke\n"
			<<"0. Thoat!!\n"
			<< "Chon: ";
		cin >> chon;

		switch (chon)
		{
		case 1:
			do
			{
				cout << "\n==========Danh Sach Ke==========\n"
					<< "1. Nhap dinh va canh\n"
					<< "2. Xuat\n"
					<< "0. Quay lai\n";
				cin >> choncn;

				switch (choncn)
				{
				case 1:
					inputds();
					break;
				case 2:
					outputds();
					break;
				default:
					break;
				}
			} while (choncn != 0);

			break;
		
		case 2:
			do
			{
				cout << "==========Ma Tran Ke==========\n"
					<< "1. Nhap dinh va canh\n"
					<< "2. Xuat\n"
					<< "0. Quay lai\n";
				cin >> choncn;

				switch (choncn)
				{
				case 1:
					inputmt();
					break;
				case 2:
					outputmt();
					break;
				default:
					break;
				}
			} while (choncn != 0);

		default:
			break;
		}

	} while (chon != 0);

	system("pause");
	return 0;
}