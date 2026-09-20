#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ### INPUT ###
    string key_input = ""; //string for storing all of the keys
    cin >> key_input; //get key input from user
    map<char, vector<long long>> letter_positions; //map of vectors, each with char position
    // ### COMPUTATION ###
    // get all occurrences of all characters into vectors
    cout << "got here \n"; //done
    for (long long i = 0; i < key_input.length(); i++) // fill all vectors with all character occurrences
    {
        short tmp = key_input[i];
        letter_positions[tmp].emplace_back(i); // put position of char into that char's vector
    }
    for (long long i = 0; i < key_input.length(); i++)
    {
        if (key_input[i] == 'd')
        {
            key_input[i] = ' '; //clear this 'd'
            short max_value_letter = 0; //letter that is the latest in the alphabet (from start to d)
            if (i != 0) // if 'd' is not first char, then search
            {
                for (long long j = 0; j < key_input.length(); j++) //check matrix instead of checking every single letter before 'd' (faster)
                {
                    if (letter_positions[i][0] <= i)
                    {
                        long long tmp = 0;
                        while (letter_positions[i][tmp] > i)
                        {
                            key_input[(letter_positions[i][tmp])] = ' '; //clear all positions with that letter existing before 'd'
                        }
                        break;
                    }
                }
            }
        }
    }
    // ### OUTPUT ###
    for (long long i = 0; i < key_input.length(); i++) //output everything that is not a space (spaces mark removed chars)
    {
        if (key_input[i] != ' ') {cout << key_input[i];}
    }
    cout << "\n";
    return 0;
}