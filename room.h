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
//regular functions needed 
  Room(const char* desc);
  void setExits(Room* north, Room* south, Room* east, Room* west);
  void setItems(Item* item);
  void printDesc();
  bool hasItem(const char* itemName);
  Item* getItem(const char* itemName);
  void printInf();
  const map<string, Room*>& getExits() const;
//for locked rooms
  //bool hasItemInInven(const char *itemName, const vector<Item *> &inventory);

private:
  const char* desc;
  map<string, Room*> exits;
  vector<Item*> items;
};

#endif
