#pragma once
#include <iostream>
#include <queue>
struct node
{
	int key;
	node* left;
	node* right;

	node(int key)
	{
		this->key = key;
		this->left = NULL;
		this->right = NULL;

	}
};

//void free(node* root)
//{
//	if(root->right!=NULL)delete root->right;
//	if(root->left!=NULL)delete root->left;
//	if(root!=NULL)delete root;
//}
node* insert(node* root, int key)
{

	if (root == NULL)
	{
		node* newNode = new node(key);
		return newNode;
	}

	if (root->key > key)
	{
		root->left = insert(root->left, key);

	}
	if (root->key < key)
	{
		root->right = insert(root->right, key);
	}
	return root;
}

node* minValueNode(node* root)
{
	node* current = root;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
node* deleteNode(node* root, int key)
{
	if (root == NULL) return root;
	if (root->key < key)
	{
		root->right = deleteNode(root->right, key);
	}
	else if (root->key > key)
	{
		root->left = deleteNode(root->left, key);
	}
	else
	{
		if (root->left == NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}


	}
	return root;
}
void print(node* root)
{
	if (root != NULL)
	{
		print(root->left);
		std::cout << " " << root->key << " ";
		print(root->right);
		//std::cout << "\n";
	}

}

int searchAndGetLevel(node* root, int key, int counter)
{
	if (root == NULL)return -1;
	if (root->key == key)return counter;
	if (key < root->key)return searchAndGetLevel(root->left, key, ++counter);
	return searchAndGetLevel(root->right, key, ++counter);
}
int max(int a, int b)
{
	if (a > b)return a;
	return b;
}
int getHeight(node* root)
{
	if (root == NULL)return 0;
	return 1 + max(getHeight(root->left), getHeight(root->right));
}
void printLevel(node* root, int level)
{
	if (root == NULL)return;
	if (level == 1)std::cout << root->key << " ";
	else if(level>1)
	{
		printLevel(root->left, level-1);
		printLevel(root->right, level-1);
	}
}
void printShirina(node* root)
{
	if (root == NULL)return;
	std::queue<node*> opashka;
	opashka.push(root);
	while (!opashka.empty())
	{
		std::cout << opashka.front()->key << " ";
		if(opashka.front()->left!=NULL)opashka.push(opashka.front()->left);
		if (opashka.front()->right != NULL)opashka.push(opashka.front()->right);
		opashka.pop();

	}
}
void printLevelOrder(node* root)
{
	if (root == NULL)return;
	int h = getHeight(root);
	//std::cout << h << ":\n ";
	for (int i = 1; i <= h; i++)
	{
		printLevel(root, i);
	}
}
bool search(node* root, int key)
{
	if (root == NULL)return false;
	if (root->key < key)
	{
		return search(root->right, key);
	}
	else if (root->key > key)
	{
		return search(root->left, key);
	}
	else if (root->key == key)return true;
}