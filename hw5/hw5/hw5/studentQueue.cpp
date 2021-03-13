/*#include <iostream>
#include <queue>
#include <string>

struct Student
{
	std::string name;
	int group;
	int arrived;

	Student()
	{
		name = "";
		group = -1;
		arrived = -1;
	}
};

struct node
{
	Student data;
	node* next;
	node(Student data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Queue
{
	node* head;
	node* tail;
public:
	Queue()
	{
		this->head = NULL;
		this->tail = NULL;
	}

	bool isEmpty()
	{
		return this->head == NULL;
	}

	Student peek()
	{
		return this->head->data;
	}

	void enqueue(Student data)
	{
		node* temp = new node(data);
		if (this->head == NULL)
		{
			this->head = temp;
			this->tail = temp;
			return;
		}
		this->tail->next = temp;
		this->tail = temp;

	}
	void dequeue()
	{
		if (this->head == NULL)return;
		node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	void print()
	{
		node* temp = this->head;
		while (temp != NULL)
		{
			std::cout << "(" << temp->data.name << " " << temp->data.group << ") ";
			temp = temp->next;
		}
		std::cout << "\n";
	}
	void free()
	{
		node* temp = this->head;
		while (temp != NULL)
		{
			node* toDelete = temp;

			temp = temp->next;
			delete toDelete;
		}
		this->head = NULL;
		this->tail = NULL;
	}
	node* findGroup(int group)
	{
		node* temp = this->head;
		while (temp != NULL)
		{
			if (temp->data.group == group)return temp;
			temp = temp->next;
		}
		return NULL;
	}
	int size()
	{
		int counter = 0;
		node* temp = this->head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
};
int main()
{
	int n, m;
	std::cin >> n >> m;
	std::queue<Student>* groups = new std::queue<Student>[m];
	std::queue<Student> firstOfEachGroup;
	//int t = 0;
	Student temp;
	std::cin >> temp.name;
	std::cin >> temp.group;
	temp.arrived = 0;
	firstOfEachGroup.push(temp);
	groups[temp.group - 1].push(temp);
	int i = 1;
	bool buffer = false;
	for (i; i < n; i++)
	{

		std::cin >> temp.name;
		std::cin >> temp.group;
		temp.arrived = i;

		if (groups[temp.group - 1].empty())
		{
			firstOfEachGroup.push(temp);

		}
		groups[temp.group - 1].push(temp);

		//std::cout << "New in : " << temp.group << " " << groups[temp.group - 1].back().name << "\n";
		if (i % 2 == 0)
		{

			int grToLeave = firstOfEachGroup.front().group;

			Student out = groups[grToLeave - 1].front();
			//if (i == 8) std::cout << "i=8: " << out.name << "\n";
			groups[grToLeave - 1].pop();
			std::cout  << out.name << " " << out.arrived << " " << i << "\n";
			 if (!groups[grToLeave - 1].empty()) buffer = true; 
			if (groups[grToLeave - 1].empty())firstOfEachGroup.pop();
			
		}
		//groups[temp.group - 1].push(temp);

	}
	if (i % 2 != 0)i++;
	// std::cout << "output:\n";
	//std::cout << firstOfEachGroup.front().name << "\n";
	if (buffer)
	{
		//std::cout << "YES!\n";
		int group = firstOfEachGroup.front().group;
		
		// std::cout << "group: " << firstOfEachGroup.front().group << "\n";
		while (!groups[group - 1].empty())
		{
			std::cout << groups[group - 1].front().name << " " << groups[group - 1].front().arrived << " " << i << "\n";
			i = i + 2;
			groups[group - 1].pop();
		}
		// std::cout << "...................\n";
		firstOfEachGroup.pop();
	}
	while (!firstOfEachGroup.empty())
	{
		//std::cout << "foeg: " << firstOfEachGroup.front().name << " \n";
		
		int group = firstOfEachGroup.front().group;
		std::cout << firstOfEachGroup.front().name << " " << firstOfEachGroup.front().arrived << " " << i << "\n";
		if (!groups[group - 1].empty())groups[group - 1].pop();
		i = i + 2;
		// std::cout << "group: " << firstOfEachGroup.front().group << "\n";
		while (!groups[group - 1].empty())
		{
			std::cout << groups[group - 1].front().name << " " << groups[group - 1].front().arrived << " " << i << "\n";
			i = i + 2;
			groups[group - 1].pop();
		}
		// std::cout << "...................\n";
		firstOfEachGroup.pop();
	}

	return 0;
}*/