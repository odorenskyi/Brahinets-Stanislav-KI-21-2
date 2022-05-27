#ifndef MODULESBRAHINETS_H_INCLUDED
#define MODULESBRAHINETS_H_INCLUDED

#include <iostream>
#include <cmath>
#define PI 3.14159265359

class ClassLab12_Brahinets
{
public:
    ClassLab12_Brahinets();
    float get_cone_radius() {return radius;}
    float get_cone_height() {return height;}
    float get_cone_volume() {return volume(radius, height);}

    void set_con_radius(float radius);
    void set_con_height(float height);

private:
    float radius, height;
    float volume(float radius, float height) {return (PI * pow(radius, 2) * height) / 3;}
};

ClassLab12_Brahinets::ClassLab12_Brahinets()
{
    radius = 5.25;
    height = 7.75;
}

void ClassLab12_Brahinets::set_con_radius(float radius)
{
    if (radius < 0)
        this->radius = 0;
    else
        this->radius = radius;
}

void ClassLab12_Brahinets::set_con_height(float height)
{
    if (height < 0)
        this->height = 0;
    else
        this->height = height;
}

#endif // MODULESBRAHINETS_H_INCLUDED
