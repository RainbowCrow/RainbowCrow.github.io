#ifndef _SHAPE_PROGRAM_H_
#define _SHAPE_PROGRAM_H_

#include <iostream>
#include <string>
#include <vector>

#include "./shape.h"
#include "./rect.h"
#include "./eclipse.h"

#define ADD_ECLIPSE 1
#define ADD_CIRCLE  2
#define ADD_RECT    3
#define ADD_SQUARE  4
#define SHOW_ALL    5
#define EXIT        0

using namespace std;

class shapeProgram
{
private:
    vector<shape *> shapes;

public:
    void run();
    ~shapeProgram();
private:
    void print_menu() const;
    int get_choice() const;
    void do_task(const int &choice);
    void add_circle();
    void add_eclipse();
    void add_rect();
    void add_square();
    void show_all();
    void print_message(const string &smg) const;
};

#endif