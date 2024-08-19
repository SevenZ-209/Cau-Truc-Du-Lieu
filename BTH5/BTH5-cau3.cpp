#include <iostream>
#include<fstream>
#include<string>
using namespace std;

#define M 17

int func(int key)
{
	return key%M;
}

struct User
{
	int id;
	string username;
	int freq;
};

struct Node
{
	User*data;
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
		ht.h[i].data = NULL;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

void insertNode(HashTable &ht, User *x)
{
	int k = func(x->id);

	if (ht.h[k].data == NULL)
	{
		ht.h[k].data = x;
	}
	else {
		if (ht.h[k].data->id = x->id)
		{
			ht.h[k].data->freq += 1;
		}
		else {
			while (ht.h[k].next != NULL)
			{
				k = ht.h[k].next;
				if (ht.h[k].data->id == x->id)
					ht.h[k].data->freq += 1;
				return;
			}
		}

	}
	while (ht.r >= 0 && ht.h[ht.r].data != NULL)
	{
		ht.r--;
	}

}

void printHashTable(HashTable ht)
{
	for (int i = 0; i < M; i++)
	{
		if (ht.h[i].data != NULL)
			cout << "BUCKET " << i << ": " << ht.h[i].data->id << "-->" << ht.h[i].next << " SO LAN: " << ht.h[i].data->freq << endl;
	}
}

int main()
{
	HashTable h;
	init(h);
	ifstream inFile("truycap.txt");
	User listUser[10];
	int i = 0;

	if (inFile.is_open()) {
		while (!inFile.eof())
		{
			User u;
			inFile >> u.id;
			inFile.ignore();
			inFile >> u.username;
			u.freq = 1;
			listUser[i++] = u;
			
		}
	}
	insertNode(h, &listUser[0]);
	insertNode(h, &listUser[0]);
	insertNode(h, &listUser[0]);
	insertNode(h, &listUser[0]);
	insertNode(h, &listUser[1]);
	insertNode(h, &listUser[4]);
	insertNode(h, &listUser[4]);




	printHashTable(h);


	system("pause");
	return 0;
}