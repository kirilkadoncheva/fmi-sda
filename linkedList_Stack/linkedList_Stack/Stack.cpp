#include <iostream>

struct Node
{
	int data;
	struct Node* next;
public:


	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
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

	
	void push( int data)
	{
		Node* temp = new Node(data);
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			this->head=temp;
		}

		





	}

	int pop()
	{
		if (head != NULL)
		{
			Node* temp = head;

			int x = head->data;
			head = head->next;

			delete temp;

			return x;
		}
		return -1;
	}


	void print()
	{
		Node* temp = this->head;
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << "\n";
	}

	
	bool search(int x)
	{
		Node* temp = this->head;
		while (temp != NULL)
		{
			if (temp->data == x) { return true; }
			temp = temp->next;
		}
		return false;
	}

	void free()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

};

int main()
{

	Stack* a = new Stack();
	a->print();
	return 0;
}