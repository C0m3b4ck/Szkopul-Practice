#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// input
	int N = 0;
	cin >> N;
	vector<string> words;
	for (int i = 0; i < N; i++)
	{
		string tmp_word = "";
		cin >> tmp_word;
		char tmp_letter;
		tmp_letter = tmp_word[0];
		words.emplace_back(tmp_word); // get so that it is sorted based on first letter
	}
	// computation
	sort(words.begin(), words.end()); // sort words alphabetically
	for (int i = 0; i < N; i++) // debug
	{
		cout << words[i] << " ";
	}
	for (int i = 0; i < N; i++)
	{
		
	}
	return 0;
}
