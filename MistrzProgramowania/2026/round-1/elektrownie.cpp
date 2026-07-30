#include <iostream>

int main()
{
    // input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long facility_num = 0;
    std::cin >> facility_num;
    long long facility_arr[facility_num] = {};
    for (long long i = 0; i < facility_num; i++)
    {
        long long tmp = 0;
        std::cin >> tmp;
        facility_arr[i] = tmp;
    }
    // output
    long long sum = 0;
    for (long long j = 0; j < facility_num; j++) // precompute full sum
    {
        sum = sum + facility_arr[j];
    }
    // send each modified sum
    for (long long i = 0; i < facility_num; i++) // for every combination
    {
        long long tmp_sum = sum;
        tmp_sum = tmp_sum - facility_arr[i];
        std::cout << tmp_sum << " ";
    }
    std::cout << "\n";
    return 0;
}