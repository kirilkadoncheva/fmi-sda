#include <iostream>
int binarySearch(long long int* a, int n,long long int x)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		long long int prev = 0;
		if (mid != 0) { prev = a[mid - 1]; }
		if (x >= prev + 1 && x <= a[mid] ) { return mid; }
		else if (x < prev + 1) { r = mid - 1; }
		else { l = mid + 1; }
	}
	return -1;
}
int main()
{
	int n;
	std::cin >> n;
	long long int* a = new long long int[n];
	long long int prev = 0;
	for (int i = 0; i < n; i++)
	{
		long long int x;
		std::cin >> x;
		
		
		a[i] = x + prev;
		prev = a[i];
	//	std::cout << prev << " " << a[i] << " " << x << "\n";
	}
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		long long int x;
		std::cin >> x;
		std::cout << binarySearch(a, n, x)+1 <<"\n";
	}
	//std::cout << binarySearch(a, n, m - 1);
	return 0;
}