#ifndef _ECLIPSE_H_
#define _ECLIPSE_H_

#include <iostream>
#include <string>
#include "./shape.h"

#define PI 3.1416

class eclipse : public shape
{
protected:
    /* data */
    double hradius;
    double vradius;
public:
    eclipse();
    eclipse(const double &hradius, const double &vradius);

    double get_hradius() const;
    double get_vradius() const;

    double get_area() const;
};

class circle : public eclipse
{
public:
    circle();
    circle(const double &radius);

    double get_radius() const;
};

#endif
