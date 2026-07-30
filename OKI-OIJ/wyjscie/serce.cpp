#include <iostream>

int main()
{
    short space_num1[] = {3, 1, 0, 1, 3, 5, 7, 9};
    short star_num1[] = {3, 7, 19, 17, 13, 9, 5, 1};
    short space_num2[] = {7, 3, 0, 0, 0, 0, 0, 0};
    short star_num2[] = {3,7, 0, 0, 0, 0, 0, 0};
    for (short i = 0; i < 8; i++)
    {
        for (short j = 0; j < space_num1[i]; j++)
        {
            std::cout << " ";
        }
        for (short j = 0; j < star_num1[i]; j++)
        {
            std::cout << "*";
        }
        for (short j = 0; j < space_num2[i]; j++)
        {
            std::cout << " ";
        }
        for (short j = 0; j < star_num2[i]; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}