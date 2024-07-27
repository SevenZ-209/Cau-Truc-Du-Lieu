#include <iostream>
using namespace std;

struct Node {
	int info;
	Node *next;
};

struct CircularLinkedList
{
	Node *head;
};

void init(CircularLinkedList &cl)
{
	cl.head = NULL;
}

Node *createNode(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void insertFirst(CircularLinkedList &cl, int x)
{
	Node *p = createNode(x);
	if (cl.head == NULL)
	{
		cl.head = p;
		cl.head->next = p;
	}
	else
	{
		Node *pLast = cl.head;
		while (pLast -> next != cl.head)
			pLast = pLast->next;
		pLast -> next = p;
		p->next = cl.head;
		cl.head = p;
	}
}

void insertLast(CircularLinkedList &cl, int x)
{
	Node *p = createNode(x);
	if (cl.head == NULL)
	{
		cl.head = p;
		cl.head->next = p;
	}
	else
	{
		Node *pLast = cl.head;
		while (pLast->next != cl.head)
			pLast = pLast->next;
		pLast->next = p;
		p->next = cl.head;
	
	}
}

void printList(CircularLinkedList cl)
{
	if (cl.head != NULL)
	{
		Node *p = cl.head;
		do
		{
			cout << p->info << " ";
			p = p->next;
		} while (p!= cl.head);
	}
	cout << endl;
}

void deleteFirst(CircularLinkedList &cl)
{
	if (cl.head != NULL)
	{
		Node *p = cl.head;
		if (p->next == cl.head)
		{
			cl.head = NULL;
		}
		else {
			Node *pLast = cl.head;
			while (pLast->next != cl.head)
				pLast = pLast->next;
			pLast->next = cl.head->next;
			cl.head = cl.head->next;
		}
		p->next = NULL;
		delete p;
	}
}

void destroyList(CircularLinkedList &cl)
{
	while (cl.head!=NULL)
	{
		deleteFirst(cl);
	}
}

int main()
{
	CircularLinkedList cl;
	init(cl);

	insertFirst(cl, 6);
	insertFirst(cl, 5);
	insertLast(cl, 7);
	printList(cl);
	deleteFirst(cl);
	printList(cl);
	destroyList(cl);
	printList(cl);

	system("pause");
	return 0;
}
