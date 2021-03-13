#include <iostream>

int min(int a, int b)
{
	if (a <= b)return a;
	return b;
}

int max(int a, int b)
{
	if (a >= b)return a;
	return b;
}


int main()
{
	int n;
	int k;
	std::cin >> n>>k;
	int* input = new int[n];
	int* sortedByPower = new int[n];
	int* answer = new int[n];
	int teamNumber = 1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
		sortedByPower[input[i] - 1] = i;
		answer[i] = 0;
	}
	
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << input[i] << " ";
	//}
	//std::cout << "\n";
	//
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << sortedByPower[i] << " ";
	//}
	//std::cout << "\n";



	for (int i = n - 1; i >= 0; i--)
	{
		if (answer[sortedByPower[i]] == 0)
		{
			//std::cout << teamNumber << ": \n";
			//std::cout << "sorted: "<<sortedByPower[i] << "\n";
			//std::cout << max(sortedByPower[i] - k, 0) << " " << min(n - 1, sortedByPower[i] + k) << "\n";
			int counter = 0;
			
			answer[sortedByPower[i]] = teamNumber;
			for (int j = sortedByPower[i]+1; j <= n-1; j++)
			{
				
				if (counter >= k) { break; }
				if (answer[j] == 0) {  answer[j] = teamNumber; counter++; }
				
			}
			//std::cout << "\n";
			counter = 0;
			for (int j = sortedByPower[i]-1; j >=0; j--)
			{
				if (counter >=k) { break; }
				if (answer[j] == 0) {  answer[j] = teamNumber; counter++; }

			}
		//	std::cout << "\n";
			if (teamNumber == 1) { teamNumber = 2; }
			else teamNumber = 1;

			//for (int i = 0; i < n; i++)
			//{
			//	std::cout << answer[i];
			//}
			//std::cout << "\n";
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << answer[i] ;
	}
	std::cout << "\n";
	return 0;
}