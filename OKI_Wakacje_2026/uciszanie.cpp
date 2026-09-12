#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false); //UNCOMMENT FOR ACTUAL USE
    //cin.tie(nullptr); // UNCOMMENT FOR ACTUAL USE
    long long student_num = 0; long long command_num = 0;
    cin >> student_num >> command_num;
    vector<char> student_states (student_num, 0);
    vector<pair<long long, long long>> switch_states; //1. is turn when S is supposed to be executed 2. is which state to be switched
    long long u_counter = 0;
    long long turn_counter = 0;
    for (long long i = 0; i < command_num; i++)
    {
        char tmp = ' ';
        cin >> tmp;
        if (tmp == 'S')
        {
            long long target = 0;
            cin >> target;
            // insert into pair vector
            switch_states.emplace_back(make_pair(turn_counter, target));
        }
        else if (tmp == 'U')
        {
            turn_counter++;
            u_counter++;
        }
    }
    turn_counter = 0;
    for (long long i = 0; i < u_counter; i++)
    {
    vector <long long> max_lengths;
    max_lengths.clear();
    long long length_counter = 0;
        // execute S command (one turn)
        long long n = i;
        while (switch_states[n].first == turn_counter)
        {
            student_states[(switch_states[n].second)] = 1;
            n++;
        }
        // calculate max
        for (long long j = 0; j < student_num; j++) {
            if (student_states[j] == 1) {
                length_counter++;
            } 
            else 
            {
                if (length_counter > 0) {
                    max_lengths.emplace_back(length_counter);
                    length_counter = 0;
                }
            }
        }

        // Add the last sequence if the loop ends with 1s
        if (length_counter > 0) {
            max_lengths.emplace_back(length_counter);
        }
        if (!max_lengths.empty()) {
            sort(max_lengths.begin(), max_lengths.end());
            cout << max_lengths.back() << endl;
        }
        else 
        {
            cout << 0 << endl;
        }
        if (!max_lengths.empty()) 
        {
            sort(max_lengths.begin(), max_lengths.end());
            long long end = max_lengths.size() - 1;
            cout << max_lengths[end] << "\n";
        } 
        else 
        {
            cout << "0\n";
        }
        turn_counter++; // fix if U > turn_counter
    }
}