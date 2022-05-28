#ifndef MODULESBRAHINETS_H_INCLUDED
#define MODULESBRAHINETS_H_INCLUDED

#include <cmath>
#include <string>

#define PI 3.14159265359

using namespace std;
class ClassLab12_Brahinets
{
public:
    ClassLab12_Brahinets();
    float get_cone_radius() {return radius;}
    float get_cone_height() {return height;}
    float get_cone_volume() {return volume(radius, height);}

    void set_con_radius(string radius);
    void set_con_height(string height);

private:
    float radius, height;
    float volume(float radius, float height) {return (PI * pow(radius, 2) * height) / 3;}
};

ClassLab12_Brahinets::ClassLab12_Brahinets()
{
    radius = 5.25;
    height = 7.75;
}

void ClassLab12_Brahinets::set_con_radius(string radius)
{
    if (stof(radius) < 0)
        this->radius = 0;
    else
        this->radius = stof(radius);
}

void ClassLab12_Brahinets::set_con_height(string height)
{
    if (stof(height) < 0)
        this->height = 0;
    else
        this->height = stof(height);
}

#endif // MODULESBRAHINETS_H_INCLUDED
