/*#include <cmath>
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


struct  Edge
{
	int u, v, w;
	Edge()
	{
		u = -1;
		v = -1;
		w = 0;
	}
	Edge(int s, int d, int weight)
	{
		u = s;
		v = d;
		w = weight;
	}
	bool operator<(Edge const& other)
	{
		if (w != other.w)return w < other.w;
		return u + v + w < other.u + other.v + other.w;
	}
};
void makeSet(int v, vector<int>& parent, vector<int>& rank)
{
	parent[v] = v;
	rank[v] = 0;
}
int findSet(int v, vector<int>& parent)
{
	if (v == parent[v])return v;
	return parent[v] = findSet(parent[v], parent);
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
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
	int cost = 0;
	vector<Edge> edges;
	vector<int> parent(g_nodes, -1);
	vector<int> rank(g_nodes, 0);
	for (int i = 0; i < g_from.size(); i++)
	{
		Edge temp(g_from[i] - 1, g_to[i] - 1, g_weight[i]);
		edges.push_back(temp);
	}
	for (int i = 0; i < g_nodes; i++)
	{
		makeSet(i, parent, rank);
	}
	sort(edges.begin(), edges.end());

	for (Edge e : edges)
	{

		if (findSet(e.u, parent) != findSet(e.v, parent))
		{
			cost = cost + e.w;
			unionSets(e.u, e.v, parent, rank);
		}
	}
	return cost;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>from;
	vector<int>to;
	vector<int>weight;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		from.push_back(x);
		to.push_back(y);
		weight.push_back(w);
	}
	cout << kruskals(n, from, to, weight) << "\n";
	return 0;
}
*/