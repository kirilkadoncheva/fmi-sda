#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void countingSort(string &word)
{
	int letters[26] = { 0 };
	int size = word.size();
	
	
	for (int i = 0; i < size; i++)
	{
		if (word[i] >= 'A'&&word[i] <= 'Z') { word[i] = word[i] + 32; }
		switch (word[i])
		{
		case 'a':letters[0]++; break;
		case 'b':letters[1]++; break;
		case 'c':letters[2]++; break;
		case 'd':letters[3]++; break;
		case 'e':letters[4]++; break;
		case 'f':letters[5]++; break;
		case 'g':letters[6]++; break;
		case 'h':letters[7]++; break;
		case 'i':letters[8]++; break;
		case 'j':letters[9]++; break;
		case 'k':letters[10]++; break;
		case 'l':letters[11]++; break;
		case 'm':letters[12]++; break;
		case 'n':letters[13]++; break;
		case 'o':letters[14]++; break;
		case 'p':letters[15]++; break;
		case 'q':letters[16]++; break;
		case 'r':letters[17]++; break;
		case 's':letters[18]++; break;
		case 't':letters[19]++; break;
		case 'u':letters[20]++; break;
		case 'v':letters[21]++; break;
		case 'w':letters[22]++; break;
		case 'x':letters[23]++; break;
		case 'y':letters[24]++; break;
		case 'z':letters[25]++; break;



		}
		
		

	}
	//string word_copy = word;
	//for (int i = 0; i < 26; i++)
	//{
	//	cout << letters[i] << " ";
	//}
	//cout << endl;
//for (int i = 1; i < 26; i++)
//{
//	letters[i] = letters[i] + letters[i - 1];
//}
//cout << word[letters[int(word_copy[1]) - 65] - 1] << "\n";
	int p = 0;
	for (int k = 0; k < 26; k++)
	{
		if (letters[k] > 0)
		{
			for (int i = p; i < p + letters[k]; i++)
			{
				word[i] = char(k + 97);
			}
			p = p + letters[k];
		}
	}
	//cout << word << "\n";
	//for (int i = size-1; i > 0; i--)
	//	{
	//		word[letters[word_copy[i] - 65] - 1] = word_copy[i];
	//		letters[word_copy[i] - 65]--;
	//	}
	//cout << word << "\n";
	//for (int i = 0; i < 26; i++)
	//{
	//	cout << letters[i] << " ";
	//}
	//cout << endl;
}

int main() {
	int n;
	cin >> n;
	string word1;
	cin >> word1;
	string word2;
	cin >> word2;
	if (word1.size() != word2.size()) { cout << "no\n"; return 0; }
	//cout << word1 << "\n";
	countingSort(word1);
	countingSort(word2);
	if (word1 == word2) { cout << "yes\n"; }
	else cout << "no\n";

	return 0;
}