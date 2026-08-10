#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long stone_num = 0;
    cin >> stone_num;
    long long stone_arr[stone_num];
    for (long long i = 0; i < stone_num; i++) //input loop
    {
        cin >> stone_arr[i];
    }
    for (long long i = 0; i < stone_num; i++)
    {
        if (!(stone_arr[i] >= stone_arr[i+1] && (i+1) <= stone_num))
        {
            cout << (i+1) << "\n";
            break;
        }
    }
    return 0;
}