#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long days = 0;
    std::cin >> days;
    long int tmp = days / 3;
    std::cout << days + tmp << "\n";
    return 0;
}