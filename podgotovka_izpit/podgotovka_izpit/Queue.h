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

class Queue
{
	Node* head;
	Node* tail;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;

	}
	void enqueue(int val)
	{
		if (head == NULL)
		{
			Node* temp = new Node(val);
			head = temp;
			tail = temp;
		}
		else
		{
			Node* temp = new Node(val);
			tail->next = temp;
			tail = temp;
		}
	}
	

	void dequeue()
	{
		if (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}


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
	~Queue()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};