#include<iostream>

using namespace std;
struct  node
{
	int data;
	node *left, *right;
	int height;
};
void treeEmpty(node *&root) {
	root = NULL;

}

int getHeight(node*root) {
	if (root == NULL)
		return 0;
	return root->height;
}
node *createNode(int x) {
	node*p = new node;
	p->data = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}

int max(int a, int b) {
	return a > b ? a : b;
}
void update(node *&root) {
	if (root != NULL) {
		root->height= 1 + max(getHeight(root->left), getHeight(root->right));
	}
}
void rightRote(node *&root) {
	node*x = root->left;
	root->left = x->right;
	x->right = root;
	// cap nhat chieu 
	update(root);
	update(x);
	root = x;
}
void insertNode(node *&root, int x) {
	if (root == NULL)
		root = createNode(x);
	else if (root->data > x)
		insertNode(root->left, x);
	else if (root->data < x)
		insertNode(root->right, x);
	else
		return;
	// cap nhat chieu cao cua cay
	update(root);

	//kiem tra can bang 
	int val = getHeight(root->left) - getHeight(root->right);
	if (val > 1 && root->left->data > x) {
		// lech trai trai
		rightRote(root);
	}
	else if (val < -1 && root->right->data < x) {
		// lech phai phai
		leftRote(root);
	}
	else if (val > 1 && root->left->data < x) {
		leftRote(root->left);
		rightRote(root);
	}
	else if (val<-1 && root->right->data>x) {
		rightRote(root->right);
		leftRote(root);
	}
		
	
}
void leftRote(node*&root) {
	node*x = root->right;
	root->right = x->left;
	x->left = root;

	// cap nhap chieu cao cay
	update(root);
	update(x);
	root = x;
}


void LNR(node *root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->data << "( " << root->height << ") ";
		LNR(root->right);
	}
}

void searchStanFor(node*&cur)

void delNode(node *&root, int key) {
	if (root == NULL)
		return;
	if (root->data > key)
		delNode(root->left, key);
	else if (root->data < key)
		delNode(root->right, key);
	else {
		// Tim node can xoa 
		node *cur = root;
		// bac 0 va bac 1
		if (cur->left == NULL)
			root = root->left;
		else if (cur->right == NULL)
			root = root->right;
	}

}



int main() {

}
