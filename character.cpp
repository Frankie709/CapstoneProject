#include "character.hpp"

// Base Class constructor
Character::Character(){
    bag = new Bag(3);
    text = new TextFormatter();
    health = 0;
    armor = 0;
    fixedSword = false;
    translatedText = false;
    powerStone = false;
}


Character::~Character(){
    delete bag;
    delete text;
}

void Character::setName(std::string n){
    name = n;
}

std::string Character::getName(){
    return name;
}

void Character::setHealth(int h){
    health = h;
}

int Character::getHealth(){
    return health;
}

int Character::getArmor(){
    return armor;
}

void Character::setArmor(int a){
    armor = a;
}

int Character::attackChance(){
	int chance = rand() % 2 + 1;
	return chance;
}

 void Character::setFixedSword(bool b){
    fixedSword = b;
 }

bool Character::getFixedSword(){
    return fixedSword;
}

void Character::setTranslatedText(bool b){
    translatedText = b;
}

bool Character::getTranslatedText(){
    return translatedText;
}

void Character::setPowerStone(bool b){
    powerStone = b;
}

bool Character::getPowerStone(){
    return powerStone;
}

void Character::gainHealth(){
    this->setHealth(this->getHealth() + 10);
    if (this->getHealth() > 100){
        this->setHealth(100);
    }
}