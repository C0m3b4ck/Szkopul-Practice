#include <iostream>
using namespace std;

int main()
{
	// input
	int N = 0;
	cin >> N;
	string path = "";
	cin >> path;
	// calculation
	int tries = 0;
	bool do_loop = true;
	while (do_loop)
	{
		for (int i = 0; i < N; i++)
		{
			char tmp = path[i];
			char tmp2 = path[(i+1)];
			if (tmp == 'X' && tmp2 == '.')
			{
				path[i] = '.';
				int tmp = i + 1;
				path[tmp] = 'X';
			}
		}
		for (int j = 0; j < N; j++) // check if all are .
		{
			if (path[j] == 'X')
			{
				break;
			}
			if (j == (N - 1)) // got to the end without breaking
			{
				do_loop = false;
				cout << "Done\n"; // debug	
				cout << tries << "\n"; // debug
			}
		}
		tries = tries + 1;
	}
	return 0;
}
