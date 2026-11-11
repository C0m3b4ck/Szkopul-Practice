#include <iostream>
#incldue <vector>
using namespace std;

int main()
{
	// input
	int N = 0; // number of numbers
	cin >> N;
	vector<int> ciag_cyfr;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		ciag_cyfr[i] = tmp;
	}
	// debug - output array
	/*
	for (int i = 0; i < N; i++)
	{
		cout << ciag_cyfr[i] << " ";
	}
	cout << "\n";
	*/
	// end debug
	// computation
	// check if any variations of 3 and 2 are to be found
	// assumption made that none are 0 at the beginning
    for (const int to_find : {2, 3})
        if (std::find(ciag_cyfr.begin(), ciag_cyfr.end(), needle) == ciag_cyfr.end())
            std::cout << "haystack does not contain " << to_find << '\n';
        else
            std::cout << "haystack contains " << to_find << '\n';
	}
	return 0;
}
