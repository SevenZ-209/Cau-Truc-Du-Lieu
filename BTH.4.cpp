#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	int height;
};

void treeEmpty(Node*&root)
{
	root = NULL;
}

Node *createNode(int x)
{
	Node *p = new Node;
	p->data = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}



int getHeight(Node*root) {
	if (root == NULL)
		return 0;
	return root->height;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void update(Node *&root) {
	if (root != NULL) {
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	}
}

void rightRotate(Node *&root) {
	Node*x = root->left;
	root->left = x->right;
	x->right = root;
	// cap nhat chieu 
	update(root);
	update(x);
	root = x;
}

void leftRotate(Node*&root) {
	Node*x = root->right;
	root->right = x->left;
	x->left = root;

	// cap nhap chieu cao cay
	update(root);
	update(x);
	root = x;
}


void insertNode(Node *&root, int x) {
	if (root == NULL)
		root = createNode(x);
	else if (root->data > x)
		insertNode(root->left, x);
	else if (root->data < x)
		insertNode(root->right, x);
	else
		return;

	update(root);

	int val = getHeight(root->left) - getHeight(root->right);
	if (val > 1 && root->left->data > x) {
		// lech trai trai
		rightRotate(root);
	}
	else if (val < -1 && root->right->data < x) {
		// lech phai phai
		leftRotate(root);
	}
	else if (val > 1 && root->left->data < x) {
		//lechtraiphai
		leftRotate(root->left);
		rightRotate(root);
	}
	else if (val<-1 && root->right->data>x) {
		//lechphaitrai
		rightRotate(root->right);
		leftRotate(root);
	}
}

//void deleteNode(Node *&root, int key) {
//	if (root = NULL)
//		return;
//	Node *cur = root;
//	Node *parent = NULL;
//	while (cur!= NULL && cur->data !=key)
//	{
//		parent = cur;
//		if (cur->data > key)
//			cur = cur->left;
//		else
//			cur = cur->right;
//	}
//	if (cur = NULL)
//		return;
//
//	//Node bac 0, bac 1
//	if (cur->left == NULL || cur->right == NULL)
//	{
//		Node *temp;
//		if (cur->left != NULL)
//			temp = cur->left;
//		else
//			temp = cur->right;
//		if (cur == root) {
//			root = temp;
//		}
//		else if (parent->data > key) {
//			parent->left = temp;
//		}
//		else
//			parent->right = temp;
//		delete cur;
//	}
//	//xoa bac 2
//
//}

int getBalance(Node *root)
{
	if (root == NULL)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}

void searchStandFor(Node *&cur, Node *&temp)
{
	if (temp->left != NULL)
	{
		searchStandFor(cur, temp->left);
	}
	else
	{
		cur->data = temp->data;
		cur = temp;
		temp = temp->right;
	}
}

void delNode(Node*&root, int key)
{
	if (root == NULL)
		return;
	if (root->data > key)
		delNode(root->left, key);
	else if (root->data < key)
		delNode(root->right, key);
	else {
		//Tim thay node can xoa
		Node *cur = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
	}
	if (root == NULL)
		return;

	int val = getBalance(root);

	if (val > 1 && getBalance(root->left) >= 0)
	{
		rightRotate(root);
	}
	else if (val < -1 && getBalance(root->right) <= 0)
	{
		leftRotate(root);
	}
	else if (val > 1 && getBalance(root->left) < 0)
	{
		leftRotate(root->left);
		rightRotate(root);
	}
	else if (val < -1 && getBalance(root->right) >0)
	{
		rightRotate(root->right);
		leftRotate(root);
	}
}
void LNR(Node *root)
{
	if (root != NULL)
	{
		LNR(root->left);
		cout << root->data << "( " << root->height << " )";
		LNR(root->right);
	}
}

void NLR(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << "( " << root->height << " )";
		NLR(root->left);
		NLR(root->right);
	}
}



int main()
{
	Node*root;
	treeEmpty(root);
	insertNode(root,40);
	insertNode(root, 20);
	insertNode(root, 50);
	insertNode(root, 10);
	insertNode(root, 30);

	LNR(root);
	cout << endl;
	insertNode(root, 7);
	LNR(root);




	system("pause");
	return 1;

}