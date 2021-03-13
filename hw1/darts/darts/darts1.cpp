#include <iostream>



int main()
{
	int n;
	std::cin >> n;
	int counter = 0;

	for (int i = 1; i <= 25; i++)
	{
		int rest = n - 2 * i;
		if (rest == 0) { counter = counter + 3; }
		else if (rest > 0)
		{
			for (int k = 1; k <= 25; k++)
			{
				int rest1 = rest - k;
				int rest2 = rest - 2 * k;
				int rest3 = rest - 3 * k;
				if (rest1 == 0) { counter = counter + 3; std::cout << k << " " << i<<" 1\n"; }
				else if (rest1 > 0 )
				{
					for (int j = 1; j <= 25; j++)
					{
						
						if (rest1-j == 0)
						{
							std::cout << j << " " << k << " " << i << " 11\n";
							counter++;
						}
						else if (rest1 - 2 * j == 0)
						{
							std::cout << j << " " << k << " " << i << " 21\n";
							counter++;
						}
						else if (rest1 - 3 * j == 0&&j!=25)
						{
							std::cout << j << " " << k << " " << i << " 31\n";
							counter++;
						}

						if (j == 20)j = 24;
					}
				}
				if (rest2 == 0) { counter = counter + 3;  std::cout << k << " " << i<<" 2\n";
				}
				else if (rest2 > 0 )
				{
					for (int j = 1; j <= 25; j++)
					{

						if (rest2 - j == 0)
						{
							std::cout <<j<<" "<< k << " " << i << " 12\n";
							counter++;
						}
						else if (rest2 - 2 * j == 0)
						{
							std::cout << j << " " << k << " " << i << " 22\n";
							counter++;
						}
						else if (rest2 - 3 * j == 0&&j!=25)
						{
							std::cout << j << " " << k << " " << i << " 32\n";
							counter++;
						}

						if (j == 20)j = 24;
					}
				}
				if (rest3 == 0&&k!=25) { counter = counter + 3;  std::cout << k << " " << i<<" 3\n";
				}
				else if (rest3 > 0&&k!=25)
				{
					for (int j = 1; j <= 25; j++)
					{

						if (rest3 - j == 0)
						{
							std::cout << j << " " << k << " " << i << " 13\n";
							counter++;
							
						}
						else if (rest3 - 2 * j == 0)
						{
							std::cout << j << " " << k << " " << i << " 23\n";
							counter++;
								
						}
						else if (rest3 - 3 * j == 0&&j!=25)
						{
							std::cout << j << " " << k << " " << i << " 33\n";
							counter++;
						}

						if (j == 20)j = 24;
					}
				}
				if (k == 20)k = 24;
			}
		}
		
		if (i == 20)i = 24;
	}
	std::cout << counter << "\n";
	
	return 0;
}