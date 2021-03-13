#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Graph
{
	long long  int v;
	list<long long int>* adj;

public:
	Graph(long long int n)
	{
		v = n;
		adj = new list<long long int>[n];
	}
	void addEdge(long long int u, long long  int s)
	{
		adj[u].push_back(s);
	}

	void print()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << " : ";
			for (auto j : adj[i])
			{
				cout << j << " ";
			}
			cout << "\n";
		}
	}

	void dfs(long long int s, bool* visited)
	{
		if (!visited[s])
		{
			visited[s] = true;
			for (auto i : adj[s])
			{
				if (!visited[i])
				{
					dfs(i, visited);
				}
			}
		}
	}

	long long int connectedComponents()
	{
		bool* visited = new bool[v];
		for (long long int i = 0; i < v; i++)
		{
			visited[i] = false;

		}
		long long int counter = 0;
		for (int i = 0; i < v; i++)
		{
			if (!visited[i])
			{
				counter++;
				dfs(i, visited);
			}
		}
		return counter;
	}
};



int main()
{
	long long int n, m;
	cin >> n >> m;
	unordered_set<pair<int, int>> edges;

	Graph g(n);
	for (long long int i = 0; i < m; i++)
	{
		long long int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
		g.addEdge(y, x); 
	}
	cout << g.connectedComponents() << "\n";
	return 0;
}
