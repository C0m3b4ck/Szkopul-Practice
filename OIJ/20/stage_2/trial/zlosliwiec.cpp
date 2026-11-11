#include <iostream>
using namespace std;

int main()
{
	// input
	long long N = 0; // ammount of cookies
	cin >> N;
	
	// calculate
	// check minimal ammount with modulo of at least 1
	for (long long i = 2; i < N; i++)
	{
		if ((N % i) > 0) // mozna zlosliwie podzielic
		{
			cout << i << " ";
			break;
		}
	}
	// check maximum ammount with modulo of at least 1
	long long max_number = 0;
	for (long long i = 2; i < N; i++)
	{
		if ((N % i) > 0) // mozna zlosliwie podzielic
		{
			max_number = i;
		}
	}
	cout << max_number << "\n"; // output finalized
	 
	return 0;
}
