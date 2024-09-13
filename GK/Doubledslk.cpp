#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* next, * prev;
};

struct DoubleList {
	Node* head, * tail;
};

void init(DoubleList& dl)
{
	dl.head = dl.tail = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = p->prev = NULL;
	return p;
}

void insertFirst(DoubleList& dl, int x)
{
	Node* p = createNode(x);
	if (dl.head==NULL)
	{
		dl.head = dl.tail = p;
	}
	else {
		p->next = dl.head;
		dl.head->prev = p;
		dl.head = p;
	}
}

void insertLast(DoubleList& dl, int x)
{
	Node* p = createNode(x);
	if (dl.head == NULL)
	{
		dl.head = dl.tail = p;
	}
	else {
		
		p->prev = dl.tail;
		dl.tail->next = p;
		dl.tail = p;
	}
}

void delNode(Node*& p)
{
	p->next = NULL;
	p->prev = NULL;
	delete p;
}

void delFirst(DoubleList& dl)
{
	if (dl.head != NULL)
	{
		Node* p = dl.head;
		dl.head = dl.head->next;
		if (dl.head==NULL)
		{
			dl.tail = NULL;
		}
		else {
			dl.head->prev = NULL;
			delNode(p);
		}
	}
}

void delLast(DoubleList& dl)
{
	if (dl.tail != NULL)
	{
		Node* p = dl.tail;
		dl.tail = dl.tail->prev;
		if (dl.tail== NULL)
		{
			dl.head = NULL;
		}
		else
		{
			dl.tail->next = NULL;
			delNode(p);
		}
	}
}

bool isEmpty(DoubleList dl)
{
	return dl.head == NULL;
}

void delList(DoubleList& dl)
{
	while (!isEmpty(dl))
	{
		delFirst(dl);
	}
}

void sortBubbleList(DoubleList& dl)
{
	for (Node *i = dl.head; i !=NULL  ; i= i->next)
	{
		for (Node *j = dl.head; j ->next != NULL; j=j->next)
		{
			if (j->info > j->next->info)
				swap(j->info, j->next->info);
		}
	}
}

void sortSelectList(DoubleList& dl)
{
	for (Node *i = dl.head; i != NULL ; i=i ->next)
	{
		Node* imin = i;
		for (Node* j = i ->next; j != NULL ; j=j->next)
		{
			if (imin->info > j->info)
			{
				imin = j;
			}
		}
		swap(imin->info, i->info);
	}
}

void interchangeSort(DoubleList& dl)
{
	for (Node *i = dl.head; i != NULL; i = i->next)
	{
		for (Node *j = i->next; j !=NULL ; j= j->next)
		{
			if (i->info < j->info)
			{
				swap(i->info, j->info);
			}
		}
	}
}

void printList(DoubleList dl)
{
	Node* p = dl.head;
	while (p!=NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}



int main()
{
	DoubleList dl;
	init(dl);

	insertLast(dl, 5);
	insertLast(dl, 1);
	insertLast(dl, 3);
	insertLast(dl, 9);
	insertLast(dl, 14);
	insertLast(dl, 13);
	printList(dl);

	interchangeSort(dl);
	cout << "==============\n";
	printList(dl);


	return 0;
}