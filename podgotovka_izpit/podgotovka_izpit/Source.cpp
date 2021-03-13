#include <iostream>
//#include "BST.h"

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
	Node* roott;
	Node* insertt(Node* root, int x)
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
	
public:
	BST()
	{
		roott = NULL;
	}
	void insert(int x)
	{
		roott = insertt(roott, x);
	}
	void remove(int x)
	{
		roott = removee(roott, x);
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
	void print()
	{
		//cout << "print\n";
		inOrder(roott);
	}
};
int main()
{
	BST a;
	//cout << "a: \n";
	//a.print();
	//a.insert(2);
	//a.print();
	//a.insert(-1);
	//a.insert(6);
	//a.insert(4);
	//a.insert(7);
	//a.print();
	//a.remove(2);
	//a.print();
	//a.remove(11);
	//a.insert(4);
	//a.print();
	//Queue a;
	//a.enqueue(1);
	//a.enqueue(2);
	//a.enqueue(3);
	//cout << a.peek() << "\n";
	//a.dequeue();
	//cout << a.peek() << "\n";
	//LinkedList l;
	//l.insertAtBeginning(7);
	//l.insertAtBeginning(8);
	//l.insertAtEnd(6);
	//
	//l.print();
	//l.deleteAtBeg();
	//l.print();
	//l.insertAtPos(3, 11);
	//l.print();

	//int* arr = new int[6];
	//arr[0] = 1;
	//arr[1] = 7;
	//arr[2] = -6;
	//arr[3] = 1;
	//arr[4] = 11;
	//arr[5] = 1;
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << "\n";
	//mergeSort(arr, 0,5);
	//cout << binarySearch(arr,6, 1) << "\n";
	//cout << "\n";
	return 0;
}