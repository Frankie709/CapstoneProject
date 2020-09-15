#include "minion.hpp"

//Constructor sets Minion object's health to 100, and name set to passed in parameter
Minion::Minion(std::string setName){
    health = 100;
    armor = 0;
    name = setName;
}

//increaseHealth() increases the Minion's health by passed in parameter
void Minion::increaseHealth(int h){
    health = health + h;
}

//decreaseHealth() decreases the Demon's health by passed in parameter
void Minion::decreaseHealth(int d){
    health = health - d;
}

//minion attack1 has a 80% chance of striking target. If it does strike, the 
//attack power is the sum of 2 6 sided dice rolls
int Minion::attack1()
{
	text->print(this->getName() + " flexed its hand, and attacked you with its"
	    " sharp claws!!\n", 1);
	int attackChance = rand() % 5 + 1;
	if(attackChance > 1)
	{
		int die1 = rand() % 7 + 1;
		int die2 = rand() % 7 + 1;
		int totalAttack = die1 + die2;
		text->print( this->getName() + "'s total attack power is " + std::to_string(totalAttack) + "!\n", 1);
		return totalAttack;
	}
	else
	{
		text->print( this->getName() + "'s attack missed you!\n", 1);
		return 0;
	}
}

//minion attack2 has a 80% chance of striking target. If it strikes, the attack
//power is the sum of 2 8 sided die rolls
int Minion::attack2()
{
	text->print(this->getName() + " created a Shadow Ball, and launched an orb of Dark Energy at you!\n", 1);
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

//minion defend function 
// 1 3 sided die will be used to gather up defense strenght, 
// Total armor level will be added to this
void Minion::defend(int damage)
{
	int die1 = rand() % 3 + 1;
	int totalDefense = die1 + armor;
	int totalDamage = damage - totalDefense;
    //Hero's attack missed
	if(damage == 0)
	{	
	}
	else if(totalDamage <= 0)
	{
		text->print(this->getName() + " gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		text->print(this->getName() + " was able to absorb the attack. No damage was done.\n", 1);
	}
	else
	{
		decreaseHealth(totalDamage);
		text->print(this->getName() + " gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		text->print(this->getName() + " was hit by your attack!\n", 1); 
		text->print(this->getName() + "'s life force was decreased to " + std::to_string(this->getHealth()) + "!\n", 1);
	}
}
