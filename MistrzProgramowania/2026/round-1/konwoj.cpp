#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, m = 0;
    std::vector<std::pair<long long, long long, long long>> street_info = {};
    std::cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long a,b,c = 0;
        std::cin >> a >> b >> c;
        street_info.push_back({a,b,c});
    }  

}