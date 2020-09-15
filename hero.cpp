#include "hero.hpp"

//Constructor sets Hero object's health to 100, and name set to passed in parameter
Hero::Hero(){
    health = 100;
    armor = 0;
}

//increaseHealth() increases the Hero's health by passed in parameter
void Hero::increaseHealth(int h){
    health = health + h;
}

//decreaseHealth() decreases the Hero's health by passed in parameter
void Hero::decreaseHealth(int d){
    health = health - d;
}

// Hero attack1 doesnt miss, but has low attack power, power is sum of 2, 6 sided die 
int Hero::attack1(){
    text->print("You slash the enemy with your gleaming sword!!\n", 1); 
	int die1 = rand() % 17 + 1;
	int die2 = rand() % 22 + 1;
	int totalAttack = die1 + die2;
	text->print("Your total attack power is " + std::to_string(totalAttack) + "!\n", 1);
	return totalAttack;
}

//hero attack2 has a 60% chance of striking target. If it strikes, the attack
//power is the sum of 2 10 sided die rolls
int Hero::attack2(){
    text->print("You used Lumen and launched a fire ball at the enemy!\n", 1);
	int attackChance = rand() % 5 + 1;
	if(attackChance < 3)
	{
		text->print("Your attack missed the enemy!\n", 1);
		return 0;
	}
	else
	{
		int die1 = rand() % 20 + 2;
		int die2 = rand() % 20 + 2;
		int totalAttack = die1 + die2;
		text->print("Your total attack damage is " + std::to_string(totalAttack) + "!\n", 1);
		return totalAttack;
	}

}

//Hero Defend function
// 1 3 sided die will be used to gather up defense strenght, 
// Total armor level will be added to this
void Hero::defend(int damage){
    int die1 = rand() % 3 + 1;
	int totalDefense = die1 + armor;
	int totalDamage = damage - totalDefense;
    //Attack missed, nothing to display
	if(damage == 0)
	{
	}
    //TotalDamage <= 0, hero was able to absorb attack
	else if(totalDamage <= 0)
	{
		text->print("You gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		text->print("You were able to absorb the attack. You sustained no damage.\n", 1);
	}
    //Attack hit hero
	else
	{
		text->print("You gathered a defense strength of " + std::to_string(totalDefense) + "!\n", 1);
		decreaseHealth(totalDamage);
		text->print("You were hit by the enemy's attack!\n", 1);
		text->print("Your life force was decreased to " + std::to_string(getHealth()) + "!\n", 1);
	}
}
