#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left, * right;
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
	return p;
}

void insertNode(Node*& root, int x)
{
	if (root == NULL)
	{
		root = createNode(x);
	}
	else
	{
		Node* p = root;
		while (true)
		{
			if (p->data > x)
			{
				if (p->left == NULL)
				{
					p->left = createNode(x);
					return;
				}
				p = p->left;
			}
			else if (p->data < x)
			{
				if (p->right == NULL)
				{
					p->right = createNode(x);
					return;
				}
				p = p->right;
			}
		}
	}
}

//void LNR(Node* root) {
//
//	if (root != NULL) {
//		LNR(root->left);
//		cout << root->data << " ";
//		LNR(root->right);
//	}
//}

void LNR(Node* root)
{

	while (root != NULL)
	{
		if (root->left == NULL)
		{
			cout << root->data << " ";
			root = root->right;
		}
		else
		{	
			Node* p = root->left;
			while (p->right && p->right != root)
			{
				p = p->right;
			}
			if (p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				cout << root->data << " ";
				root = root->right;
			}

		}
		
	}
	
}

int main()
{

	Node* root;
	init(root);
	insertNode(root, 40);
	insertNode(root, 60);
	insertNode(root, 20);
	insertNode(root, 25);
	insertNode(root, 30);

	LNR(root);

	system("pause");
	return 0;
}