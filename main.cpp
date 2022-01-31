#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  
  char item[200] = "White Board";
  char label[200] = "French Class";
  char description[200] = "Bonjour! You are in the French Class... Yayyy!!";
  room* frenchclass = new Room(label, description);

  strcpy(label,"bathroom");
  strcpy(description ,"You are in the bathroom. Unlike the school one, this one smells tolerable. Is that lavender?");
  Room* bathroom = new Room(label,description);
  strcpy(item,"SOAP");
  Item* soap = new Item(item);
  bathroom->addItem(soap);
  
  strcpy(label,"pool");
  strcpy(description ,"You have entered the pool room. Woah the floor is slippery, don't fall in!");
  Room* pool = new Room(label,description);
  
  strcpy(label,"hot tub");
  strcpy(description ,"You are in the hot tub room. It's so hot in here, and the steam is so thick you can barely see!");
  Room* hottub = new Room(label,description);
  
  strcpy(label,"roller coaster");
  strcpy(description ,"You are in the roller coaster room. Wow, could the rooms get any weirder? Wait is that kid falling?");
  Room* rollercoaster = new Room(label,description);
  
  strcpy(label,"animal farm");
  strcpy(description ,"You are in the animal farm. Is it just me or is that bull coming towards you a little too fast...");
  Room* animalfarm = new Room(label,description);
  
  strcpy(label,"ball pit");
  strcpy(description ,"You've fallen into the ball pit. Getting out will require immense effort. Who knew this would be so difficult?");
  Room* ballpit = new Room(label,description);
  strcpy(item,"BALL");
  Item* ball = new Item(item);
  ballpit->addItem(ball);
  
  strcpy(label,"cafeteria");
  strcpy(description ,"You are in the cafeteria. Remnants of food fights still stain the walls.");
  Room* cafeteria = new Room(label,description);
  
  strcpy(label,"ice cream");
  strcpy(description ,"You are in the ice cream shop. Ooh birthday cake, your favorite!");
  Room* icecream = new Room(label,description);
  
  strcpy(label,"indoor beach");
  strcpy(description ,"You are in the indoor beach. In case you don't know what that is, it's like a beach, but indoors");
  Room* indoorbeach = new Room(label,description);
  strcpy(item,"SHOVEL");
  Item* shovel = new Item(item);
  indoorbeach->addItem(shovel);
  
  strcpy(label,"shaved ice");
  strcpy(description ,"You are at the shaved ice shop! Who knew strawberry and root beer would go together so well!");
  Room* shavedice = new Room(label,description);
  
  strcpy(label,"kitchen");
  strcpy(description ,"You are in the kitchen. There's no way that lump of tasteless flour becomes bread.");
  Room* kitchen = new Room(label,description);
  strcpy(item,"KNIFE");
  Item* knife = new Item(item);
  kitchen->addItem(knife);
  
  strcpy(label,"tree house");
  strcpy(description ,"You are in the tree house! so. high. above. the. ground. Don't fall!");
  Room* treehouse = new Room(label,description);
  
  strcpy(label,"puppy room");
  strcpy(description ,"You are in the puppy room. You want to leave, but how can anyone say no to those eyes?");
  Room* puppyroom = new Room(label,description);
  strcpy(item,"PUPPY");
  Item* puppy = new Item(item);
  puppyroom->addItem(puppy);
  
  strcpy(label,"trampoline");
  strcpy(description ,"You are in the trampoline room. Wow it feels like you're on the moon! Watch out for the ceiling!");
  Room* trampoline = new Room(label,description);
  
  strcpy(label,"theater");
  strcpy(description ,"You are in the indoor theater. Your shoes are probably going to have popcorn all over them for the next month or so.");
  Room* theater = new Room(label,description);
  

  
  rooms.push_back(bathroom);
  rooms.push_back(mathclass);
  rooms.push_back(chemclass);
  rooms.push_back(bioclass);
  rooms.push_back(physicsclass);
  rooms.push_back(litclass);
  rooms.push_back(historyclass);
  rooms.push_back(frenchclass);
  rooms.push_back(japaneseclass);
  rooms.push_back(spanishclass);
  rooms.push_back(globalpolitics);
  rooms.push_back(computerclass);
  rooms.push_back(cafe);
  rooms.push_back(library);
  rooms.push_back(gym);
  rooms.push_back(dramaroom);

}
