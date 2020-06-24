#ifndef _RECT_H_
#define _RECT_H_

#include <iostream>
#include <string>
#include "./shape.h"

class rect : public shape
{
protected:
    double length;
    double width;

public:
    rect();
    rect(const double &length, const double &width);

    double get_length() const;
    double get_width() const;

    double get_area() const;
};

class square : public rect
{
public:
    square();
    square(const double &side);

    double get_side() const;
};

#endif