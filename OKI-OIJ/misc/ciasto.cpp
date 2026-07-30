#include <iostream>
using namespace std;

int main()
{
    short kg, speed, time = 0;
    std::cin >> kg >> speed >> time; //input
    if (kg/speed > time || kg/speed == time)
    {
        cout << "TAK\n";
        cout << (kg%speed) << "\n";
    }
    else
    {
        cout << "NIE\n";
    }
    return 0;
}