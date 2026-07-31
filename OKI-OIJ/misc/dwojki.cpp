#include <iostream>
using namespace std;

long long x;
long long tmp;

bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// returns 2^i as long long, or -1 on overflow
long long pow2(int i) {
    if (i < 0 || i >= 63) return -1;   // 2^63 overflows signed long long
    return 1LL << i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    x = 0;
    tmp = 2;
    cin >> x;
    long long tries = 0;
    if (x >= 1)
    {
        tries++;
    }
    for (long long i = 1; i < x; i++) //skip 1 - 2^0 is 1
    {
        tmp = pow2(i);
        if (tmp <= x) // && isPowerOfTwo(tmp) == 1
        {
            tries++;
        }
        else if (tmp > x)
        {
            break;
        }
    }
    cout << tries << "\n";
    return 0;
}