#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    long long top_num = 0;
    long long incr = 0;
    cin >> top_num;
    vector<tuple<string, short, short>> score_pairs;
    //cin.ignore();
    string line, tmp;
    //getline(cin, line);           // read entire line
    //stringstream ss(line);        // parse it
    while (cin >> tmp) 
    {
        // check first letters
        long long mul1 = 0, mul2 = 0, tmp_num = 0;
        string full_name = tmp;
        if (tmp[0] == 'B')
        {
            mul1 = 1;
            tmp.erase(0, 1);
        }
        else if (tmp.size() >= 2 && tmp[0] == 'K' && tmp[1] == 'B') 
        {
            mul1 = 2;
            tmp.erase(0, 2);
        }
        else if (tmp.size() >= 2 && tmp[0] == 'M' && tmp[1] == 'B')
        {
            mul1 = 3;
            tmp.erase(0, 2);
        }
        else if (tmp.size() >= 2 && tmp[0] == 'G' && tmp[1] == 'B')
        {
            mul1 = 4;
            tmp.erase(0, 2);
        }
        else if (tmp.size() >= 2 && tmp[0] == 'T' && tmp[1] == 'B')
        {
            mul1 = 5;
            tmp.erase(0, 2);
        }
        else if (tmp.size() >= 2 && tmp[0] == 'P' && tmp[1] == 'B')
        {
            mul1 = 6;
            tmp.erase(0, 2);
        }
        //check last letters (first characters removed)
        if (tmp == "azar")
        {
            mul2 = 3;
        }
        else if (tmp == "ek")
        {
            mul2 = 2;
        }
        else if (tmp == "osia")
        {
            mul2 = 1;
        }
        tmp_num = mul1 * mul2;
        score_pairs.emplace_back(full_name, tmp_num, mul1); //name, value, chunk value
    }
    // debug
    //for (int i = 0; i < score_pairs.size(); i++)
    //cout << get<0>(score_pairs[i]) << " " << get<1>(score_pairs[i]) << " " << get<2>(score_pairs[i]) << "\n";
    // sort - find largest num, find how many times it occurs, sort all occurrences by chunk_scores
    sort(score_pairs.begin(), score_pairs.end(), [](const auto& a, const auto& b) {
        if (get<1>(a) != get<1>(b))  // different scores
            return get<1>(a) > get<1>(b);  // higher score first
        return get<2>(a) > get<2>(b);      // tie-break: higher mul1 first
    });
    // debug
    //cout << " ++++++++++ \n";
    for (long long i = 0; i < top_num && i < (long long)score_pairs.size(); i++)
    //cout << get<0>(score_pairs[((long long)score_pairs.size() - 1 - i)]) << "\n";
    cout << get<0>(score_pairs[i]) << "\n";
    // output

    return 0;
}