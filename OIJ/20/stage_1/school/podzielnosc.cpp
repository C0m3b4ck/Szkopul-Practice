#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N = 0; long long A = 0; //N is number ammount, A is number
    long long sum_of_nums = 0; //sum of all numbers to be checked if divisible by 6
    bool has_two = false; bool has_three = false;
    // ### INPUT, COMPUTING AND OUTPUT ###
    cin >> N; //get N to start loop
    for (long long i = 0; i < N; i++)
    {
        cin >> A; //get A
        if (A % 6 == 0) {cout << "TAK\n"; return 0;} // if 6 appears, that is an instant yes
        if (A % 3 == 0) {has_three = true; if (has_two) {cout << "TAK\n"; return 0;}} // multiple of 3 * multiple of 2 = multiple of 6, instant yes, else just set has_three to true
        if ((A & 1) == 0) {has_two = true; if (has_three) {cout << "TAK\n"; return 0;}} // multiple of 2 * multiple of 3 = multiple of 6, instant yes, else just set has_two to true 
        //sum_of_nums = sum_of_nums * A; // increase sum_of_nums
        //cout << sum_of_nums << "\n"; //debug
    }
    //cout << to_string(sum_of_nums) << "\n"; //debug
    /*if (sum_of_nums % 2 == 0 && sum_of_nums % 3 == 0) //check if sum is divisible by 6
    {
        cout << "TAK\n"; 
    }
    else
    {
        cout << "NIE\n"; //if hasn't met any requirements to be divisible by 6, return no and gracefully close 
    }*/
    cout << "NIE\n";
    return 0;
}