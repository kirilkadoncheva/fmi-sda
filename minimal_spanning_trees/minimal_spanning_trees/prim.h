#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;


const int INF = 1000000000; 

struct Edge {
	int w = INF, to = -1;

	Edge()
	{
		w = INF;
		to = -1;
	}
	Edge(int weight, int dst)
	{
		w = weight;
		to = dst;
	}
	bool operator<(Edge const& other) const {
		return w < other.w;
	}
};



void prim(int s,int n, vector<vector<Edge>> adj) 
{
	int total_weight = 0;
	vector<Edge> min_e(n);
	min_e[s].w = 0;
	set<Edge> q;
	Edge temp(0, s);
	q.insert(temp);
	vector<bool> selected(n, false);
	for (int i = 0; i < n; ++i) {
		if (q.empty()) {
			cout << "No MST!" << endl;
			exit(0);
		}

		int v = q.begin()->to;
		selected[v] = true;
		total_weight += q.begin()->w;
		q.erase(q.begin());

		if (min_e[v].to != -1)
			cout << v << " " << min_e[v].to << endl;

		for (Edge e : adj[v]) {
			if (!selected[e.to] && e.w < min_e[e.to].w) {
				q.erase({ min_e[e.to].w, e.to });
				min_e[e.to] = { e.w, v };
				q.insert({ e.w, e.to });
			}
		}
	}

	cout << total_weight << endl;
}