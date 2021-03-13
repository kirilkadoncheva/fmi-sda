/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;




int abs(int a)
{
	if (a < 0)return -a;
	return a;
}

struct point
{
	long long int x;
	long long int y;
public:
	point()
	{
		x = 0; y = 0;
	}
	point(long long int a, long long int b)
	{
		x = a; y = b;
	}

};
void swap(long long int& x, long long int& y)
{
	int a = x;
	x = y;
	y = a;
}


double getDistance(point a, point b)
{
	return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool cmpBigger(point a, point b)
{
	point x(0, 0);
	double distA = getDistance(a, x);
	double distB = getDistance(b, x);
	if (distA == distB)
	{
		if (a.x == b.x)
		{
			return a.y > b.y;
		}
		else return a.x > b.x;
	}
	else return distA > distB;
}
void swapPoints(point& a, point& b)
{
	swap(a.x, b.x);
	swap(a.y, b.y);
}
class minHeap
{
private:
	std::vector<point>arr;
	
public:
	minHeap()
	{
		
	}
	void buildMinHeap(point* arr1, int n)
	{
		
		if (this->arr.size() > 0)this->arr.clear();
	//std:cout << this->arr.size()<<"NEw heap: \n";
		for (int i = 0; i < n; ++i)
		{
			this->arr.push_back(arr1[i]);
		}

		
		for (int i = n / 2 - 1; i >= 0; i--)
		{

			bubbleDown(i);
		}

	}
	int getSize()
	{
		return arr.size();
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void bubbleDown(int i)
	{
		int length = arr.size();
		int l = leftChild(i);
		int r = rightChild(i);
		if (l >= length)return;

		int min = i;
		if (cmpBigger(arr[i], arr[l]))min = l;
		if (r < length&&cmpBigger(arr[min], arr[r]))min = r;
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
		if (cmpBigger(arr[p], arr[i]))
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

	point top()
	{
		if (arr.size() > 0)return arr[0];
		point x(0, 0);
		return x;
	}

	void pop()
	{
		int length = arr.size();
		if (length == 0)return;
		arr[0] = arr[length - 1];
		arr.pop_back();
		bubbleDown(0);

	}

	void push(point value)
	{
		int length = arr.size();
		arr.push_back(value);
		bubbleUp(length);
	}

	void print()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
		}
		std::cout << "\n";
	}
	void printFirstK(int k)
	{
		for (int i = 0; i < k; i++)
		{
			std::cout  << arr[i].x << " " << arr[i].y<<"\n" ;
		}
		std::cout << "\n";
	}

};


int main()
{
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	long long int n, k;
	std::cin >> n >> k;

	point* input = new point[n];

	for (int i = 0; i < n; i++)
	{
		long long int x, y;
		std::cin >> x >> y;
		point a(x, y);

		input[i] = a;
	}
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << input[i].x << " " << input[i].y << "\n";
	//}
	minHeap points;
	points.buildMinHeap(input, n);
	//points.print();
	points.printFirstK(k);
	//for (int i = 0; i < k; i++)
	//{
	//    std::cout << points.top().x << " " << points.top().y << "\n";
	//    points.pop();
	//}

	return 0;

}*/