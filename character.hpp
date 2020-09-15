#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include "bag.hpp"
#include "textFormatter.hpp"

//Character class declaration
class Character{
    protected:
        std::string name;
        int health;
        int armor;
        bool fixedSword;
        bool translatedText;
        bool powerStone;
    public:
        Character();
        ~Character();
        Bag *bag;
        TextFormatter *text;
        void gainHealth();
        std::string getName();
        void setFixedSword(bool b);
        bool getFixedSword();
        void setTranslatedText(bool b);
        bool getTranslatedText();
        void setPowerStone(bool b);
        bool getPowerStone();
        void setName(std::string);
        int getHealth();
        void setHealth(int);
        int getArmor();
        void setArmor(int);
        int attackChance(); //Used in fights
        virtual void increaseHealth(int health) = 0;        // Declared as pure virtual function
        virtual void decreaseHealth(int damage) = 0;        // Declared as pure virtual function
        virtual int attack1() = 0;
        virtual int attack2() = 0;
        virtual void defend(int damage) = 0;
};
#endif