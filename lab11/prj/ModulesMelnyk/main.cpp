#include "ModulesMelnyk.h"

using namespace std;

void FindRase(BusStation* rase)
{
    BusStation* begin = rase;
    string station;
    bool isRase = false;

    cout << "Введіть місто: ";

    getline(cin, station);

    size_t find_rase;
    do
    {
        string buffRase = begin->name_rase;
        for (short i = 0; i < Size_Name_Rase; i++)
        {
            if(station[i] >= 'А' && station[i] <= 'Я')
                station[i] = char(station[i]) + 32;
            if(buffRase[i] >= 'А' && buffRase[i] <= 'Я')
                buffRase[i] = char(buffRase[i]) + 32;
        }

        find_rase = buffRase.find(station);
        if (find_rase != string::npos)
        {
            isRase = true;
            cout << begin->num_rase << endl
                 << begin->name_rase << endl
                 << begin->name_station << endl
                 << begin->days_rase << endl;

            for (short i = 0; i < Amount_Time; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                cout << begin->time_rase[i] << " ";
            }
        }
        if(begin->next == nullptr) {break;}
        begin = begin->next;
    } while (begin->next != nullptr);

    if (isRase == false) {cout << "Ми не змогли знайти жодного рейсу!" << endl << endl;}
    else {cout << endl << endl;}
}

void ShowRases(BusStation* rase)
{
    short i = 0;
    BusStation* begin = rase;
    do
    {
        cout << "|" << left << setw(Size_Num_Rase) << begin->num_rase << "|" << setw(Size_Name_Rase) << begin->name_rase
             << "|" << setw(Size_Days_Rase) << begin->days_rase << "|";

        for (i = 0; i < 5; i++)
        {
            if (strstr(begin->time_rase[i], "№"))
            {
                break;
            }
            cout << begin->time_rase[i] << " ";
        }

        if (strlen(begin->name_station) > 1)
        {
            cout << endl;
            cout << left << setw(5) << "|" << "|" << setw(Size_Name_Rase) << begin->name_station
                 << right << "|" << setw(36) << "|";
        }

        if (strlen(begin->name_station) < 1 && i > 4)
        {
            cout << endl;
            cout << "|" << right << setw(Size_Num_Rase+1) << "|" << setw(Size_Name_Rase+1)
                 << "|" << setw(Size_Days_Rase+3)
                 << right << setw(36) << "|";


            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                cout << begin->time_rase[i] << " ";
            }
            cout << endl;
        }
        else if (strlen(begin->name_station) > 1 && i > 4)
        {
            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                cout << begin->time_rase[i] << " ";
            }
            cout << endl;
        }
        else if (i > 4)
        {
            cout << "|";
            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                cout << begin->time_rase[i] << " ";
            }
            cout << endl;
        }

        else
        {
            cout << endl;

        }
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;

        begin = begin->next;
    } while (begin->next != nullptr);

    cout << endl;
}
