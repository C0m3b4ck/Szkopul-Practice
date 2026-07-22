#include <iostream>
#include <algorithm>

int main()
{
    int ppl_num = 0;
    std::cin >> ppl_num;
    int power_arr[ppl_num];
    //input
    for (int i = 0; i < ppl_num; i++)
    {
        std::cin >> power_arr[i];
    }
    //sort
    std::sort(power_arr, power_arr + ppl_num);
    //out
    for (short l = 1; l < 11; l++)
    {
        std::cout << power_arr[ppl_num-l] << " ";
    }
}