#include "demon.hpp"

//Constructor sets Demon object's health to 100, and name set to passed in parameter
Demon::Demon(std::string setName){
    health = 100;
    armor = 0;
    name = setName;
}

//increaseHealth() increases the Demon's health by passed in parameter
void Demon::increaseHealth(int h){
    health = health + h;
}

//decreaseHealth() decreases the Demon's health by passed in parameter
void Demon::decreaseHealth(int d){
    health = health - d;
}

//demon attack1 has a 80% chance of striking target. If it does strike, the 
//attack power is the sum of 2 8 sided dice rolls
int Demon::attack1()
{
	text->print(this->getName() + " released a Dark Pulse of energy and shot it straight at you!\n", 1);
	int attackChance = rand() % 5 + 1;
	if(attackChance > 1)
	{
		int die1 = rand() % 8 + 1;
		int die2 = rand() % 8 + 1;
		int totalAttack = die1 + die2;
		text->print(this->getName() + "'s total attack power is " + std::to_string(totalAttack) + "!\n", 1);
		return totalAttack;
	}
	else
	{
		text->print(this->getName() + "'s attack missed you!\n", 1);
		return 0;
	}
}

//Demon attack2 has a 80% chance of striking target. If it strikes, the attack
//power is the sum of 2 10 sided die rolls
int Demon::attack2()
{
	text->print(this->getName() + " created a Dark Void meant to drain your energy!\n", 1); 
	int attackChance = rand() % 5 + 1;
	if(attackChance < 2)
	{
		text->print(this->getName() + "'s attack missed you!\n", 1);
		return 0;
	}
	else
	{
		int die1 = rand() % 10 + 2;
		int die2 = rand() % 10 + 2;
		int totalAttack = die1 + die2;
		text->print(this->getName() + "'s total attack power is " + std::to_string(totalAttack) + "!\n", 1);
		return totalAttack;
	}
}

//Demon defend function 
// 1 4 sided die will be used to gather up defense strenght, 
// Total armor level will be added to this
void Demon::defend(int damage)
{
	int die1 = rand() % 4 + 1;
	int totalDefense = die1 + armor;
	int totalDamage = damage - totalDefense;
    //Hero's attack missed
	if(damage == 0)
	{	
	}
	else if(totalDamage <= 0)
	{
		text->print(this->getName() + " gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		text->print(this->getName() + " was able to absorb the attack. No damage was done to it.\n", 1); 
	}
	else
	{
		decreaseHealth(totalDamage);
		text->print(this->getName() + " gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		text->print(this->getName() + " was hit by your attack!\n", 1);
		text->print(this->getName() + "'s life force was decreased to " + std::to_string(this->getHealth()) + "!\n", 1);
	}
}
