#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct file
{
	string name;
	file* parent;
	vector<file*> children;

	file(file* parentt,string _name)
	{
		name = _name;
		parent = parentt;

	}
};
void swapString(string& a, string& b)
{
	string t = a;
	a = b;
	b = t;
}


int partition(string* arr, int low, int high)
{
	string pivot = arr[high];   
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (arr[j] < pivot)
		{
			i++;   
			swapString(arr[i], arr[j]);
		}
	}
	swapString(arr[i + 1], arr[high]);
	return (i + 1);
}


void quickSort(string* arr, int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);

		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


file* searchVector(vector <file*> a, string b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->name == b)return a[i];
	}
	return NULL;
}
void mkdir(file* currdirectory)
{
	string name;
	cin >> name;
	if (searchVector(currdirectory->children, name)!=NULL)
	{
		cout << "Directory already exists\n";
	}
	else
	{
		file* temp = new file(currdirectory, name);
		currdirectory->children.push_back(temp);
	}
}

void ls(file* currdirectory)
{
	int n = currdirectory->children.size();
	string* arr = new string[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = currdirectory->children[i]->name;
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void pwd(file* currdirectory)
{
	if (currdirectory->name == "/") { cout << "/\n"; return; }
	string result = "/" + currdirectory->name + "/";
	file* temp = currdirectory->parent;
	while (temp->name != "/")
	{
		result = "/" + temp->name + result;
		temp = temp->parent;
	}
	cout << result << "\n";
}
void cd(file* &currdirectory)
{
	string name;
	cin >> name;
	if (name != "..")
	{
		file* temp = searchVector(currdirectory->children, name);
		if (temp!=NULL)
		{
			//cout << temp->name<<"\n";
			currdirectory = temp;
			//cout << currdirectory->name << "\n";
		}
		else
		{
			cout << "No such directory\n";
		}
	}
	else
	{
		if (currdirectory->parent == NULL)
		{
			cout << "No such directory\n";
		}
		else
		{
			currdirectory = currdirectory->parent;
		}
	}
}
int main()
{
	file* startDirectory = new file(NULL, "/");
	file* currDirectory = startDirectory;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string query;
		cin >> query;
		if (query == "mkdir")
		{
			mkdir( currDirectory);
		}
		else if (query == "ls")
		{
			ls( currDirectory);
		}
		else if (query == "pwd")
		{
			pwd( currDirectory);
		}
		else
		{
			cd( currDirectory);
		}
	}
// mkdir(currDirectory);
//mkdir(currDirectory);
//mkdir(currDirectory);
//ls(currDirectory);
//pwd(currDirectory);
//cd(currDirectory);
//mkdir(currDirectory);
//mkdir(currDirectory);
//ls(currDirectory);
//pwd(currDirectory);

	return 0;

}