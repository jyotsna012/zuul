#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

void printObjects(vector<item*> objects);
void dropAddItem(char* iName, room* currentRoom, vector<item*> &objectss, int addOrDrop);
void printRoom(room* a, vector<item*> b);

int main(){
  
  vector<item*> objects;
  vector<room*> rooms;
  
  char N[10] = "NORTH";
  char E[10] = "EAST";
  char S[10] = "SOUTH";
  char W[10] = "WEST";
  
  char itemm[200] = " Paper Towel ";
  char label[200] = "French Class";
  char des[200] = "Bonjour! You are in the French Class... Yayyy!!";
  room* frenchclass = new room(label, des);

  strcpy(label,"bathroom");
  strcpy(des,"You are now in the cleanest bathroom");
  room* bathroom = new room(label,des);
  item* papertowel = new item(itemm);
  bathroom->addItem(papertowel);
  
  strcpy(label,"library");
  strcpy(itemm, "book");
  strcpy(des,"Shh... everyone is studying in thr library");
  room* library = new room(label,des);
  item* book = new item(itemm);
  library->addItem(book);
  
  strcpy(label,"Bio Class");
  strcpy(itemm, "microscope");
  strcpy(des,"Ohh is that connective tissue I see under the microscope in the Bio Class");
  room* bioclass = new room(label,des);
  item* microscope = new item(itemm);
  bioclass->addItem(microscope);
  
  strcpy(label,"Computer Class");
  strcpy(itemm, "computer");
  strcpy(des,"lets program zuul in the computer lab");
  room* computerclass = new room(label,des);
  item* computer = new item(itemm);
  computerclass->addItem(computer);
  
  strcpy(label,"Drama Room");
  strcpy(itemm, "costumes");
  strcpy(des,"we are in the drama room");
  room* dramaroom = new room(label,des);
  item* costumes = new item(itemm);
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
  
  room* currentRoom = litclass;
  int input;
  cout << "Hi, this is the game ZUUL. You can go to a room, pick an item, drop an item, or quit the game. Have fun!"<< endl;
  while(true){
    cout << endl;
    printRoom(currentRoom,objects);
    if(currentRoom == gym){
      break;
    }
    cout << "You can enter 1 for go, 2 for pick up, 3 for drop, or 4 for quit!" << endl;
    cin >> input;
    if(input == 4){
      break;
    }
    else if(input == 1){
      char diDir[20];
      int exit;
      cout << "type which exit you would like to use. Enter 1 for North, 2 for East. 3 for South, 4 for West" << endl;
      cin >> exit;
      if(exit == 1){
      	strcpy(diDir, "NORTH");
      }
      if(exit == 2){
      	strcpy(diDir, "EAST");
      }
      if(exit == 3){
	strcpy(diDir, "SOUTH");
      }
      if(exit == 4){
	strcpy(diDir, "WEST");
      }
	    
      if(currentRoom->getNextRoom(diDir)!=NULL){
	currentRoom = currentRoom->getNextRoom(diDir);
      }
      else{
	cout << "this is not a valid exit" << endl;
      }
    }
    else if(input == 2){
      char in[10];
      cout << "which item will you pick up" << endl;
      cin.get(in,10);
      cin.get();
      dropAddItem(in, currentRoom, objects, 1);
    }
    else if(input == 3){
      char in[10];
      cout << "which item do you want to drop" << endl;
      cin.get(in,10);
      cin.get();
      dropAddItem(in, currentRoom, objects, 2);
    }
  }
  
  return 0;
}

void printRoom(room* a, vector<item*> b){

  char display[150];
  strcpy(display,(a->getDes()));
  cout << display << endl;
  a->printTheItems();
  cout << "There are exits:" << endl;
  a->printTheExits();
  cout << "Your inventory has:" << endl;
  printObjects(b);
  cout << endl;
}
void dropAddItem(char* iName, room* currentRoom, vector<item*> &objectss, int addOrDrop){

	if(addOrDrop == 1){
		objectss.push_back(currentRoom->getItem(iName));
    		currentRoom->removeItem(iName);	
	}
	if(addOrDrop == 2){
		
		 for(vector<item*>::iterator it=objectss.begin(); it!=objectss.end(); it++){
   		 	char* currentL = (*it)->getName(); 
		 	if(strcmp(iName,currentL)==0){
     		 	currentRoom->addItem(*it);
			    objectss.erase(it);
		    	break;
		    }
		}
	}
}

void printObjects(vector<item*> objects){
  for(vector<item*>::iterator it=objects.begin(); it!=objects.end(); it++){
    cout << (*it)->getName() << "  ";
  }
}
