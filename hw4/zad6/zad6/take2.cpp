#include <iostream>
#include <stack>
using namespace std;

int main()
{

	int N;
	cin >> N;

	int* trees = new int[N];
	stack <int> s;

	for (int i = 0; i < N; i++) cin >> trees[i];

	int maxSight = 1;
	int maxSightIndex = N - 1;
	s.push(trees[N - 1]);
	int previousSight = 1;
	for (int i = N - 2; i >= 0; i--) {
		previousSight++;
		while (!s.empty() && trees[i] > s.top()) {
			s.pop();
			previousSight--;
		}


		s.push(trees[i]);
		if (previousSight >= maxSight) {
			maxSight = previousSight;
			maxSightIndex = i;
		}

	}

	cout << maxSightIndex << endl;
	return 0;
}