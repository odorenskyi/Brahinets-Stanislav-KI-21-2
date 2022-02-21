#include <iostream>
#include <cmath>
#include "ModulesBraginets.h"

using namespace std;

void test_s_calculation()
{
    system("chcp 1251 && cls");

    double expresult[7] = {2.689551, 4.376435, 1.406503, 1.843720,
                           3.314480, 1.809893, 5.436336};

    double x[7] = {2, 4, -0.4, 3, -8, -0.01, -25};
    double y[7] = {4, 4, 78, -49, 17, 17.3, 60.14};
    double z[7] = {6, 6, 1, 2, 0, 7.9, 7.99};

    for (short i = 0; i < 7; i++)
    {
        if (round(s_calculation(x[i], y[i], z[i])*1000000)/1000000.0 == expresult[i])
        {
            cout << s_calculation(x[i], y[i], z[i]) << " = " << expresult[i] << endl;
            cout << "Result: #[" << i + 1 << "] PASSED\n";
        }
        else
        {
            cout << s_calculation(x[i], y[i], z[i]) << " = " << expresult[i] << endl;
            cout << "Result: #[" << i + 1 << "] FAILED\n";
        }
    }
}

int main()
{
    test_s_calculation();

    cout << "Для продовження натисніть буль-яку клавішу....";
    cin.get();

    return 0;
}
