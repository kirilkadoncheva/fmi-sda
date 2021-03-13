#include <iostream>
#include <stack>


int main()
{
	int n, k;
	std::cin >> n >> k;
	int* arr = new int[n];
	int counter = 0;
	std::stack<int>minInOrder;
	std::stack<int>maxInOrder;
	std::stack<int>minNoOrder;
	std::stack<int>maxNoOrder;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (minInOrder.empty())minInOrder.push(arr[i]);
		else
		{
			int min = minInOrder.top();
			if (min < arr[i])minInOrder.push(min);
			else minInOrder.push(arr[i]);
		}
		if (maxInOrder.empty())maxInOrder.push(arr[i]);
		else
		{
			int max = maxInOrder.top();
			if (max > arr[i])maxInOrder.push(max);
			else maxInOrder.push(arr[i]);
		}

	}
	for (int i = n - 1; i >= 0; i--)
	{

		if (minNoOrder.empty())minNoOrder.push(arr[i]);
		else
		{
			int min = minNoOrder.top();
			if (min < arr[i])minNoOrder.push(min);
			else minNoOrder.push(arr[i]);
		}
		if (maxNoOrder.empty())maxNoOrder.push(arr[i]);
		else
		{
			int max = maxNoOrder.top();
			if (max > arr[i])maxNoOrder.push(max);
			else maxNoOrder.push(arr[i]);
		}

	}
	//while (!maxNoOrder.empty())
	//{
	//	std::cout << maxNoOrder.top() << " ";
	//	maxNoOrder.pop();
	//}
	//std::cout << "\n";
	int indexStart;
	int indexEnd;
	int currCounter = 0;
	if (k > 0)counter = n;

	while (maxInOrder.top() - minInOrder.top() > k)
	{
		//std::cout << maxInOrder.top() << " " << minInOrder.top() << " " << k << "\n";
		currCounter++;
		maxInOrder.pop();
		minInOrder.pop();
	}
	//std::cout << currCounter << "\n";
	indexStart =n- currCounter;
	//std::cout << n-currCounter-1 << "\n";
	for (int l = n - currCounter - 1; l >= 0; l--)
	{
		counter = counter + l;
	}
	currCounter = 0;
	if (!maxInOrder.empty())
	{
		//currCounter = 0;


		while (maxNoOrder.top() - minNoOrder.top() > k)
		{
			//std::cout << maxInOrder.top() << " " << minInOrder.top() << " " << k << "\n";
			currCounter++;
			maxNoOrder.pop();
			minNoOrder.pop();
		}


	}
	//std::cout << currCounter << "\n";
	indexEnd =currCounter - 1;
	for (int l = n - currCounter - 1; l >= 0; l--)
	{
		counter = counter + l;
	}

	
	//std::cout << indexStart << " " << indexEnd << "\n";
    for (int i = indexStart; i <= indexEnd; i++)
    {
    	int min = arr[i];
    	int max = arr[i];
    	for (int j = i+1; j <=indexEnd; j++)
    	{
    		if (min > arr[j]) { min = arr[j]; }
    		if (max < arr[j]) { max = arr[j]; }
    		if (max - min <= k) { counter++; }
    	}
    
    }
	bool breaak = false;
	for (int i = indexEnd; i >=indexStart; i--)
	{
		if (breaak)break;
		int min = arr[i];
		int max = arr[i];
		for (int j = i + 1; j < n-1; j++)
		{
			if (min > arr[j]) { min = arr[j]; }
			if (max < arr[j]) { max = arr[j]; }
			if (max - min <= k) {  counter++; }
			else { breaak = true; }
		}
	}
	breaak = false;
	for (int i = indexStart; i <= indexEnd; i++)
	{
		if (breaak)break;
		int min = arr[i];
		int max = arr[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (min > arr[j]) { min = arr[j]; }
			if (max < arr[j]) { max = arr[j]; }
			if (max - min <= k) { /*std::cout << i << " " << j << "\n"; */counter++; }
			else { breaak = true; }
		}
	}
	std::cout << counter << "\n";

	return 0;
}