#ifndef _NEW_ITEM_H_
#define _NEW_ITEM_H_

#include <iostream>
#include <string>

using namespace std;

class NewItem
{
private:
    int nPrice, nAmount;
    string nName;

public:
    NewItem(){};
    NewItem(const string &nName, const int &nPrice, const int &nAmount);

    virtual void show_item() const;
    virtual string get_name_item() const;
};

#endif