#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

int main()
{
    long long N = 0;
    long long dist = 0;
    std::cin >> N;
    std::vector<std::pair<long long, long long>> xy;
    for (long long i = 0; i < N; i++)
    {
        long long tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        xy.push_back({tmp1, tmp2});
    }
    long long distance_sum = 0;
    for (long long i = 0; i < N - 1; i++)
    {
        distance_sum += std::abs(xy[i].first - xy[i+1].first) + std::abs(xy[i].second - xy[i+1].second);
    }
    long long max_savings = 0;
    for (long long i = 1; i < N - 1; i++)
    {
        long long left  = std::abs(xy[i-1].first - xy[i].first)   + std::abs(xy[i-1].second - xy[i].second);
        long long right = std::abs(xy[i].first   - xy[i+1].first) + std::abs(xy[i].second   - xy[i+1].second);
        long long skip  = std::abs(xy[i-1].first - xy[i+1].first) + std::abs(xy[i-1].second - xy[i+1].second);
        long long savings = left + right - skip;
        if (savings > max_savings)
        {
            max_savings = savings;
        }
    }
    std::cout << distance_sum - max_savings << "\n";
    return 0;
}