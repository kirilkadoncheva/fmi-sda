#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;
	int height;

	Node(double value, Node *left = nullptr, Node *right = nullptr)
	{
		this->value = value;
		this->left = left;
		this->right = right;
		this->height = 1;
	}
};
int max(int a, int b)
{
	if (a > b)return a;
	return b;
}

int getHeight(Node* root)
{
	if (root == nullptr)return 0;
	return root->height;
}

int getBalance(Node* root)
{
	if (root == nullptr)return 0;
	return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return y;

}
Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return x;
}

Node* minValueNode(Node* root)
{
	Node* curr = root;
	while (curr->left != nullptr)
	{
		curr = curr->left;
	}
	return curr;
}


class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

	Node* addNode(Node* root, double value)
	{
		if (root == nullptr)
		{
			Node* temp = new Node(value);
			temp->height = 1;
			return temp;
		}
		if (value < root->value)
		{
			root->left = addNode(root->left, value);

		}
		else if (value > root->value)
		{
			root->right = addNode(root->right, value);
		}
		else
		{
			cout << value << " already added\n";
			return root;
		}

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		int balance = getBalance(root);


		if (balance > 1 && value < root->left->value)
		{
			return rightRotate(root);
		}


		if (balance<-1 && value > root->right->value)
		{
			return leftRotate(root);
		}


		if (balance > 1 && value > root->left->value)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}


		if (balance < -1 && value < root->right->value)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* deleteNode(Node* root, double value)
	{
		if (root == nullptr)
		{
			cout << value << " not found to remove\n";
			return nullptr;
		}

		if (value < root->value)
		{
			root->left = deleteNode(root->left, value);

		}
		else if (value > root->value)
		{
			root->right = deleteNode(root->right, value);
		}
		else
		{
			if (root->left == nullptr)
			{
				Node *temp = root->right;

				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;

				}
				free(temp);

			}
			else if (root->right == nullptr)
			{
				Node *temp = root->left;
				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;

				}
				free(temp);
			}

			else
			{

				Node* temp = minValueNode(root->right);
				root->value = temp->value;
				root->right = deleteNode(root->right, temp->value);
			}
		}



		if (root == nullptr)
			return root;

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);


		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);


		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}



public:
	AVLTree()
	{
		root = NULL;
	}


	void add(double value)
	{
		this->root = this->addNode(this->root, value);

	}

	void remove(double value)
	{
		this->root = this->deleteNode(this->root, value);

	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};
