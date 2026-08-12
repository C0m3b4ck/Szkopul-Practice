#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long num_of_nums = 0;
    cin >> num_of_nums;
    long long todo_nums[num_of_nums];
    for (long long i = 0; i < num_of_nums; i++)
    {
        long long tmp = 0;
        cin >> tmp;
        todo_nums[i] = tmp;
    }
    // calculate how many multpiles of 10 and 5 appear
    // maybe use gaussian summation, eg. (10....10000, single sum is 0+0000=5 zeros, then 5x2=10 total zeros)
    for (long long i = 0; i < num_of_nums; i++) {
        long long counter = 0;
        long long result = todo_nums[i];
        while (result > 0) {
            result /= 5;
            counter += result;
        }
        cout << counter << "\n";
    }
    return 0;
}