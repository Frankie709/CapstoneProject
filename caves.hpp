#ifndef CAVES_HPP
#define CAVES_HPP
#include "room.hpp"
class Caves : public Room{
	public:
		Caves();
        void transition(bool v);
	    void enterDescription(bool v);
		void exitDescription(bool e);
		void interactFeature1(std::string verb, Character *&hero, Item *itemArr[], Room* roomArr[]);
        void interactFeature2(std::string verb, Character *&hero, Item *itemArr[], Room* roomArr[]);
		void interactItem(std::string verb, std::string itemName, Character *&hero, Item *itemArr[], Room* roomArr[]);
		void interactVerb(Room *&curRoom, Room *roomArr[], std::string verb, Character *&hero);
		void changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]);
        void secondFeature1Interaction(std::string verb, Character *&hero, Item *itemArr[], Room* roomArr[]);
        void secondFeature2Interaction(std::string verb, Character *&hero, Item *itemArr[], Room* roomArr[]);
		void itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item* itemArr[], Room* roomArr[]);
};
#endif

