#include <iostream>



long int merge(int* arr, int l, int m, int r)
{
	long int counter = 0;;
	int* arrL = new int[m - l + 1];
	int* arrR = new int[r - m];
	int sizeL = m - l + 1;
	int sizeR = r - m;
	for (int i = l; i <= m; i++)
	{
		arrL[i - l] = arr[i];
	}
	for (int i = m + 1; i <= r; i++)
	{
		arrR[i - m - 1] = arr[i];
	}

	int iL = 0;
	int iR = 0;
	int i = l;
	while (iL < sizeL&&iR < sizeR)
	{
		if (arrL[iL] <= arrR[iR]) { arr[i++] = arrL[iL++]; }
		else { arr[i++] = arrR[iR++];  counter += m + 1 - iL - l; }
		
	}
	while (iL < sizeL)
	{
		arr[i] = arrL[iL]; iL++; i++;
	}
	while (iR < sizeR)
	{
		arr[i] = arrR[iR]; iR++; i++;
	}

	delete[] arrL;
	delete[] arrR;
	return counter;
}



long int mergeSort(int* arr, int l, int r)
{
	long int inversionsCounter = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		inversionsCounter = mergeSort(arr, l, m);
		inversionsCounter += mergeSort(arr, m + 1, r);
		inversionsCounter += merge(arr, l, m, r);
	}
	return inversionsCounter;
}


int main()
{
	int n;
	std::cin >> n;
	int* buildings = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> buildings[i];

	}
	std::cout << mergeSort(buildings, 0, n - 1) << "\n";

	delete[] buildings;

	return 0;

}

