//Jyotsna Tera
//ZUUL Game - Explore the school, pick up, and drop items.

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

//function prototypes
void printObjects(vector<item*> objects);
void dropAddItem(char* iName, room* currentRoom, vector<item*> &objectss, int addOrDrop);
void printRoom(room* a, vector<item*> b);

int main(){
  //initializing vectors
  vector<item*> objects;
  vector<room*> rooms;
  
  //setting the directions
  char N[10] = "NORTH";
  char E[10] = "EAST";
  char S[10] = "SOUTH";
  char W[10] = "WEST";
	
  //creating the rooms and the items in the room  
  char itemm[200] = " Paper Towel - 1";
  char label[200] = "French Class";
  char des[200] = "Bonjour! You are in the French Class... Yayyy!!";
  room* frenchclass = new room(label, des);

  strcpy(label,"bathroom");
  strcpy(des,"You are now in the cleanest bathroom");
  room* bathroom = new room(label,des);
  item* papertowel = new item(itemm);
  bathroom->addItem(papertowel);
  
  strcpy(label,"library");
  strcpy(itemm, "book -2");
  strcpy(des,"Shh... everyone is studying in thr library");
  room* library = new room(label,des);
  item* book = new item(itemm);
  library->addItem(book);
  
  strcpy(label,"Bio Class");
  strcpy(itemm, "microscope - 3");
  strcpy(des,"Ohh is that connective tissue I see under the microscope in the Bio Class");
  room* bioclass = new room(label,des);
  item* microscope = new item(itemm);
  bioclass->addItem(microscope);
  
  strcpy(label,"Computer Class");
  strcpy(itemm, "computer - 4");
  strcpy(des,"lets program zuul in the computer lab");
  room* computerclass = new room(label,des);
  item* computer = new item(itemm);
  computerclass->addItem(computer);
  
  strcpy(label,"Drama Room");
  strcpy(itemm, "costumes - 5");
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
  
 //adding neighbrs of the room
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
  
  //adding rooms to vector
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
  
 //game starts in lit class
  room* currentRoom = litclass;
  int input;
  //welcome
  cout << "Hi, this is the game ZUUL. You can go to a room, pick an item, drop an item, or quit the game. Have fun!"<< endl;
  while(true){
    cout << endl;
    printRoom(currentRoom,objects);
    //game will continue unitl you reach the gym
    if(currentRoom == gym){
      cout << "u are at the gym! u win!!"
      break;
    }
    //asks the user for what to do
    cout << "You can enter 1 for go, 2 for pick up, 3 for drop, or 4 for quit!" << endl;
    cin >> input;
    //will quit game if input = 4
    if(input == 4){
      break;
    }
    //moving to another room
    else if(input == 1){
      char diDir[20];
      int exit;
      //asking which direction to move in
      cout << "which exit?. Enter 1 for North, 2 for East. 3 for South, 4 for West" << endl;
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
	
      //chnages current room to the next room	    
      if(currentRoom->getNextRoom(diDir)!=NULL){
	currentRoom = currentRoom->getNextRoom(diDir);
      }
      else{
	cout << "not a valid exit" << endl;
      }
    }
    //picking up items
    else if(input == 2){
      int choice;
      char in[100];
      cout << "which item will you pick up. enter the number associated with the item" << endl;
      cin >> choice;
      if(choice == 1){
      	strcpy(in, "Paper Towel - 1");
      }
      if(choice == 2){
      	strcpy(in, "book -2");
      }
      if(choice == 3){
      	strcpy(in, "microscope - 3");
      }
      if(choice == 4){
      	strcpy(in, "computer - 4");
      }
      if(choice == 5){
      	strcpy(in, "costumes - 5");
      }
      cout<<"working1"<<endl;
      dropAddItem(in, currentRoom, objects, 1);
      cout<<"working2"<<endl;
    }
    //dropping items
    else if(input == 3){
      int choice;
      char in[100];
      cout << "which item will you pick up. enter the number associated with the item" << endl;
      cin >> choice;
      if(choice == 1){
      	strcpy(in, "Paper Towel - 1");
      }
      if(choice == 2){
      	strcpy(in, "book -2");
      }
      if(choice == 3){
      	strcpy(in, "microscope - 3");
      }
      if(choice == 4){
      	strcpy(in, "computer - 4");
      }
      if(choice == 5){
      	strcpy(in, "costumes - 5");
      }
      cout<<"working1"<<endl;
      dropAddItem(in, currentRoom, objects, 2);
      cout<<"working2"<<endl;
    }
  }
  
  return 0;
}

//will print the current room, decription, and inventory
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
//adds item to inventory or drops item
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

//prints all the objects
void printObjects(vector<item*> objects){
  for(vector<item*>::iterator it=objects.begin(); it!=objects.end(); it++){
    cout << (*it)->getName() << "  ";
  }
}
