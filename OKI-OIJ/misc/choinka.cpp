#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long size = 0;
    long long spaces = 0;
    long long stars = 1;
    cin >> size;
    // output
    for (long long i = 0; i < size; i++)
    {
        for (long long j = 0; j < ((size - stars/2)); j++) //((max_size * 2) - max_size - stars)
        {
            cout << " ";
        }
        for (long long j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
        stars = stars + 2;
    }
    for (long long j = 0; j < ((size)); j++) //((max_size * 2) - max_size - stars)
    {
        cout << " ";
    }
    cout << "*" << "\n";
    //second stage
    stars = 3;
    for (long long i = 0; i < size; i++)
    {
        for (long long j = 0; j < ((size - stars/2)); j++) //((max_size * 2) - max_size - stars)
        {
            cout << " ";
        }
        for (long long j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
        stars = stars + 2;
    }
    for (long long j = 0; j < ((size)); j++) //((max_size * 2) - max_size - stars)
    {
        cout << " ";
    }
    cout << "*" << "\n";
    for (long long j = 0; j < ((size)); j++) //((max_size * 2) - max_size - stars)
    {
        cout << " ";
    }
    cout << "*" << "\n";
    return 0;
}