#include <iostream>
using namespace std;

int main()
{
    // wejscie
    string raw_str = "";
    cin >> raw_str;

    //short out = 'a' - '0'; //debug - a to 49, zeby kolejnosc litery w alfabecie - od shorta odjac 48
    //cout << out << "\n"; //debug

    // analiza
    for (long long i = 0; i < raw_str.length(); i++) // caly string
    {
        if (raw_str[i] == 'd') // jesli znaleziono d
        {
            cout << "Jest d\n"; //debug
            raw_str[i] = ' '; //d zamieniamy w null character
            short max_char = 0; // do maksymalnej wartosci chara
            for (long long j = (i - 1); j >= 0; j--) // sprawdzamy jaka jest najwyzsza wartosc litery (najpozniejsza)
            {
                short tmp = (raw_str[j] - '0') - 48;
                if (tmp > max_char) {max_char = tmp;} // zmiana na nowa wyzsza wartosc
                cout << tmp << " " << max_char << "\n"; //debug
            }
            cout << "usuwamy " << raw_str << "\n"; //debug
            for (long long j = (i - 1); j >= 0; j--) // usuwamy wszystkie najwyzsze litery
            {
                short tmp = (raw_str[j] - '0') - 48;
                if (tmp == max_char) {raw_str[j] = ' '; cout << "Ustawiam \n";} //debug
                cout << tmp << " " << max_char << "\n"; //debug
            }
        }
    }

    // wyjscie
    for (long long i = 0; i < raw_string.length(); i++)
    {
        if (raw_string[i] != ' ') // pomija spacje (zostawione dla zachowania dlugosci napisu zamiast usuwania d)
        {
            cout << raw_str[i];
        }
    }
    cout << "\n";

    return 0;
}
