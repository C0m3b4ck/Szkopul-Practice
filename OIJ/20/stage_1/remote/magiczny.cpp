#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	// ### INPUT ###
	// gets 5 lines of 5 characters
	string magical_square = ""; //array to keep the square's strings
	for (short i = 0; i < 5; i++)
	{
		string tmp = "";
		cin >> tmp;
		magical_square.append(tmp);
	}
	//cout << magical_square; //DEBUG - show magical_square string

	// ### COMPUTING ###
	//squares 0, 6, 12, 18, 24 can just be set to 'Z' if they are not filled in
	if (magical_square[0] == '?') {magical_square[0] = 'Z';}
	if (magical_square[6] == '?') {magical_square[6] = 'Z';}
	if (magical_square[12] == '?') {magical_square[12] = 'Z';}
	if (magical_square[18] == '?') {magical_square[18] = 'Z';}
	if (magical_square[24] == '?') {magical_square[24] = 'Z';}
	
	//if a square is empty, fill it with diagonally opposite letter (multiples of 4, substracted/added)
	//done manually
	// column 0 (square 0 excluded)
	// row 0 (square 0 excluded)
	if (magical_square[1] == '?' && magical_square[5] != '?') {magical_square[1] = magical_square[5];}
	else if (magical_square[5] == '?' && magical_square[1] != '?') {magical_square[5] = magical_square[1];}
	else {magical_square[5] == 'Z'; magical_square[1] == 'Z';}

	if (magical_square[2] == '?' && magical_square[10] != '?') {magical_square[2] = magical_square[10];}
	else if (magical_square[10] == '?' && magical_square[2] != '?') {magical_square[10] = magical_square[2];}
	else {magical_square[10] == 'Z'; magical_square[2] == 'Z';}

	if (magical_square[3] == '?' && magical_square[15] != '?') {magical_square[3] = magical_square[15];}
	else if (magical_square[15] == '?' && magical_square[3] != '?') {magical_square[15] = magical_square[3];}
	else {magical_square[15] == 'Z'; magical_square[3] == 'Z';}

	if (magical_square[4] == '?' && magical_square[20] != '?') {magical_square[4] = magical_square[20];}
	else if (magical_square[20] == '?' && magical_square[4] != '?') {magical_square[20] = magical_square[4];}
	else {magical_square[20] == 'Z'; magical_square[4] == 'Z';}
	//column 1 (squares 1 and 6 excluded)
		if (magical_square[11] == '?' && magical_square[7] != '?') {magical_square[11] = magical_square[7];}
	else if (magical_square[7] == '?' && magical_square[11] != '?') {magical_square[7] = magical_square[11];}
	else {magical_square[11] == 'Z'; magical_square[7] == 'Z';}

	if (magical_square[16] == '?' && magical_square[8] != '?') {magical_square[16] = magical_square[8];}
	else if (magical_square[8] == '?' && magical_square[16] != '?') {magical_square[8] = magical_square[16];}
	else {magical_square[16] == 'Z'; magical_square[8] == 'Z';}

	if (magical_square[21] == '?' && magical_square[9] != '?') {magical_square[21] = magical_square[9];}
	else if (magical_square[9] == '?' && magical_square[21] != '?') {magical_square[9] = magical_square[21];}
	else {magical_square[21] == 'Z'; magical_square[9] == 'Z';}
	//row 1 (square 5 excluded)
	if (magical_square[7] == '?' && magical_square[11] != '?') {magical_square[7] = magical_square[11];}
	else if (magical_square[11] == '?' && magical_square[7] != '?') {magical_square[11] = magical_square[7];}
	else {magical_square[7] == 'Z'; magical_square[11] == 'Z';}

	if (magical_square[8] == '?' && magical_square[16] != '?') {magical_square[8] = magical_square[16];}
	else if (magical_square[16] == '?' && magical_square[8] != '?') {magical_square[16] = magical_square[8];}
	else {magical_square[16] == 'Z'; magical_square[8] == 'Z';}

	if (magical_square[9] == '?' && magical_square[21] != '?') {magical_square[9] = magical_square[21];}
	else if (magical_square[21] == '?' && magical_square[9] != '?') {magical_square[21] = magical_square[9];}
	else {magical_square[21] == 'Z'; magical_square[9] == 'Z';}
	//column 2 (squares 2, 7 and 12 excluded)
	//17, 22
	if (magical_square[17] == '?' && magical_square[13] != '?') {magical_square[17] = magical_square[13];}
	else if (magical_square[13] == '?' && magical_square[17] != '?') {magical_square[13] = magical_square[17];}
	else {magical_square[17] == 'Z'; magical_square[13] == 'Z';}

	if (magical_square[22] == '?' && magical_square[14] != '?') {magical_square[22] = magical_square[14];}
	else if (magical_square[14] == '?' && magical_square[22] != '?') {magical_square[14] = magical_square[22];}
	else {magical_square[22] == 'Z'; magical_square[14] == 'Z';}
	//row 2
	if (magical_square[13] == '?' && magical_square[17] != '?') {magical_square[13] = magical_square[17];}
	else if (magical_square[17] == '?' && magical_square[13] != '?') {magical_square[17] = magical_square[13];}
	else {magical_square[17] == 'Z'; magical_square[13] == 'Z';}

	if (magical_square[14] == '?' && magical_square[22] != '?') {magical_square[14] = magical_square[22];}
	else if (magical_square[22] == '?' && magical_square[14] != '?') {magical_square[22] = magical_square[14];}
	else {magical_square[22] == 'Z'; magical_square[14] == 'Z';}
	//column 3 (squares 3, 8, 13 and 18 excluded)
	//23
	if (magical_square[23] == '?' && magical_square[19] != '?') {magical_square[23] = magical_square[19];}
	else if (magical_square[19] == '?' && magical_square[23] != '?') {magical_square[19] = magical_square[23];}
	else {magical_square[23] == 'Z'; magical_square[19] == 'Z';}
	//row 3
	if (magical_square[19] == '?' && magical_square[23] != '?') {magical_square[19] = magical_square[23];}
	else if (magical_square[23] == '?' && magical_square[19] != '?') {magical_square[23] = magical_square[19];}
	else {magical_square[23] == 'Z'; magical_square[19] == 'Z';}
	//column 4 (squares 4, 9, 14, 19 and 24 excluded)
	//DONE: 0,1,2,3,4,5,6,7,8,9,10,11,12,TODO 13,TODO 14,15,16,TODO 17,18,TODO 19,20,21,TODO 22, TODO 23, 24
	/*
	KLUCZ
	LICZY
	UCIEC
	CZEKI
	ZYCIE
	*/
	
	// ### OUTPUT ###
	// check if fixed square is magical - argument is: if not (all of this) is correct, output "NIE", else: output fixed square
	if (magical_square[5] == magical_square[1]
		&& magical_square[10] == magical_square[2] 
		&& magical_square[15] == magical_square[3] 
		&& magical_square[20] == magical_square[4] 
		&& magical_square[11] == magical_square[7] 
		&& magical_square[16] == magical_square[8]
		&& magical_square[21] == magical_square[9]
		&& magical_square[17] == magical_square[13]
		&& magical_square[22] == magical_square[14]
		&& magical_square[23] == magical_square[19])
	{
		for (short i = 1; i < 26; i++)
		{
			cout << magical_square[(i-1)];
			if (i%5 == 0) {cout << "\n";}
		}
	}
	else
	{
		cout << "NIE";
	}

	return 0;
}
