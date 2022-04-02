#ifndef MODULESBRAGINETS_H_INCLUDED
#define MODULESBRAGINETS_H_INCLUDED

using namespace std;
#define Size 12
double s_calculation(double x, double y, double z);

float count_electrycity(float num);

struct avr_temp
{
    float Celcius = 0;
    float Fahrenheit = 0;
};

avr_temp count_tempreture(int mid_temp[], int n);

int count_bit(long int number);

string ReadFile(string file_path, string back_str[]);

string task_10_1(string output_file_path, string input_file_path, string word, string back_str[]);

string task_10_2(string input_file_path, string word, string back_str[]);

string task_10_3(string output_file_path, double x, double y, double z, long int bit_number, string back_str[]);


#endif // MODULESBRAGINETS_H_INCLUDED
