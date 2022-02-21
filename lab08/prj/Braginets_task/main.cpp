#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>

#include "ModulesBraginets.h"

void copyright();
void expression(char a, char b);
void DecHexNumber(int x, int y, int z);

int x, y, z;
char a, b;

using namespace std;

int main()
{
    system("chcp 1251 && cls");
    copyright();

    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть 'a' та 'b': ";
    cin >> a >> b;

    cout << endl;

    expression(a, b);
    DecHexNumber(x, y, z);

    cout << "Результат виконання функцій: S = " << s_calculation(x, y, z) << endl;
    getch();

    return 0;

}

void copyright()
{
    cout << "© Брагінець Станіслав" << endl << endl;
}

void expression(char a, char b)
{
    bool expression = abs(a - 22) <= b + 5;
    cout << noboolalpha << "Результат |a - 22| <= b + 5: " << expression << endl << endl;
}

void DecHexNumber(int x, int y, int z)
{
    cout << "'x' В десятковій: " << dec << x
         << "\t'x' В шістнадцятковій: " << hex << x << endl;
    cout << "'y' В десятковій: " << dec << y
         << "\t'y' В шістнадцятковій: " << hex << y << endl;
    cout << "'z' В десятковій: " << dec << z
         << "\t'z' В шістнадцятковій: " << hex << z << endl << endl;

}
