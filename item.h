#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
public:
    Item(const char *name);
    const char *getName();

private:
    const char *name;
};

#endif