#include "Functions.h"

using namespace std;

int main()
{
    system("chcp 1251 && cls");
    ClassLab12_Brahinets cone;
    char example[] = "..\\..\\TestSuite\\ExampleResults.txt";
    char result[] = "..\\..\\TestSuite\\TestResult.txt";

    if (followDirectory(result) == false) {return 1;}

    ifstream ExampleFile(example);
    ofstream ResultFile(result);

    if (isFileOpen(ExampleFile, ResultFile) == false) {return 2;}

    for (short i = 0; i < 10; i++)
    {
        string radius, height, volume, buffLine;
        getline(ExampleFile, buffLine);
        radius = buffLine.erase(0, 8);

        getline(ExampleFile, buffLine);
        height = buffLine.erase(0, 8);

        getline(ExampleFile, buffLine);
        volume = buffLine.erase(0, 8);

        cone.set_con_radius(radius);
        cone.set_con_height(height);

        checkObject(ResultFile, cone, radius, height, volume, i);
    }

    ExampleFile.close();
    ResultFile.close();
    cout << "Для завершення натистіть Enter...";
    cin.get();
    return 0;
}
