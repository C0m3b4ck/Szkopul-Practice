#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N = 0, M = 0; //rectangle size - N is y, M is x
    // ### INPUT ###
    cin >> N >> M; //get N and M
    const long long map_char_num = (N*M);
    string garden_map = "";
    // get map
    for (long long i = 0; i < N; i++) //iterate per column
    {
        string tmp_str = "";
        cin >> tmp_str;
        garden_map.append(tmp_str);
    }
    // DEBUG - print garden map
    /*for (long long i = 0; i < (map_char_num); i++)
    {
        cout << garden_map[i];
    }*/
    // use X and Y for mapping
    // populate pair table
    vector<pair<long long,long long>> xy_matrix = {};
    for (long long i = 0; i < N; i++) //populate matrix with coordinates
    {
        long long y = i;
        for (long long j = 0; j < M; j++)
        {
            long long x = j;
            xy_matrix.emplace_back(make_pair(x,y)); //emplace into vector
        }
    }

    // ### CALCULATION AND OUTPUT ###
    for (long long i = 0; i < (map_char_num); i++)
    {
        // define variables
        short piek = 0, zar = 0, obo = 0;
        // get x and y from matrix
        pair<long long, long long> xy = xy_matrix[i];
        // precompute neighboring coordinates
        vector<pair<long long, long long>> field_nums(9);
        field_nums[0] = make_pair(xy.first - 1, xy.second + 1); //get top left
        field_nums[1] = make_pair(xy.first, xy.second + 1); //get top middle
        field_nums[2] = make_pair(xy.first + 1, xy.second + 1); //get top right
        field_nums[3] = make_pair(xy.first - 1, xy.second); //get left
        field_nums[4] = xy; //get itself
        field_nums[5] = make_pair(xy.first + 1, xy.second); //get right
        field_nums[6] = make_pair(xy.first - 1, xy.second - 1); //get bottom left
        field_nums[7] = make_pair(xy.first, xy.second - 1); //get bottom middle
        field_nums[8] = make_pair(xy.first + 1, xy.second - 1); //get bottom right

        // lookup chars from map based on the precomputed pairs above
        for (long long j = 0; j < 9; j++)
        {
            long long fx = field_nums[j].first;
            long long fy = field_nums[j].second;
            if (fx >= 0 && fx < M && fy >= 0 && fy < N)
            {
                long long nth = fy * M + fx;
                char tmp = garden_map[nth];
                switch(tmp)
                {
                    case '*':
                        piek++;
                        break;
                    case '#':
                        zar++;
                        break;
                    case '.':
                        obo++;
                        break;
                    default:
                        break;
                }
            }
        }
        // === OUTPUT ===
        if (piek > zar) //piekne
        {
            cout << "*";
        }
        else if (zar > piek) //zarosniete
        {
            cout << "#";
        }
        else //else - obojetne
        {
            cout << ".";
        }
        if ((i + 1) % M == 0) cout << '\n';
    }

    return 0;
}   