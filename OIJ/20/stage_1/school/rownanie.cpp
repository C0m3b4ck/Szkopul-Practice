#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ### INPUT ###
    long long A = 0; long long B = 0; long long C = 0; //C is the outcome of the equasion
    long long X = 0; long long Y = 0; //X and Y are the blanks to be filled
    cin >> A >> B >> C >> X >> Y; //get A, B, C, X, Y
    // ### COMPUTATION AND OUTPUT ###
    if ((A * X) + (B * Y) == C)
    {
        cout << "TAK\n"; //the equasion is correct
    }
    else
    {
        cout << "NIE\n"; //equasion is not correct (requirements not met)
        //cout << ((A * X) + (B * Y)) << "\n"; //debug
        //cout << A << " " << B << " " << C << " " << X << " " << Y << "\n"; //debug
    }
    return 0;
}