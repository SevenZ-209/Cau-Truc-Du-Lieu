#include <iostream>
using namespace std;

#define M 7

int func(int key)
{
	return key%M;
}


struct Node
{
	int key;
	int next;
};

struct HashTable {
	Node h[M];
	int r;
};

void init(HashTable &ht)
{
	for (int i = 0; i < M; i++)
	{
		ht.h[i].key = -1;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

void insertNode(HashTable &ht, int x)
{
	int k = func(x);

	if (ht.h[k].key == -1)
	{
		ht.h[k].key = x;
	}
	else {
		ht.h[ht.r].key = x;
		while (ht.h[k].next != -1)
		{
			k = ht.h[k].next;
		}
		ht.h[k].next = ht.r;
	}

	while (ht.r >= 0 && ht.h[ht.r].key != -1)
	{
		ht.r--;
	}

}

void printHashTable(HashTable ht)
{
	for (int i = 0; i < M; i++)
	{
		if (ht.h[i].key != -1)
			cout << "BUCKET " << i << ": " << ht.h[i].key << "-->" << ht.h[i].next << endl;
	}
}

int main()
{
	HashTable h;
	init(h);

	insertNode(h, 7);
	insertNode(h, 14);
	insertNode(h, 21);
	insertNode(h, 25);
	insertNode(h, 30);

	printHashTable(h);


	system("pause");
	return 0;
}