#include <iostream>
#include <vector>
struct interval
{
	long long x;
	long long y;

	interval()
	{
		this->x = 0;
		this->y = 0;
	}
	interval(long long a, long long b)
	{
		this->x = a;
		this->y = b;
	}
	bool operator<(interval& b)
	{
		if (this->x < b.x)return true;
		if (this->x == b.x)if (this->y < b.y)return true;
		return false;
	}
	bool operator>(interval& b)
	{
		return !(this->operator<(b)||this->operator==(b));
	}
	bool operator==(interval& b)
	{
		return (this->x == b.x&&this->y == b.y);
	}
	interval operator=(interval& b)
	{
		this->x = b.x;
		this->y = b.y;
		return *this;
	}
	//0 - yes
	//1 - left
	//2 - right
	int contains(long long val)

	{
		if (val >= this->x&&val <= this->y)return 0;
		if (val < this->x)return 1;
		return 2;
	}
};
struct Node
{
	double possible;
	interval i;
	Node *left;
	Node *right;
	int height;

	Node(double value,interval i, Node *left = nullptr, Node *right = nullptr)
	{
		this->possible=value;
		this->i = i;
		this->left = left;
		this->right = right;
		this->height = 1;
	}

	
};
int max(int a, int b)
{
	if (a > b)return a;
	return b;
}
interval maxInterval(interval a, interval b)
{
	if (b < a)return a;
	return b;
}
int getHeight(Node* root)
{
	if (root == nullptr)return 0;
	return root->height;
}

int getBalance(Node* root)
{
	if (root == nullptr)return 0;
	return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return y;

}
Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return x;
}

Node* minValueNode(Node* root)
{
	Node* curr = root;
	while (curr->left != nullptr)
	{
		curr = curr->left;
	}
	return curr;
}


class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, interval value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->i == value)
		{
			return true;
		}

		if (value < current->i)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		std::cout << "("<<current->i.x<<", "<<current->i.y<<"; "<<current->possible << ") ";
		printRecursive(current->right);
	}

	Node* addNode(Node* root, interval value)
	{
		if (root == nullptr)
		{
			Node* temp = new Node(0,value);
			temp->height = 1;
			return temp;
		}
		if (value < root->i)
		{
			root->left = addNode(root->left, value);

		}
		else if ( root->i<value )
		{
			root->right = addNode(root->right, value);
		}
		else
		{
			std::cout <<"("<< value.x<<", "<<value.y<<") " << " already added\n";
			return root;
		}

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		int balance = getBalance(root);


		if (balance > 1 && value < root->left->i)
		{
			return rightRotate(root);
		}


		if (balance<-1 && value > root->right->i)
		{
			return leftRotate(root);
		}


		if (balance > 1 && value > root->left->i)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}


		if (balance < -1 && value < root->right->i)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* deleteNode(Node* root, interval value)
	{
		if (root == nullptr)
		{
			std::cout << "("<<value.x<<", "<<value.y<<") " << " not found to remove\n";
			return nullptr;
		}

		if (value < root->i)
		{
			root->left = deleteNode(root->left, value);

		}
		else if (value > root->i)
		{
			root->right = deleteNode(root->right, value);
		}
		else
		{
			if (root->left == nullptr)
			{
				Node *temp = root->right;

				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;

				}
				free(temp);

			}
			else if (root->right == nullptr)
			{
				Node *temp = root->left;
				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;

				}
				free(temp);
			}

			else
			{

				Node* temp = minValueNode(root->right);
				root->i = temp->i;
				root->right = deleteNode(root->right, temp->i);
			}
		}



		if (root == nullptr)
			return root;

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);


		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);


		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}


	void whereIsIt(Node* root, long long int val)
	{
		if (root == NULL)return;
		int p = root->i.contains(val);
		switch (p)
		{
		case 0:
			root->possible++;
			//std::cout <<val<<": "<< root->i.x << "::" << root->i.y << "\n";
			whereIsIt(root->left, val);
			whereIsIt(root->right, val);
			break;
		case 1:
			whereIsIt(root->left, val);
			break;
		case 2:
			whereIsIt(root->right, val);
			break;
		}
	}
	void findRightInterval(Node* root, long long int val,interval& bestFit,double& pos)
	{
		if (root == NULL)return ;
		int p = root->i.contains(val);
		
		switch (p)
		{
		case 0:
			if ((bestFit.x == 0 && bestFit.y == 0) || root->possible < pos) { bestFit = root->i; pos = root->possible; /*std::cout << bestFit.x << ":" << bestFit.y << "\n";*/ }
			findRightInterval(root->left, val,bestFit,pos);
			findRightInterval(root->right, val, bestFit,pos);
			break;
		case 1:
			findRightInterval(root->left, val, bestFit,pos);
			break;
		case 2:
			findRightInterval(root->right, val, bestFit,pos);
			break;
		}
	}
public:
	AVLTree()
	{
		root = NULL;
	}


	void add(interval value)
	{
		this->root = this->addNode(this->root, value);

	}

	void remove(interval value)
	{
		this->root = this->deleteNode(this->root, value);

	}

	bool contains(interval value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}
	void findPossible(long long x)
	{
		whereIsIt(this->root, x);
	}
	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		std::cout << std::endl;
	}
	bool foundInterval(long long int val)
	{
		interval res(0,0);
		double pos = -1;
		findRightInterval(this->root, val, res,pos);
		//std::cout << res.x<<"::"<<res.y << "\n";
		interval p(0, 0);
		if (res == p)return false;
		this->remove(res);
		return true;

	}
};

int main()
{
	AVLTree a;
	long long int n, m;
	std::cin >> n >> m;
	std::vector<long long>students;
	for (int i = 0; i < n; i++)
	{
		long long int y;
		std::cin >> y;
		students.push_back(y);
		

	}
	for (int i = 0; i < m; i++)
	{
		long long int y;
		long long int t;
		std::cin >> y >> t;
		interval inter(y - t, y + t);
		a.add(inter);
	}
	//a.print();
	
	for (int i = 0; i < n; i++)
	{

		a.findPossible(students[i]);

	} 
	//a.print();
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		
		if(a.foundInterval(students[i]))counter++;
	
	}
	std::cout << counter << "\n";
	//AVLTree a;
	//interval x(1, 4);
	//a.add(x);
	//interval y(0, 2);
	//interval z(5, 6);
	//a.add(y);
	//a.add(z);
	//a.print();
	//std::cout << a.contains(x);
	//a.remove(x);
	//a.print();
	//std::cout<<a.contains(x);
	return 0;
}