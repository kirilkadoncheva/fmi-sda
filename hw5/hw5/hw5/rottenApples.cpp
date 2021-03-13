/*#include <iostream>
struct apple
{
	int x, y,day;
	apple()
	{
		this->x = 0;
		this->y = 0;
		this->day = 0;
	}
};
struct node
{
	apple data;
	node* next;
	node(apple data)
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

	apple peek()
	{
		return this->head->data;
	}
	void enqueue(apple data)
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
			std::cout << "("<<temp->data.x << " "<<temp->data.y<<" "<<temp->data.day<<") ";
			temp = temp->next;
		}
		std::cout <<"\n";
	}
	bool find(int x, int y)
	{
		node* temp = this->head;
		while (temp != NULL)
		{
			if (temp->data.x == x && temp->data.y == y)return true;
			temp = temp->next;
		}
		return false;
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
	int n, m, t;
	std::cin >> n >> m >> t;
	int counter = 0;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = 0;
		}
	}
	int x, y;
	int day = 0;
	
	Queue a;
	while (std::cin >> x >> y)
	{
		if (x >= 1 && x <= n&&y >= 1 && y <= m)
		{
			counter++;
			matrix[x - 1][y - 1] = 1;
			apple temp;
			temp.x = x;
			temp.y = y;
			temp.day = day;
			a.enqueue(temp);
		}
		
	}
	std::cout << day << "\n";
	while(day<t&&(!a.isEmpty())/*&&(!(a.peek().x==first.x&&a.peek().y==first.y)))
	{
		//if (a.isEmpty()) { break; }
		apple temp = a.peek();
		
		int prevDay = day;
		day++;
		//std::cout << prevDay<<"\n";
		while (temp.day == prevDay&&(!a.isEmpty()))
		{
			//std::cout << a.peek().x << " " << a.peek().y << ":\n ";
			if (temp.x - 1 >= 1&&matrix[temp.x-2][temp.y-1]==0)
			{
				counter++;
				apple rotten;
				rotten.x = temp.x - 1;
				rotten.y = temp.y;
				rotten.day = day;
				matrix[rotten.x - 1][rotten.y - 1] = 1;
				//std::cout << "(" << rotten.x << " " << rotten.y << ") ";
				a.enqueue(rotten);
				
			}
			if (temp.x + 1 <= n && matrix[temp.x ][temp.y-1] == 0)
			{
				counter++;
				apple rotten;
				rotten.x = temp.x + 1;
				rotten.y = temp.y;
				rotten.day = day;
				matrix[rotten.x - 1][rotten.y - 1] = 1;
				//std::cout << "(" << rotten.x << " " << rotten.y << ") ";
				a.enqueue(rotten);
				
			}
			if (temp.y - 1 >= 1 && matrix[temp.x-1][temp.y-2] == 0)
			{
				counter++;
				apple rotten;
				rotten.x = temp.x ;
				rotten.y = temp.y-1;
				rotten.day = day;
				matrix[rotten.x - 1][rotten.y - 1] = 1;
				//std::cout << "(" << rotten.x << " " << rotten.y << ") ";
				a.enqueue(rotten);
				
			}
			if (temp.y+1 <=m && matrix[temp.x -1][temp.y] == 0)
			{
				counter++;
				apple rotten;
				rotten.x = temp.x ;
				rotten.y = temp.y+1;
				rotten.day = day;
				matrix[rotten.x - 1][rotten.y - 1] = 1;
				//std::cout << "(" << rotten.x << " " << rotten.y << ") ";
				a.enqueue(rotten);
				
			}
			//std::cout  << counter << "\n";
			a.dequeue();
			
			//a.print();
			
			temp = a.peek();
		}
	}
	//a.print();
	std::cout <<n*m-counter<< "\n";
	return 0;
}*/