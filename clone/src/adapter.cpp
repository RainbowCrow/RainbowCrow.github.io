#include "../include/adapter.h"

using namespace std;

Adapter::Adapter(const string &name, const int &price, const int &amount)
{
    oName = name;
    oPrice = price * 0.75;
    oAmount = amount;
}

string Adapter::get_name_item() const 
{
    return OldItem::get_name_old_item();
}

void Adapter::show_item() const
{
    OldItem::show_old_item();
}