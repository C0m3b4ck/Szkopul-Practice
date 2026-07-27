#include <cstdio>
#include <cstring>

int main() {
    int n;
    scanf("%d", &n);
    char s[32];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%s\n", s);
    }
    return 0;
}
