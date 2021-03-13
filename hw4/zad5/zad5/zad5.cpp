#include <iostream>


class node {
public:
	int data;
	node* next;

	node(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
	~node()
	{
		delete this->next;
	}
	
};

class Stack {
public:
	node *head;
	

	Stack() {
		this->head = nullptr;
	
	}

	~Stack()
	{
		while (this->head != nullptr)
		{
			node* temp = this->head;
			this->head = this->head->next;

			delete temp;
		}
	}
	void push(int node_data) {
		node* newNode = new node(node_data);

		if (this->head==NULL) {
			this->head = newNode;
		}
		else {
			newNode->next = this->head;
			this->head = newNode;
		}

		
	}

	

	int pop()
	{
		node* toDelete = this->head;
		if (this->head == NULL)return 0;
		this->head = this->head->next;
		
		int x = toDelete->data;
		delete toDelete;
		return x;
	}
	int peek()
	{
		if(this->head!=NULL)return this->head->data;
		return 0;
	}

	bool isEmpty()
	{
		if (this->head == NULL) { return true; }
		return false;
	}

};

bool possible(int* trucks, int n)
{
	Stack* buffer = new Stack();


	int counter = 1;
		
		for (int i = 1; i < n; i++)
	{
		int x = trucks[i - 1];
		if (x > trucks[i])
		{
			buffer->push(x);

		}
		else
		{
			if (x > counter) { return false; }
			counter++;
		}
	}
		return true;
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		int* trucks = new int[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> trucks[i];
		}

		if (possible(trucks, n))std::cout << "yes\n";
		else std::cout << "no\n";

		delete trucks;
	}

	return 0;
}