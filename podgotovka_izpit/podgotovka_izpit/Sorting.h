#pragma once
#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;

}
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) { swap(arr[i], arr[j]); }
		}
	}
}

void selectionSort(int* arr, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j]) { min = j; }
		}
		swap(arr[min], arr[i]);
	}
}

void insertionSort(int* arr, int n)
{

	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
int partition(int* arr, int l, int r)
{
	
	int pivot = arr[r];

	int i = (l - 1);

		for (int j = l; j <= r - 1; j++)
		{
			
			if (arr[j] < pivot)
			{
				i++;    
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[r]);
			return (i + 1);
}
void quickSort(int* arr, int l, int r)
{
	if (l < r)
	{
		
		int pi = partition(arr, l, r);

		quickSort(arr, l, pi - 1);  
		quickSort(arr, pi + 1, r); 
	}
}

void merge(int* arr, int l, int m, int r)
{
	int size1 = m - l + 1;
	int size2 = r - m;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	for (int i = l; i <= m; i++)
	{
		arr1[i - l] = arr[i];
	}
	for (int i = m+1; i <= r; i++)
	{
		arr2[i - m-1] = arr[i];
	}
	int i = 0;
	int j = 0;
	int k = l;
	while (i < size1&&j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < size1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void mergeSort(int* arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

bool binarySearch(int* arr,int n, int x)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (x < arr[m])
		{
			r = m - 1;
		}
		else if (x > arr[m])
		{
			l = m + 1;
		}
		else return true;
	}
	return false;
}