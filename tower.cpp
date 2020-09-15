#include "tower.hpp"

Tower::Tower(){
    roomName = "THRONE";
    mapName = "the Throne Room";
    index = 12;
}

void Tower::enterDescription(bool v){
	if(v){
		text->print("You are standing in a wide, circular room. Unlike the rest of the castle,\n"
		"this room is in pristine condition. Fine, plush rugs line the floors. The King's banners\n"
		"decorate the walls. And a royal " + text->changeColor("throne", "F") + " sits at the edge, overseeing the realm.\n"
		"The only blemish is a patched up window, with burn marks on the wall overseeing the river.\n"
		"The hint of a smile creeps onto your face.\n"
		"So still you almost missed him, the " + text->changeColor("demon", "F") + " stands with his back against you, facing out towards the realm.\n"
		"A cold, terrible laugh fills the room.\n", 1);
	}
	else{
		text->print("You are standing in a wide, circular room. Unlike the rest of the castle,\n"
		"this room is in pristine condition. Fine, plush rugs line the floors. The King's banners\n"
		"decorate the walls. And a royal " + text->changeColor("throne", "F") + " sits at the edge, overseeing the realm.\n"
		"The only blemish is a patched up window, with burn marks on the wall overseeing the river.\n"
		"The hint of a smile creeps onto your face.\n"
		"So still you almost missed him, the " + text->changeColor("demon", "F") + " stands with his back against you, facing out towards the realm.\n"
		"A cold, terrible laugh fills the room.\n", 1);
	}
	bag->inArea();
} 

void Tower::exitDescription(bool e){}

void Tower::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){}

void Tower::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){}

void Tower::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){}

void Tower::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {}

void Tower::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {}

void Tower::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){}

void Tower::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){}

void Tower::transition(bool v){
	if(v){
		
	}
	else{
		
	}
}

void Tower::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]){}

