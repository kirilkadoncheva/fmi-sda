/*#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
	int src, dest, weight;
};


class Graph
{
public:
	
	int V, E;

	
	Edge* edge;
};


Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

class subset
{
public:
	int parent;
	int rank;
};


int find(subset subsets[], int i)
{
	
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}


void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


int myComp(Edge* a, Edge* b)
{
	
	return a->weight > b->weight;
}


void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge* result[V]; // Tnis will store the resultant MST  
	int e = 0; // An index variable, used for result[]  
	int i = 0; // An index variable, used for sorted edges  

	// Step 1: Sort all the edges in non-decreasing  
	// order of their weight. If we are not allowed to  
	// change the given graph, we can create a copy of  
	// array of edges  
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	// Allocate memory for creating V ssubsets  
	subset *subsets = new subset[(V * sizeof(subset))];

	// Create V subsets with single elements  
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1  
	while (e < V - 1 && i < graph->E)
	{
		// Step 2: Pick the smallest edge. And increment  
		// the index for next iteration  
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle,  
		// include it in result and increment the index  
		// of result for next edge  
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge  
	}

	// print the contents of result[] to display the  
	// built MST  
	cout << "Following are the edges in the constructed MST\n";
	for (i = 0; i < e; ++i)
		cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
	return;
}


struct Edge {
	int u, v, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
	make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
	if (find_set(e.u) != find_set(e.v)) {
		cost += e.weight;
		result.push_back(e);
		union_sets(e.u, e.v);
	}
}*/