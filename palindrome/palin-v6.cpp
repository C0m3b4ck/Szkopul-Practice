#pragma GCC optimize("O2")
#include <cstdio>
#include <cstring>
#include <unistd.h>

bool is_leap(long long y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, long long y) {
    if (m == 2) return is_leap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

long long P10[26];

long long make_pal(long long p, int n) {
    long long r = p, t = p;
    if (n & 1) t /= 10;
    for (int i = 0; i < n / 2; i++) {
        r = r * 10 + (t % 10);
        t /= 10;
    }
    return r;
}

long long smallest_pal(long long v, int n) {
    if (n == 0) return v <= 0 ? 0 : -1;
    long long mx = P10[n];
    if (v >= mx) return -1;
    if (v < 0) v = 0;
    int h = (n + 1) / 2;
    long long mp = P10[h];
    long long s = mx / mp;
    long long p = v / s;
    long long pal = make_pal(p, n);
    if (pal >= v) return pal;
    if (++p >= mp) return -1;
    return make_pal(p, n);
}

struct DDMM {
    int dd, mm;
    long long rv;
};

DDMM ddmm[366];
char ddmm_ds[366][5];

static char ibuf[1 << 22];
static char obuf[1 << 22];
static int opos = 0;

void out_str(const char* s) {
    while (*s) obuf[opos++] = *s++;
}

void out_ll(long long x) {
    char tmp[24];
    int t = 0;
    if (x < 0) { obuf[opos++] = '-'; x = -x; }
    if (x == 0) { obuf[opos++] = '0'; return; }
    while (x > 0) { tmp[t++] = '0' + (x % 10); x /= 10; }
    for (int i = t - 1; i >= 0; i--) obuf[opos++] = tmp[i];
}

int main() {
    P10[0] = 1;
    for (int i = 1; i <= 18; i++) P10[i] = P10[i-1] * 10;

    int ddmm_n = 0;
    for (int dd = 1; dd <= 31; dd++)
        for (int mm = 1; mm <= 12; mm++) {
            if (mm == 2 && dd > 29) continue;
            if ((mm==4||mm==6||mm==9||mm==11) && dd > 30) continue;
            ddmm[ddmm_n].dd = dd;
            ddmm[ddmm_n].mm = mm;
            ddmm_ds[ddmm_n][0] = '0'+dd/10;
            ddmm_ds[ddmm_n][1] = '0'+dd%10;
            ddmm_ds[ddmm_n][2] = '0'+mm/10;
            ddmm_ds[ddmm_n][3] = '0'+mm%10;
            ddmm_ds[ddmm_n][4] = 0;
            ddmm[ddmm_n].rv = (long long)(ddmm_ds[ddmm_n][3]-'0') * 1000
                            + (long long)(ddmm_ds[ddmm_n][2]-'0') * 100
                            + (long long)(ddmm_ds[ddmm_n][1]-'0') * 10
                            + (ddmm_ds[ddmm_n][0]-'0');
            ddmm_n++;
        }

    int n = 0;
    {
        int r = read(STDIN_FILENO, ibuf, sizeof(ibuf));
        int pos = 0;
        while (pos < r && ibuf[pos] >= '0' && ibuf[pos] <= '9')
            n = n * 10 + (ibuf[pos++] - '0');

        for (int tc = 0; tc < n; tc++) {
            while (pos < r && (ibuf[pos] < '0' || ibuf[pos] > '9')) pos++;

            char s[32];
            int slen = 0;
            while (pos < r && ibuf[pos] >= '0' && ibuf[pos] <= '9')
                s[slen++] = ibuf[pos++];
            s[slen] = 0;

            int L = slen;
            int ddi = (s[0]-'0')*10 + s[1]-'0';
            int mmi = (s[2]-'0')*10 + s[3]-'0';
            long long yi = 0;
            for (int i = 4; i < L; i++) yi = yi * 10 + (s[i] - '0');

            long long best_yr = -1;
            int best_i = 0;

            for (int try_len = L; try_len <= 22; try_len++) {
                if (best_yr >= 0) break;
                int ml = try_len - 8;
                if (ml < 0) continue;

                for (int i = 0; i < ddmm_n; i++) {
                    int d_mm = ddmm[i].mm;
                    int d_dd = ddmm[i].dd;
                    long long my = (d_mm > mmi || (d_mm == mmi && d_dd > ddi)) ? yi : yi + 1;
                    if (my < 1000) my = 1000;
                    long long d_rv = ddmm[i].rv;

                    if (ml == 0) {
                        if (d_rv < my) continue;
                        if (best_yr >= 0 && d_rv >= best_yr) continue;
                        if (d_dd > days_in_month(d_mm, d_rv)) continue;
                        best_yr = d_rv;
                        best_i = i;
                    } else {
                        long long mn = (my <= d_rv) ? 0 : (my - d_rv + 9999) / 10000;
                        long long mv = smallest_pal(mn, ml);
                        if (mv < 0) continue;
                        long long yr = mv * 10000LL + d_rv;
                        if (best_yr >= 0 && yr >= best_yr) continue;
                        if (d_dd > days_in_month(d_mm, yr)) continue;
                        best_yr = yr;
                        best_i = i;
                    }
                }
            }

            out_str(ddmm_ds[best_i]);
            out_ll(best_yr);
            obuf[opos++] = '\n';
        }
    }

    write(STDOUT_FILENO, obuf, opos);
    return 0;
}
