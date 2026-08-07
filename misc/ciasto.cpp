#include <iostream>
using namespace std;

int main()
{
    long long kg, speed, time = 0;
    std::cin >> kg >> speed >> time; //input
    if ((kg - (time * speed)) <= 0)
    {
        cout << "TAK\n";
        cout << (speed * time - kg) << "\n";
    }
    else
    {
        cout << "NIE\n";
        cout << (kg / time + 1) << "\n";
    }
    return 0;
}