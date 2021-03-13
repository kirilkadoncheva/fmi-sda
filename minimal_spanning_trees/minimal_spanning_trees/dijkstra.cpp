#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;


class Graph
{
	int v;
	list<pair<int, int>>* adj;

public:
	Graph(int n)
	{
		v = n;
		adj = new list<pair<int, int>>[n];
	}
	void addEdge(int u, int s, int dist)
	{
		pair<int, int> temp;
		temp.first = s;
		temp.second = dist;
		adj[u].push_back(temp);
		//temp.first = u;
		//adj[s].push_back(temp);
	}


	void print()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << " : ";
			for (auto j : adj[i])
			{
				cout << j.first << ":" << j.second << " ";
			}
			cout << "\n";
		}
	}

	void dijkstra(int s, vector<int> & d, vector<int> & p)
	{
		int n = v;
		d.assign(n, INT_MAX);
		p.assign(n, -1);

		d[s] = 0;
		using pii = pair<int, int>;
		priority_queue<pii, vector<pii>, greater<pii>> q;
		q.push({ 0, s });
		while (!q.empty()) {
			int l = q.top().second;
			int d_l = q.top().first;
			q.pop();
			if (d_l != d[l])
				continue;

			for (auto edge : adj[l]) {
				int to = edge.first;
				int len = edge.second;

				if (d[l] + len < d[to]) {
					d[to] = d[l] + len;
					p[to] = l;
					q.push({ d[to], to });
				}
			}
		}
	}

};


int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		g.addEdge(u, v, d);
	}
	vector<int>p(n);
	vector<int>d(n);
	 g.dijkstra(0, d, p);
	 for (int i = 0; i < n; i++)
	 {
		 cout << d[i] << " " << p[i] << "\n";
	 }
	return 0;
}