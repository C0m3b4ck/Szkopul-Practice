#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //input
    int date_num;
    std::cin >> date_num;
    std::vector<std::string> date_arr = {};    
    for (int i = 0; i < date_num; i++)
    {
        std::string tmp = "";
        std::cin>>tmp;
        date_arr.push_back(tmp);
    }
    //palindrome calculations - output in loop
    for (int i = 0; i < date_num; i++)
    {   
        //getting number of days and months
        bool has_been_changed = false;
        std::string work_string = date_arr[i];
        short days = 10 * (work_string[0] - '0') + (work_string[1] - '0');
        short months = 10 * (work_string[2] - '0') + (work_string[3] - '0');
        //getting year
        long long year = 0;
        for (size_t j = 4; j < work_string.size(); ++j) {
            long long power = 1;
            for (size_t k = j + 1; k < work_string.size(); ++k)
            {
                power *= 10;                       // 10^(remaining digits)
                year += (work_string[j] - '0') * power;
            }
        }

        //try to increase day decimal digit
        if (!(days>=31))
        {
            if (!(
                (days>30) 
                && (months%2 == 0) 
                && months != 8
            ))
            {
                if (!(
                    (days>28) 
                    && months==2
                    && year%4 != 0
                ))
                {
                    if (!(
                        (days>29) && 
                        months == 2 && 
                        (year%4 == 0)
                    ))
                    {
                        // changing decimal digit is possible - change
                        short tmp = work_string[0] - '0';
                        tmp++;
                        work_string[0] = (tmp + '0');
                        work_string[(work_string.length()-1)] = tmp + '0';
                        std::cout << work_string << "\n";
                        break;
                    }
                }
            }
        }
        //try increasing 2nd digit
        if (!has_been_changed && !(work_string[0] == '3' && (work_string[1] - '0') > 1))
        {
            short tmp = work_string[1] - '0';
            tmp++;
            tmp = tmp + '0';
            work_string[1] = tmp;
            work_string[(work_string.length()-2)] = work_string[1];
            std::cout << work_string << "\n";
            break;
        }
        //try increasing 3rd digit
        if (!has_been_changed && !(work_string[2] == '1'))
        {
            short tmp = work_string[2] - '0';
            tmp++;
            tmp = tmp + '0';
            work_string[2] = tmp;
            work_string[(work_string.length()-3)] = work_string[2];
            std::cout << work_string << "\n";
            break;
        }
        //try increasing 4th digit
        if (!has_been_changed && !((work_string[3] - '0') >= 9))
        {
            if (!((work_string[2] == '1') && !((work_string[3] - '0') >= 2)))
            {
                short tmp = work_string[3] - '0';
                tmp++;
                tmp = tmp + '0';
                work_string[3] = tmp;
                work_string[(work_string.length()-4)] = work_string[3];
                std::cout << work_string << "\n";
                break;
            }
        }
        // else - check which digit you can increase
        bool keep_working = true;
        for (int k = 5; k < work_string.length(); k++)
        {
            if (keep_working)
            {
                if ((work_string[k] - '0') < 9)
                {
                    short tmp = work_string[k] - '0';
                    tmp++;
                    tmp = tmp + '0';
                    work_string[k] = tmp;
                    work_string[(work_string.length() - (k+5))] = work_string[k];
                    std::cout << work_string << "\n";
                    break;
                }
            }
        }
        //finally, if forced to - increase digit 5 (worst case scenario)
        if ((work_string[4] - '0') < 9) //is the check even necessary now?
        {
            short tmp = work_string[4] - '0';
            tmp++;
            tmp = tmp + '0';
            work_string[4] = tmp;
            work_string[(work_string.length() - 5)] = work_string[4];
            std::cout << work_string << "\n";
            break;
        }
    }
    

    return 0;
}
