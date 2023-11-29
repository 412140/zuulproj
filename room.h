#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
using namespace std;

class Item;

class Room
{
public:
  Room(const char *desc);
  void setExits(Room *north, Room *south, Room *east, Room *west);
  void setItems(Item *item);
  void printDesc();
  bool hasItem(const char *itemName);
  Item* getItem(const char *itemName);

private:
  const char *desc;
  map<const char *, Room *> exits;
  vector<Item *> items;
};

#endif
