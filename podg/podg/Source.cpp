#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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

		void topologicalSortHelper (int s, bool* & visited, bool* & cycleFinder, stack<int> &output) 
		{
			if (cycleFinder[s]) { output.push(-1); return; }
			cycleFinder[s] = true;
			for (auto i : adj[s]) if (!visited[i]) topologicalSortHelper(i, visited, cycleFinder, output);
			visited[s] = true;
			output.push(s);
		}
		vector<int> topologicalSort()
		{
			bool* visited = new bool[v];
			bool* cycleFinder = new bool[v];

			for (int i = 0; i < v; i++)
			{
				visited[i] = false;
				cycleFinder[i] = false;
			}

			stack<int> output;

			for (int i = 0; i < v; i++)
			{
				if(!visited[i]) topologicalSortHelper(i, visited, cycleFinder, output);
			}
			
			vector<int> res;
			
			while (!output.empty())
			{
				if (output.top() == -1)return vector<int>(1, -1);
				res.push_back(output.top());
				output.pop();
			}

			return res;
		}
		vector<int> bfs(vector<int> inDegrees)
		{
			//cout << this->v << " \n";
			vector<int> res;
			//cout<<s<<"bfs\n";
			int countVisited = 0;
			queue<int> nodes;
			for (int i = 0; i < inDegrees.size(); i++)
			{
				if (inDegrees[i] == 0)nodes.push(i);
			}
			
		
			
			while (!nodes.empty())
			{
				countVisited++;
				int t = nodes.front();
				nodes.pop();
				res.push_back(t);

				
				list<int> ::iterator it;

				for (it = adj[t].begin(); it != adj[t].end(); it++)
				{
					--inDegrees[*it];
					if (inDegrees[*it]==0)
					{
						
						
						//cout<<"("<<*it<<"; "<<answer[*it]<<") ";
						nodes.push(*it);
					}
				}

				
			}

			if(countVisited==this->v)return res;
			return vector<int>();
		}
	};

	
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
	{
		Graph g(numCourses+1);
		if (prerequisites.empty())
		{
			vector<int> res;
			for (int i = 0; i < numCourses; i++)
			{
				res.push_back(i);

			}
			return res;
		}
		vector<int> inDegrees(numCourses + 1,0);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			g.addEdge(prerequisites[i][1], prerequisites[i][0]);
			inDegrees[prerequisites[i][0]]++;
		}
		//g.printEdges();
		return g.bfs(inDegrees);

	}
int main()
{
	int n;
	cin >> n;
	string s = "";
	while (n != 0)
	{
		s = s + char(n % 10 + 48);
		n = n / 10;
	}
	string res = "";
	for (int i = s.length() - 1; i >= 0); i--)
	{
	res = res + s[i];
	}
	cout << res << "\n";
	//int n, m;
	//cin >> n >> m;
	//vector<vector<int>> input(n);
	//
	//for (int i = 0; i < n; i++)
	//{
	//	input[i].resize(m);
	//
	//	for (int j = 0; j < m; j++) {
	//		cin >> input[i][j];
	//	}
	//}
	////for (int i = 0; i < n; i++)
	////{
	////	for (int j = 0; j < m; j++)
	////	{
	////		cout << input[i][j] << " ";
	////	}
	////	cout << "\n";
	////}
	//cout << "\n\n\n";
	//vector<int> res =
	//	findOrder(n, input);
	//for (int i = 0; i < res.size(); i++)
	//{
	//	cout << res[i] << " ";
	//}
	//cout << "\n";
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(3, 2);
	//g.addEdge(2, 0);
	//g.addEdge(2, 3);
	//g.addEdge(3, 3);
	vector<int> res = g.topologicalSort();
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	
	
	//cout << "Following is Breadth First Traversal "
	//	<< "(starting from vertex 2) \n";
	//g.bfs(2);
	//cout << "Following is BreadthDepyh First Traversal "
	//	<< "(starting from vertex 2) \n";
	//g.dfs(2);
}