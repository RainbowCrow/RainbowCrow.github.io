#include "../include/rect.h"
#include <iostream>
#include <string>

using namespace std;

rect::rect()
{
    this->length = 1.0;
    this->width = 1.0;
    type = "Rectangle";
}

rect::rect(const double &length, const double &width)
{
    this->length = length;
    this->width = width;
    type = "Rectangle";
}

double rect::get_length() const
{
    return length;
}

double rect::get_width() const
{
    return width;
}

double rect::get_area() const
{
    return length * width;
}

square::square() : rect()
{
    type = "Square";
}

square::square(const double &side) : rect(side, side)
{
    type = "Square";
}

double square::get_side() const
{
    return length;
}

