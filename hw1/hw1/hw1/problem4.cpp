#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int m;
		cin >> m;
		if (m < 1) { cout << "no\n"; continue; }

		else if (m > 1)
		{
			if (n <= m) { cout << "no\n"; continue; }
			else
			{
				if ((n - m + 1) % 2 == 0) { cout << "yes\n"; continue; }
				else { cout << "no\n"; continue; }
			}
		}
		else if (n != 0) { cout << "no\n"; continue; }
		else { cout << "yes\n"; continue; }
	}
	return 0;
}
