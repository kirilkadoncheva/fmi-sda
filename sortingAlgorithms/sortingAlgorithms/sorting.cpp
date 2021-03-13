#include <iostream>

void merge(int* arr, int l, int m, int r)
{
	int* arrL = new int[m - l+1];
	int* arrR = new int[r - m];
	int sizeL = m - l + 1;
	int sizeR = r - m;
	for (int i = l; i <= m; i++)
	{
		arrL[i-l] = arr[i];
	}
	for (int i = m+1; i <= r; i++)
	{
		arrR[i-m-1] = arr[i];
	}

	int iL = 0;
	int iR = 0;
	int i = l;
	while (iL < sizeL&&iR < sizeR)
	{
		if (arrL[iL] <= arrR[iR]) { arr[i] = arrL[iL]; iL++; }
		else { arr[i] = arrR[iR]; iR++; }
		i++;
	}
	while (iL < sizeL)
	{
		arr[i] = arrL[iL]; iL++; i++;
	}
	while (iR < sizeR)
	{
		arr[i] = arrR[iR]; iR++; i++;
	}
}
void mergeSort(int* arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot) { std::swap(arr[i], arr[j]); i++; }
	}
	std::swap(arr[i], arr[high]);
	return i;
}
void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi, high);
	}
}

void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j + 1]) { std::swap(arr[j], arr[j + 1]); }
		}
	}
}

void selectionSort(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[iMin]) { iMin = j; }
		}
		if(i!=iMin)std::swap(arr[i], arr[iMin]);
	}
}

void insertionSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			
			arr[j + 1] = arr[j];
			j--;

		}
		arr[j+1] = key;
	}
}

void countingSort(char* arr, int n)
{
	char* arrCopy = new char[n];

	
	int* counting = new int[256];
	for (int i = 0; i < n; i++)
	{
		arrCopy[i] = arr[i];
		counting[arr[i]]++;
	}
		
	for (int i = 1; i < 256; i++)
	{
		counting[i] = counting[i] + counting[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		arr[counting[arrCopy[i]] - 1] = arrCopy[i];
		counting[arrCopy[i] - 1]--;
	}
}

void bubbleSort1(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) { std::swap(arr[j], arr[j + 1]); }
		}
	}
}

void insertionSort1(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int partition1(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot) { std::swap(arr[i], arr[j]); i++; }
	}
	std::swap(arr[i], arr[high]);

	return i;

}
void quickSort1(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition1(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void selectionSort1(int* arr, int n)
{
	for (int i = n-1; i >= 0; i--)
	{
		int iMax = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > arr[iMax]) { iMax = j; }
		}
		if (i != iMax) { std::swap(arr[i], arr[iMax]); }
	}
}

int main()
{
	int n;
	std::cin >> n;
	//char* word = new char[3];
	//word[0] = 'b';
	//word[1] = 'c';
	//word[2] = 'a';
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout<< word[i];
	//
	//}
	//std::cout << "\n";
	//countingSort(word,3);
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout<< word[i];
	//
	//}
	int* a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	
	}
	//quickSort1(a, 0, n - 1);
	selectionSort1(a, n);
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i]<<" ";
	
	}
	std::cout << "\n";
	

	return 0;
}