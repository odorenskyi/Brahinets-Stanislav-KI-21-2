#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesBraginets.h"

using namespace std;

int main()
{
    system("chcp 1251 && cls");
    char symbol;

    cout << "������� ������!" << endl
         << "n) s_calculation       v) count_electrycity" << endl
         << "c) count_tempreture    x) count_bit" << endl
         << "z or Z) exit" << endl;
    cin >> symbol;

    while (symbol != 'z' && symbol != 'Z')
    {
        while (symbol != 'n' && symbol != 'v' &&
               symbol != 'c' && symbol != 'x' &&
               symbol != 'z' && symbol != 'Z')
        {
            cin.clear();              // free up the space in streaming input
            while (cin.get() != '\n')
                continue;
            cout << "\a������ ������ n, v, c, x, z or Z: ";
            cin >> symbol;
        }

        if (symbol == 'z' || symbol == 'Z')
            break;

        switch (symbol)
        {
            case 'n':
            {
                double x, y, z;
                cout << "������ ��� �����: ";

                while (!(cin >> x >> y >> z))
                {
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout << "�� ����� �� �����, ��������� �� ���: ";
                }
                cout << "S = " << setprecision(9) << s_calculation(x, y, z) << endl;
                break;
            }
            case 'v':
            {
                float electrycity;
                cout << "������ ������� ������� �����������㳿 (���/���): ";

                while (!(cin >> electrycity) || electrycity < 0)
                {
                    cin.clear();

                    while (cin.get() != '\n')
                        continue;
                    cout << "�� ����� ����������, ��������� �� ���: ";
                }
                cout << setprecision(9) << round(count_electrycity(electrycity) * 100.0) /100.0 << endl;
                break;
            }
            case 'c':
            {
                avr_temp year_temp;

                int mid_month_temp_cel[Size];

                for (int i = 0; i < Size; i++)
                {
                    cout << "������ ������� ����������� " << i + 1 << " �����: ";

                    while (!(cin >> mid_month_temp_cel[i]))
                    {
                        cin.clear();
                        while (cin.get() != '\n')
                            continue;
                        cout << "�� ����� ����������, ��������� �����: ";
                    }
                }
                year_temp = count_tempreture(mid_month_temp_cel, Size);
                cout << endl << "������������ ����������� �� ������: "
                             << round(year_temp.Celcius * 100.0)/100.0 << endl;
                cout << "������������ ����������� �� �����������: "
                     << round(year_temp.Fahrenheit * 100.0)/100.0 << endl;
                break;
            }
            case 'x':
            {
                long int num = 0;
                cout << "������ ������������ �����: ";

                while (!(cin >> num) || num < 0 || num > 5740499)
                {
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout << "�� ����� ����������, ��������� �����: ";
                }
                cout << count_bit(num);
                break;
            }
        }
        cout << endl << "������ ��������� ������: ";
        cin >> symbol;
    }
    cout << "�����!!" << endl;

    return 0;
}
