#include <iostream>
using namespace std;

int main()
{
    short N = 0, M = 0; //N is height (increment variable), M is width
    // ### INPUT ###
    cin >> N >> M; //get N and M from user
    // ### COMPUTATION AND OUTPUT ###
    for (short i = 0; i < N; i++) //increment by height
    {
        for (short j = 0; j < i; j++) //print spaces
        {
            cout << " ";
        }
        for (short j = 0; j < M; j++) // print asterisks
        {
            cout << "*";
        }
        cout << "\n"; // end off row with an endline
    }
    return 0;
}