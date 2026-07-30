#include <iostream>

int main()
{
    long long N = 0;
    long long dist = 0;
    std::cin >> N;
    long long xy[N] = {};
    for (long long i = 0; i < N; i++)
    {
        long long tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        xy[i] = tmp1;
        xy[(i+1)] = tmp2;
    }
    long long distance_sum = 0;
    for (long long i = 0; i < N; i++)
    {
        distance_sum += std::abs(xy[i] - xy[i+2]) + std::abs(xy[i+1] - xy[i+3]);
    }
    long long max_savings = 0;
    for (long long i = 0; i < N; i++)
    {
        long long savings = (std::abs(xy[i] - xy[i+1]) + std::abs(xy[i+4] - xy[i+5])) - std::abs(xy[i+2] - xy[i+3]);
        if (savings > max_savings) {
            max_savings = savings;
        }
    }
    std::cout << (distance_sum - max_savings) << "\n";
    return 0;
}