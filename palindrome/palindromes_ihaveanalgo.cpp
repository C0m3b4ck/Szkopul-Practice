#include <iostream>
#include <vector>

std::vector<std::string> date_arr = {};

// Definition inside the namespace
long long check_palindrome_valid(std::string palindrome)
{
    for (int z = 0; z < palindrome.length(); z++)
    {
        if (palindrome[z] != palindrome[(palindrome.length() - (1 + z))])
        {
            return z;
        }
    }
    std::cout << palindrome << "\n";
    return -1; //return -1 upon success
}

std::string make_palindrome(std::string work_string)
{
        //std::string work_string = date_arr[i];
        //get day and month int
        int day = ((work_string[0] - '0') * 10) + (work_string[1] - '0');
        int month = ((work_string[2] - '0') * 10) + (work_string[3] - '0');
        long long ws_length = work_string.length();
        short year = (work_string[ws_length - 1] - '0') + ((work_string[(ws_length - 2)] - '0') * 10);
        if (month%2 == 0 && month != 12 && month != 2 && month != 8 || month == 9)
        {
            if (day < 21)         // first - increase day decimal digit
            {
                short tmp = (work_string[0] - '0');
                tmp++;
                char tmp_char = (tmp + '0');
                work_string[0] = tmp_char;
                work_string[(work_string.length() - 1)] = work_string[0];
                return work_string;
            }
            else //if can't, increase day non-dec, then month dec if possible, month non-dec as last resort
            {
                if ((work_string[1]) != '9' && (work_string[0]) != '3') //day non-dec
                {
                    short tmp = (work_string[1] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[1] = tmp_char;
                    work_string[(work_string.length() - 2)] = work_string[1];
                    /*check_palindrome_valid(work_string);
                    std::cout << work_string << "\n";
                    break;   */
                    return work_string;
                }
                else if ((work_string[2] - '0') != 1 && !((work_string[3] - '0') > 2)) //month dec
                {
                    short tmp = (work_string[2] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[2] = tmp_char;
                    work_string[(work_string.length() - 3)] = work_string[2];
                    return work_string;
                }
                else //last resort - increasing month non-dec (+10^(year length) years)
                {
                    if (work_string[3] != '9')
                    {
                        short tmp = (work_string[3] - '0');
                        tmp++;
                        char tmp_char = (tmp + '0');
                        work_string[3] = tmp_char;
                        work_string[(work_string.length() - 4)] = work_string[3];
                        return work_string;
                    }
                }
            }
        }
        else if (month%2 != 0 && month != 12 && month != 2) //same handling but for months that can reach 31 days
        {
            if (day < 22)         // first - increase day decimal digit
            {
                short tmp = (work_string[0] - '0');
                tmp++;
                char tmp_char = (tmp + '0');
                work_string[0] = tmp_char;
                work_string[(work_string.length() - 1)] = work_string[0];
                return work_string;
            }
            else //if can't, increase day non-dec, then month dec if possible, month non-dec as last resort
            {
                if ((work_string[1]) != '9' && (work_string[0]) != '3') //day non-dec
                {
                    short tmp = (work_string[1] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[1] = tmp_char;
                    work_string[(work_string.length() - 2)] = work_string[1];
                    return work_string; 
                }
                else if ((work_string[2] - '0') != 1 && !((work_string[3] - '0') > 2)) //month dec
                {
                    short tmp = (work_string[2] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[2] = tmp_char;
                    work_string[(work_string.length() - 3)] = work_string[2];
                    return work_string;
                }
                else //last resort - increasing month non-dec (+10^(year length) years)
                {
                    if (work_string[3] != '9')
                    {
                        short tmp = (work_string[3] - '0');
                        tmp++;
                        char tmp_char = (tmp + '0');
                        work_string[3] = tmp_char;
                        work_string[(work_string.length() - 4)] = work_string[3];
                        return work_string;
                    }
                }
            }
        }
        else if (month == 2) //february handling
        {
            if (day < 19)         // first - increase day decimal digit
            {
                short tmp = (work_string[0] - '0');
                tmp++;
                char tmp_char = (tmp + '0');
                work_string[0] = tmp_char;
                work_string[(work_string.length() - 1)] = work_string[0];
                return work_string;
            }
            else //if can't, increase day non-dec, then month dec if possible, month non-dec as last resort
            {
                if ((work_string[1]) != '9' && (work_string[0]) != '3') //day non-dec
                {
                    short tmp = (work_string[1] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[1] = tmp_char;
                    work_string[(work_string.length() - 2)] = work_string[1];
                    return work_string;  
                }
                else if ((work_string[2] - '0') != 1 && !((work_string[3] - '0') > 2)) //month dec
                {
                    short tmp = (work_string[2] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[2] = tmp_char;
                    work_string[(work_string.length() - 3)] = work_string[2];
                    return work_string; 
                }
                else //last resort - increasing month non-dec (+10^(year length) years)
                {
                    if (work_string[3] != '9')
                    {
                        short tmp = (work_string[3] - '0');
                        tmp++;
                        char tmp_char = (tmp + '0');
                        work_string[3] = tmp_char;
                        work_string[(work_string.length() - 4)] = work_string[3];
                        return work_string;
                    }
                }
            }
        }
        else if (month == 12) //december handling
        {
            if (day < 22)         // first - increase day decimal digit
            {
                short tmp = (work_string[0] - '0');
                tmp++;
                char tmp_char = (tmp + '0');
                work_string[0] = tmp_char;
                work_string[(work_string.length() - 1)] = work_string[0];
                return work_string;
            }
            else if (day == 31) // if 31.12
            {
                short tmp = (work_string[4] - '0');
                tmp++;
                char tmp_char = (tmp + '0');
                work_string[4] = tmp_char;
                work_string[(work_string.length() - 5)] = work_string[4];
                return work_string;
            }
            else //if can't, increase day non-dec, then month dec if possible, month non-dec as last resort
            {
                if ((work_string[1]) != '9' && (work_string[0]) != '3') //day non-dec
                {
                    short tmp = (work_string[1] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[1] = tmp_char;
                    work_string[(work_string.length() - 2)] = work_string[1];
                    return work_string;   
                }
                else if ((work_string[2] - '0') != 1 && !((work_string[3] - '0') > 2)) //month dec
                {
                    short tmp = (work_string[2] - '0');
                    tmp++;
                    char tmp_char = (tmp + '0');
                    work_string[2] = tmp_char;
                    work_string[(work_string.length() - 3)] = work_string[2];
                    return work_string;
                }
                else //last resort - increasing month non-dec (+10^(year length) years)
                {
                    if (work_string[3] != '9')
                    {
                        short tmp = (work_string[3] - '0');
                        tmp++;
                        char tmp_char = (tmp + '0');
                        work_string[3] = tmp_char;
                        work_string[(work_string.length() - 4)] = work_string[3];
                        return work_string;
                    }
                }
            }
                
        }
    return ""; // palindrome not found (somehow?!)
}

int main()
{
    //input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int date_num = 0;
    std::cin >> date_num;

    for (int i = 0; i < date_num; i++)
    {
        std::string tmp;
        std::cin>>tmp;
        date_arr.push_back(tmp);
    }

    // the algo
    for (int i = 0; i < date_num; i++)
    {
        long long status = (check_palindrome_valid(make_palindrome(date_arr[i])));
        while (status != -1)
        {
            std::string palindrome_to_fix = date_arr[i];
            status = (check_palindrome_valid(make_palindrome(palindrome_to_fix)));
        }
    }
    return 0;
}