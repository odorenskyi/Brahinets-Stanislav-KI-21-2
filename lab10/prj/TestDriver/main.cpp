#include <iostream>
#include <string>
#include <fstream>
#include "ModulesBraginets.h"

#define EXAM 3
#define SIZE_STR 13
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251&& cls");
    string output_file_path = "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\Files\\outputfile.txt";
    string input_file_path = "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\Files\\inputfile.txt";
    string words[EXAM] {"оПХОНПНЬХКЮ", "оПХЦНРСБЮКЮ", "ЯНмЪвМХИ"};
    string files_1[EXAM] {"D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_1\\TCM1_1.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_1\\TCM1_2.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_1\\TCM1_3.txt"};
    string str_1[SIZE_STR];
    string str_2[SIZE_STR];

    string testing_file_path = "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\Files\\testing_result.txt";
    fstream TestingFile (testing_file_path, ios_base::out);
    TestingFile << "Task_10_1" << endl;
    cout << "Task_10_1" << endl;
    TestingFile.close();

    fstream TestingFile1 (testing_file_path, ios_base::app);
    short i = 0, j = 0, counter = 0;
    for (i = 0; i < EXAM; i++)
    {
        task_10_1(output_file_path, input_file_path, words[i], str_1);
        ReadFile(files_1[i], str_2);

        for (j = 0; j < 8; j++)
        {
            if (str_1[j] == str_2[j])
                counter++;
            else
                counter--;
        }
        if (counter == 8)
        {
            TestingFile1 << "TSM1_" << i + 1 << " Passed" << endl;
            cout << "TSM1_" << i + 1 << " Passed" << endl;
        }
        else
        {
            TestingFile1 << "TSM1_" << i + 1 << " Failed" << endl;
            cout << "TSM1_" << i + 1 << " Failed" << endl;
        }

        counter = 0;
    }

    string files_2[EXAM] {"D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_2\\TCM2_1.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_2\\TCM2_2.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_2\\TCM2_3.txt"};

    str_1[SIZE_STR] = " ";
    str_2[SIZE_STR] = " ";
    TestingFile1 << "Task_10_2" << endl;
    cout << "Task_10_2" << endl;
    for (i = 0; i < EXAM; i++)
    {
        task_10_2(input_file_path, words[i], str_1);
        ReadFile(files_2[i], str_2);

        for (j = 0; j < 3; j++)
        {
            if (str_1[j] == str_2[j])
                counter++;
            else
                counter--;
        }
        if (counter == 3)
        {
            TestingFile1 << "TSM2_" << i + 1 << " Passed" << endl;
            cout << "TSM2_" << i + 1 << " Passed" << endl;
        }
        else
        {
            TestingFile1 << "TSM2_" << i + 1 << " Failed" << endl;
            cout << "TSM2_" << i + 1 << " Failed" << endl;
        }
        counter = 0;
    }

    double x[EXAM] {4, 1, 7};
    double y[EXAM] {5, 2, 8};
    double z[EXAM] {6, 3, 9};
    long int b[EXAM] = {7, 56, 45};
    string files_3[EXAM] {"D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_3\\TCM3_1.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_3\\TCM3_2.txt",
                          "D:\\STAS\\алор\\Brahinets-Stanislav-KI-21-2\\lab10\\prj\\TestDriver\\TestFiles\\Task_10_3\\TCM3_3.txt"};

    str_1[SIZE_STR] = " ";
    str_2[SIZE_STR] = " ";

    TestingFile1 << "Task_10_3" << endl;
    cout << "Task_10_3" << endl;
    for (i = 0; i < EXAM; i++)
    {
        task_10_1(output_file_path, input_file_path, words[0], str_1);
        task_10_3(output_file_path, x[i], y[i], z[i], b[i], str_1);
        ReadFile(files_3[i], str_2);

        for (j = 0; j < 12; j++)
        {
            if (str_1[j] == str_2[j])
                counter++;
            else
                counter--;
        }
        if (counter == 12)
        {
            TestingFile1 << "TSM3_" << i + 1 << " Passed" << endl;
            cout << "TSM3_" << i + 1 << " Passed" << endl;
        }
        else
        {
            TestingFile1 << "TSM3_" << i + 1 << " Failed" << endl;
            cout << "TSM3_" << i + 1 << " Failed" << endl;
        }
        counter = 0;
    }

    TestingFile1.close();

    system("pause");

    return 0;
}
