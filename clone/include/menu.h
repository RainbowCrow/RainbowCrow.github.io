#ifndef _MENU_H_
#define _MENU_H_

#include "./shop.h"

using namespace std;

class Menu 
{
private:
    Shop *shop;
public:
    Menu();
    ~Menu();
    void run();
private:
    void menu() const;
    void menu_1() const;
    void menu_2() const;

    int get_choice() const;

    void do_menu(const int &choice);
    void do_menu_1(const int &choice);
    void do_menu_2(const int &choice);

    void search_item();

    void new_item();
    void add_new();
    void search_new();
    void delete_new();

    void old_item();
    void add_old();
    void search_old();
    void delete_old();
};

#endif
