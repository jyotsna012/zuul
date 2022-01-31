#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  
  char item[200] = " Paper Towel ";
  char label[200] = "French Class";
  char des[200] = "Bonjour! You are in the French Class... Yayyy!!";
  room* frenchclass = new room(label, des);

  strcpy(label,"bathroom");
  strcpy(des,"You are now in the cleanest bathroom");
  room* bathroom = new room(label,des);
  item* papertowel = new item(item);
  bathroom->addItem(papertowel);
  
  strcpy(label,"library");
  strcpy(item, "book");
  strcpy(des,"Shh... everyone is studying in thr library");
  room* library = new room(label,des);
  item* book = new item(item);
  library->addItem(book);
  
  strcpy(label,"Bio Class");
  strcpy(item, "microscope");
  strcpy(des,"Ohh is that connective tissue I see under the microscope in the Bio Class");
  room* bioclass = new room(label,des);
  item* microscope = new item(item);
  bioclass->addItem(microscope);
  
  strcpy(label,"Computer Class");
  strcpy(item, "computer");
  strcpy(des,"lets program zuul in the computer lab");
  room* computerclass = new room(label,des);
  item* computer = new item(item);
  computerclass->addItem(computer);
  
  strcpy(label,"Drama Room");
  strcpy(item, "costumes");
  strcpy(des,"we are in the drama room");
  room* dramaroom = new room(label,des);
  item* costumes = new item(item);
  dramaroom->addItem(costumes);
  
  
  strcpy(label,"Math Class");
  strcpy(des,"You are in everyone's most favorite class...not...math ugh!");
  room* mathclass = new room(label,des);
  
  strcpy(label,"Chem Class");
  strcpy(des ,"Whoa, I see something smoking in the chem class - must be a cool reaction");
  room* chemclass = new room(label,des);
  
  strcpy(label,"Physics Class");
  strcpy(des ,"We are in the Physics Class");
  room* physicsclass = new room(label,des);
  
  strcpy(label,"Lit Class");
  strcpy(des ,"We are in the Lit Class");
  room* litclass = new room(label,des);
  
  strcpy(label,"History Class");
  strcpy(des ,"We are in the History Class");
  room* historyclass = new room(label,des);
  
  strcpy(label,"Japanese Class");
  strcpy(des ,"We are in the Japanese Class");
  room* japaneseclass = new room(label,des);
  
  strcpy(label,"Spanish Class");
  strcpy(des ,"We are in the Spanish Class");
  room* spanishclass = new room(label,des);
  
  strcpy(label,"GloPo Class");
  strcpy(des ,"We are in the GloPo Class");
  room* glopoclass = new room(label,des);
  
  strcpy(label,"Cafe");
  strcpy(des ,"We are in the Cafe");
  room* cafe = new room(label,des);
  
  strcpy(label,"Gym");
  strcpy(des ,"We are in the Gym");
  room* gym = new room(label,des);
  
  bathroom -> addAround(S, mathclass);
  mathclass -> addAround(S, chemclass );
  mathclass -> addAround(N, bathroom);
  mathclass -> addAround(E, bioclass);
  chemclass -> addAround(N, mathclass);
  bioclass -> addAround(E, litclass);
  bioclass -> addAround(W, mathclass);
  physicsclass -> addAround(S, litclass);
  litclass -> addAround(N, physicsclass);
  litclass -> addAround(S, historyclass);
  litclass -> addAround(E, frenchclass );
  litclass -> addAround(W, bioclass);
  historyclass -> addAround(N, litclass);
  frenchclass -> addAround(E, japaneseclass);
  frenchclass -> addAround(W, litclass);
  japaneseclass -> addAround(E, glopoclass);
  japaneseclass -> addAround(W, frenchclass);
  spanishclass -> addAround(S, glopoclass);
  glopoclass -> addAround(S, computerclass );
  glopoclass -> addAround(E, cafe);
  glopoclass -> addAround(W, japaneseclass);
  glopoclass -> addAround(N, spanishclass);
  computerclass -> addAround(N, glopoclass);
  cafe -> addAround(E, gym);
  cafe -> addAround(W, glopoclass);
  library -> addAround(S, gym);
  gym -> addAround(N, library);
  gym -> addAround(S, dramaroom);
  gym -> addAround(W, cafe);
  dramaroom -> addAround(N, gym);
  
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
  rooms.push_back(glopoclass);
  rooms.push_back(computerclass);
  rooms.push_back(cafe);
  rooms.push_back(library);
  rooms.push_back(gym);
  rooms.push_back(dramaroom);

}
