#include <iostream>
using namespace std;

int main()
{
    // ### INPUT ###
    short counter_arr[4] = {0, 0, 0, 0}; //two even/two uneven needed to pass, last element is a counter and later - a flag
    long long abc[3] = {0,0,0}; //an array for the A, B, C variables
    cin >> abc[0] >> abc[1] >> abc[2]; //get A, B, C
    // ### COMPUTING AND OUTPUT ###
    // for each - check if is even, then set flags
    if (abc[0] % 2 == 0) {counter_arr[0] = 1;}
    if (abc[1] % 2 == 0) {counter_arr[1] = 1;}
    if (abc[2] % 2 == 0) {counter_arr[2] = 1;}
    // parse even/uneven states
    for (short i = 0; i < 3; i++)
    {
        if (counter_arr[i] == 0) {counter_arr[3] = counter_arr[3] + 1;} // increment if uneven
    }
    // check which ones prevailed
    string output = "";
    if (counter_arr[3] >= 2) //at least two uneven ones - output them
    {
        counter_arr[3] = 0; //set it to 0 for further use
        for (short i = 0; i < 3; i++) //get first two uneven ones
        {
            if (counter_arr[i] == 0) {output.append(to_string(abc[i]) + " "); counter_arr[3] = counter_arr[3] + 1;} // add an uneven number to the output string, increment flag
            if (counter_arr[3] == 2) {cout << "TAK\n" << output << "\n"; return 0;}
        }
    }
    else if (counter_arr[3] < 2) // at least two even ones
    {
        counter_arr[3] = 0; //set it to 0 for further use
        for (short i = 0; i < 3; i++) //get first two even ones
        {
            if (counter_arr[i] == 1) {output.append(to_string(abc[i]) + " "); counter_arr[3] = counter_arr[3] + 1;} // add an uneven number to the output string, increment flag
            if (counter_arr[3] == 2) {cout << "TAK\n" << output << "\n"; return 0;}
        }  
    }
    cout << output << " " << counter_arr[3] << "\n"; //debug
    return 0;
}