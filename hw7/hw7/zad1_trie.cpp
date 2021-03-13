/*#include <iostream>
#include <string>
using namespace std;

const int SIZE = 26;

struct TrieNode
{
	struct TrieNode* children[SIZE];
	bool isEnd;
	int countChildren;

	TrieNode()
	{
		this->isEnd = false;
		for (int i = 0; i < SIZE; i++)
		{
			this->children[i] = NULL;
		}
		this->countChildren = 0;
	}
};

void insert(TrieNode* root, string key)
{
	TrieNode* current = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!current->children[index])
		{
			current->children[index] = new TrieNode();

		}
		current->countChildren++;
		current = current->children[index];
	}
	current->isEnd = true;
}


bool isLeaf(TrieNode* root)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (root->children[i] != NULL)return false;

	}
	return true;
}


int countWordsWithPrefix(TrieNode* root, string prefix)
{
	TrieNode* current = root;
	for (int i = 0; i < prefix.length(); i++)
	{
		int index = prefix[i] - 'a';
		if (current->children[index] == NULL)return 0;

		current = current->children[index];
	}
	if (current->isEnd)return current->countChildren + 1;
	return current->countChildren;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	TrieNode* root = new TrieNode();

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		insert(root, input);
	}

	for (int i = 0; i < q; i++)
	{
		string query;
		cin >> query;
		cout << countWordsWithPrefix(root, query) << "\n";

	}

	return 0;

}*/