#include <iostream>
#include <vector>
#include <list>
#include <queue>
//#include "graph.h"
using namespace std;
class Graph
{
	int v;
	list<int>* adj;
public:
	Graph(int n)
	{
		this->v = n;
		adj = new list<int>[n];
	}

	void addEdge(int v, int u)
	{
		adj[v].push_back(u);
	}
	void printEdges()
	{
		cout << v << endl;
		list<int> ::iterator it;
		for (int t = 0; t < v; t++)
		{
			cout << t << ": ";
			for (it = adj[t].begin(); it != adj[t].end(); it++)
			{
				cout << *it << " ";
			}
			cout << "\n";
		}

	}
	vector<int> bfs(int s)
	{
		vector<int>res;
		bool* visited = new bool[this->v];
		for (int i = 0; i < this->v; i++)
		{
			visited[i] = false;
		}
		queue<int> queue;
		visited[s] = true;
		queue.push(s);
		while (!queue.empty())
		{
			int p = queue.front();
			res.push_back(p);
			queue.pop();
			for (list<int> ::iterator i = adj[p].begin(); i != adj[p].end(); i++)
			{
				if (!visited[*i])
				{
					queue.push(*i);
					visited[*i] = true;
				}
			}
		}
		return res;

	}
};
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	Graph g(numCourses);
	if (prerequisites.empty())
	{
		vector<int> res;
		for (int i = 0; i < numCourses; i++)
		{
			res.push_back(i);

		}
		return res;
	}
	for (int i = 0; i < prerequisites.size(); i++)
	{
		g.addEdge(prerequisites[i][1], prerequisites[i][0]);
	}
	return g.bfs(0);

}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> input(n);
	
	for (int i = 0; i < n; i++)
	{
		input[i].resize(m);

		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << input[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n\n";
	vector<int> res = 
		findOrder(n,input);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << "\n";
	//Graph g(4);
	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(1, 2);
	//g.addEdge(2, 0);
	//g.addEdge(2, 3);
	//g.addEdge(3, 3);
	//
	//cout << "Following is Breadth First Traversal "
	//	<< "(starting from vertex 2) \n";
	//g.bfs(2);
	//cout << "Following is BreadthDepyh First Traversal "
	//	<< "(starting from vertex 2) \n";
	//g.dfs(2);
}