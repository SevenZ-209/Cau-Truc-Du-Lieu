#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* right, * left;
	int height;
};

void init(Node*& root)
{
	root = NULL;
}

Node* createNode(int x)
{
	Node* p = new Node;
	p->data = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}


int geiHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}

void updateHeight(Node*& root)
{
	if (root != NULL)
	{
		root->height = 1 + max(geiHeight(root->left), geiHeight(root->right));
	}
}



int main()
{




	system("pause");
	return 0;
}