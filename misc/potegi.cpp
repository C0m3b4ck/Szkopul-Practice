#include <iostream>
using namespace std;

bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// returns 2^i as long long, or -1 on overflow
long long pow2(long long i) {
    if (i < 0 || i >= 63) return -1;   // 2^63 overflows signed long long
    return 1LL << i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long smaller_than = 0;
    long long tmp = 2;
    
    cin >> smaller_than;
    for (long long i = 0; i < (smaller_than + 1); i++)
    {
        tmp = pow2(i);
        if (tmp <= smaller_than)
        {
            cout << tmp << "\n";
        }
        else
        {
            break;
        }
    }
    return 0;
}