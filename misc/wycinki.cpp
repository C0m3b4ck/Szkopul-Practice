#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct FlatHashMap {
    static constexpr long long EMPTY = LLONG_MAX;
    static constexpr long long DELETED = LLONG_MIN;
    
    long long *keys;
    int *values;
    size_t capacity;
    size_t size;
    
    FlatHashMap(size_t n) {
        capacity = 1;
        while (capacity < n * 2) capacity <<= 1;
        keys = new long long[capacity];
        values = new int[capacity];
        fill_n(keys, capacity, EMPTY);
        size = 0;
    }
    
    ~FlatHashMap() {
        delete[] keys;
        delete[] values;
    }
    
    inline size_t hash(long long k) const {
        k ^= k >> 33;
        k *= 0xff51afd7ed558ccdLL;
        k ^= k >> 33;
        k *= 0xc4ceb9fe1a85ec53LL;
        k ^= k >> 33;
        return k & (capacity - 1);
    }
    
    void put(long long k, int v) {
        size_t h = hash(k);
        while (true) {
            if (keys[h] == EMPTY || keys[h] == DELETED) {
                keys[h] = k;
                values[h] = v;
                size++;
                return;
            }
            if (keys[h] == k) {
                if (v < values[h]) values[h] = v;
                return;
            }
            h = (h + 1) & (capacity - 1);
        }
    }
    
    bool get(long long k, int &out) const {
        size_t h = hash(k);
        while (true) {
            if (keys[h] == EMPTY) return false;
            if (keys[h] == k) {
                out = values[h];
                return true;
            }
            h = (h + 1) & (capacity - 1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, sum;
    if (!(cin >> n >> sum)) return 0;
    
    FlatHashMap first(n + 1);
    first.put(0, -1);
    
    long long pref = 0;
    long long best = 0;
    
    for (long long i = 0; i < n; i++) {
        long long x; cin >> x;
        pref += x;
        int earliest;
        if (first.get(pref - sum, earliest)) {
            long long len = i - earliest;
            if (len > best) best = len;
        }
        int existing;
        if (!first.get(pref, existing)) {
            first.put(pref, i);
        }
    }
    
    if (best == 0) cout << "BRAK\n";
    else cout << best << "\n";
    return 0;
}