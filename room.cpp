#include <iostream>
#include "room.h"
#include "item.h"
using namespace std;

Room::Room(const char *desc) : desc(desc)
{
}

void Room::setExits(Room *north, Room *south, Room *east, Room *west)
{
	exits["North"] = north;
	exits["South"] = south;
	exits["East"] = east;
	exits["West"] = west;
}

void Room::setItems(Item *item)
{
	items.push_back(item);
}

// https://www.codingninjas.com/studio/library/iterators-auto-keyword
void Room::printDesc()
{
	cout << "You are in" << desc << endl;
	cout << "The exits are: " << endl;
	for (auto it = exits.begin(); it != exits.end(); ++it)
	{
		cout << it->first << endl;
	}
	if (!items.empty())
	{
		cout << "The items in the room are: " << endl;
		for (auto it = items.begin(); it != items.end(); ++it)
		{
			cout << (*it)->getName() << endl;
		}
	}
	else
	{
		printf("no items here");
	}
}

bool Room::hasItem(const char *itemName)
{
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (strcmp((*it)->getName(), itemName) == 0)
		{
			return true;
		}
	}
	return false;
}

void Room::getItem(const char *itemName)
{
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (strcmp((*it)->getName(), itemName) == 0)
		{
			Item* item = *it;
			items.erase(it);
			return item;
		}
	}
}
