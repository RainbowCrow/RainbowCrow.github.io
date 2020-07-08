#include "../include/shop.h"

using namespace std;

Shop::Shop()
{
    this->shop_name = "Ditmemay";
}

void Shop::insert_new(const string &nName, const int &nPrice, const int &nAmount)
{
    NewItem *new_item = new NewItem(nName, nPrice, nAmount);
    news.push_back(new_item);
}

void Shop::show_new() const 
{
    for(int i = 0; i < news.size(); i++) 
    {
        news[i]->show_item();
    }
}

void Shop::delete_new(const string &nName) 
{
    for(int i = 0; i < news.size(); i++) 
    {
        if(news[i]->get_name_item() == nName) {
            delete news[i];
            news.erase(news.begin() + i);
        }
    }
}

void Shop::insert_old(const string &oName, const int &oPrice, const int &oAmount)
{
    Adapter *old_item = new Adapter(oName, oPrice, oAmount);
    olds.push_back(old_item);
}

void Shop::show_old() const 
{
    for(int i = 0; i < olds.size(); i++) 
    {
        olds[i]->show_item();
    }
}

void Shop::delete_old(const string &oName) 
{
    for(int i = 0; i < olds.size(); i++) 
    {
        if(olds[i]->get_name_item() == oName) {
            delete olds[i];
            olds.erase(olds.begin() + i);
        }
    }
}

void Shop::show_shop() const 
{
    cout << shop_name << endl;
    show_new();
    show_old();
}
