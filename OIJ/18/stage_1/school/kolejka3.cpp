#include <iostream>
#include <string>
using namespace std;

int main()
{
    // input
    int N = 0;
    string path = "";
    int counter = 1;
    cin >> N;
    cin >> path;
    // compute
    while (path.find('X') != string::npos)
    {
        for (int i = 0; i < N - 1; ++i)
        {
            if (path[i] == 'X' && path[i + 1] == '.')
            {
                path[i] = '.';
                path[i + 1] = 'X';
                ++i; // x moves one place per turn
            }
        }
	if (path[N - 1] == 'X') path[N - 1] = '.'; // shop entry

        ++counter;
    }
    // output
    cout << counter << '\n';
    return 0;
}
