#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string path;
    cin >> N >> path;

    long long delay = 0;
    long long answer = 0;
    int nextPerson = -1;

    for (int i = N - 1; i >= 0; --i) {
        if (path[i] != 'X') continue;

        if (nextPerson != -1) {
            int gap = nextPerson - i;

            if (gap == 1) {
                // The people are adjacent: this person loses a second,
                // and also inherits the delay ahead.
                ++delay;
            } else {
                // Empty tiles can absorb some of the delay ahead.
                delay = max(0LL, delay - (gap - 2));
            }
        }

        // N - i seconds to reach the shop without being delayed:
        // move to the last tile, then enter on the following second.
        answer = max(answer, static_cast<long long>(N - i) + delay);
        nextPerson = i;
    }

    cout << answer << '\n';
    return 0;
}
