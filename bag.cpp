#include "bag.hpp"

Bag::Bag(int s) {
	count = 0;
	bagSize = s;
    text = new TextFormatter();
	data = new Item[bagSize];
}


Bag::~Bag() {
    delete text;
    if (data != NULL) {
        delete [] data;
    }
}

//Resets bag count
void Bag::clear() {
	count = 0;
}

//Inserts object into bag
bool Bag::insert(bag_type *value) {
	bool reply;
	if (count <bagSize) {
		data[count] = *value;
		reply = true;
		count++;
	}
	else {
		reply = false;
	}
	return reply;
}

//Checks if object is in bag
bool Bag::inBag(std::string value) {
	bool reply = false;
	int  index;
	for (index = 0; index<count && !reply; index++)
		if (data[index].getName() == value) reply = true;
	return reply;
}


Item Bag::getFeature(std::string value) {
	Item temp;
	int  index;
	for (index = 0; index<count; index++)
		if (data[index].getName() == value) {
			temp = data[index];
		}
	return temp;
}

//Returns number of an object
int Bag::howMany(bag_type *value) {
	int thisMany = 0;
	int index;
	for (index = 0; index<count; index++)
		if (data[index].getName() == value->getName()) thisMany++;
	return thisMany;
}

//Removes object from bag
bool Bag::remove(bag_type *value) {
	bool reply = false;
	int  index;
	if (howMany(value) == 0) {
		return reply;
	}
	reply = true;
	index = 0;
	while (data[index].getName() != value->getName()) {
		index++;
	}
	for (; index < count - 1; index++) {
		data[index] = data[index + 1];
	}
	count--;
}

//Returns count
int Bag::getCount() {
	return count;
}

//Displays the name and description for all items in bag
void Bag::display() {
	if (getCount() == 0) {
		text->print("There is nothing in your bag.\n", 1);
	}
	else {
		for (int i = 0; i < getCount(); i++) {
			text->print( text->firstLetterUpper(data[i].getName()) + ": " + data[i].getDescription() + "\n", 1);
		}
	}
}

void Bag::inArea(){
    int comma = getCount();
    if (getCount() == 0){
        //print nothing
    } else {
        text->print("Lastly, you see ", 1);
        for (int i = 0; i < getCount(); i++){
            if (data[i].getName() == "OAR" || data[i].getName() == "ALE"){ 
                text->print("an ", 1);
            } else if (data[i].getName() == "WATER" || data[i].getName() == "JERKY" || data[i].getName() == "GOGGLES"
            || data[i].getName() == "MUSHROOMS"){
                text->print("some ", 1);
            }
            else {
                text->print("a ", 1);
            }
            text->print(text->changeColor(text->toLowerCase(data[i].getName()), "I"), 1); 
            if (comma > 2){
                text->print(", ", 1);
            } else if (comma > 1) {
                text->print(", and ", 1);
            } 
            
        comma--;
        }
        text->print(" in the area. \n", 1);
    }
}


std::string Bag::printIndex() {
    std::string output;
	if (getCount() == 0) {
		text->print("You have nothing in your bag.\n", 1);
        return {};
	}
	else {
		for (int i = 0; i < count; i++) {
			output.append(std::to_string(data[i].getIndex()) + "\n");
		}
	}
    return output;
}





//Checks if bag is full, if it is return true, otherwise return false
bool Bag::bagFull() {
	if (count == bagSize) {
		return true;
	}
	else {
		return false;
	}
}


