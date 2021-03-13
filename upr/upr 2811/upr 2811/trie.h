#pragma once
#include <iostream>
int SIZE = 26;

struct node
{
	node** children;
	bool isEnd;
	node()
	{
		children = new node*[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			children[i] = NULL;
		}
		isEnd = false;
	}
};