#pragma once
#include <iostream>
using namespace std;


void swap(double *x, double *y);

class MinHeap
{
	double *harr; 
	int capacity; 
	int heap_size; 
public:

	MinHeap(int capacity);

	int getSize() { return heap_size; }
	void MinHeapify(int);

	int parent(int i) { return (i - 1) / 2; }

	
	int left(int i) { return (2 * i + 1); }

	
	int right(int i) { return (2 * i + 2); }

	
	double pop();

	
	
	void decreaseKey(int i, double new_val);

	
	double top() { return harr[0]; }

	
	void deleteKey(int i);

	void push(double k);
};


MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new double[cap];
}


void MinHeap::push(double k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}


void MinHeap::decreaseKey(int i, double new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}


double MinHeap::pop()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap 
double root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	pop();
}


void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(double *x, double *y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

class MaxHeap
{
	double *harr;
	int capacity;
	int heap_size;
public:

	MaxHeap(int capacity);


	void MaxHeapify(int);

	int parent(int i) { return (i - 1) / 2; }


	int left(int i) { return (2 * i + 1); }


	int right(int i) { return (2 * i + 2); }

	int getSize() { return heap_size; }
	double pop();

	

	void decreaseKey(int i, double new_val);


	double top() { return harr[0]; }


	void deleteKey(int i);

	void push(double k);
};


MaxHeap::MaxHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new double[cap];
}


void MaxHeap::push(double k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}


	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;


	while (i != 0 && harr[parent(i)] < harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}


void MaxHeap::decreaseKey(int i, double new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] < harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}


double MaxHeap::pop()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap 
	double root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);

	return root;
}

void MaxHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	pop();
}


void MaxHeap::MaxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] > harr[i])
		smallest = l;
	if (r < heap_size && harr[r] > harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MaxHeapify(smallest);
	}
}

