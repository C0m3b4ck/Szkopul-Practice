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

    //brute-force
    for (int i = 0; i < date_num; i++)
    {
        std::string work_string = date_arr[i];
        
    }

return 0;
}