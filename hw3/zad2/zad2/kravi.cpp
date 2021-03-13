#include <iostream>

void merge(long long int* arr, int l, int m, int r)
{
	long long int* arrL = new long long int[m - l + 1];
	long long int* arrR = new long long int[r - m];
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
void mergeSort(long long int* arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
bool possibleAnswer(long long int* arr, int n, int k, int x)
{
	int counter = 1;
	int koliba = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - koliba >= x)
		{
			counter++;
			koliba = arr[i];
			if (counter == k)return true;
		}
	}
	return false;
}
unsigned long long int longestDistance(long long int* arr, int n, int k)
{
	int l = 0;
	int r = arr[n - 1];
	unsigned long long int maxx = 0;
	//std::cout << maxx << "\n";
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (possibleAnswer(arr, n, k, mid))
		{
			if (mid > maxx) { maxx = mid; }
			l = mid + 1;

		}
		else
		{
			r = mid;
		}
	}
	return maxx;
}
int main()
{
	int n, k;
	std::cin >> n;
	std::cin >> k;
	long long int* kolibi = new long long int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> kolibi[i];
	}

	mergeSort(kolibi, 0, n - 1);

	std::cout << longestDistance(kolibi, n, k);

	return 0;
}