#include "item.hpp"

Item::Item(std::string name, std::string desc, int idx){
    featureName = name;
	description = desc;
    index = idx;
}

Item::Item() {}

std::string Item::getName(){
    return featureName;
}

void Item::setDescription(std::string d){
    description = d;
}

std::string Item::getDescription() {
	return description;
}

int Item::getIndex(){
    return index; 
}
