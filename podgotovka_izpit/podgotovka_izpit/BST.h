#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BST
{
	Node* root;
	Node* insertt(Node* root,int x)
	{
		if (root == NULL)
		{
			Node* temp = new Node(x);
			root = temp;
			return root;
		}
		if (root->data > x)
		{
			root->left = insertt(root->left, x);

		}
		else if (x > root->data)
		{
			root->right = insertt(root->right, x);
		}
		return root;
	}
	Node* minValue(Node* root)
	{
		Node* curr = root;
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}
	Node* removee(Node* root, int x)
	{
		if (root == NULL)
		{
			return root;
		}
		if (x < root->data)
		{
			root->left = removee(root->left, x);
		}
		else if (x > root->data)
		{
			root->right = removee(root->right, x);
		}
		else
		{
			if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				Node* temp = minValue(root->right);
				root->data = temp->data;
				root->right = removee(root->right, temp->data);
				delete temp;
			}
		}
		return root;
	}
	void inOrder(Node* root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
	}
public:
	BST()
	{
		root = NULL;
	}
	void insert(int x)
	{
		insertt(root, x);
	}
	void remove(int x)
	{
		removee(root,x);
	}
	void print()
	{
		inOrder(root);
	}
};