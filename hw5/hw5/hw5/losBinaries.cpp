/*#include <iostream>
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

void print(node* root)
{
	if (root != NULL)
	{
		print(root->left);
		std::cout <<" "<< root->key << " ";
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
int main()
{
	int n, k;
	std::cin >> n >> k;
	int root;
	std::cin >> root;
	node* tree = new node(root);
	for (int i = 1; i < n; i++)
	{
		std::cin >> root;
		insert(tree, root);
	}

	int* inquiries = new int[k];
	for (int i = 0; i < k; i++)
	{
		std::cin >> inquiries[i];
	}
	for (int i = 0; i < k; i++)
	{
		std::cout << searchAndGetLevel(tree, inquiries[i], 0) << "\n";
	}
	return 0;
}*/