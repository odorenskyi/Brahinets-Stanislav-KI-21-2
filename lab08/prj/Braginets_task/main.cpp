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

    cout << "������ x, y, z: ";
    cin >> x >> y >> z;
    cout << "������ 'a' �� 'b': ";
    cin >> a >> b;

    cout << endl;

    expression(a, b);
    DecHexNumber(x, y, z);

    cout << "��������� ��������� �������: S = " << s_calculation(x, y, z) << endl;
    getch();

    return 0;

}

void copyright()
{
    cout << "� �������� ��������" << endl << endl;
}

void expression(char a, char b)
{
    bool expression = abs(a - 22) <= b + 5;
    cout << noboolalpha << "��������� |a - 22| <= b + 5: " << expression << endl << endl;
}

void DecHexNumber(int x, int y, int z)
{
    cout << "'x' � ���������: " << dec << x
         << "\t'x' � ��������������: " << hex << x << endl;
    cout << "'y' � ���������: " << dec << y
         << "\t'y' � ��������������: " << hex << y << endl;
    cout << "'z' � ���������: " << dec << z
         << "\t'z' � ��������������: " << hex << z << endl << endl;

}






