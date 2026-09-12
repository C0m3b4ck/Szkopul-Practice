#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N = 0, M = 0; //rectangle size (N is y-axis)
	cin >> N >> M;
	string garden_map = ""; //a single string to keep all of the chars, a string is just an array of chars sooo
	for (long long i = 0; i < N; i++)
	{
		string tmp = "";
		cin >> tmp;
		garden_map.append(tmp); //add to main string
	}
	// TEMPORARY DEBUG TEST PRINT
	/*for (long long i = 0; i < (N * M); i++)
	{
		cout << garden_map[i] << "\n";
	}*/
	long long map_size = garden_map.length(); //precompute string length for further use
	for (long long i = 0; i < (N * M); i++)
	{
		short piek = 0, zar = 0, obo = 0; //piekne, zarosniete, obojetne	
		//calculate field digits, run check for each one
		short field_nums[9] = {};
		field_nums[0] = (i - (M+1)); //get top left
		field_nums[1] = (i - M); //get top middle
		field_nums[2] = (i - (M-1)); //get top right
		field_nums[3] = (i--); //get left
		field_nums[4] = i; //get itself
		field_nums[5] = (i++); //get right
		field_nums[6] = (i + (M-1)); //get bottom left
		field_nums[7] = (i + M); //get bottom middle
		field_nums[8] = (i + (M+1)); //get bottom right
		for (short j = 0; j < 9; j++) //check each field from the precomputed array
		{	
			//cout << "DEBUG: " << field_nums[j] << "\n"; //DEBUG
			if (!(field_nums[j] < 0) && !(field_nums[j] > map_size)) //check if less than 0 or greater than array size
			{
				//check field type (switch), then add based on that
				//cout << " " << field_nums[j] << garden_map[(field_nums[j])] << " "; //DEBUG
				switch(garden_map[(field_nums[j])])
				{
					case '*': //piekne
						cout << "Piek++"; //debug
						piek++;
						break;
					case '.': //obojetne
						cout << "Obo++"; //debug
						obo++;
						break;
					case '#': //zarosniete
						cout << "Zaro++"; //debug
						zar++;
						break;
				}
				cout << "\n"; //debug
			}
		}
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
		if (i % M == 2) {cout << "\n";} // seems correct, worked in test
	}
	return 0;
}
