#include "ModulesBrahinets.h"

using namespace std;

void WriteToDataFile(char file_name[], BusStation* rase)
{
    fstream File;
    File.open(file_name, ios::out | ios::binary);
    while(rase->next != nullptr)
    {
        File.write((char*)&*rase->num_rase, sizeof(rase->num_rase));
        File.write((char*)&*rase->name_rase, sizeof(rase->name_rase));
        File.write((char*)&*rase->name_station, sizeof(rase->name_station));
        File.write((char*)&*rase->days_rase, sizeof(rase->days_rase));
        for(short i = 0; i < Amount_Time; i++)
        {
            if (strstr(rase->time_rase[i], "№"))
            {
                File.write((char*)&*rase->time_rase[i], sizeof(rase->time_rase[i]));
                break;
            }
            File.write((char*)&*rase->time_rase[i], sizeof(rase->time_rase[i]));
        }
        rase = rase->next;
    }
    File.close();
    cout << "Дякую за використання!" << endl;

}

void ReadDataFile(char file_name[], BusStation* rase)
{
    fstream File;
    rase->next = nullptr;
    File.open(file_name, ios::in | ios::binary);
    do
    {
        File.read((char*)&*rase->num_rase, sizeof(rase->num_rase));
        File.read((char*)&*rase->name_rase, sizeof(rase->name_rase));
        File.read((char*)&*rase->name_station, sizeof(rase->name_station));
        File.read((char*)&*rase->days_rase, sizeof(rase->days_rase));
        for(short i = 0; i < Amount_Time; i++)
        {
            rase->time_rase[i] = new char [Time];
            File.read((char*)&*rase->time_rase[i], sizeof(rase->time_rase[i]));
            if (strstr(rase->time_rase[i], "№"))
            {
                break;
            }
        }
        if (File.peek() == 1)
        {
            break;
        }
        else
        {
            rase->next = new BusStation;
            rase = rase->next;
            rase->next = nullptr;
        }
    } while(File.peek() != -1);
    File.close();
}

BusStation* AddExample(char file_name[], BusStation* rase)
{
    fstream File;
    File.open(file_name, ios::out | ios::binary);
    rase = new BusStation;
    strcpy(rase->num_rase, "455");
    strcpy(rase->name_rase, "Кропивницький - Дніпро");
    strcpy(rase->name_station, "Центральний автовокзал");
    strcpy(rase->days_rase, "щоденно до 29.10");
    rase->time_rase[0] = new char[Time];
    strcpy(rase->time_rase[0], "07:30");
    rase->time_rase[1] = new char[Time];
    strcpy(rase->time_rase[1], "11:30");
    rase->time_rase[2] = new char[Time];
    strcpy(rase->time_rase[2], "№");
    rase->next = nullptr;
    File.write((char*)&*rase->num_rase, sizeof(rase->num_rase));
    File.write((char*)&*rase->name_rase, sizeof(rase->name_rase));
    File.write((char*)&*rase->name_station, sizeof(rase->name_station));
    File.write((char*)&*rase->days_rase, sizeof(rase->days_rase));
    for(short i = 0; i < Amount_Time; i++)
    {
        if (strstr(rase->time_rase[i], "№"))
        {
            File.write((char*)&*rase->time_rase[i], sizeof(rase->time_rase[i]));
            break;
        }
        File.write((char*)&*rase->time_rase[i], sizeof(rase->time_rase[i]));
    }
    File.close();
    return rase;
}

void WriteToTxtFile(fstream &file, BusStation* rase)
{
    short i = 0;
    BusStation* begin = rase;
    do
    {
        file << "|" << left << setw(Size_Num_Rase) << begin->num_rase << "|" << setw(Size_Name_Rase) << begin->name_rase
             << "|" << setw(Size_Days_Rase) << begin->days_rase << "|";

        for (i = 0; i < 5; i++)
        {
            if (strstr(begin->time_rase[i], "№"))
            {
                break;
            }
            file << begin->time_rase[i] << " ";
        }

        if (strlen(begin->name_station) > 1)
        {
            file << endl;
            file << left << setw(5) << "|" << "|" << setw(Size_Name_Rase) << begin->name_station
                 << right << "|" << setw(36) << "|";
        }

        if (strlen(begin->name_station) < 1 && i > 4)
        {
            file << endl;
            file << "|" << right << setw(Size_Num_Rase+1) << "|" << setw(Size_Name_Rase+1)
                 << "|" << setw(Size_Days_Rase+3)
                 << right << setw(36) << "|";


            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                file << begin->time_rase[i] << " ";
            }
            file << endl;
        }
        else if (strlen(begin->name_station) > 1 && i > 4)
        {
            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                file << begin->time_rase[i] << " ";
            }
            file << endl;
        }
        else if (i > 4)
        {
            file << "|";
            for (i = 5; i < 10; i++)
            {
                if (strstr(begin->time_rase[i], "№"))
                {
                    break;
                }
                file << begin->time_rase[i] << " ";
            }
            file << endl;
        }

        else
        {
            file << endl;

        }
        file << "------------------------------------------------------------------------------------------------------------------" << endl;

        begin = begin->next;
    } while (begin->next != nullptr);

    cout << endl;

    file.close();
}
