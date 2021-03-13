#include <iostream>
struct ballbon
{
public:
	int ball;
	int bon;

	bool operator<=(ballbon& other)
	{
		return this->bon <= other.bon;
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

int main()
{
	int n, m;
	std::cin >> n;
	std::cin >> m;
	ballbon* input = new ballbon[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i].ball;
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i].bon;
	}

	mergeSort(input, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		std::cout << input[i].ball<<" ";
	}
	std::cout << "\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << input[i].bon<<" ";
	}
	return 0;
}