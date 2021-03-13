#include <iostream>
#include "binaryTree.h"
#include <map>
#include <queue>

int main()
{
	std::priority_queue<int,std::vector<int>, std::greater<int>> p;
	p.push(2);
	p.push(11);
	p.push(1);
	std::cout << p.top() << "\n";

	//node* tree=new node(4);
	//insert(tree, 2);
	//insert(tree, 3);
	//insert(tree, 1);
	//insert(tree, 5);
	//
//	//print(tree); std::cout << "\n";
	//
	//printLevelOrder(tree); std::cout << "\n";
	//printShirina(tree); std::cout << "\n";
	//print(tree);

	return 0;
}