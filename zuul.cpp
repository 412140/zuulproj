#include "room.h"
#include "item.h"
#include <vector>
#include <iostream>

using namespace std;

/*
Ghazi abbas
c++ fall sem
zuul

simple terminal based adventure game

+++ Room.h and Room.cpp were made while working with Nick Braun

Sources:
All canvas videos from classes&inheritance and student list.
https://en.cppreference.com/w/cpp/language/nullptr
https://stackoverflow.com/questions/1282295/what-is-the-nullptr-keyword-and-why-is-it-better-than-null
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/?ref=header_search
https://cplusplus.com/reference/vector/vector/
https://en.cppreference.com/w/cpp/container/map
https://cplusplus.com/reference/map/map/
https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
*/

int main()
{

    // iterm vector
    vector<Item*> inventory;

    // create rooms and add descriptions
    Room* entrance = new Room("The entrance to the Hotel. You cant remember how you got here.");
    Room* lobby = new Room("The lobby of the Hotel. Where is the attendant?");
    Room* pool = new Room("The pool room has a card reader lock.");
    Room* h1 = new Room("The first part of the hallway. You can barely see the lobby.");
    Room* h2 = new Room("The second part of the hallway. How far does it go?");
    Room* h3 = new Room("The last part of the hallway. there is a Fire exit here,it has akeylock.");
    Room* dine = new Room("the hotels dining room");
    Room* r1 = new Room("This room is vacant.");
    Room* r2 = new Room("This room seems to be occupied, but nobody is here.");
    Room *r3 = new Room("The cleaners cart is still outside, but no cleaner to be seen.");
    Room* r4 = new Room("This room appears to be vacant.");
    Room* r5 = new Room("This room is empty");
    Room* r6 = new Room("This room is incredibly boring");
    Room* bathr = new Room("The Hotels public restroom.");
    Room* courty = new Room("A veyr large and open courtyard.");
    Room* exit = new Room("The final exit. you made it.");
    // exits for the rooms ( could have organized here but lazy)
    entrance->setExits(lobby, nullptr, nullptr, nullptr);
    lobby->setExits(dine, entrance, pool, h1);
    pool->setExits(nullptr, nullptr, lobby, nullptr);
    h1->setExits(r6, r1, lobby, h2);
    h2->setExits(r5, r2, h1, h3);
    h3->setExits(r4, r3, h2, exit);
    r1->setExits(h1, nullptr, nullptr, nullptr);
    r2->setExits(h2, nullptr, nullptr, nullptr);
    r3->setExits(h3, nullptr, nullptr, nullptr);
    r4->setExits(nullptr, h3, nullptr, nullptr);
    r5->setExits(nullptr, h2, nullptr, nullptr);
    r6->setExits(nullptr, h1, nullptr, nullptr);
    dine->setExits(courty, lobby, nullptr, bathr);
    bathr->setExits(nullptr, nullptr, dine, nullptr);
    courty->setExits(nullptr, dine, nullptr, nullptr);
    // make items elements + adding it to the proper room
    Item *cookie = new Item("a warm cookie");
    Item *fork = new Item("Silver fork");
    Item *soap = new Item("Hand soap");
    Item *keyCard = new Item("master keycard");
    Item *metKey = new Item("metal key");

    lobby->setItems(cookie);
    pool->setItems(metKey);
    dine->setItems(fork);
    bathr->setItems(soap);
    r3->setItems(keyCard);
    // set first "room" (entrance)
    Room* currentRoom = entrance;
    while (true)
    {
        char cmd[50];
        cout << "Enter a command: quit, inventory, drop, get, or go" << endl;
        cin >> cmd;

        if (strcmp(cmd, "quit") == 0)
        {
            printf("Bye.");
            break;
        }
        else if (strcmp(cmd, "inventory") == 0)
        {
            cout << "your inventory: " << endl;
            if (inventory.empty())
            {
                cout << "Empty"<< endl;
            }
            else
            {
                for (const auto &item : inventory)
                {
                    cout << "- " << item->getName() << endl;
                }
            }
        }
        else if (strcmp(cmd, "drop") == 0)
        {
            char itemName[20];
            cout << "item to be dropped: ";
            cin >> itemName;

            for (auto it = inventory.begin(); it != inventory.end(); ++it)
            {
                if (strcmp((*it)->getName(), itemName) == 0)
                {
                    Item *item = *it;
                    inventory.erase(it);
                    currentRoom->setItems(item);
                    cout << "You dropped : " << itemName << " in the room" << endl;
                    break;
                }
            }
            
        }else if (strcmp(cmd, "get") == 0)
        {
            char itemName[15];
            cout << "Enter item to be picked up: ";
            cin >> itemName;
            if (currentRoom->hasItem(itemName)) 
            {
                Item* item = currentRoom->getItem(itemName);
                inventory.push_back(item);
                cout << "You picked up the " << itemName << endl;
            } else
            {
                cout << "The " << itemName << " is not in the room."<< endl;
            }
        }       
        else if (strcmp(cmd, "go") == 0)
        {
            char direction[20];
            cout << "Enter direction (north, south, east, west): ";
            cin >> direction;
            cin.ignore(); //eat return

            // Lowercase the direction to match instructions
            for (int i = 0; direction[i]; i++)
            {
                direction[i] = tolower(direction[i]);
            }

            cout << "Entered direction: " << direction << endl;

            auto it = currentRoom->getExits().find(direction);
            if (it != currentRoom->getExits().end())
            {
                currentRoom = it->second;
                currentRoom->printDesc();
            }
            else
            {
                cout << "Invalid direction. Try again." << endl;
                cout << "Valid directions are:";
                for (const auto &exit : currentRoom->getExits())
                {
                    cout << " " << exit.first;
                }
                cout << endl;
            }



        } else{cout << "command not recognized.." << endl;}
        
        
    }

            
    delete soap;
    delete fork;
    delete keyCard;
    delete metKey;
    delete cookie;


    return 0;}