#include <iostream>

#include "../include/shop.h"

int main(int argc, char *argv[])
{
	vector<NewItem*> news;
	vector<NewItem*> olds;

	NewItem *abc = new NewItem("abc", 123, 123);
	Adapter *xyz = new Adapter("xyz", 12, 12);

	news.push_back(abc);
	olds.push_back(xyz);

	xyz->show_item();

	news[0]->show_item();
	olds[0]->show_item();

	delete abc;
	delete xyz;
}