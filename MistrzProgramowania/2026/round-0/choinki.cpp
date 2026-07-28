#include <cstdio>

int main()
{
    long long n;
    scanf("%lld", &n);
    long long lo = 1, hi = n;
    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;
        printf("? %lld\n", mid);
        fflush(stdout);
        char c;
        scanf(" %c", &c);
        if (c == '>')
            lo = mid + 1;
        else if (c == '<')
            hi = mid - 1;
        else
            break;
    }
    return 0;
}