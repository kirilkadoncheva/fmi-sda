#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Edge
{
public:
	int u;
	int v;
	int w;
public:
	Edge()
	{
		u = -1;
		v = -1;
		w = 0;
	}
	Edge(int src, int dst, int weight)
	{
		u = src;
		v = dst;
		w = weight;
	}

	bool operator<(Edge const& other)
	{
		return w > other.w;
	}
};

void makeSet(int s, vector<int>& parent, vector<int>& rank)
{
	parent[s] = s;
	rank[s] = 0;
}

int findSet(int s, vector<int>& parent)
{
	if (s == parent[s])return s;

	return parent[s] = findSet(parent[s], parent);
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank)
{
	a = findSet(a, parent);
	b = findSet(b, parent);
	if (a != b)
	{
		if (rank[a] < rank[b])swap(a, b);
		parent[b] = a;
		if (rank[a] == rank[b])rank[a]++;
	}
}

int kruskal(int n, vector<Edge> edges)
{
	int cost = 0;
	vector<int>parent(n, -1);
	vector<int>rank(n, 0);

	for (int i = 0; i < n; i++)
	{
		makeSet(i, parent, rank);
	}

	sort(edges.begin(), edges.end());

	for (Edge e : edges)
	{
		if (findSet(e.u, parent) != findSet(e.v, parent))
		{
			unionSets(e.u, e.v, parent, rank);
			cost += e.w;
		}
	}

	return cost;
}
long long int cost(int u, int v,int n, vector<Edge> edges)
{
	vector<int> parent(n);
	vector<int>rank(n);
	sort(edges.begin(), edges.end());
	long long int cost = 0;
	for (int i = 0; i < n; i++)
	{
		makeSet(i, parent, rank);
	}
	int i = 0;
	for (i;i<edges.size();i++)
	{
		if (findSet(u, parent) == findSet(v, parent))
		{
			break;
		}
		if (findSet(edges[i].u, parent) != findSet(edges[i].v, parent))
		{
			unionSets(edges[i].u, edges[i].v, parent, rank);
		}
		
	}
	i--;
	for (i; i < edges.size(); i++)
	{
		cost += edges[i].w;
	}

	return cost;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		Edge temp(x-1, y-1, w);
		edges.push_back(temp);
	}
	
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum += cost(j, i, n, edges);
		}
	}
	cout << sum%1000000000 << "\n";
	return 0;
}
