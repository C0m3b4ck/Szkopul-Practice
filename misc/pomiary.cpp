#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<long long> seen;
    long long inp;
    long long counter = 0;
    while (cin >> inp && inp != -1) {
        if (inp > 0 && seen.insert(inp).second) {
            counter++;
        }
    }
    cout << counter << "\n";
}