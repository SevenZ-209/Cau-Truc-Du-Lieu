#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define MAX 50

//Khai bao cau truc
struct Stack
{
	char* a[MAX];
	int top;
};

//Khoi tao rong
void init(Stack &s) {
	s.top = -1;
}

//Cac thao tac
void push(Stack &s, char* x) {
	if (s.top < MAX) {
		s.a[++s.top] = x;
	}
}

bool isEmpty(Stack s) {
	return s.top == -1;
}

char* pop(Stack &s) {
	if (!isEmpty(s)) {
		return s.a[s.top--];
	}
}

void printStack(Stack s) {
	for (int i = 0; i <= s.top; i++)
		cout << s.a[i] << " ";
	cout << endl;
}

//Cau truc hang doi
struct Node
{
	char* info;
	Node *next;
};

struct Queue
{
	Node *head;
};

void init(Queue &q) {
	q.head = NULL;
}
Node * createNode(char *x) {
	Node*p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

//Them vao cuoi
void enQueue(Queue &q, char *x) {
	Node*p = createNode(x);
	if (q.head == NULL) {
		q.head = p;
	}
	else {
		Node*plast = q.head;
		while (plast->next != NULL)
			plast = plast->next;
		plast->next = p;
	}
}

//Lay ra tu dau
char* deQueue(Queue &q) {
	char*data = "";
	if (q.head != NULL) {
		Node* p = q.head;
		q.head = q.head->next;
		data = p->info;

		p->next = NULL;
		delete p;
	}
	return data;
}
bool emty(Queue q){
	return q.head == NULL;

}
int getPriorty(char op) {
	if (op == '/' || op == '*')
		return 2;
	if (op == '-' || op == '+')
		return 1;
	return 0;
}
void infixToPostfix(char str[]) {
	Stack s;
	init(s);
	Queue postfix;
	init(postfix);
	char *p = strtok(str, " ");
	while (p != NULL) {
		if (isdigit(*p))
			enQueue(postfix, p);
		else if (*p == '(')
			push(s, p);
		else if (*p == ')') {
			char *op = pop(s);
			while (*op != '(') {
				enQueue(postfix, op);
				op = pop(s);
			}
			
		}
		else {
			if(!isEmpty(s))
		}
		



		else {
			if (!isEmpty(s)) {
				char*op = pop(s);
				enQueue(postfix, op);
			}
			push(s, p);
		}
		p = strtok(NULL, " ");
	}
}

int main() {
	char str[] = "2 + 4 - ( 5 - 3 ) / 2 + 3 - 1 * 5";

	system("pause");
	return 1;
}