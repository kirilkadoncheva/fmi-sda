#pragma once
#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class Stack
{
	Node* head;
	
public:
	Stack()
	{
		head = NULL;
		

	}
	void push(int val)
	{
		if (head == NULL)
		{
			Node* temp = new Node(val);
			head = temp;
			
		}
		else
		{
			Node* temp = new Node(val);
			temp->next = head;
			head = temp;
		}
	}
	
	
	int pop()
	{
		if (head != NULL)
		{
			Node* temp = head;
			int p = head->data;
			head = head->next;
			delete temp;
			return p;
		}
		return NULL;

	}

	int peek()
	{
		if (head != NULL)
		{
			
			int p = head->data;
			
			return p;
		}
		return NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)return true;
		return false;
	}
	void print()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;

		}
		cout << "\n";
	}
	~Stack()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};