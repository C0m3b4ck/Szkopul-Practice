#include <iostream>
#include <algorithm>
int main()
{
    // input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long team_num = 0;
    std::cin >> team_num;
    long long excercise_arr[team_num];
    long long penalty_arr[team_num];
    for (int i = 0; i < team_num; i++)
    {
        long long tmp = 0;
        std::cin >> tmp;
        excercise_arr[i] = tmp;
        tmp = 0;
        std::cin >> tmp;
        penalty_arr[i] = tmp;
    }
    // sort excercise numbers
    std::sort (excercise_arr, excercise_arr + team_num);
    //debug 
    //std::cout << (excercise_arr[(team_num - 1)] - excercise_arr[(team_num - 2)]) << "\n";
    if ((excercise_arr[(team_num - 1)] != excercise_arr[(team_num - 2)]))
        // -> if yes, output MAKSIMUM
    {
        std::cout << "MAKSIMUM \n";
    }
        // -> else, output MINIMUM
    else
    {
        std::cout << "MINIMUM \n";
    }
    return 0;
}