#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num;
    std::vector<int> bin_arr = {};
    std::cin >> num;
    // if num is 0 - output 0 0 
    if (num == 0)
    {
        std::cout << "0 0";
        return 0;
    }
    else
    {
        // ininital num to bin
        int y = num;
        for (int i = 0; i < num; i++)
        {
            long int x = y % 2;
            y = y / 2;
            bin_arr.push_back(x);
            if (y <= 0)
            {
                break;
            }
        }
        std::reverse(bin_arr.begin(), bin_arr.end());
        // print num 1
        for (int i = 0; i < bin_arr.size(); i++)
        {
            std::cout << bin_arr[i];
        }
        std::cout << " ";
        // get sum of digits num 1
        int sum = 0;
        // ---> sum up the digits
        for (int i = 0; i < bin_arr.size(); i++)
        {
            sum = sum + bin_arr[i];
        }
        // ---> convert to binary
        bin_arr.clear();
        y = sum;
        //for (int i = 0; i < (sum / 2 + sum % 2); i++)
        for (int i = 0; i < sum; i++)
        {
            long int x = y % 2;
            y = y / 2;
            bin_arr.push_back(x);
            if (y <= 0)
            {
                break;
            }
        }
        std::reverse(bin_arr.begin(), bin_arr.end());
        //print num 2
        for (int i = 0; i < bin_arr.size(); i++)
        {
            std::cout << bin_arr[i];
        }
    }
}