// Bag data structure borrowed from: https://www.austincc.edu/akochis/cosc1320/bag.htm
#ifndef BAG
#define BAG
#include "item.hpp"
#include "textFormatter.hpp"
#include <iostream>
typedef Item bag_type;

class Bag {
private:
	int count;
	int	bagSize;
	bag_type *data;
public:
	Bag(int);
	~Bag();
    TextFormatter *text;
	bool insert(bag_type*);  // Put a member in the bag
	bool remove(bag_type*);  // remove a member from the bag
	int getCount();            // number of members in bag
	void clear();           // remove all members from bag
	bool inBag(std::string value);   // is a member in the bag?
	Item getFeature(std::string value); //Returns a feature from the bag 
	int howMany(bag_type*); // how many member in bag.
	void display(); // Displays all items and descriptions
    std::string printIndex();
	bool bagFull();	//Checks if the bag is full
    void inArea();
};
#endif
