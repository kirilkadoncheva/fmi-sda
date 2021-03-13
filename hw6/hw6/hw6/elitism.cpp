/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>

void swap(double& x, double& y)
{
	double a = x;
	x = y;
	y = a;
}

class minHeap
{
private:
	double* arr;
	int capacity;
	int size;

public:
	minHeap(int capacity)
	{
		arr = new double[capacity];
		this->capacity = capacity;
		this->size = 0;
	}

	int getSize()
	{
		return this->size;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void bubbleDown(int i)
	{
		int length = this->size;
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
		if (this->size > 0)return arr[0];
		return -1;
	}

	void pop()
	{
		int length = this->size;
		if (length == 0)return;
		arr[0] = arr[length - 1];
		this->size--;
		if(this->size>0)bubbleDown(0);

	}

	void push(double value)
	{
		int length = this->size;
		if (this->size < capacity)
		{
			arr[this->size] = value;
			this->size++;
			bubbleUp(length);
		}
		
	}

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

};

class maxHeap
{
private:
	double* arr;
	int capacity;
	int size;
public:
	maxHeap(int capacity)
	{
		arr = new double[capacity];
		this->capacity = capacity;
		this->size = 0;
	}
	int getSize()
	{
		return this->size;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void bubbleDown(int i)
	{
		int length = this->size;
		int l = leftChild(i);
		int r = rightChild(i);
		if (l >= length)return;

		int max = i;
		if (arr[i] < arr[l])max = l;
		if (r < length&&arr[max] < arr[r])max = r;
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
		if (this->size > 0)return arr[0];
		return -1;
	}

	void pop()
	{
		int length = this->size;
		if (length == 0)return;
		arr[0] = arr[length - 1];
		this->size--;
		if(this->size>0)bubbleDown(0);

	}

	void push(double value)
	{
		int length = this->size;
		if (this->size < capacity)
		{
			
			arr[this->size]=value;
			this->size++;
			bubbleUp(length);
		}
	}

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};

double getMedian(double x, double& m, maxHeap* l, minHeap* r)
{
	int indicator = 0;
	int lSize = l->getSize();
	int rSize = r->getSize();
	if (lSize > rSize)indicator = 1;
	else if (lSize < rSize)indicator = -1;
	switch (indicator)
	{
	case 0:
		if (x < m)
		{
			l->push(x);
			m = l->top();
		}
		else
		{
			r->push(x);
			m = r->top();
		}
		break;
	case -1:
		if (x < m)
		{
			l->push(x);
		}
		else
		{
			l->push(r->top());
			r->pop();
			r->push(x);
		}
		m = (l->top() + r->top()) / 2;
		break;
	case 1:
		if (x < m)
		{
			r->push(l->top());
			l->pop();
			l->push(x);
		}
		else
		{
			r->push(x);
		}
		m = (l->top() + r->top()) / 2;
		break;
	}

	return m;
}
int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	double m = 0;
	maxHeap* l = new maxHeap(500000);
	minHeap* r = new minHeap(500000);

	for (int i = 0; i < n; i++)
	{
		double x;
		std::cin >> x;
		m = getMedian(x, m, l, r);
		std::cout << std::fixed << std::setprecision(1) << m << "\n";
	}
	return 0;
}
*/