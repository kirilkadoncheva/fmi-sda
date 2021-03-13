#pragma once
#include <iostream>
#include <vector>

void swap(double& x, double& y)
{
	double a = x;
	x = y;
	y = a;
}

class minHeap
{
private:
	std::vector<double>arr;
	
public:
	minHeap()
	{
		
	}

	int getSize()
	{
		return arr.size();
	}

	int parent(int i)
    {
		return (i - 1) / 2;
	} 

	void bubbleDown(int i)
	{
		int length = arr.size();
		int l = leftChild(i);
		int r = rightChild(i);
		if (l >= length)return;

		int min = i;
		if (arr[i] > arr[l])min = l;
		if (r<length&&arr[min]>arr[r])min = r;
		if (min != i)
		{
			swap(arr[i], arr[min]);
			bubbleDown(min);
		}
	}

	void bubbleUp(int i)
	{
		if (i == 0)return;

		int p = parent(i);
		if (arr[p] > arr[i])
		{
			swap(arr[i], arr[p]);
			bubbleUp(p);
		}
	}
	int leftChild(int i)
	{
		return (2 * i + 1);
	}

	int rightChild(int i)
	{
		return (2 * i + 2);
	}

	double top()
	{
		if(arr.size()>0)return arr[0];
		return NULL;
	}

	void pop()
	{
		int length = arr.size();
		if (length == 0)return;
		arr[0] = arr[length - 1];
		arr.pop_back();
		bubbleDown(0);
		
	}

	void push(double value)
	{
		int length = arr.size();
		arr.push_back(value);
		bubbleUp(length);
	}

	void print()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i]<< " ";
		}
		std::cout << "\n";
	}

};

class maxHeap
{
private:
	std::vector<double> arr;
public:
	maxHeap()
	{

	}
	int getSize()
	{
		return arr.size();
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void bubbleDown(int i)
	{
		int length = arr.size();
		int l = leftChild(i);
		int r = rightChild(i);
		if (l >= length)return;

		int max = i;
		if (arr[i] < arr[l])max = l;
		if (r<length&&arr[max]<arr[r])max = r;
		if (max != i)
		{
			swap(arr[i], arr[max]);
			bubbleDown(max);
		}
	}

	void bubbleUp(int i)
	{
		if (i == 0)return;

		int p = parent(i);
		if (arr[p] < arr[i])
		{
			swap(arr[i], arr[p]);
			bubbleUp(p);
		}
	}
	int leftChild(int i)
	{
		return (2 * i + 1);
	}

	int rightChild(int i)
	{
		return (2 * i + 2);
	}

	double top()
	{
		if (arr.size() > 0)return arr[0];
		return NULL;
	}

	void pop()
	{
		int length = arr.size();
		if (length == 0)return;
		arr[0] = arr[length - 1];
		arr.pop_back();
		bubbleDown(0);

	}

	void push(double value)
	{
		int length = arr.size();
		arr.push_back(value);
		bubbleUp(length);
	}

	void print()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};