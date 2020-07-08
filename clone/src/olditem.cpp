#include "../include/olditem.h"

using namespace std;

OldItem::OldItem(const string &oName, const int &oPrice, const int &oAmount)
{
    this->oName = oName;
    this->oPrice = oPrice;
    this->oAmount = oAmount;
}

string OldItem::get_name_old_item() const 
{
    return oName;
}

void OldItem::show_old_item() const 
{
    cout << oName << " " << oPrice << " " << oAmount << endl;
}