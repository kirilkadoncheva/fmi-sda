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

		if (this->head == NULL) {
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
		if (this->head != NULL)return this->head->data;
		return 0;
	}

	bool isEmpty()
	{
		if (this->head == NULL) { return true; }
		return false;
	}

	void free()
	{
		Stack::~Stack();
	}

};
int main()
{
	int n;
	std::cin >> n;
	int* trees = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> trees[i];
	}

	Stack* st = new Stack();
	st->push(trees[n - 1]);
	int maxCounter = 1;
	int maxIndex = n - 1;
	int prevVisible = 1;

	for (int i = n - 2; i >= 0; i--)
	{
		prevVisible++;

		while (st->peek() <= trees[i] && (!st->isEmpty()))
		{
			prevVisible--;
			st->pop();
		}

		st->push(trees[i]);
		if (prevVisible >= maxCounter)
		{
			maxCounter = prevVisible;
			maxIndex = i;
		}
	}

	std::cout << maxIndex << "\n";
	return 0;
}