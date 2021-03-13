#include <iostream>
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
	std::queue<Student>* groups= new std::queue<Student>[m];
	std::queue<Student> firstOfEachGroup;
	//int t = 0;
	Student temp;
	std::cin >> temp.name;
	std::cin >> temp.group;
	temp.arrived = 0;
	firstOfEachGroup.push(temp);
	groups[temp.group - 1].push(temp);
	for (int i = 1; i < n; i++)
	{
		
		std::cin >> temp.name;
		std::cin >> temp.group;
		temp.arrived = i;
		if (temp.group != firstOfEachGroup.front().group)
		{
			if (groups[temp.group - 1].empty())
			{
				firstOfEachGroup.push(temp);
				groups[temp.group - 1].push(temp);
			}
			else if(abs(groups[temp.group-1].back().arrived-temp.arrived)<=2)
			{
				groups[temp.group - 1].push(temp);
			}
			else
			{
				firstOfEachGroup.push(temp);
			}
		}
		else
		{
			if (groups[temp.group - 1].empty())
			{
				firstOfEachGroup.push(temp);
				groups[temp.group - 1].push(temp);
			}
			else if (abs(groups[temp.group - 1].front().arrived - temp.arrived) <= 2)
			{
				groups[temp.group - 1].push(temp);
			}
			else
			{
				firstOfEachGroup.push(temp);
			}
		}
		//groups[temp.group - 1].push(temp);
	
	}
	int t = 2;
	//std::cout << "output:\n";
	while (!firstOfEachGroup.empty())
	{
		//std::cout << "foeg: " << firstOfEachGroup.front().name << " \n";
		int group = firstOfEachGroup.front().group;
		std::cout << firstOfEachGroup.front().name << " " << firstOfEachGroup.front().arrived << " " << t << "\n";
		if(!groups[group - 1].empty())groups[group - 1].pop();
		t = t + 2;
		//std::cout << "group: " << firstOfEachGroup.front().group << "\n";
		while (!groups[group - 1].empty())
		{
			std::cout << groups[group - 1].front().name << " " << groups[group - 1].front().arrived << " " << t << "\n";
			t = t + 2;
			groups[group - 1].pop();
		}
		//std::cout << "...................\n";
		firstOfEachGroup.pop();
	}

	return 0;
}