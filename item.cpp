#include <cstring>
#include "item.h"

item::item(char* newN){
  name = new char[200];
  strcpy(label, newN);
}
char* item :: getName(){
  return name;
}
