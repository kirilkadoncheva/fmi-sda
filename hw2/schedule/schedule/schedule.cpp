#include <iostream>
struct Event{
public:
	int bi;
	int ti;
	Event operator=(Event& other)
	{
		this->bi = other.bi;
		this->ti = other.ti;

		return *this;
	}

	bool operator<(Event& other)
	{
		return this->ti < other.ti;
	}

	void print()
	{
		std::cout << this->bi << " " << this->ti << "\n";
	}

};
void swap(Event& a, Event& b)
{
	Event x = a;
	a = b; b = x;
}

void merge(Event* arr, int l, int m, int r)
{
	int sizeL = m + 1 - l;
	int sizeR = r - m;

	Event* arrL = new Event[sizeL];
	Event* arrR = new Event[sizeR];

	for (int i = 0; i < sizeL; i++)
	{
		arrL[i] = arr[i + l];
	}

	for (int i = 0; i < sizeR; i++)
	{
		arrR[i] = arr[i + m+1];
	}

	int iL = 0;
	int iR = 0;
	int i = l;

	while (iL < sizeL&&iR < sizeR)
	{
		if (arrL[iL] < arrR[iR])
		{
			arr[i++] = arrL[iL++];
		}
		else
		{
			arr[i++] = arrR[iR++];
		}
	}

	while (iL < sizeL)
	{
		arr[i++] = arrL[iL++];
	}

	while (iR < sizeR)
	{
		arr[i++] = arrR[iR++];
	}

}

void mergeSort(Event* arr, int l, int r)
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
	int n;
	std::cin >> n;
	if (n == 0) { std::cout << 0 << "\n"; return 0; }
	Event* events = new Event[n];
	int* nextPossible = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> events[i].bi;
		std::cin >> events[i].ti;
		events[i].ti += events[i].bi;

		nextPossible[i] = 1;

	}

	
	mergeSort(events, 0, n - 1);

	

	
	int counter = 1;
	int indexPrev = 0;
	for (int i = 1; i < n; i++)
	{
		if (events[indexPrev].ti<= events[i].bi) { counter++; indexPrev = i; }
	}

	std::cout << counter << "\n";
	


	
	
	return 0;
}