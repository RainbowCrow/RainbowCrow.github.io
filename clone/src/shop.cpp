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
    for (int i = 0; i < news.size(); i++)
    {
        news[i]->show_item();
    }
}

void Shop::search_new(const string &nName) const
{
    for (int i = 0; i < news.size(); i++)
    {
        if (news[i]->get_name_item() == nName)
        {
            news[i]->show_item();
            return;
        }
    }
    cout << "Not found" << endl;
}

void Shop::delete_new(const string &nName)
{
    for (int i = 0; i < news.size(); i++)
    {
        if (news[i]->get_name_item() == nName)
        {
            delete news[i];
            news.erase(news.begin() + i);
        }
    }
}

vector<NewItem *> Shop::get_news() const
{
    return news;
}

void Shop::insert_old(const string &oName, const int &oPrice, const int &oAmount)
{
    Adapter *old_item = new Adapter(oName, oPrice, oAmount);
    olds.push_back(old_item);
}

void Shop::show_old() const
{
    for (int i = 0; i < olds.size(); i++)
    {
        olds[i]->show_item();
    }
}

void Shop::search_old(const string &oName) const
{
    for (int i = 0; i < olds.size(); i++)
    {
        if (olds[i]->get_name_item() == oName)
        {
            olds[i]->show_item();
            return;
        }
    }
    cout << "Not found" << endl;
}

void Shop::delete_old(const string &oName)
{
    for (int i = 0; i < olds.size(); i++)
    {
        if (olds[i]->get_name_item() == oName)
        {
            delete olds[i];
            olds.erase(olds.begin() + i);
        }
    }
}

vector<NewItem *> Shop::get_olds() const
{
    return olds;
}

void Shop::show_shop() const
{
    cout << shop_name << endl;
    cout << "-----New Item------" << endl;
    show_new();
    cout << "-----Old Item------" << endl;
    show_old();
}

void Shop::search_item(const string &name) const
{
    cout << "New Item: ";
    search_new(name);
    cout << "Old Item: ";
    search_old(name);
}
