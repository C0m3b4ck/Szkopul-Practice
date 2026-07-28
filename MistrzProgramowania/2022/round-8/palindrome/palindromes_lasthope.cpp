#include <iostream>
#include <vector>

int main()
{
    //input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int date_num = 0;
    std::cin >> date_num;
    std::vector<std::string> date_arr = {};

    for (int i = 0; i < date_num; i++)
    {
        std::string tmp;
        std::cin>>tmp;
        date_arr.push_back(tmp);
    }

    //compute all strings
    for (int i = 0; i < date_num; i++)
    {
        std::string work_string = date_arr[i];
        //get day and month int
        int day = ((work_string[0] - '0') * 10) + (work_string[1] - '0');
        int month = ((work_string[2] - '0') * 10) + (work_string[3] - '0');
        // first - try to increase decimal digit of days
            //handle edge cases:
            //31122113
            //30066003
        long long ws_length = work_string.length();
        short year = (work_string[ws_length - 1] - '0') + ((work_string[(ws_length - 2)] - '0') * 10);
        if (month != 2)
        {
            if (day > 29)
            {
                if (month%2 == 0 && month != 12 && month != 2 && month != 8 || month == 9)
                {
                        //set day digits to 01
                        work_string[0] = '0';
                        work_string[1] = '1';
                        //increase month digit by 1
                        if (work_string[3] == '9') //september into october
                        {
                            work_string[3] == '0';
                            work_string[2] == '1';
                            work_string[ws_length - 2] = '1';
                            work_string[ws_length - 1] = '0';
                            std::cout << work_string << "\n"; 
                            break;
                        }
                        else
                        {
                            int tmp = (work_string[3] - '0');
                            tmp++;
                            char tmp_char = (tmp + '0');
                            work_string[3] = tmp_char;
                            work_string[ws_length - 1] = work_string[0];
                            work_string[ws_length - 2] = work_string[1];
                            work_string[ws_length - 3] = work_string[2];
                            work_string[ws_length - 4] = work_string[3];
                            std::cout << work_string << "\n"; 
                            break;
                        }  
                }
                  
            }
            else if (month != 12 && month != 2 && month != 9)
            {
                if (day > 30)
                {
                    //set day digits to 01
                    work_string[0] = '0';
                    work_string[1] = '1';
                    //increase month digit by 1
                    int tmp = (work_string[3] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[3] = tmp_char;
                    work_string[ws_length - 1] = work_string[0];
                    work_string[ws_length - 2] = work_string[1];
                    work_string[ws_length - 3] = work_string[2];
                    work_string[ws_length - 4] = work_string[3];
                    std::cout << work_string << "\n"; 
                    break;
                }  
            }
        }
        else if (month == 12)
        {
            //handle december - increase year, changing month to january decreases year, trickitiyiy
        }
        else //handling february
        {
            if (year%4 == 0 || year == 0)
            {
                if (day > 28)
                {
                    //set day digits to 01
                    work_string[0] = '0';
                    work_string[1] = '1';
                    //increase month digit by 1
                    work_string[2] = '0';
                    work_string[3] = '3';
                    //mirror digits
                    work_string[ws_length - 1] = '0';
                    work_string[ws_length - 2] = '1';
                    work_string[ws_length - 3] = '0';
                    work_string[ws_length - 4] = '3';
                    //output
                    std::cout << work_string << "\n"; 
                    break;
                }
                // 20 02 - increase day digit 2
                // 10 02 - increase day decimal digit
            }
            else
            {
                if (day > 27)
                {
                    //set day digits to 01
                    work_string[0] = '0';
                    work_string[1] = '1';
                    //increase month digit by 1
                    work_string[2] = '0';
                    work_string[3] = '3';
                    //mirror digits
                    work_string[ws_length - 1] = '0';
                    work_string[ws_length - 2] = '1';
                    work_string[ws_length - 3] = '0';
                    work_string[ws_length - 4] = '3';
                    //output
                    std::cout << work_string << "\n";  
                    break;
                }
                // 20 02 - increase day digit 2
                // 10 02 - increase day decimal digit
            }
        }
    }
}