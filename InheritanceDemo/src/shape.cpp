#include <iostream>
#include <string>
#include "../include/shape.h"

using namespace std;

shape::shape()
{
    this->type = "";
}

string shape::get_type() const
{
    return type;
}

double shape::get_area() const
{
    return 0.0;
}

void shape::display() const
{
    cout << "Type of shape: " << type << endl;
    cout << "Area of shape: " << get_area() << endl;
}
