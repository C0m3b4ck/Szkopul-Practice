#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_leap(long long y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int days_in_month(int m, long long y) {
    if (m == 2) return is_leap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

string make_palindrome(const string& prefix, int N) {
    string r = prefix;
    if (N % 2 == 0) {
        for (int i = prefix.length() - 1; i >= 0; i--)
            r += prefix[i];
    } else {
        for (int i = prefix.length() - 2; i >= 0; i--)
            r += prefix[i];
    }
    return r;
}

string int_to_str(int val, int width) {
    string s = to_string(val);
    while ((int)s.length() < width) s = "0" + s;
    return s;
}

string inc_string(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] < '9') { s[i]++; return s; }
        s[i] = '0';
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> valid_ddmm;
    for (int dd = 1; dd <= 31; dd++) {
        for (int mm = 1; mm <= 12; mm++) {
            if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11)) continue;
            if (dd == 30 && mm == 2) continue;
            valid_ddmm.push_back(dd * 100 + mm);
        }
    }

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        int orig_len = s.length();
        bool found = false;

        for (int attempt = 0; attempt <= 2; attempt++) {
            int N = orig_len + attempt;
            int H = (N + 1) / 2;
            if (H < 4) continue;

            int ddmm_in = 0;
            string mid_in = "";

            if (attempt == 0) {
                string prefix0 = s.substr(0, H);
                int dd_in = (prefix0[0] - '0') * 10 + (prefix0[1] - '0');
                int mm_in = (prefix0[2] - '0') * 10 + (prefix0[3] - '0');
                ddmm_in = dd_in * 100 + mm_in;
                mid_in = (H > 4) ? prefix0.substr(4) : "";
            }

            for (int ddmm : valid_ddmm) {
                int dd = ddmm / 100;
                int mm = ddmm % 100;
                string ddmm_str = int_to_str(dd, 2) + int_to_str(mm, 2);

                string cand_prefix;

                if (attempt > 0 || ddmm > ddmm_in) {
                    cand_prefix = ddmm_str + string(H - 4, '0');
                } else if (ddmm == ddmm_in) {
                    cand_prefix = ddmm_str + mid_in;
                    string pal = make_palindrome(cand_prefix, N);
                    if (pal > s) {
                        long long yyyy = 0;
                        for (int i = 4; i < N; i++)
                            yyyy = yyyy * 10 + (pal[i] - '0');
                        if (dd <= days_in_month(mm, yyyy)) {
                            cout << pal << "\n";
                            found = true;
                            break;
                        }
                    }
                    if (mid_in.empty()) continue;
                    string next_mid = inc_string(mid_in);
                    if (next_mid.empty()) continue;
                    cand_prefix = ddmm_str + next_mid;
                } else {
                    continue;
                }

                string pal = make_palindrome(cand_prefix, N);
                if (attempt == 0 && pal <= s) continue;

                long long yyyy = 0;
                for (int i = 4; i < N; i++)
                    yyyy = yyyy * 10 + (pal[i] - '0');
                if (dd <= days_in_month(mm, yyyy)) {
                    cout << pal << "\n";
                    found = true;
                    break;
                }
            }

            if (found) break;
        }
    }
    return 0;
}
