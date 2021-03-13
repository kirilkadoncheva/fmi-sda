#include <iostream>
struct ballbon
{
public:
	long long int ball;
	long long int bon;
	long long int maxbons;
	bool operator<=(ballbon& other)
	{
		return this->maxbons <= other.maxbons;
	}
};

void merge(ballbon* arr, int l, int m, int r)
{
	ballbon* arrL = new ballbon[m - l + 1];
	ballbon* arrR = new ballbon[r - m];
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
void mergeSort(ballbon* arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

bool possibleAnswer(ballbon* arr, int n, long long int m, long long int x)
{
	long long int counterBalloons = 0;
	int i = 0;
	while (arr[i].maxbons <= x&&i<n)
	{
		i++;
	}
	for (; i < n; i++)
	{
		long long int left = arr[i].maxbons - x;
		counterBalloons = counterBalloons + left / arr[i].bon;
		if (left%arr[i].bon > 0) { counterBalloons++; }
	}
	if (counterBalloons <= m)return true;
	return false;
}

long long int minBonbons(ballbon* arr, int n, long long int m)
{
	long long int l = 0;
	long long int r = arr[n - 1].maxbons;
	long long int min = r;
	//std::cout << min << "\n";
	while (l < r)
	{
		long long int mid = (l + r) / 2;
		if (possibleAnswer(arr, n, m, mid))
		{
			if (mid <= min) { min = mid; r = mid; }
		}
		else
		{
			l = mid + 1;
		}
	}

	return min;
}
int main()
{
	int n;
	long long int m;
	std::cin >> n;
	std::cin >> m;
	ballbon* input = new ballbon[n];
	long long int* maxbons = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i].ball;
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i].bon;
	    input[i].maxbons = input[i].ball*input[i].bon;
	}

	mergeSort(input, 0, n - 1);
	std::cout << minBonbons(input, n, m)<<"\n";
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << input[i].ball << " ";
	//}
	//std::cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << input[i].bon << " ";
	//}
	//std::cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << input[i].maxbons << " ";
	//}
	return 0;
}