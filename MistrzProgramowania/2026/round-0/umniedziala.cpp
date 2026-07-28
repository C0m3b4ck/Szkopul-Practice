#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long number_of_numbers;
    std::cin >> number_of_numbers;
    long long tmp = 2;
    long long unev_tmp = 1;
    for (long long i = 0; i < number_of_numbers; i++)
    {
        for (long long j = 0; j < unev_tmp; j++)
        {
            std::cout<<tmp;
        }
        unev_tmp = unev_tmp + 2;
        tmp = tmp + 2;
    }
    std::cout << "\n";
}