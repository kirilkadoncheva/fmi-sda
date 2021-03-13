#include <iostream>
struct truck
{
public:
	int pos;
	int monsters;



};
int abs(int a)
{
	if (a < 0)return -a;
	return a;
}

long long int calculate(truck* arr, int n, int x)
{
	long long int counter = 0;
	for (int i = 0; i < n; i++)
	{
		counter = counter + abs(x - arr[i].pos)*arr[i].monsters;
	}
	return counter;
}
long long int minMonsters(truck* arr, int n, int* pos,int size)
{
	int l = 0;
	int r = size - 1;
	long long int min = calculate(arr, n, 0);
	long long int lastCount = min;
	//std::cout << min << "\n";
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (mid == 0)
		{

			long long int currentCount = calculate(arr, n, pos[mid]);
			long long int nextCount = calculate(arr, n, pos[mid + 1]);
			std::cout << "l: " << l << " r: " <<r<<" "<< currentCount << " " << nextCount << "\n";
			if (currentCount < nextCount)
			{
				if (min > currentCount) { min = currentCount; }
				return min;
			}
			else
			{
				if (min > nextCount) { min = nextCount; }
				l = mid + 1;
			}

		}
		else
		{
			long long int currentCount = calculate(arr, n, pos[mid]);
			long long int prevCount = calculate(arr, n, pos[mid - 1]);
			if (currentCount < prevCount)
			{
				if (min > currentCount) { min = currentCount; }
				l = mid + 1;
			}
			else
			{
				if (min > prevCount) { min = prevCount; }
				r = mid - 1;
			}
			//std::cout << "l: " << l << " r: " << r << " " << prevCount << " " << currentCount << "\n";
			if (l > r) { lastCount = calculate(arr, n, r); }
		}

	}
	//std::cout << lastCount << " " << min << "\n";
	if (lastCount < min) { min = lastCount; }
	return min;
}
int main()
{
	int n;
	std::cin >> n;
	if (n == 0 || n == 1) { std::cout <<0<< "\n"; return 0; }
	truck* trucks = new truck[n];
	std::cin >> trucks[0].pos;
	std::cin >> trucks[0].monsters;
	int min = trucks[0].pos;
	int max = trucks[0].pos;
	for (int i = 1; i < n; i++)
	{
		std::cin >> trucks[i].pos;
		std::cin >> trucks[i].monsters;
		if (min > trucks[i].pos) { min = trucks[i].pos; }
		if (max < trucks[i].pos) { max = trucks[i].pos; }

	}
	int size = abs(max - min + 1);
	int* positions = new int[size];
	for (int i = min; i <= max; i++)
	{
		positions[i - min] = i;
	}
	//for (int i = 0; i <size; i++)
	//{
	//    std::cout << positions[i] << " ";
	//}
	//std::cout << "\n";
	//mergeSort(trucks, 0, n - 1);

	//std::cin >> x;
	std::cout << minMonsters(trucks, n, positions,size) << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//    std::cout << trucks[i].pos<<" "<<trucks[i].monsters<<" "<<trucks[i].maxMonsters<<"\n";
	//
	//}
	return 0;
}