#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesBraginets.h"

#define SIZE 6      // Amount of examples
using namespace std;

int main()
{
    system("chcp 1251 && cls");
    int i = 0 , j = 0;

    float expect_value_result[SIZE] = {110329.82, 640979.25, 1580.32, 427237.59, 11383.34, 182184.58};
    float example_electricity[SIZE] = {456.012, 1200.23, 12.078, 800, 87, 753};

    cout << "Task 9.1" << endl;
    for (i = 0; i < SIZE; i++)
    {
        if (round(count_electrycity(example_electricity[i])*100.0) / 100.0 == round(expect_value_result[i] * 100.0) / 100.0)
            cout << setprecision(9) << round(count_electrycity(example_electricity[i])*100.0) / 100.0
                 << endl << "#" << i + 1 << " Passed" << endl;
        else
            cout << setprecision(9) << round(count_electrycity(example_electricity[i])*100.0) / 100.0
                 << endl << "#" << i + 1 << " Failed" << endl;
    }

    cout << endl << "Task 9.2" << endl;
    int month_temp[6][Size] = {{45, 7, 6, 12, 3, 75, -78, 6, 2, 3, 4, 5},
                              {-45, 1, 32, 17, -66, 11, 7, 5, 10, -23, 44, 33},
                              {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
                              {36, 44, -12, -11, -3, -9, -15, -17, 7, -8, -13, 2},
                              {-78, 31, 22, 11, -22, 21, -45, 30, 47, 29, -55, 22},
                              {12, -12, 13, -13, 22, -22, 11, -11, 23, -23, 3, -3}};
    avr_temp year_expect_result[6] = {{7.5, 45.5}, {2.17, 35.9}, {6.5, 43.7},
                                      {0.08, 32.15}, {1.08, 33.95}, {0, 32}};
    avr_temp year_temp; // accepts the result of the function "count_tempreture"
    int temp[Size];     // alternately accepts two-dimensional array

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < Size; j++)
            temp[j] = month_temp[i][j];

        year_temp = count_tempreture(temp, Size);

        if (round(year_temp.Celcius * 100.0) / 100.0 == round(year_expect_result[i].Celcius * 100.0) / 100.0 &&
            round(year_temp.Fahrenheit * 100.0) / 100.0 == round(year_expect_result[i].Fahrenheit * 100.0) / 100.0)
        {
            cout << round(year_temp.Celcius * 100.0) / 100.0 << " = " << round(year_expect_result[i].Celcius * 100.0) / 100.0 << endl;
            cout << round(year_temp.Fahrenheit * 100.0) / 100.0 << " = " << round(year_expect_result[i].Fahrenheit * 100.0) / 100.0 << endl;
            cout << "#" << i + 1 << " Passed" << endl;
        }

        else
        {
            cout << round(year_temp.Celcius * 100.0) / 100.0 << " = " << round(year_expect_result[i].Celcius * 100.0) / 100.0 << endl;
            cout << round(year_temp.Fahrenheit * 100.0) / 100.0 << " = " << round(year_expect_result[i].Fahrenheit * 100.0) / 100.0 << endl;
            cout << "#" << i + 1 << " Failed" << endl;
        }
    }

    cout << endl << "Task 9.3" << endl;
    int expect_bit_result[SIZE] = {28, 15, 6, 22, 30, 31};
    long int bit_num[SIZE] = {45, 5740499, 574000, 15678, 36, 1};

    for (i = 0; i < SIZE; i++)
    {
        if (count_bit(bit_num[i]) == expect_bit_result[i])
            cout << count_bit(bit_num[i]) << endl << "#" << i + 1 << " Passed" << endl;
        else
            cout << count_bit(bit_num[i]) << endl << "#" << i + 1 << " Failed" << endl;
    }
    return 0;
}
