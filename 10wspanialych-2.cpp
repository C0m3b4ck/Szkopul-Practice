#include <iostream>

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
    int top10[10];
    for (short l = 0; l < 10; l++)
    {
        int max = *std::max_element(power_arr, power_arr + ppl_num);
        top10[l] = max;
        int max_arr_pos = 0;
        for (int i = 0; i < ppl_num; i++)
        {
            if (power_arr[i] == max)
            {
                max_arr_pos = i;
            }
        }
        std::remove(power_arr + max_arr_pos, power_arr + max_arr_pos + 1, max);
        // debug
        std::cout << "DEBUG \n";
        for (int i = 0; i < ppl_num; i++)
        {
            std::cout << power_arr[i] << " ";
        }
        std::cout << "\n";
    }
    // get max element
    //add it to top10
    // remove max element
    //get max again
    for (short l = 0; l < 10; l++)
    {
        std::cout << top10[l] << " ";
    }
}