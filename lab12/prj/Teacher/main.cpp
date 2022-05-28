#include "Functions.h"

using namespace std;

int main()
{
    system("chcp 1251 && cls");
    ClassLab12_Brahinets cone;
    char example[] = "ExampleResults.txt";
    char result[] = "TestResult.txt";

    if (followDirectory(result) == false) {return 1;}

    ifstream ExampleFile(example);
    ofstream ResultFile(result);

    if (isFileOpen(ExampleFile, ResultFile) == false) {return 2;}

    for (short i = 0; i < 11; i++)
    {
        string radius, height, volume, buffLine;
        getline(ExampleFile, buffLine);
        radius = buffLine.erase(0, 7);

        getline(ExampleFile, buffLine);
        height = buffLine.erase(0, 7);

        getline(ExampleFile, buffLine);
        volume = buffLine.erase(0, 7);

        cone.set_con_radius(radius);
        cone.set_con_height(height);

        checkObject(ResultFile, cone, radius, height, volume, i);
    }

    ExampleFile.close();
    ResultFile.close();
    cin.get();
    return 0;
}
