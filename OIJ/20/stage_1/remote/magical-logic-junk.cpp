#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Fill main diagonal with 'Z'
    for (int i = 0; i < 5; ++i) {
        int pos = i * 5;
        if (grid[pos] == '?') {
            grid[pos] = 'Z';
        }
    }

    // Fill column 0 (excluding first element)
    for (int i = 1; i < 5; ++i) {
        int pos = i * 5;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos - 4]; // row 0, column 0
        }
    }

    // Fill row 0 (excluding first element)
    for (int i = 1; i < 5; ++i) {
        int pos = i;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos + 4]; // row 1, column 0
        }
    }

    // Fill row 1 (excluding first element)
    for (int i = 2; i < 5; ++i) {
        int pos = i + 5;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos - 4]; // row 0, column 1
        }
    }

    // Fill row 2 (excluding first element)
    for (int i = 3; i < 5; ++i) {
        int pos = i + 10;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos - 4]; // row 0, column 2
        }
    }

    // Fill row 3 (excluding first element)
    for (int i = 4; i < 5; ++i) {
        int pos = i + 15;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos - 4]; // row 0, column 3
        }
    }

    // Fill row 4 (excluding first element)
    for (int i = 1; i < 5; ++i) {
        int pos = i + 20;
        if (grid[pos] == '?') {
            grid[pos] = grid[pos - 4]; // row 0, column 4
        }
    }
}

bool checkMagicSquare(const vector<char>& grid) {
    // Check rows
    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += grid[i * 5 + j];
        }
        for (int j = 0; j < 5; ++j) {
            if (grid[i * 5 + j] != grid[i * 5 + (4 - j)]) {
                return false;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += grid[j * 5 + i];
        }
        for (int j = 0; j < 5; ++j) {
            if (grid[j * 5 + i] != grid[(4 - j) * 5 + i]) {
                return false;
            }
        }
    }

    return 0;
}

int main() {
    vector<char> grid(25, '?');
    fillMagicSquare(grid);
    if (checkMagicSquare(grid)) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << grid[i * 5 + j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NIE\n";
    }
    return 0;
}