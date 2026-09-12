#include <iostream>
#include <array>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // === INPUT ===
    long long N = 0, M = 0; //rectangle size, N is y and M is x
    cin >> N >> M; //get N and M
    char garden_map[(N*M)] = {};
    // actual map input
    for (long long i = 0; i < N; i++) //iterate per columns
    {
        for (long long j = 0; j < M; j++) //get every char for row
        {
            char tmp;
            cin >> tmp;
            garden_map[(i+j)] = tmp;
        }
    }
    // === validation and OUTPUT ===
    long long map_size = N * M; //precompute correct map size
    for (long long i = 0; i < map_size; i++)
    {
        short piek = 0, zar = 0, obo = 0; //piekne, zarosniete, obojetne

		//calculate field digits, run check for each one

        //check if field is in corner (if yes, needs special calc)
        short arr_size = 0; //for iteration
        if (i == 0 || i % M == 1 || i == map_size)
        {
            arr_size = 4;
        }
        else
        {
            arr_size = 9;
        }
		array<short int, arr_size> field_nums = {};
        // handle each type of corner first
        if (i == 0)
        {
            arr_size = 4;
        }
        else
        {
            arr_size = 9;
        }
		field_nums[0] = (i - (M+1)); //get top left
		field_nums[1] = (i - M); //get top middle
		field_nums[2] = (i - (M-1)); //get top right
		field_nums[3] = (i--); //get left
		field_nums[4] = i; //get itself
		field_nums[5] = (i++); //get right
		field_nums[6] = (i + (M-1)); //get bottom left
		field_nums[7] = (i + M); //get bottom middle
		field_nums[8] = (i + (M+1)); //get bottom right
        // DEBUG ARRAY PRINT
        for (short n = 0; n < arr_size; n++)
        {
            cout << field_nums[n] << " ";
        }
        cout << "\n"; //debug
        for (long long j = 0; j < arr_size; j++)
        {
            if (!(field_nums[j] < 0) && !(field_nums[j] > map_size)) //check if less than 0 or greater than array size
            {
                short number_field = field_nums[j];
                char tmp = garden_map[number_field];
                //cout << tmp << "\n"; //debug
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
                    default: // just break if incorrect char
                        break;
                }
            }
        }
        // === OUTPUT ===
        // based on the three counter variables, determine output
		if (piek > zar && piek > obo) //piekne
		{
			cout << "*";
		}
		else if (obo > zar && obo > piek) //obojetne
		{
			cout << ".";
		}
		else if (zar > obo && zar > piek) //zarosniete
		{
			cout << "#";
		}
		//if (i % M == 2) {cout << "\n";} // WRONG
    }

    return 0;
}