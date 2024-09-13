#include <iostream>
using namespace std;
#define MAX 100

struct list
{
	int a[MAX];
	int n;
};

void nhapSoPT(list& l)
{
	do
	{
		cout << "Nhap so luong phan tu: ";
		cin >> l.n;
		if (l.n<=0 || l.n > MAX)
		{
			cout << "Nhap lai so luong";
		}
	} while (l.n <= 0 || l.n > MAX);
	
	for (int i = 0; i < l.n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " : ";
		cin >> l.a[i];
		cout << endl;
	}
}

void xuatPT(list l)
{
	for (int i = 0; i < l.n; i++)
	{
		cout << l.a[i] << " ";
	}
	cout << endl;
}

int* findMax(list l)
{
	if (l.a != NULL) {
		int iMax = 0;
		for (int i = 1; i < l.n; i++)
		{
			if (l.a[i] > l.a[iMax])
			{
				iMax = i;
			}

		}
		return &l.a[iMax];
	}

	return NULL;

}

void insert_last(list& l, int &x)
{
	cout << "Nhap so phan tu ban muon them vao o cuoi : ";
	cin >> x;
	l.a[l.n++] = x;
}

int search(list l, int& x)
{
	cout << "Nhap so phan tu ban muon tiem kiem";
	cin >> x;
	for (int i = 0; i < l.n; i++)
	{
		if (l.a[i] == x)
			return i;
	}
	return NULL;
}

void delete_last(list& l)
{
	l.n--;
}

void del_pos(list& l, int vt)
{
	cout << "Nhap vi tri ban muon xoa: ";
	cin >> vt;
	for (int i = vt-1; i < l.n; i++)
	{
		 l.a[i] = l.a[i + 1];
	}
	l.n--;
}

int *find_Second_max(list l)
{
	if (l.a !=NULL)
	{
		int sec = 0;
		int* max = findMax(l);

		for (int i = 1; i < l.n; i++)
		{
			if (l.a[sec] < l.a[i] && l.a[i] < *max)
			{
				sec = i;
			}
		}
		return &l.a[sec];
	}
	
	return NULL;
}

void selectsion_sort(list &l)
{
	for (int i = 0; i < l.n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < l.n; j++)
		{
			if (l.a[j] < l.a[min])
				min = j;
		}
		swap(l.a[i], l.a[min]);
	}
}

void insertionSort(list& l)
{
	for (int i = 1; i < l.n; i++)
	{
		int x = l.a[i];
		int pos = i - 1;
		while (pos >=0 && l.a[pos] > x)
		{
			l.a[pos + 1] = l.a[pos];
			pos--;
		}
		l.a[pos + 1] = x;
	}
}

void bubbleSortt(list &l)
{
	for (int i = 0; i < l.n-1; i++)
	{
		for (int j = 0; j < l.n-i-1; j++)
		{
			if (l.a[j] > l.a[j+1])
			{
				swap(l.a[j], l.a[j + 1]);
			}
		}
	}
}

void interchangeSort(list& l)
{
	for (int i = 0; i < l.n-1; i++)
	{
		for (int j = i+1; j < l.n; j++)
		{
			if (l.a[i] > l.a[j])
			{
				swap(l.a[j], l.a[i]);
			}
		}
	}
}



int main()
{
	list l;
	int x=0;
	nhapSoPT(l);
	xuatPT(l);

	interchangeSort(l);
	
	xuatPT(l);
	

	
	
	system("pause");
	return 0;
};