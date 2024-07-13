#include <iostream>
using namespace std;

struct Node {
	int info;
	Node *prev, *next;
};

struct Doublelist
{
	Node *head, *tail;
};

void init(Doublelist &dl)
{
	dl.head = dl.tail = NULL;
}

Node *createNode(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void PrintListFirst(Doublelist dl)
{
	Node *p = dl.head;
	
	while (p!=NULL)
	{
		cout << p->info << " ";
		p=p->next;
	}
	cout << endl;
}

void PrintListLast(Doublelist dl)
{
	Node *p = dl.tail;

	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->prev;
	}
	cout << endl;
}

void InsertFirst(Doublelist &dl, int x)
{
	Node *p = createNode(x);
	if (dl.head == NULL)
	{
		dl.head = dl.tail = p;
	}
	else
	{
		p->next = dl.head;
		dl.head->prev = p;
		dl.head = p;
	}
}

void InsertLast(Doublelist &dl, int x)
{
	Node *p = createNode(x);
	if (dl.head == NULL)
	{
		dl.head = dl.tail = p;
	}
	else
	{
		dl.tail->next = p;
		p->prev = dl.tail;
		dl.tail = p;
	}
}

void delNode(Node *&p)
{
	p->next = NULL;
	p->prev = NULL;
	delete p;
}

void delFirst(Doublelist &dl)
{
	if (dl.head != NULL)
	{
		Node *p = dl.head;
		dl.head = dl.head->next;
		if (dl.head == NULL)
			dl.tail = NULL;
		else
			dl.head->prev = NULL;
		delNode(p);
	}
}

void delLast(Doublelist &dl)
{
	if (dl.head != NULL)
	{
		Node *p = dl.tail;
		dl.tail = dl.tail->prev;
		if (dl.head == NULL)
			dl.tail = NULL;
		else
			dl.tail->next = NULL;
		delNode(p);
	}
}

Node *FindMax(Doublelist dl)
{
	Node *res = dl.head;
	Node *p = dl.head;
	while (p!=NULL)
	{
		if (p->info > res->info)
			res = p;
		p = p->next;
	}
	return res;
}

Node *FindMin(Doublelist dl)
{
	Node *res = dl.head;
	Node *p = dl.head;
	while (p != NULL)
	{
		if (p->info < res->info)
			res = p;
		p = p->next;
	}
	return res;
}

Node *findNode(Doublelist dl, const int key)
{
	if (dl.head != NULL)
	{
		Node *p = dl.head;
		while (p != NULL)
		{
			if (p->info == key)
				return p;
			p = p->next;

		}
	}
	return NULL;
}

void insertAfter(Doublelist &dl, const int key, const int x)
{
	Node*q = findNode(dl, key);
	if (q != NULL)
	{
		if (q == dl.tail)
			InsertLast(dl, x);
		else
		{
			Node *p = createNode(x);
			p->next = q->next;
			q->next->prev - p;

			p->prev = q;
			q->next = p;
		}
	}
	else cout << "Khong tim thay!\n";
}

void swap(int&a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}



int main()
{
	Doublelist dl;
	init(dl);
	InsertFirst(dl, 7);
	InsertLast(dl, 8);

	PrintListFirst(dl);
	PrintListLast(dl);

	delLast(dl);

	PrintListFirst(dl);
	PrintListLast(dl);

	system("pause");
	return 0;
}