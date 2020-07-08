#ifndef _OLD_ITEM_H_
#define _OLD_ITEM_H_

#include <iostream>
#include <string>

using namespace std;
class OldItem
{
protected:
    string oName;
    int oPrice, oAmount;

public:
    OldItem(){};
    OldItem(const string &oName, const int &oPrice, const int &oAmount);
    string get_name_old_item() const;
    virtual void show_old_item() const;
};

#endif