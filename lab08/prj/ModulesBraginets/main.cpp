#include <iostream>
#include <cmath>
#include <bitset>

#define Size  12

using namespace std;
const double PI = 3.14159265;

// Returns the solution of the expression
double s_calculation(double x, double y, double z)
{
    return 1 + sqrt(pow(x / abs(y - z), 3) +
          (pow(x, 2) + z) / sqrt(abs((z + x) * y)) -
            cos(x * pow(z, 2)) / (2 * y + PI));
}

// Returns the cost of electricity used
float count_electrycity(float num)
{
    if (num < 150)
    {
        cout << "Ви спожили " << round(num * 1000.0) / 1000.0 << " кВт" << endl
             << "У цьому випадку 1 кВт коштує 130,843 грн." << endl
             << "До сплати: ";
        return num * 130.843;
    }
    else if (num >= 150 && num < 800)
    {
        cout << "Ви спожили " << round(num * 1000.0) / 1000.0 << " кВт" << endl
             << "У цьому випадку 1 кВт коштує 241.945 грн." << endl
             << "До сплати: ";
        return num * 241.945;
    }
    else if (num >= 800)
    {
         cout << "Ви спожили " << round(num * 1000.0) / 1000.0 << " кВт" << endl
             << "У цьому випадку 1 кВт коштує 534.047 грн." << endl
             << "До сплати: ";
        return num * 534.047;
    }
}

/* Returns the structure which contains
average temperature by Celsius and by Fahrenheit*/
struct avr_temp
{
    float Celcius = 0;
    float Fahrenheit = 0;
};

avr_temp count_tempreture(int mid_temp[], int n)
{
    avr_temp temp;
    float mid_temp_far[n];
    int i = 0;

    for (i = 0; i < n; i++)
        mid_temp_far[i] = 32 + 1.8 * mid_temp[i];

    for (i = 0; i < n; i++)
    {
        temp.Celcius += mid_temp[i];
        temp.Fahrenheit += mid_temp_far[i];
    }
    temp.Celcius /= n;
    temp.Fahrenheit /= n;

    return temp;
}


/* Returns the number of zeros if high bit = 0,
otherwise the number of ones*/
int count_bit(long int number)
{
    bitset<32> b_number(number);
    if(!((number >> 9) & 1))
    {
        cout << "Так як 10 біт = 0, кількість 0: ";
        return 32 - b_number.count();
    }
    else
    {
        cout << "Так як 10 біт = 1, кількість 1: ";
        return b_number.count();
    }
}



