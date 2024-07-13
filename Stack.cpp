#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define MAX 50

struct Stack
{
	int a[MAX];
	int top;
};

void init(Stack &s)
{
	s.top = -1;
}

void push(Stack &s, int x)
{
	if (s.top <= MAX)
	{
		s.a[++s.top] = x;
	}
}

int pop(Stack &s)
{
	if (s.top > -1)
	{
		return s.a[s.top--];
	}
}

void printlist(Stack &s)
{
	for (int i = 0; i <= s.top ; i++)
	{
		cout << s.a[i] << endl;
	}
}

bool isEmty(Stack s)
{
	return s.top == -1;
}

void convertDecToBin(int n)
{
	Stack s;
	init(s);

	while (n!=0)
	{
		push(s, n % 2);
		n /= 2;
	}
	while (!isEmty(s))
	{
		cout << pop(s);
	}
	cout << endl;

}

void Cal(char str[])
{
	Stack s;
	init(s);
	int t = 0;
	
	char *p = strtok(str, " ");
	while (p!= NULL)
	{
		if (isdigit(*p))
		{
			push(s, atoi(p));
		}
		else
		{
			int b = pop(s);
			int a = pop(s);
			
			switch (*p)
			{
			case '+':
				t = a + b;
				break;
			case '-':
				t = a - b;
				break;
			case '*':
				t = a*b;
				break;
			case '/':
				t = a / b;
				break;
			default:
				break;
			}
			push(s, t);
		}
		p = strtok(NULL, " ");
	}
	cout << "Gia tri bieu thuc: " << pop(s) << endl;

}

int main()
{
	char str[] = " 2 5 6 + * 5 / 1 -";
	Cal(str);


	system("pause");
	return 0;
}