#include <iostream>
using namespace std;

int main()
{
	// input
	std::string instruction = "";
	cin >> instruction;
	// calculation
	int x = 0; // L subtracts, P adds
	int y = 0; // D subtracts, G adds
	for (int i = 0; i <= instruction.size(); i++)
	{
		char tmp = instruction[i];
		if (tmp == 'G') {y = y + 1;}
		else if (tmp == 'D') {y = y - 1;}
		else if (tmp == 'P') {x = x + 1;}
		else if (tmp == 'L') {x = x - 1;}
	}
	// output
	if (x > 0)
	{
		// output as many L as x
		for (int i = 0; i < x; i++)
		{
			cout << "L";
		}
	}
	else if (x < 0) 
	{
		// abs x, output as many P as x
		x = x * (-1);
		for (int i = 0; i < x; i++)
		{
			cout << "P";
		}
	}
	if (y > 0)
	{
		// output as many D as y
		for (int i = 0; i < y; i++)
		{
			cout << "D";
		}
	}
	else if (y < 0) 
	{
		// abs y, output as many G as y
		y = y * (-1);
		for (int i = 0; i < y; i++)
		{
			cout << "G";
		}
	}
	cout << "\n";
	return 0;
}
