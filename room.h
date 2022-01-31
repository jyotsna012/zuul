#pragma once
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class room{

  public:
    //description of room
    char* des;
    //name of room
    char* label;
    //items in room
    vector<item*> items;
    room(char*,char*);
    //gets the next room based on direction
    room* getNextRoom(char*);
    //gets the item
    item* getItem(char*);
    //add item to room
    void addItem(item*);
    //print the items
    void printTheItems();
    //print the exits in the room
    void printTheExits();
    void addAround(char*,room*);
    char* getDes();
    char* getLabel();
    void removeItem(char*);
    //map of neighbors
    map<char*,room*> neighbors;

};

