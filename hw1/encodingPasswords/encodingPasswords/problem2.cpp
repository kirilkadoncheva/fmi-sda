#include <iostream>

int main()
{
	int min;
	std::cin >> min;
	int n;
	std::cin >> n;
	int buffer=0;
	for (int i = 0; i < n; i++)
	{
		int student;
		std::cin >> student;
		buffer = buffer + student - min;
		
	}
	if (buffer >= 0)std::cout << "yes\n";
	else std::cout << "no\n";
		
	return 0;
}