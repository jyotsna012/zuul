#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

room::room(char* nLabel, char* nDes){
  des = new char[200];
  label = new char[200];
  strcpy(label, nLabel);
  strcpy(des, nDes);
}

void room::printTheItems(){
  cout << "here are the items in this room: " << endl;
  for(vector<item*> :: interator it = items.begin(); it != items.end(); it++){
    cout << (*it)->getName() << endl;
  }
}

void room::printTheExits(){
  map<char*,room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    cout << it->first << endl;
  }
}

room* room::getNextRoom(char* d){
  map<char*,room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    if(strcmp((it->first),d)==0){
      return it->second;
    }
  }
  return NULL;
}

item* room::getItem(char* label){
  for(vector<item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      return (*it);
    }
  }
  return NULL;
}

void room::removeItem(char* label){
  for(vector<item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      items.erase(it);
      break;
    }
  }
}

void room::addItem(item* i){
  items.push_back(i);
}

char* Room::getDes(){
  return des;
}

char* Room::getLabel(){
  return label;
}
void Room::addAround(char* d, room* n){
  neighbors.insert({d,n});
}

