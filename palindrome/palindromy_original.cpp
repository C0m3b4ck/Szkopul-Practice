#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_dates;
    std::cin >> num_dates;
    //get dates in ddmmyyyy
    std::vector<std::string> date_arr = {};
    for (int i = 0; i < num_dates; i++)
    {
        std::string temp_string;
        std::cin>>temp_string;
        date_arr.push_back(temp_string);
    }
    //get next palindrome for each date
    for (int i = 0; i < num_dates; i++)
    {
        //get day, month, year from string
        // char - '0'
        std::string temp_string = date_arr[i];
        short day = (10 * (temp_string[0] - '0')) + (temp_string[1] - '0');
        short month = (10 * (temp_string[2] - '0')) + (temp_string[3] - '0');
        long long int year = 0;
        for (short f = 0; f < (temp_string.length() - 4); f++)
        {
            if (temp_string[f+4 != 0])
            {
                year = year + (temp_string[f+4] - '0') * (pow(10,(temp_string.length() - 5 - f)));
            }
        }
        //calculate palindrome
        //days can't be over 31
        //that means year range from 01 to 31
        short new_day = day;
        short new_month = month;
        long long int new_year = year;
        //make current palindrome
        // number reversal
        // add/remove multiples of 9
        // 23 + 9 = 32
        // 18 + 63 = 81, because 8-1 is 7 and 7x9 is 63
        ////// first, try to add to decimal digit of day num, that way year does not increase significantly
        ////// it needs to be in the future, so no decreasing days if m/y does not 
        ////// increasing month digit +1 increases largest multiple of 10 for year (+1000 for 4-digit year)

        /// 1. decrease month digit 1 by as much as possible - often the past
        /// 2. decrease day digit 1 by as much as possible - often the past
        /// 3. if fails - increase day digit 2 by 1 
        //validate palindrome
        // step 3.
            //validate month shenanigans
            if (new_day > 28 && new_month == 2 && (new_year%4 != 0))
            {
                // fix - february has more days than 28 on non-leap year
            }
            else if (new_day > 29 && new_month == 2 && ((new_year % 4) == 0))
            {
                new_day = 29; //maybe some reversal, from 13 to 31?
            }
            if (new_day > 30 && (new_month%2)==0)
            {
                new_day = 30;
            }
            if (new_day > 31 || new_month < 0)
            {
                new_day = 31;
            }
            if (new_month > 12 || new_month < 0)
            {
                new_month = 1;
            }
            
            // print
            if (new_day < 10)
            {
                std::cout<<"0";
            }
            std::cout<<new_day;
            if (new_month < 10)
            {
                std::cout<<"0";
            }
            std::cout<<new_month << new_year << "\n";
    }
    return 0;
}