#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "./olditem.h"
#include "./newitem.h"

using namespace std;

class Adapter : public OldItem, public NewItem
{
public:
    Adapter(const string &name, const int &price, const int &amount);

    string get_name_item() const;
    void show_item() const;
};

#endif