#include <iostream>
#include "ModulesBrahinets.h"
#include "ModulesMelnyk.h"
#include "ModulesMalenko.h"
using namespace std;

short CheckFile(fstream &File)
{
    if (!File.is_open())
    {
        cout << "Не можу відкрити файл!" << endl
             << "Програма переривається!" << endl;
        return 1;
    }
    if (File.peek() == EOF)
    {
        cout << "Файл порожній!" << endl
             << "Додаю один рейс!" << endl;
        return 2;
    }
    else
    {
        cout << "Перевірка файлу пройшла добре!" << endl;
        return 3;
    }
}

void WorkWithRase(fstream &File, char file_name[], BusStation* rase)
{
    short choise;
    while (true)
    {
        cout << "1 - Пошук рейса." << endl
             << "2 - Вивести весь розклад руху автобусів." << endl
             << "3 - Додання нового рейса." << endl
             << "4 - Вилучення одного рейса за номером." << endl
             << "5 - Завершення." << endl;

        cout << "Введіть цифру від 1-5: ";
        cin >> choise;

        while (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Ви ввели не число. Спробуйте ще раз: ";
            cin >> choise;
        }
        while (cin.get() != '\n')
                continue;

        switch (choise)
        {
            case 1: FindRase(rase);   break;
            case 2: ShowRases(rase);  break;
            case 3: AddRase(rase);    break;
            case 4: DeleteRase(rase); break;
            case 5: WriteToDataFile(file_name, rase);
                    WriteToTxtFile(File, rase); return; break;
            default: break;
        }
    }
}

int main()
{
    system("chcp 1251 && cls");
    char binary_file_name[11] = "Rases.dat";
    fstream dataFile;
    dataFile.open(binary_file_name, ios::in | ios::binary);
    fstream txtFile;
    txtFile.open("txtRases.txt", ios::out);

    BusStation* rase;

    switch (CheckFile(dataFile))
    {
        case 1: return 1;                    break;
        case 2: rase = AddExample(binary_file_name, rase); break;
        case 3: rase = new BusStation;
    }
    dataFile.close();
    ReadDataFile(binary_file_name, rase);

    WorkWithRase(txtFile, binary_file_name, rase);
    return 0;
}
