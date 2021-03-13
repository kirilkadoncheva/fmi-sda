#include <iostream>
int abs(int n)
{
	if (n < 0)return -n;
	return n;
}
int main()
{
	int n;
	std::cin >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i != k)
			{
				int curr = nums[k] - nums[i];
				if (curr >= 0)
				{
					int res = abs(i - k)*nums[i];
					if (res > max) { max = res; }
				}
			}
		}

	}
	std::cout << max << std::endl;
	return 0;

}