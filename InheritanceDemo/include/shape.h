#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <string>

using namespace std;

class shape
{
protected:
    /* data */
    string type;

public:
    shape(); // default constructor
    virtual ~shape();
    string get_type() const; // return type
    virtual double get_area() const; // return 0.0
    void display() const;    // print type and area of a shape
};

#endif