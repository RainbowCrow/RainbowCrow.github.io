#include "../include/newitem.h"

using namespace std;

NewItem::NewItem(const string &nName, const int &nPrice, const int &nAmount)
{
    this->nName = nName;
    this->nPrice = nPrice;
    this->nAmount = nAmount;
}

string NewItem::get_name_item() const
{
    return nName;
}

void NewItem::show_item() const
{
    cout << nName << " " << nPrice << " " << nPrice << endl;
}