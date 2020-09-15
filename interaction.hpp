#ifndef INTERACTION_HPP
#define INTERACTION_HPP
#include <iostream>
#include "room.hpp"
#include "character.hpp"
#include "textFormatter.hpp"
#include "parser.hpp"
#include "item.hpp"

class Interaction{
    protected:
	    int flashbackCounter;
        bool fight1; 
        bool fight2; 
        bool fight3;
        bool fight4;
        bool fight5;
        bool fight6;
    public:
        TextFormatter *text;
        Parser *parser;
        Interaction();
        ~Interaction();
        std::string intro();
        bool storyElements(Room *&, Room* [], Item* [], Character*&, Character*&, Character*&,
		Character*&, Character*&, Character*&, Character*&,bool&, bool&);
	    bool fight(Character *&hero, Character *&enemy);
		void printFlashback(Room *&curRoom, Character *&hero);
		int getFlashbackCounter();
        void setFlashbackCounter(int);
		void increaseFlashback();
        bool mountainFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool&);
        bool caveFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[]);
        bool labFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool&);
        bool terraceFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool&);
        bool diningHallFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[]);
        bool finalFight(Room *&curRoom, Character *&hero, Character *&demon, Room* roomArr[], Item* itemArr[], bool&);
        void epilogue(Character *&hero);

};
#endif
