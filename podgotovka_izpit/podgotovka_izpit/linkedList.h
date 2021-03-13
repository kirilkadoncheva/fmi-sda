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

class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;

	}
	void insertAtBeginning(int val)
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
			temp->next = head;
			head = temp;
		}
	}
	void insertAtEnd(int val)
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
	void insertAtPos(int pos,int val)
	{
		int counter = 1;
		if (head == NULL) { this->insertAtEnd(val); return; }
		if (pos == 0) { this->insertAtBeginning(val); return; }
		Node* prev = head;
		Node* curr = head->next;
		while (counter < pos&&curr!=NULL)
		{
			counter++;
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL) {
			Node* temp = new Node(val);
			prev->next = temp;
			temp->next = curr;
		}
		else this->insertAtEnd(val);
	}
	void deleteAtBeg()
	{
		if (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		

	}
	
	void deleteAtPos(int pos)
	{
		if (head != NULL)
		{
			if (pos == 0) { this->deleteAtBeg(); return; }
			int counter = 0;
			Node* prev = head;
			Node* curr = head->next;
			while (counter < pos&&curr!=NULL)
			{
				counter++;
				prev = curr;
				curr = curr->next;
			}
			
			if (curr != NULL) {
				prev->next = curr->next;
				delete curr;
			}
		}
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
	~LinkedList()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};