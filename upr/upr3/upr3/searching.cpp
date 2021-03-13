#include <iostream>
#include <cmath>

double max(double a, double b)
{
	if (a > b)return a;
	return b;
}
bool binarySearch(int arr[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (x == arr[mid])return true;
		else if (x > arr[mid])
		{
			l = mid + 1;
			
		}
		else 
		{
			r = mid - 1;
		}
	}

	return false;

}

int zad1(int arr[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		
		 if (x > arr[mid])
		{
			l = mid + 1;
           
		}
		else
		{
		     ans = mid;
			r = mid - 1;
		}
	}

	return ans;
}

int zad2(int n)
{  //log ot long long e 64, kowto znachi che sys 100 opereacii shte sme sigurni che otgowora e prawilen
	double l = 0.0;
	double r = max(1.0, n);
	double eps = 0.000001;
	while (r - l > eps)
	{
		double mid = (l + r) / 2;
		if (mid*mid*mid > n)
		{
			r = mid;
		}
		else { l = mid; }
	}
	return r;
}

int zad3(int arr[], int n)
{
	int l = 0;
	int r = n - 1;
	int missing = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (arr[m] == m)
		{
			l = m + 1;
		}
		else
		{
			missing = m;
			r = m - 1;
		}
	}

	return missing;
}

int zad5_dop(int arr[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (x < arr[mid])
		{
			l = mid + 1;
			ans = mid;

		}
		else
		{
			
			r = mid - 1;
		}
	}

	return ans;
}

int zad5(int arr[], int n, int x)
{
	int first = zad1(arr, n, x);
	int second = zad5_dop(arr, n, x);
	return second - first + 1;

}
int main()
{
	int arr[] = { 0,1,2,4,5,6,7 };
	int n = sizeof(arr) / sizeof(int);

	int x = -100;

	std::cout << zad3(arr,n);
	return 0;
}