#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long max_glass = 0;
    std::cin >> max_glass;
    long long min_glass = 0;
    min_glass = max_glass / 2;
    if ((min_glass * 2) != max_glass) //eliminate wrong rounding
    {
        min_glass++;
    }
    std::cout << min_glass << "\n";
    return 0;
}