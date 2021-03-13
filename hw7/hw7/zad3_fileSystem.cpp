/*#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void mkdir(unordered_map<string, set<string>>& fileSystem, vector<string>& directories,string currDirectory)
{
	string name;
	cin >> name;
	if (fileSystem[currDirectory].empty())
	{
		fileSystem[currDirectory].insert(name);
		directories.push_back(name);
	}
	else if (fileSystem[currDirectory].find(name) != fileSystem[currDirectory].end())
	{
		cout << "Directory already exists\n";
		
	}
	else
	{
		fileSystem[currDirectory].insert(name);
		directories.push_back(name);
	}
}

void ls(unordered_map<string, set<string>>& fileSystem, string currDirectory)
{
	if (fileSystem[currDirectory].empty())return;
	set<string> ::iterator it;

	for (it = fileSystem[currDirectory].begin(); it != fileSystem[currDirectory].end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

string findParent(string name, unordered_map<string, set<string>>& fileSystem, vector<string>& directories)
{
	int startIndex = 0;
	for (int i = 0; i < directories.size(); i++)
	{
		if (directories[i] == name)
		{
			startIndex = i; break;
		}
	}
	for (startIndex; startIndex >= 0; startIndex--)
	{
		if (fileSystem[directories[startIndex]].find(name) != fileSystem[directories[startIndex]].end())
		{
			return directories[startIndex];
		}
	}
	return "$";
}
void pwd(unordered_map<string, set<string>>& fileSystem, vector<string>& directories, string currDirectory)
{
	if (currDirectory == "/") { cout << "/\n"; return; }
	string result = "/"+currDirectory + "/";
		string parent = findParent(currDirectory, fileSystem, directories);
		while (parent != "/")
		{
			result = "/" + parent + result;
			parent= findParent(parent, fileSystem, directories);
	    }
		cout << result << "\n";
}


void cd(unordered_map<string, set<string>>& fileSystem, vector<string>& directories, string& currDirectory)
{
	string name;
	cin >> name;
	if (name != "..")
	{
		if (fileSystem[currDirectory].empty()||fileSystem[currDirectory].find(name) == fileSystem[currDirectory].end())
		{
			cout << "No such directory\n";
			
		}
		else
		{
			currDirectory = name;
		}
	}
	else
	{
		string p = findParent(currDirectory, fileSystem, directories);
		if(p == "$")cout << "No such directory\n";
		else currDirectory = p;
	}
	
}
void print(unordered_map<string, set<string>>& fileSystem, vector<string>& directories, string currDirectory)
{
	cout <<currDirectory << "\n";
	for (int i = 0; i < directories.size(); i++)
	{
		cout << directories[i] << " ";
	}
	cout << "\n";
	unordered_map<string, set<string>> ::iterator it;
	for (it = fileSystem.begin(); it != fileSystem.end(); it++)
	{
		cout << it->first << ": ";
		set<string> ::iterator it1;
		for (it1 = it->second.begin(); it1 != it->second.end(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << "\n";
	}
}
int main()
{
	vector<string> directories;
	unordered_map<string, set<string>> fileSystem;
	string currDirectory="/";

	directories.push_back("/");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string query;
		cin >> query;
		if (query == "mkdir")
		{
			mkdir(fileSystem, directories, currDirectory);
		}
		else if (query == "ls")
		{
			ls(fileSystem, currDirectory);
		}
		else if (query == "pwd")
		{
			pwd(fileSystem, directories, currDirectory);
		}
		else
		{
			cd(fileSystem, directories, currDirectory);
		}
	}
	//mkdir(fileSystem, directories, currDirectory);
	//mkdir(fileSystem, directories, currDirectory);
	//mkdir(fileSystem, directories, currDirectory);
	//mkdir(fileSystem, directories, "AAA");
	//print(fileSystem, directories, currDirectory);
	//cd(fileSystem, directories, currDirectory);
	//mkdir(fileSystem, directories, currDirectory);
	//print(fileSystem, directories, currDirectory);
	////pdw(fileSystem, directories, "a");
	//ls(fileSystem, currDirectory);
	

	return 0;
}*/