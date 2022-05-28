#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "ModulesBrahinets.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool followDirectory(char file_name[])
{
    string cpp_file = __FILE__;
    size_t found = cpp_file.find("\\lab12\\prj");

    if (found == string::npos)
    {
        ofstream resultFile(file_name);
        resultFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;

        for (short i = 0; i < 99; i++) {cout << "\a";}

        resultFile.close();
        return false;
    }
    else {return true;}
}

bool isFileOpen (ifstream &example_file, ofstream &result_file)
{
    if (!example_file.is_open())
    {
        cout << "Не можу відкрити файл з прикладами!" << endl;
        return false;
    }
    else if (!result_file.is_open())
    {
        cout << "Не можу відкрити файл для перевірки тестування!" << endl;
        return false;
    }
    else {return true;}
}

void checkObject (ofstream &result_file, ClassLab12_Brahinets cone,
                  string radius, string height, string volume, short i)
{
    if (round(cone.get_cone_radius() * 100.0 / 100.0) == round((stof(radius)) * 100.0 / 100.0) &&
        round(cone.get_cone_height() * 100.0 / 100.0) == round((stof(height)) * 100.0 / 100.0) &&
        round(cone.get_cone_volume() * 100.0 / 100.0) == round((stof(volume)) * 100.0 / 100.0))
    {
        result_file << "Test Case " << i + 1
                    << " Passed" << endl;
    }
    else
    {
        result_file << "Test Case " << i + 1
                    << " Failed" << endl;
    }
}

#endif // FUNCTIONS_H_INCLUDED
