#include <iostream>
#include <string>


int main()
{
	std::string input;
	std::cin >> input;
	int size = input.size();
	//std::string encoded = "";
	char currentSymbol = input[0];
	int counter = 0;
	//bool finished = false;
	int i = 0;
		while ( i < size)
		{
			while (i < size && input[i] == currentSymbol)
			{
				counter++;
				i++;
				
			}
			std::string result = "";
            while (counter != 0)
			{
				result = char(counter % 10 + 48) + result;
				counter = counter / 10;
			}
			//encoded = encoded + result + currentSymbol;
			
			std::cout << result << currentSymbol;


				currentSymbol = input[i];
				counter = 0;
				
			
			

		}
	
		std::cout  << std::endl;

	return 0;
}