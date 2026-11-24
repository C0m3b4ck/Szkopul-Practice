#include <iostream>
using namespace std;

int main()
{
	// input
	int N = 0; // number of Fibonacci numbers
	int H = 0; // wysokosc
	cin >> N >> H;
	// computation
	int tmp1 = 1; int tmp2 = 1;
	N = N - 2;
	int area = 2;
	for (int i = 0; i < N; i ++)
	{
		int tmp3 = tmp1 + tmp2; // get next Fibonacci number
		//cout << tmp1 << " " << tmp2 << " " << tmp3 << "\n"; //debug
		area = area + tmp3; // add to area
		tmp1 = tmp2; // move nums by one
		tmp2 = tmp3;
	}
	int min_width = 0;
	if (area % H != 0) {min_width = (area / H) + 1;} else {min_width = area / H;} // check minimal width with following height
	cout << "\n" << area << " " << min_width << "\n"; // debug
	
	return 0;
}
