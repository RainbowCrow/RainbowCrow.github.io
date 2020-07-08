#include "../include/menu.h"

using namespace std;

Menu::Menu()
{
    this->shop = new Shop();
}

void Menu::menu() const 
{
    cout << "----Menu----" << endl;
    cout << "1. Show shop" << endl;
    cout << "2. Search item" << endl;
    cout << "3. New item" << endl;
    cout << "4. Old item" << endl;
    cout << "0. Exit" << endl; 
}

void Menu::menu_1() const
{
    cout << "----New-item----" << endl;
    cout << "1. Show item" << endl;
    cout << "2. Add item" << endl;
    cout << "3. Search item" << endl;
    cout << "4. Delete item" << endl;
    cout << "0. Exit" << endl;
}

void Menu::menu_2() const
{
    cout << "----Old-item----" << endl;
    cout << "1. Show item" << endl;
    cout << "2. Add item" << endl;
    cout << "3. Search item" << endl;
    cout << "4. Delete item" << endl;
    cout << "0. Exit" << endl;
}

int Menu::get_choice() const
{
    int choice;
    cout << "Your choice: ";
    while (!(cin >> choice))
    {
        cin.clear();
        cout << "Invalid input. Re-input: ";
        fflush(stdin);
    }
    return choice;
}

void Menu::do_menu(const int &choice)
{
    switch (choice)
    {
    case 1:
        this->shop->show_shop();
        break;
    case 2:
        search_item();
        break;
    case 3:
        new_item();
        break;
    case 4:
        old_item();
        break;
    case 0:
        cout << "Bye!";
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
}

void Menu::run()
{
    bool running = true;
    while (running)
    {
        menu();
        int choice = get_choice();
        do_menu(choice);
        if (choice == 0)
            running = false;
    }
}

void Menu::search_item()
{
    string name;
    cout << "name: " << endl;
    cin >> name;
    this->shop->search_item(name);
}

void Menu::new_item()
{
    bool running = true;
    while (running)
    {
        menu_1();
        int choice = get_choice();
        do_menu_1(choice);
        if (choice == 0)
            running = false;
    }
}

void Menu::add_new()
{
    string name;
    int price, amount;
    cout << "name: " ;
    cin >> name;
    cout << "price: ";
    cin >> price;
    cout << "amount: ";
    cin >> amount;

    this->shop->insert_new(name, price, amount);
}

void Menu::search_new()
{
    string name;
    cout << "name: ";
    cin >> name;

    this->shop->search_new(name);
}

void Menu::delete_new()
{
    string name;
    cout << "name: ";
    cin >> name;

    this->shop->delete_new(name);
}

void Menu::old_item()
{
    bool running = true;
    while (running)
    {
        menu_2();
        int choice = get_choice();
        do_menu_2(choice);
        if (choice == 0)
            running = false;
    }
}

void Menu::add_old()
{
    string name;
    int price, amount;
    cout << "name: " ;
    cin >> name;
    cout << "price: ";
    cin >> price;
    cout << "amount: ";
    cin >> amount;

    this->shop->insert_old(name, price, amount);
}

void Menu::search_old()
{
    string name;
    cout << "name: ";
    cin >> name;

    this->shop->search_old(name);
}

void Menu::delete_old()
{
    string name;
    cout << "name: ";
    cin >> name;

    this->shop->delete_old(name);
}

Menu::~Menu()
{
    for(int i = 0; i < this->shop->get_news().size(); i++)
    {
        delete this->shop->get_news()[i]; 
    }

    for(int i = 0; i < this->shop->get_olds().size(); i++)
    {
        delete this->shop->get_olds()[i]; 
    }
}

void Menu::do_menu_1(const int &choice)
{
    switch (choice)
    {
    case 1:
        this->shop->show_new();
        break;
    case 2:
        add_new();
        break;
    case 3:
        search_new();
        break;
    case 4:
        delete_new();
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
}

void Menu::do_menu_2(const int &choice)
{
    switch (choice)
    {
    case 1:
        this->shop->show_old();
        break;
    case 2:
        add_old();
        break;
    case 3:
        search_old();
        break;
    case 4:
        delete_old();
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
}