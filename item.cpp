#include <cstring>
#include "item.h"

item::item(char* newN){
  name = new char[200];
  strcpy(name, newN);
}
char* item::getName(){
  return name;
}
