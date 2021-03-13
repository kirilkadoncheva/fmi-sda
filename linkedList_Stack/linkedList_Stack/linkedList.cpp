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

class SinglyLinkedList
{
	Node* head;
	Node* tail;
public:
	SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtEnd(int data)
	{
		Node* temp = new Node(data);
		temp->next = NULL;
		if (this->head == NULL)
		{
			
			this->head = temp;
			this->tail = temp;

		}
		else
		{
			this->tail->next = temp;
		}
	}
	int size()
	{
		int counter = 0;
		Node* temp = this->head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool isPalindrome()
	{
		if (this->head == NULL || this->head->next == NULL)return true;
		int size = this->size();
		int middle = size / 2;
		Node* newHead;
		Node* current = head;
		Node* next = head->next;
		head->next = NULL;
		int counter = 1;
		Node* prev=NULL;
		Node* nextNext = NULL;
		while (counter<middle)
		{
			prev = current;
			nextNext = next->next;
			next->next = current;
			current = next;
			next = nextNext;

			counter++;

		}
		this->head = current;
		newHead = nextNext;
		//std::cout << "reversed: \n";
		//while (this->head != NULL)
		//{
		//	std::cout << this->head->data << " ";
		//	this->head = this->head->next;
		//	//newHead = newHead->next;
		//}
		//std::cout << "\n";
		//std::cout << size << " " << counter << "\n";
		if (size % 2 != 0)
		{
		//	std::cout << "size\n";
			newHead = newHead->next;
		}

		while (this->head != NULL)
		{
			//std::cout << this->head->data << " " << newHead->data << "\n";
			if (this->head->data != newHead->data)return false;
			this->head = this->head->next;
			newHead = newHead->next;
		}
		return true;


	}
	void insertAtPosition(int position, int data)
	{
		Node* temp = new Node(data);
		temp->next = NULL;
		

		if (position == 0)
		{
			temp->next = this->head;
			this->head = temp;
		}
		else
		{
			Node* previous = head;
			Node* current = head->next;
			int counterPos = 1;
			if (current == NULL)
			{
				if (position == 1)
				{
					this->head->next = temp;
					temp->next = NULL;
					this->tail = temp;
					return;
				}
				else

				{
					std::cout << "ERROR!\n"; return;
				}
			}
			while (counterPos < position)
			{
				if (current == NULL && counterPos + 1 < position) { std::cout << "ERROR!\n"; return; }
				previous = current;
				current = current->next;
				counterPos++;
			}
			//std::cout << previous->data << " " << current->data << "\n";
			temp->next = current;
			previous->next = temp;
			
			
		}
		
		

		

	}

	void deleteFirst()
	{
		if (head != NULL)
		{
			Node* temp = head;

			head = head->next;

			delete temp;
		}
	}

	void deleteLast()
	{
		if (tail == NULL) { return; }
		Node* prev = this->head;
		Node* current = this->head->next;
		if (current == NULL)
		{
			this->head = NULL;
			delete current;
			return;
		}
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;

		}
		delete current;
		prev->next = NULL;
		this->tail = prev;
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

	void deleteAtPosition(int position)
	{
		if (position < 0) { return; }
		if (position == 0)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
			return;
		}
		Node* prev = this->head;
		Node* current = this->head->next;
		int counterPos = 1;
		while (counterPos < position)
		{
			if (current == NULL) { return; }
			prev = current;
			current = current->next;
			counterPos++;
		}
		//std::cout << prev->data;
		prev->next = current->next;
		if (current->next == NULL) { this->tail = prev; }
		delete current;
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
Node* reverse(Node* head)
{

	if (head == NULL || head->next == NULL) return head;
	Node* newHead;
	Node* current = head;
	Node* next = head->next;
	head->next = NULL;

	while (next != NULL)
	{
		Node* nextNext = next->next;
		next->next = current;
		current = next;
		next = nextNext;



	}
	newHead = current;
	return newHead;



}
int main()
{

	SinglyLinkedList* a =new SinglyLinkedList();
	a->print();

	
     a->insertAtPosition(0, 1);
a->print();

//a->insertAtPosition(1, 2);
a->insertAtPosition(1, 1);
a->insertAtPosition(1, 2);
a->insertAtPosition(1, 3);
a->insertAtPosition(1, 7);
a->insertAtPosition(1, 3);
a->insertAtPosition(1, 2);
a->print();
std::cout << a->isPalindrome() << "\n";

//a->insertAtPosition(1, 9);
//a->print();
//
//std::cout << a->search(7) << "\n";
//
//std::cout << a->search(11) << "\n";
//a->print();
//	
//a->free();
//a->print();
	return 0;
}