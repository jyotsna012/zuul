#pragma once
#include <vector>
#include <map>
#inlcude "item.h"

using namespace std;

class room{

  public:
    char* des;
    char* label;
    vector<item*> items;
    map<char*, room*> neighbors;
    room(char*,char*);
    room* getNextRoom(char*);
    room* getItem(char*);
    void addItem(item*);
    void printTheItems();
    void printTheExits();
    void addNeighbor(char*, room*);
    char* getDes;
    char* getLabel;
    void removeItem(char*);
}
