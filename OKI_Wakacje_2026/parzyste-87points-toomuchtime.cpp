#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N = 0;
    cin >> N;
    if (N%2 != 0) N--;
    long long suma = 0;
    for (long long i = 0; i <= N; i = i+2)
    {
        suma = suma + i;
    }
    cout << suma << "\n";
    return 0;
}