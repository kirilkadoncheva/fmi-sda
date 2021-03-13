#pragma once
#include <iostream>
#include <vector>


void swap(int& x, int& y)
{
	int a = x;
	x = y;
	y = a;
}
struct Node
{
	int point[2]; 
	Node *left, *right;

};
void swapNodes(Node* a, Node* b)
{
	swap(a->point[0], b->point[0]);
	swap(a->point[1], b->point[1]);

}
class maxHeap
{
private:
	std::vector<Node*> arr;
public:
	maxHeap()
	{

	}
	int getSize()
	{
		return arr.size();
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void bubbleDown(int i)
	{
		int length = arr.size();
		int l = leftChild(i);
		int r = rightChild(i);
		if (l >= length)return;

		int max = i;
		if (arr[i] < arr[l])max = l;
		if (r < length&&arr[max] < arr[r])max = r;
		if (max != i)
		{
			swapNodes(arr[i], arr[max]);
			bubbleDown(max);
		}
	}

	void bubbleUp(int i)
	{
		if (i == 0)return;

		int p = parent(i);
		if (arr[p] < arr[i])
		{
			swapNodes(arr[i], arr[p]);
			bubbleUp(p);
		}
	}
	int leftChild(int i)
	{
		return (2 * i + 1);
	}

	int rightChild(int i)
	{
		return (2 * i + 2);
	}

	Node* top()
	{
		if (arr.size() > 0)return arr[0];
		return NULL;
	}

	void pop()
	{
		int length = arr.size();
		if (length == 0)return;
		arr[0] = arr[length - 1];
		arr.pop_back();
		bubbleDown(0);

	}

	void push(Node* value)
	{
		int length = arr.size();
		arr.push_back(value);
		bubbleUp(length);
	}

	void print()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};

struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;

	for (int i = 0; i < 2; i++)
		temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	return temp;
}


Node* insertRec(Node *root, int point[], unsigned depth)
{
	 
	if (root == NULL)
		return newNode(point);

	
	unsigned cd = depth % 2;

	
	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth + 1);
	else
		root->right = insertRec(root->right, point, depth + 1);

	return root;
}


Node* insert(Node *root, int point[])
{
	return insertRec(root, point, 0);
}

bool arePointsSame(int point1[], int point2[])
{
	
	for (int i = 0; i < 2; ++i)
		if (point1[i] != point2[i])
			return false;

	return true;
}

Node* searchRec(Node* root, int point[], unsigned depth)
{
	
	if (root == NULL)
		return NULL;
	if (arePointsSame(root->point, point))
		return root;

	 
	unsigned cd = depth % 2;

	
	if (point[cd] < root->point[cd])
		return searchRec(root->left, point, depth + 1);

	return searchRec(root->right, point, depth + 1);
}
double getDistance(Node* a, Node* b)
{
	return std::sqrt((a->point[0] - b->point[0])*(a->point[0] - b->point[0]) + (a->point[1] - b->point[1])*(a->point[1] - b->point[1]));
}

void closestKPoints(Node* x, Node* root, maxHeap& points, unsigned depth, int k)
{
	if (root == NULL) return;
	

	if (abs(root->point[depth] - x->point[depth]) <= getDistance(x, points.top()))
	{
		double dist = getDistance(x, root);
		if (points.getSize() >= k)
		{
			double currMax = getDistance(points.top(), x);
			double dist = getDistance(x, root);
			if (dist < currMax) { points.pop(); points.push(root); }

		}
		else
		{
			points.push(root);
		}
		if (depth == 0)depth = 1;
		else depth = 0;
		if (x->point[depth] < root->point[depth])
		{
			closestKPoints(x, root->left, points, depth, k);
			closestKPoints(x, root->right, points, depth, k);

		}
		else
		{
			closestKPoints(x, root->right, points, depth, k);
			closestKPoints(x, root->left, points, depth, k);
			
		}
	}


}

bool search(Node* root, int point[])
{
	
	return searchRec(root, point, 0);
}