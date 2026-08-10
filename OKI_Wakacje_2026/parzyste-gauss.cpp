#include <iostream>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    long long N = 0;
    cin >> N;
    if (N%2 != 0) N--;
    long long sum = 0;
    if (N == 1 || N == 0)
    {
        sum = 0;
    }
    else if (N == 2)
    {
        sum = 2;
    }
    else if (N == 5)
    {
        sum = 6;
    }
    else
    {
        long long precomp = (N) + 2; // includes non-2 numbers
        for (long long i = 2; i <= (N/2); i = i + 2) // 10 has 2x(2+10) + 6 (middle digit)
        {
            //sum = sum + i; is too basic, Gauss summation :)
            sum = sum + precomp;
        }
        if ((N/2)%2 != 0) sum = sum + (N/2+1);
    }
    cout << sum << "\n";
    return 0;
}