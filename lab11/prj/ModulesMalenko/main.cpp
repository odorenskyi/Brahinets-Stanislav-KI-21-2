#include "ModulesMalenko.h"

using namespace std;

void DeleteRase(BusStation* &rase)
{
    BusStation* delete_rase = rase;
    BusStation* buffer = nullptr;

    bool isDelete = false;
    short number;
    cout << "Введіть номер рейсу: ";

    while (!(cin >> number))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Ви ввели не число. Спробуйте ще раз: ";
    }

    do {
        if (number == atoi(delete_rase->num_rase))
        {
            if (delete_rase == rase) {rase = rase->next;}
            else {buffer->next = delete_rase->next;}

            delete(delete_rase);
            isDelete = true;
            break;
        }
        buffer = delete_rase;
        delete_rase = delete_rase->next;
    } while (delete_rase != nullptr);

    if (isDelete == false) {cout << "Ми не змогли знайти жодного рейсу для видалення!" << endl << endl;}
    else {cout << endl << endl;}

}

void AddNumRase(BusStation* rase, BusStation* new_rase)
{
    BusStation* begin = rase;
    char num_rase1[Size_Num_Rase];

    cout << "Введіть номер рейса (не більше 999): ";
    cin >> num_rase1;

    while ((!isdigit(int(num_rase1[0])) && !isdigit(int(num_rase1[1])) && !isdigit(int(num_rase1[2])))
           || (atoi(num_rase1) > 999) )
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Ви ввели не число або більше 999. Спробуйте ще раз: ";
        cin >> num_rase1;
    }
    do
    {
        if (num_rase1[0] == begin->num_rase[0] &&
            num_rase1[1] == begin->num_rase[1] &&
            num_rase1[2] == begin->num_rase[2] &&
            num_rase1[3] == begin->num_rase[3] )
        {
            char answer;
            cout << "Під цим номером рейс: " << begin->name_rase << endl
                 << "Ви мали наувазі цей рейс?(Т\\Н) ";
            cin >> answer;
            while (answer != 'Т' && answer != 'т' && answer != 'Н' && answer != 'н')
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "Введіть \"Так\" або \"Ні\": ";
                cin >> answer;
            }
            if (answer == 'Н' || answer == 'н')
            {
                cout << "Рейс з таким номером вже є," << endl
                     << "введіть інший номер: ";
                cin >> num_rase1;
                while (strstr(begin->num_rase, num_rase1))
                {
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout << "Знову схожі, введіть ще раз: ";
                    cin >> num_rase1;
                }
            }
        }
        begin = begin->next;
    } while (begin->next != nullptr);

    while (cin.get() != '\n')
        continue;
    strcpy(new_rase->num_rase, num_rase1);
}

void AddRase(BusStation* rase)
{
    BusStation* new_rase, * p;
    p = rase->next;
    new_rase = new BusStation;

    AddNumRase(rase, new_rase);

    cout << "Введіть маршрут: ";
    cin.getline(new_rase->name_rase, Size_Name_Rase);
    cout << "Введіть автостанцію або автовокзал (якщо є): ";
    cin.getline(new_rase->name_station, Size_Name_Station);
    cout << "Введіть графік: ";
    cin.getline(new_rase->days_rase, Size_Days_Rase);

    char hours[3], minutes[3];
    for (short i = 0; i < Amount_Time; i++)
    {
        new_rase->time_rase[i] = new char[Time];
        cout << "Введіть години відправлення або прибуття (для завершення введіть №): ";
        cin >> hours;

        if (hours[0] == '№')
        {
            strcpy(new_rase->time_rase[i], "№");
            break;
        }
        while (atoi(hours) > 24 || atoi(hours) < 0)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Неправильно. Спробуйте ще раз: ";
            cin >> hours;
        }

        cout << "Введіть хвилини відправлення або прибуття (для завершення введіть №): ";
        cin >> minutes;
        if (minutes[0] == '№')
        {
            strcpy(new_rase->time_rase[i], "№");
            break;
        }
        while (atoi(minutes) > 59 || atoi(minutes) < 0)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Неправильно. Спробуйте ще раз: ";
            cin >> minutes;
        }

        new_rase->time_rase[i][2] = ':';

        if (hours[0] == '0' && hours[1] == '\0')
        {
            new_rase->time_rase[i][0] = '0';
            new_rase->time_rase[i][1] = '0';
        }
        else if (atoi(hours) <= 9)
        {
            new_rase->time_rase[i][0] = '0';
            new_rase->time_rase[i][1] = hours[0];
        }
        else
        {
            new_rase->time_rase[i][0] = hours[0];
            new_rase->time_rase[i][1] = hours[1];
        }
        if (minutes[0] == '0' && minutes[1] == '\0')
        {
            new_rase->time_rase[i][3] = '0';
            new_rase->time_rase[i][4] = '0';
        }
        else if (atoi(minutes) <= 9)
        {
            new_rase->time_rase[i][3] = '0';
            new_rase->time_rase[i][4] = minutes[0];
        }
        else
        {
            new_rase->time_rase[i][3] = minutes[0];
            new_rase->time_rase[i][4] = minutes[1];
        }
    }

    new_rase->next = p;
    rase->next = new_rase;
    cout << endl;

}
