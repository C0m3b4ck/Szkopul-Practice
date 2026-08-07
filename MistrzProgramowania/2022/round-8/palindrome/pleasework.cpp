#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// Funkcja sprawdzająca poprawność daty
bool isValidDate(int d, int m, int y) {
    if (m < 1 || m > 12) return false;
    static const int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int max_day = days_in_month[m - 1];
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        max_day = 29;
    }
    return d >= 1 && d <= max_day;
}

// Funkcja do konwersji daty na liczbę dni od początku epoki (np. od 0001-01-01)
long dateToDays(int d, int m, int y) {
    // Prostą funkcję można zaimplementować, ale dla uproszczenia:
    // - Zakładamy, że rok 0001 jest początkiem
    long days = 0;
    for (int year = 1; year < y; ++year) {
        days += 365 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0);
    }
    static const int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int month = 1; month < m; ++month) {
        days += days_in_month[month - 1];
        if (month == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) days += 1;
    }
    days += d - 1;
    return days;
}

// Funkcja do konwersji dni z powrotem na datę
void daysToDate(long totalDays, int &d, int &m, int &y) {
    static const int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    y = 1;
    long days_in_year;
    while (true) {
        days_in_year = 365 + ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 1 : 0);
        if (totalDays >= days_in_year) {
            totalDays -= days_in_year;
            y++;
        } else {
            break;
        }
    }
    m = 1;
    for (int i = 0; i < 12; ++i) {
        int md = days_in_month[i];
        if (i == 1 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) md++;
        if (totalDays >= md) {
            totalDays -= md;
            m++;
        } else {
            break;
        }
    }
    d = totalDays + 1;
}

// Funkcja sprawdzająca, czy data w formacie DDMMYYYY to palindrom
bool isPalindromeDate(const string &date_str) {
    string rev = date_str;
    reverse(rev.begin(), rev.end());
    return date_str == rev;
}

// Funkcja generująca wszystkie palindromy dat (DDMMYYYY)
vector<long> generatePalindromes() {
    vector<long> palindromes;
    // Generujemy palindromy z części rokowej
    for (int half = 0; half <= 9999; ++half) {
        string half_str = to_string(half);
        while ((int)half_str.size() < 4) half_str = "0" + half_str;
        string rev_half = half_str;
        reverse(rev_half.begin(), rev_half.end());

        string date_str = "";
        // Tworzymy formę DDMMYYYY, gdzie DD i MM wyznacza odwrócona część
        for (int d1=0; d1<=9; ++d1) {
            for (int d2=0; d2<=9; ++d2) {
                string d_str = "";
                d_str += ('0' + d1);
                d_str += ('0' + d2);
                string m_str = d_str; // Długość 2
                // Tworzymy pełny palindrom DDMMYYYY
                string full_date = d_str + m_str + half_str;
                if (full_date.size() != 8) continue;
                // Sprawdzamy, czy to palindrom (mamy już odwróconą część)
                if (isPalindromeDate(full_date)) {
                    int dd = stoi(d_str);
                    int mm = stoi(m_str);
                    int yyyy = stoi(half_str);
                    if (isValidDate(dd, mm, yyyy)) {
                        long days = dateToDays(dd, mm, yyyy);
                        palindromes.push_back(days);
                    }
                }
            }
        }
    }
    return palindromes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long> palindromes = generatePalindromes();
    sort(palindromes.begin(), palindromes.end());

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        int s_d = stoi(s.substr(0,2));
        int s_m = stoi(s.substr(2,2));
        int s_y = stoi(s.substr(4,4));
        long s_days = dateToDays(s_d, s_m, s_y);

        // ищemy najbliższy palindrom
        long res_days = -1;
        long min_diff = LLONG_MAX;

        // przeszukujemy listę palindromów
        auto it = lower_bound(palindromes.begin(), palindromes.end(), s_days);
        // sprawdzamy najbliższe daty
        if (it != palindromes.end()) {
            long diff = *it - s_days;
            if (diff < min_diff) {
                min_diff = diff;
                res_days = *it;
            }
        }
        if (it != palindromes.begin()) {
            auto it2 = it - 1;
            long diff = s_days - *it2;
            if (diff < min_diff) {
                min_diff = diff;
                res_days = *it2;
            }
        }

        // konwersja z powrotem do DDMMYYYY
        int d, m, y;
        daysToDate(res_days, d, m, y);
        string dd = to_string(d);
        string mm = to_string(m);
        string yyyy = to_string(y);
        if (d < 10) dd = "0" + dd;
        if (m < 10) mm = "0" + mm;
        while ((int)yyyy.size() < 4) yyyy = "0" + yyyy;

        cout << dd + mm + yyyy << "\n";
    }

    return 0;
}