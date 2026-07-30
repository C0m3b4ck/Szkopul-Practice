#include <iostream>
#include <vector>

int main()
{
    long long Z;
    std::cin >> Z;
    for (long long itr = 0; itr < Z; itr++)
    {
        long long n, m, q, A, B, C;
        std::cin >> n >> m >> q >> A >> B >> C;
        std::vector<long long> a(n);
        std::vector<long long> b(m);
        std::vector<std::pair<char, long long>> queries;
        for (long long i = 0; i < n; i++)
            std::cin >> a[i];
        for (long long i = 0; i < m; i++)
            std::cin >> b[i];
        for (long long i = 0; i < q; i++)
        {
            char t;
            long long x;
            std::cin >> t >> x;
            queries.push_back({t, x});
        }
        for (long long i = 0; i < q; i++)
        {
            char t, long long x; // t is character whose value is changing, x is the value
            std::cin >> t >> x;
        }
    }
}