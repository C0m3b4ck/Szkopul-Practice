#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //### INPUT ###
    long long N = 0; // N is the ammount of cables
    cin >> N; //get N
    // get socket coords
    vector<pair<long long, long long>> socket_array = {};
    for (long long i = 0; i < (2 *N); i++)
    {
        long long tmp1 = 0, tmp2 = 0; //tmp1 is X, tmp2 is Y
        cin >> tmp1 >> tmp2; //get X and Y
        socket_array.emplace_back(make_pair(tmp1, tmp2)); //emplace into vector
    }
    // ### COMPUTATION ###
    // sort vector by X
    sort(socket_array.begin(), socket_array.end());
    
    //DEBUG - cout sorted vector
    /*for (long long i = 0; i < N; i++)
    {
        cout << socket_array[i].first << " " << socket_array[i].second << "\n";
    }*/ 
    //DEBUG

    //for each two sockets, bind by X
    for (long long i = 0; i < (2*N); i++)
    {
        long long second = i++;
        cout << socket_array[i].first << " " << socket_array[i].second << " " << socket_array[second].first << " " << socket_array[second].second << "\n";
    }
    //optional: if not possible by X, do by Y
    //for (long long i = 0)
    return 0;
}