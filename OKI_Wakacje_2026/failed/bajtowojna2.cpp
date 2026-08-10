#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    long long top_num = 0;
    cin >> top_num;
    vector<string> name_arr;
    cin.ignore();
    string line, tmp;
    getline(cin, line);           // read entire line
    stringstream ss(line);        // parse it
    while (ss >> tmp) {
        name_arr.emplace_back(tmp);
    }
    vector<short> scores;
    vector<short> mul1_arr;
    // przedrostki - B KB MB GB TB PB
    for (long long i = 0; i < name_arr.size(); i++)
    {
        short mul1, mul2, tmp = 0;
        string name = name_arr[i];
        // check first letters
        if (name[0] == 'B')
        {
            mul1 = 1;
            name.erase(0, 1);
            mul1_arr.emplace_back(mul1);
        }
        else if (name[0] == 'K' && name[1] == 'B')
        {
            mul1 = 2;
            name.erase(0, 2);
            mul1_arr.emplace_back(mul1);
        }
        else if (name[0] == 'M' && name[1] == 'B')
        {
            mul1 = 3;
            name.erase(0, 2);
            mul1_arr.emplace_back(mul1);
        }
        else if (name[0] == 'G' && name[1] == 'B')
        {
            mul1 = 4;
            name.erase(0, 2);
            mul1_arr.emplace_back(mul1);
        }
        else if (name[0] == 'T' && name[1] == 'B')
        {
            mul1 = 5;
            name.erase(0, 2);
            mul1_arr.emplace_back(mul1);
        }
        else if (name[0] == 'P' && name[1] == 'B')
        {
            mul1 = 6;
            name.erase(0, 2);
            mul1_arr.emplace_back(mul1);
        }
        //check last letters (first characters removed)
        if (name == "azar")
        {
            mul2 = 3;
        }
        else if (name == "ek")
        {
            mul2 = 2;
        }
        else if (name == "osia")
        {
            mul2 = 1;
        }
        tmp = mul1 * mul2;
        scores.emplace_back(tmp);
    }
    // get max, then remove
    for (long long i = 0; i < top_num; i++)
    {
        long long pos = 0;
        short tmp_max = get_max(scores.begin(), scores.end());
        vector<short> pos_arr;
        // get how many times max score occurs
        for (long long j = 0; j < (long long)scores.size(); j++)
        {
            if (scores[j] == tmp_max)
            {
                pos_arr.emplace_back[j]; //get each max score's pos in arr
            }
        }
        for (long long j = 0; j < (long long)pos_arr.size(); j++)
        {
            for (long long m = 0; m < (long long)pos_arr.size(); m++)
            {
                short pos_max = get_max(pos_arr.begin(), pos_arr.end());
                
            }
        }
        cout << name_arr[pos] << "\n";
        scores[pos] = 0;
    }
    return 0;
}
