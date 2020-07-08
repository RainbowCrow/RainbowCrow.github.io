#ifndef SHOP_H
#define SHOP_H

#include "./newitem.h"
#include "./olditem.h"
#include "./adapter.h"

#include <vector>

using namespace std;

class Shop
{
private:
    string shop_name;
    vector<NewItem *> news;
    vector<NewItem *> olds;

public:
    Shop();

    void insert_new(const string &nName, const int &nPrice, const int &nAmount);
    void show_new() const;
    void delete_new(const string &nName);

    void insert_old(const string &oName, const int &oPrice, const int &oAmount);
    void show_old() const;
    void delete_old(const string &oName);
    
    void show_shop() const;
};

#endif