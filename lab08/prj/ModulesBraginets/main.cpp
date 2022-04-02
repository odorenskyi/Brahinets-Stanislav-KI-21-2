#include <iostream>
#include <cmath>
#include <bitset>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define Size  12
#define AMOUNT_STR 12

using namespace std;
const double PI = 3.14159265;

// Returns the solution of the expression
double s_calculation(double x, double y, double z)
{
    return 1 + sqrt(pow(x / abs(y - z), 3) +
          (pow(x, 2) + z) / sqrt(abs((z + x) * y)) -
            cos(x * pow(z, 2)) / (2 * y + PI));
}

// Returns the cost of electricity used
float count_electrycity(float num)
{
    if (num < 150)
    {
        cout << "Р’Рё СЃРїРѕР¶РёР»Рё " << round(num * 1000.0) / 1000.0 << " РєР’С‚" << endl
             << "РЈ С†СЊРѕРјСѓ РІРёРїР°РґРєСѓ 1 РєР’С‚ РєРѕС€С‚СѓС” 130,843 РіСЂРЅ." << endl
             << "Р”Рѕ СЃРїР»Р°С‚Рё: ";
        return num * 130.843;
    }
    else if (num >= 150 && num < 800)
    {
        cout << "Р’Рё СЃРїРѕР¶РёР»Рё " << round(num * 1000.0) / 1000.0 << " РєР’С‚" << endl
             << "РЈ С†СЊРѕРјСѓ РІРёРїР°РґРєСѓ 1 РєР’С‚ РєРѕС€С‚СѓС” 241.945 РіСЂРЅ." << endl
             << "Р”Рѕ СЃРїР»Р°С‚Рё: ";
        return num * 241.945;
    }
    else if (num >= 800)
    {
         cout << "Р’Рё СЃРїРѕР¶РёР»Рё " << round(num * 1000.0) / 1000.0 << " РєР’С‚" << endl
             << "РЈ С†СЊРѕРјСѓ РІРёРїР°РґРєСѓ 1 РєР’С‚ РєРѕС€С‚СѓС” 534.047 РіСЂРЅ." << endl
             << "Р”Рѕ СЃРїР»Р°С‚Рё: ";
        return num * 534.047;
    }
}

/* Returns the structure which contains
average temperature by Celsius and by Fahrenheit*/
struct avr_temp
{
    float Celcius = 0;
    float Fahrenheit = 0;
};

avr_temp count_tempreture(int mid_temp[], int n)
{
    avr_temp temp;
    float mid_temp_far[n];
    int i = 0;

    for (i = 0; i < n; i++)
        mid_temp_far[i] = 32 + 1.8 * mid_temp[i];

    for (i = 0; i < n; i++)
    {
        temp.Celcius += mid_temp[i];
        temp.Fahrenheit += mid_temp_far[i];
    }
    temp.Celcius /= n;
    temp.Fahrenheit /= n;

    return temp;
}


/* Returns the number of zeros if high bit = 0,
otherwise the number of ones*/
int count_bit(long int number)
{
    bitset<32> b_number(number);
    if(!((number >> 9) & 1))
    {
        cout << "РўР°Рє СЏРє 10 Р±С–С‚ = 0, РєС–Р»СЊРєС–СЃС‚СЊ 0: ";
        return 32 - b_number.count();
    }
    else
    {
        cout << "РўР°Рє СЏРє 10 Р±С–С‚ = 1, РєС–Р»СЊРєС–СЃС‚СЊ 1: ";
        return b_number.count();
    }
}

// Read file and come back the contain of the file
string ReadFile(string file_path, string back_str[])
{
    fstream File;
    File.open(file_path, ios_base::in);
    if (!File.is_open())      // if the file did not open
    {
        cout << "Не можу відкрити файл " << file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (File.good())
    {

        getline(File, back_str[i]);
        back_str[i] += '\n';
        i++;
    }

    File.close();
    return back_str[AMOUNT_STR];
}

// Task 10.1
string task_10_1(string output_file_path, string input_file_path, string word, string back_str[])
{
    fstream outFile;
    outFile.open(output_file_path, ios_base::out);

    if (!outFile.is_open())         // if the file did not open
    {
        cout << "Не можу відкрити файл " << output_file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }

    // Wright the information about developer
    outFile << "Виконавець   | Брагінець Станіслав" << endl
            << "ВНЗ          | ЦНТУ" << endl
            << "Місто/Країна | Кропивницький/Україна" << endl
            << "Рік розробки | 2022" << endl;

    // Open inputfile.txt
    fstream inFile(input_file_path, ios_base::out);
    if (!inFile.is_open())      // if the file did not open
    {
        cout << "Не можу відкрити файл " << input_file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }
    inFile << word;

    // Count the number of symbols in lowercase
    int count_low = 0, i = 0;
    for (i = 0; i < word.size(); i++)
    {
        if (islower(word[i]) || word[i] == 'я')
            count_low++;
    }
    outFile << "\nКількість символів в нижньому регістрі: " << count_low << endl;

    // Is there a word in the poem
    string poem = {"В хаті сонячній промінь косо\n"
                   "На долівку ляга з вікна\n"
                   "Твої чорні шовкові коси\n"
                   "Припорошила вже сивина"};

    size_t find_word;

    find_word = poem.find(word);
    if (find_word != string::npos)
        outFile << "\nВаше слово є у частині вірша \"Матері\"!" << endl;
    else
        outFile << "\nВашого слова немає у частині вірша \"Матері\"!" << endl;

    outFile.close();
    inFile.close();

    // Read the file and save the information
    // in the massive of string
    ReadFile(output_file_path, back_str);

    return back_str[AMOUNT_STR];
}

// Task 10.2
string task_10_2(string input_file_path, string word, string back_str[])
{
    fstream inFile;
    inFile.open(input_file_path, ios_base::out);
    if (!inFile.is_open())      // if the file did not open
    {
        cout << "Не можу відкрити файл " << input_file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }
    inFile << word << endl;
    inFile.close();

    fstream inFile1;
    inFile1.open(input_file_path, ios_base::app);

    if (!inFile1.is_open())      // if the file did not open
    {
        cout << "Не можу відкрити файл " << input_file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }
    /* Change symbols in lowercase to uppercase
    and vise versa */
    int i = 0;
    for (i = 0; i < word.size(); i++)
    {
        if (isupper(word[i]))
            word[i] = tolower(word[i]);
        else
            word[i] = toupper(word[i]);
    }
    inFile1 << endl << word << endl;

    // Rewriting the time and data
    time_t rawtime;
    time(&rawtime); // data in seconds
    inFile1 << "Дата й час дозапису інформації: " << ctime(&rawtime) << endl;

    inFile1.close();

    ReadFile(input_file_path, back_str);

    return back_str[AMOUNT_STR];
}

// Task 10.3
string task_10_3(string output_file_path, double x, double y, double z, long int bit_number, string back_str[])
{
    fstream outFile;
    outFile.open(output_file_path, ios_base::app);

    if (!outFile.is_open())      // if the file did not open
    {
        cout << "Не можу відкрити файл " << output_file_path << endl;
        cout << "Програму призупинено." << endl;
        exit(EXIT_FAILURE);
    }

    // Rewriting the result of s_calculation() function
    outFile << endl << "Результат функції s_calculation(): " << setprecision(9) << s_calculation(x, y, z) << endl;

    // Translate to binary code
    bitset<32> b_number(bit_number);
    outFile << endl << "Двійковий код: " << b_number;

    outFile.close();

    ReadFile(output_file_path, back_str);

    return back_str[AMOUNT_STR];
}



