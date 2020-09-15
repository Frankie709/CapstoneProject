#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
#include <iostream>
#include "character.hpp"
#include "item.hpp"
#include "bag.hpp"
#include "textFormatter.hpp"
class Room		//Will be base class
{
protected:
	std::string roomName; 
    std::string mapName;
    std::string feature1;
    std::string feature2;
    int index;
	bool visited;		//Will keep track if room has been visited before
	bool exited;		//If room has been exited before
	Room *top;			//Link Room to those around it 
	Room *left;
	Room *right;
	Room *bottom;
    bool roomChanges[2];
    bool canEnter;
    bool itemInteraction[10]; 
    bool feature1Interaction[5];
    bool feature2Interaction[5];
public:
    Room();
	~Room();
    virtual void secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* []) = 0;
    virtual void secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* []) = 0;
	virtual void enterDescription(bool) = 0; 
	virtual void exitDescription(bool) = 0;
	virtual void interactFeature1(std::string verb, Character *& hero, Item* [], Room* []) = 0;
    virtual void interactFeature2(std::string verb, Character *& hero, Item* [], Room* []) = 0;
	virtual void interactItem(std::string verb, std::string itm, Character *& hero, Item* [], Room* []) = 0;
	virtual void interactVerb(Room*&, Room*[], std::string verb, Character *&hero) = 0;
	virtual void changeRoom(Room *&,std::string, bool&, Character *&hero, Room* []) = 0;
	virtual void itemFeatureDrop(std::string, std::string, std::string, Character *&hero, Item*[], Room* roomArr[]) = 0;
    virtual void transition(bool) = 0;
	//Inherited functions
    Bag *bag; // Bag to hold items for room
    TextFormatter *text;
    bool getCanEnter();
    void setCanEnter(bool);
    bool getRoomChanges(int);
    void setRoomChanges(int, bool);
    int getIndex();
    bool getFeature1Interaction(int);
    bool getFeature2Interaction(int);
    bool getItemInteraction(int);
    void setFeature1Interaction(int, bool);
    void setFeature2Interaction(int, bool);
    void setItemInteraction(int, bool);
    std::string getFeature1();
    std::string getFeature2();
	std::string getRoomName(); // returns room name
    std::string getMapName(); // Name for map print out
	bool getVisited(); // returns true or false if room has been visited
	bool getExited();
	void setVisited(bool); //Switches to true if visited
	void setExited(bool);
	Room* getTop();
	Room* getLeft();
	Room* getRight();
	Room* getBottom();
	void setTop(Room*);
	void setLeft(Room*);
	void setRight(Room*);
	void setBottom(Room*);
	void exchangeItem(Bag *&, Bag *&, Item*);
};
#endif