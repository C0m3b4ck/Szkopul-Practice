#include <iostream>
using namespace std;

int main()
{
    // ### INPUT 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0, M = 0; //N is y, M is x (rectangle size)
    cin >> N >> M; // get N and M
    const int total = N * M; // calculate total fields
    string garden_map; // array of chars a.k.a string
    garden_map.reserve(total); //reseve mem space
    for (int i = 0; i < N; i++) // get rows and append them to arr
    {
        string row;
        cin >> row;
        garden_map += row;
    }

    const int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1}; //x changes for getting neighbors and itself
    const int dy[9] = { 1, 1, 1,  0, 0, 0, -1,-1,-1}; //y changes for getting neighbors and itself

    // ### COMPUTING AND OUTPUT ###
    for (int i = 0; i < total; i++)
    {
        int piek = 0, zar = 0;
        int x = i % M, y = i / M;

        for (int d = 0; d < 9; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                char c = garden_map[ny * M + nx];
                if (c == '*') piek++;
                else if (c == '#') zar++;
            }
        }

        // ### OUTPUT ###
        if (piek > zar) cout << '*';
        else if (zar > piek) cout << '#';
        else cout << '.';

        if ((i + 1) % M == 0) cout << '\n';
    }

    return 0;
}
