#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// input
	int N = 0;
	cin >> N;
	string path = "";
	cin >> path;
	// calculation
	string path_empty(N, '.'); 
	const char* path_cmp = path.c_str();
	const char* path_empty_cmp = path_empty.c_str();
	int counter = 0;
	while (strcmp(path_cmp, path_empty_cmp) != 0) // while path and empty path not the same
	{
		for (int i = 0; i < N; i++)
		{
			char tmp1 = path[i];
			char tmp2 = path[last_ele];
			if (tmp1 == 'X' && tmp2 == '.')
			{
				path[i] = '.';
				path[last_ele] = 'X';
				i = i + 1; // can only move by 1
			}
		}
		int last_ele = N;
		if (path[last_ele] == 'X')
		{
			path[last_ele] = '.';
		}
		cout << path << "\n"; // debug
		path_cmp = path.c_str();
		path_empty_cmp = path_empty.c_str();
		counter = counter + 1;
	}
	// output
	cout << counter << "\n"; // output ammount of moves
	return 0;
}
