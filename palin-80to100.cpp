// ============================================================
// PALINDROME DATE FINDER
// ============================================================
// Given a date string ddmmYYYY..., find the NEXT date whose
// full string representation is a palindrome.
//
// PALINDROME STRUCTURE:
//   ddmm [middle palindrome] reversed(ddmm)
//   The year IS reversed(ddmm), possibly with a palindrome
//   prefix in front of it.
//   Example: "0306" + "1221" + "6030" → year = 12216030
//
// PRECOMPUTATION:
//   There are only 366 valid calendar days (dd,mm combos).
//   We precompute all of them, including rv = reverse(ddmm).
//
// KEY OPTIMIZATION (yi > 9092):
//   rv ranges 101–9092. When yi > 9092, ALL entries have
//   rv < my, so year = pal(mn)*10000 + rv where
//   mn = ceil((my-rv)/10000). Since rv spans only ~9000
//   values, mn changes by at most 1 across all entries.
//   With 2 possible my values × 2 mn groups = at most 4
//   groups. We scan entries sorted by rv (ascending) and
//   pick the first valid entry per group → O(1) per query.
//
// SLOW PATH (yi ≤ 9092):
//   Some entries may have rv ≥ my (year = rv directly).
//   We check all 366 entries with early pruning.
// ============================================================

#pragma GCC optimize("O3,unroll-loops")
#include <cstdio>
#include <cstring>

static long long P10[26];
static int max_days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

// Leap year: divisible by 4, except centuries unless div by 400.
static inline bool is_leap(long long y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Build an n-digit palindrome from prefix p.
// Mirrors the first half onto the back.
// Odd length: center digit of p is shared, not duplicated.
static inline long long make_pal(long long p, int n) {
    long long r = p, t = p;
    if (n & 1) t /= 10;
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        r = r * 10 + (t % 10);
        t /= 10;
    }
    return r;
}

// Smallest n-digit palindrome >= v. Returns -1 if none exists.
// Extracts prefix of v, mirrors it, checks if >= v.
// If not, tries next prefix.
static inline long long smallest_pal(long long v, int n) {
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

// Precomputed table of all valid (dd,mm) calendar dates.
// ddmm_dd[i] = day, ddmm_mm[i] = month,
// ddmm_rv[i] = reverse(ddmm) as integer,
// ddmm_ds[i] = "ddmm" string.
static int ddmm_dd[366], ddmm_mm[366];
static long long ddmm_rv[366];
static char ddmm_ds[366][5];

// Indices into ddmm table, sorted by rv ascending.
// Critical for O(1) fast path: smallest rv gives smallest year.
static int sorted_idx[366];

// Buffered I/O: 1MB buffers, fread/fwrite for speed.
static char ibuf[1 << 20];
static char obuf[1 << 20];
static int ipos = 0, ilen = 0, olen = 0;

static inline int readChar() {
    if (ipos == ilen) {
        ilen = fread(ibuf, 1, sizeof(ibuf), stdin);
        ipos = 0;
        if (ilen == 0) return -1;
    }
    return ibuf[ipos++];
}

static inline int readInt() {
    int c = readChar(), x = 0;
    while (c <= ' ' && c != -1) c = readChar();
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = readChar(); }
    return x;
}

static inline int readStr(char* s) {
    int c = readChar(), i = 0;
    while (c <= ' ' && c != -1) c = readChar();
    while (c > ' ') { s[i++] = c; c = readChar(); }
    s[i] = 0;
    return i;
}

static inline void flushOut() {
    fwrite(obuf, 1, olen, stdout);
    olen = 0;
}

static inline void writeChar(char c) {
    if (olen == sizeof(obuf)) flushOut();
    obuf[olen++] = c;
}

static inline void writeLL(long long x) {
    if (x == 0) { writeChar('0'); return; }
    char buf[20]; int n = 0;
    while (x > 0) { buf[n++] = '0' + x % 10; x /= 10; }
    while (n--) writeChar(buf[n]);
}

// O(1) digit count via binary search on P10 powers.
// Narrowly tests powers of 10 in cascading halves: 7→4→2→1.
static inline int digit_count(long long v) {
    int d = 0;
    if (v >= P10[7]) d += 7;
    if (v >= P10[d+4]) d += 4;
    if (v >= P10[d+2]) d += 2;
    if (v >= P10[d+1]) d += 1;
    return d + 1;
}

int main() {
    // Init powers of 10: P10[i] = 10^i
    P10[0] = 1;
    for (int i = 1; i <= 18; i++) P10[i] = P10[i-1] * 10;

    // Build ddmm table: all 366 valid calendar dates.
    // rv = reverse(ddmm): e.g. dd=03,mm=06 → "0306" → 6030.
    // The year ends with rv; a palindrome prefix may precede it.
    int ddmm_n = 0;
    for (int dd = 1; dd <= 31; dd++)
        for (int mm = 1; mm <= 12; mm++) {
            if (dd > max_days[mm]) continue;
            ddmm_dd[ddmm_n] = dd;
            ddmm_mm[ddmm_n] = mm;
            ddmm_ds[ddmm_n][0] = '0'+dd/10;
            ddmm_ds[ddmm_n][1] = '0'+dd%10;
            ddmm_ds[ddmm_n][2] = '0'+mm/10;
            ddmm_ds[ddmm_n][3] = '0'+mm%10;
            ddmm_ds[ddmm_n][4] = 0;
            ddmm_rv[ddmm_n] = (long long)(mm%10) * 1000
                            + (long long)(mm/10) * 100
                            + (long long)(dd%10) * 10
                            + (dd/10);
            ddmm_n++;
        }

    // Sort entries by rv ascending. In the O(1) fast path,
    // year = pal(mn)*10000 + rv. Smallest rv → smallest year.
    for (int i = 0; i < ddmm_n; i++) sorted_idx[i] = i;
    for (int i = 0; i < ddmm_n - 1; i++)
        for (int j = i + 1; j < ddmm_n; j++)
            if (ddmm_rv[sorted_idx[j]] < ddmm_rv[sorted_idx[i]]) {
                int tmp = sorted_idx[i]; sorted_idx[i] = sorted_idx[j]; sorted_idx[j] = tmp;
            }

    int n = readInt();
    char s[32];

    for (int tc = 0; tc < n; tc++) {
        int L = readStr(s);
        int ddi = (s[0]-'0')*10 + s[1]-'0';   // Input day
        int mmi = (s[2]-'0')*10 + s[3]-'0';   // Input month
        long long yi = 0;                       // Input year
        for (int i = 4; i < L; i++) yi = yi * 10 + (s[i] - '0');

        long long best_yr = -1;
        int best_i = 0;
        // base_ml = minimum middle palindrome length.
        // Total length = 4(ddmm) + ml + 4(reversed ddmm) = ml + 8.
        // So ml = L - 8, clamped to 0 for short strings.
        int base_ml = L - 8;
        if (base_ml < 0) base_ml = 0;

        // ====================================================
        // FAST PATH: yi > 9092 (max possible rv)
        // ====================================================
        // When yi > 9092, rv (101–9092) < yi ≤ my for all entries.
        // So year = pal(mn)*10000 + rv always.
        //
        // Since rv spans only 8991 values and mn = ceil((my-rv)/10000),
        // mn changes by at most 1 across all entries.
        // With 2 my values × 2 mn groups = at most 4 groups.
        // We scan entries sorted by rv, taking the first valid
        // entry per group. In practice ~4-10 entries checked.
        // ====================================================
        if (yi > 9092) {
            // For each possible my (yi or yi+1), compute the rv
            // boundary that separates the two mn values.
            // Entries with rv < boundary → higher mn,
            // entries with rv >= boundary → lower mn.
            long long M0 = (yi - 101 + 9999) / 10000;
            long long rv_b0 = yi - (M0 - 1) * 10000;
            long long M1 = (yi + 1 - 101 + 9999) / 10000;
            long long rv_b1 = (yi + 1) - (M1 - 1) * 10000;

            // Count non-empty groups (boundary > 9092 means no
            // entry can have the lower mn value for that my).
            int total_grps = (rv_b0 <= 9092 ? 2 : 1) + (rv_b1 <= 9092 ? 2 : 1);
            int found_mask = 0, found_cnt = 0;
            long long group_yr[4];
            int group_bi[4];

            // Scan entries sorted by rv (ascending).
            // Stop when all groups have a valid entry.
            for (int k = 0; k < ddmm_n && found_cnt < total_grps; k++) {
                int i = sorted_idx[k];
                int d_mm = ddmm_mm[i];
                int d_dd = ddmm_dd[i];
                long long d_rv = ddmm_rv[i];

                // my_off = 0 → my = yi (candidate after input date)
                // my_off = 1 → my = yi+1 (candidate on/before input date)
                int my_off = (d_mm > mmi || (d_mm == mmi && d_dd > ddi)) ? 0 : 1;
                long long rv_b = my_off ? rv_b1 : rv_b0;
                // Group: bit 0-1 for my=yi, bit 2-3 for my=yi+1,
                // low bit = which mn sub-group.
                int grp = my_off * 2 + (d_rv >= rv_b ? 1 : 0);

                // Skip if we already found this group.
                if (found_mask & (1 << grp)) continue;

                long long my = yi + my_off;
                long long mn = (my - d_rv + 9999) / 10000;

                int ml = digit_count(mn);
                if (ml < base_ml) ml = base_ml;
                if (mn >= P10[ml]) { found_mask |= (1 << grp); found_cnt++; continue; }
                long long mv = smallest_pal(mn, ml);
                if (mv < 0) { found_mask |= (1 << grp); found_cnt++; continue; }
                long long yr = mv * 10000LL + d_rv;

                // Validate: date must exist (e.g. Feb 29 needs leap year).
                int mxday;
                if (d_mm == 2) mxday = is_leap(yr) ? 29 : 28;
                else mxday = max_days[d_mm];
                if (d_dd > mxday) continue;

                found_mask |= (1 << grp);
                found_cnt++;
                group_yr[grp] = yr;
                group_bi[grp] = i;
            }

            // Pick the best (smallest) year across all groups.
            for (int g = 0; g < 4; g++) {
                if ((found_mask & (1 << g)) && group_yr[g] >= 0) {
                    if (best_yr < 0 || group_yr[g] < best_yr) {
                        best_yr = group_yr[g];
                        best_i = group_bi[g];
                    }
                }
            }
        } else {
            // ====================================================
            // SLOW PATH: yi ≤ 9092
            // ====================================================
            // Some entries may have rv ≥ my → year = rv directly
            // (no palindrome prefix needed). Must check all 366.
            // Sorted by rv + early pruning on best_yr.
            // ====================================================
            for (int k = 0; k < ddmm_n; k++) {
                int i = sorted_idx[k];
                int d_mm = ddmm_mm[i];
                int d_dd = ddmm_dd[i];

                // my = next year threshold (strictly after input date).
                long long my;
                if (d_mm > mmi || (d_mm == mmi && d_dd > ddi))
                    my = yi;
                else
                    my = yi + 1;
                if (my < 1000) my = 1000;

                long long d_rv = ddmm_rv[i];

                long long yr;
                if (d_rv >= my) {
                    // rv itself >= my: palindrome is just ddmm+rv,
                    // year = rv directly (no prefix needed).
                    yr = d_rv;
                } else {
                    // Need a palindrome prefix.
                    // mn = smallest value whose palindrome prefix
                    // makes year >= my.
                    long long mn = (my - d_rv + 9999) / 10000;
                    // Pruning: if mn*10000 already >= best, skip.
                    if (best_yr >= 0 && mn * 10000LL >= best_yr) continue;
                    int ml = digit_count(mn);
                    if (ml < base_ml) ml = base_ml;
                    if (mn >= P10[ml]) continue;
                    long long mv = smallest_pal(mn, ml);
                    if (mv < 0) continue;
                    yr = mv * 10000LL + d_rv;
                }

                // Skip if already have a better answer.
                if (best_yr >= 0 && yr >= best_yr) continue;

                // Validate date exists in this year.
                int mxday;
                if (d_mm == 2)
                    mxday = is_leap(yr) ? 29 : 28;
                else
                    mxday = max_days[d_mm];
                if (d_dd > mxday) continue;

                best_yr = yr;
                best_i = i;
            }
        }

        // Output: ddmm + year (palindrome is ddmm + reversed(ddmm))
        char* ds = ddmm_ds[best_i];
        writeChar(ds[0]);
        writeChar(ds[1]);
        writeChar(ds[2]);
        writeChar(ds[3]);
        writeLL(best_yr);
        writeChar('\n');
    }

    flushOut();
    return 0;
}
