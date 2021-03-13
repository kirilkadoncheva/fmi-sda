#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Graph
{
	int countVertices;
	list <int>* adj;

public:
	Graph(int n)
	{
		this->countVertices = n;
		adj = new list<int>[n];
	}
	void addEdge(int v, int u)
	{
		adj[v].push_back(u);
	}
	void bfs(int s)
	{
		bool* visited = new bool[this->countVertices];
		for (int i = 0; i < this->countVertices; i++)
		{
			visited[i] = false;
		}
		queue<int> queue;
		visited[s] = true;
		queue.push(s);
		while (!queue.empty())
		{
			s = queue.front();
			cout << s << " ";
			queue.pop();
			for (list<int> ::iterator i = adj[s].begin(); i != adj[s].end(); i++)
			{
				if (!visited[*i])
				{
					queue.push(*i);
					visited[*i] = true;
				}
			}
		}
	}
	void dfsHelper(int s,bool* visited)
	{
		visited[s] = true;
		cout << s << " ";
		list<int> ::iterator i;
		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				dfsHelper(*i, visited);
			}
		}
	}
	void dfs(int s)
	{
		bool* visited = new bool[this->countVertices];
		for (int i = 0; i < this->countVertices; i++)
		{
			visited[i] = false;
		}
		dfsHelper(s, visited);
	}
};