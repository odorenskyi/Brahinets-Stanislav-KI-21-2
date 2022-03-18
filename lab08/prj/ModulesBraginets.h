#ifndef MODULESBRAGINETS_H_INCLUDED
#define MODULESBRAGINETS_H_INCLUDED

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


#endif // MODULESBRAGINETS_H_INCLUDED
