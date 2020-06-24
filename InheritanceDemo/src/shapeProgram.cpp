#include "../include/shapeprogram.h"
// #include "../include/shape.h"
// #include "../include/eclipse.h"

// #include <iostream>
// #include <string>
// #include <vector>

using namespace std;

void shapeProgram::run()
{
    bool running = true;
    while (running)
    {
        print_menu();
        int choice = get_choice();
        do_task(choice);
        if (choice == EXIT)
            running = false;
    }
}

void shapeProgram::print_menu() const
{
    cout << "Demo Shape Program" << endl;
    cout << ADD_ECLIPSE << ".Add Eclipse" << endl;
    cout << ADD_CIRCLE << ".Add Circle" << endl;
    cout << ADD_RECT << ".Add Rect" << endl;
    cout << ADD_SQUARE << ".Add Square" << endl;
    cout << SHOW_ALL << ".Show all" << endl;
    cout << EXIT << ".Exit" << endl;
}

int shapeProgram::get_choice() const
{
    int choice;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}

void shapeProgram::do_task(const int &choice)
{
    switch (choice)
    {
    case ADD_ECLIPSE:
        add_eclipse();
        break;
    case ADD_CIRCLE:
        add_circle();
        break;
    case ADD_RECT:
        add_rect();
        break;
    case ADD_SQUARE:
        add_square();
        break;
    case SHOW_ALL:
        show_all();
        break;
    case EXIT:
        print_message("Bye!");
        break;
    default:
        print_message("Invalid choice!");
        break;
    }
}

void shapeProgram::add_eclipse()
{
    double hradius, vradius;
    cout << "Enter horizontal radius: ";
    cin >> hradius;
    cout << "Enter vertical radius: ";
    cin >> vradius;

    eclipse *e = new eclipse(hradius, vradius);
    shapes.push_back(e);

    cout << "Eclipse added" << endl;
}

void shapeProgram::add_circle()
{
    double radius;
    cout << "Enter radius: ";
    cin >> radius;

    circle *e = new circle(radius);
    shapes.push_back(e);

    cout << "Circle added" << endl;
}

void shapeProgram::add_rect()
{
    double length, width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    rect *e = new rect(length, width);
    shapes.push_back(e);

    cout << "Rectangle added" << endl;
}

void shapeProgram::add_square()
{
    double side;
    cout << "Enter side: ";
    cin >> side;

    square *e = new square(side);
    shapes.push_back(e);

    cout << "Square added" << endl;
}

void shapeProgram::show_all()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << i+1 << " .";
        shapes[i]->display();
    }
}

void shapeProgram::print_message(const string &smg) const
{
    cout << smg << endl;
}

shapeProgram::~shapeProgram() 
{
    for(int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
}