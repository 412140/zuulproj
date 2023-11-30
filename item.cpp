#include <iostream>
#include "Item.h"

Item::Item(const char *name) : name(name) {}

const char *Item::getName()
{
    return name;
}