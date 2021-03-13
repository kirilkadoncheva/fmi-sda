#include <iostream>
#include <time.h>
#include <stdlib.h>
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}
int partition(int* arr, int low, int high)
{
	//srand(time(NULL));
	//int p = rand() % (high) + low;

	if (high != low)swap(arr[high - 1], arr[high]);
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);

		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int firstAliveMonster(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)return i;
	}
	return -1;
}

int main()
{
	int n;
	int x;
	std::cin >> n;
	std::cin >> x;
	int size = n;
	int* monsters = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> monsters[i];
	}
	int* newMonsters = new int[n];
	quickSort(monsters, 0, n - 1);
	int p = 0;
	for (int i = 0; i < n;)
	{
		newMonsters[p] = monsters[i];
		i++;
		
		//std::cout<<monsters[i]<<" "<<newMonsters[p]
		while (monsters[i] == newMonsters[p])
		{
			i++;
		}
		p++;
	}
	delete[] monsters;
	monsters = newMonsters;
	//for (int i = 0; i < p; i++)
	//{
	//	std::cout<< monsters[i]<<" ";
	//}
	int counter = 0;
	size = p;
	//for (int i = 0; i < n; i++)
	//{
	//    std::cout << monsters[i]<<" ";
	//}
	//std::cout << "\n";
	
	int i =  p- 1;
	int lastBombed = p;
	int firstAlive = firstAliveMonster(monsters, lastBombed);
	while (firstAlive >= 0)
	{
		if (i < 0)i = lastBombed - 1;
		if (monsters[i] > 0)
		{
			//int pos = monsters[i];
			lastBombed = i;
	     
			//while (monsters[i] == pos && i >= 0)
			//{
			//
			//	monsters[i] = 0;
			//	i--;
			//}
	
			counter++;
			for (int j = i; j >= firstAlive; j--)
			{
				if (monsters[j] > 0)monsters[j] = monsters[j] - x;
	
			}
			i--;
		}
		else { i--; }
		//std::cout << lastBombed << "\n";
		firstAlive = firstAliveMonster(monsters, lastBombed);
	
	}
	std::cout << counter << "\n";

	return 0;
}