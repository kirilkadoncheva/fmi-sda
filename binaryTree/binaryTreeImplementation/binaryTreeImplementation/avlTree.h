#pragma once
#include <iostream>
struct node
{
public:
	int key;
	node* left;
	node* right;
	int height;

	
};
node* newNode(int key)
{
	node* Node = new node();
	Node->key = key;
	Node->left = NULL;
	Node->right = NULL;
	Node->height = 1;
	return Node;
}
int max(int a, int b)
{
	if (a > b)return a;
	return b;
}

int height(node* root)
{
	if (root == NULL) return 0;
	return root->height;
}

node* rightRotate(node* y)
{
	node* x = y->left;
	node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->right), height(y->left)) + 1;
	x->height = max(height(x->right), height(x->left)) + 1;

	return x;
}

node* leftRotate(node* x)
{
	node* y = x->right;
	node* T2 = y->left;

	y->left = x;
	x->right = T2;
	y->height = max(height(y->right), height(y->left)) + 1;
	x->height = max(height(x->right), height(x->left)) + 1;

	return y;
}

int getBalance(node* root)
{
	if (root == NULL)return 0;
	return height(root->left) - height(root->right);
}

node* insert(node* root, int key)
{
	if (root == NULL)
	{
		node* temp = newNode(key);
		return temp;
	}
	if (key < root->key)
	{
		root->left = insert(root->left, key);

	}
	else if (key > root->key)
	{
		root->right = insert(root->right, key);
	}
	else return root;

	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);

	//left left case
	if (balance > 1 && key < root->left->key)
	{
		return rightRotate(root);
	}

	//right right case
	if (balance<-1 && key > root->right->key)
	{
		return leftRotate(root);
	}

	//left right case
	if (balance > 1 && key > root->left->key)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//right left case
	if (balance < -1 && key < root->right->key)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}
node* removeNode(node* root, double value)
{
	if (root == NULL)
	{
		std::cout << value << " not found to remove\n";
		return root;
	}
	if (value < root->key)
	{
		root->left = removeNode(root->left, value);
	}
	else if (value > root->key)
	{
		root->right = removeNode(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			node* temp = root->right;
			*root = *temp;
			delete temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			*root = *temp;
			delete temp;
		}
		else
		{
			node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = removeNode(root->right, temp->key);
		}


	}
	int height = height(root);
	int balance = getBalance(root);


	if (root == NULL)
		return root;







	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);


	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}


	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);


	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;




}
void printInOrder(node* root)
{
	if (root != NULL)
	{
		printInOrder(root->left);
		std::cout << root->key << " ";
		printInOrder(root->right);
	}
}