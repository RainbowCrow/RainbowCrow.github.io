#include <iostream>
#include <string>
#include "../include/eclipse.h"

using namespace std;

eclipse::eclipse()
{
    this->hradius = 1.0;
    this->vradius = 1.0;
    type = "Eclipse";
}

eclipse::eclipse(const double &hradius, const double &vradius)
{
    this->hradius = hradius;
    this->vradius = vradius;
    type = "Eclipse";
}

double eclipse::get_hradius() const
{
    return hradius;
}

double eclipse::get_vradius() const
{
    return vradius;
}

double eclipse::get_area() const
{
    return PI * hradius * vradius;
}

circle::circle() : eclipse()
{
    type = "Circle";
}

circle::circle(const double &radius) : eclipse(radius, radius)
{
    type = "Circle";
}

double circle::get_radius() const 
{
    return hradius;
}

