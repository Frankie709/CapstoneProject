#include "river.hpp"

River::River(){
    roomName = "RIVER";
	mapName = "the Zemya river";
	feature1 = "BANK";
	feature2 = "BOAT";
    index = 4;
} 

void River::enterDescription(bool v) {
	if (v) {
		text->print("The " + text->changeColor("boat", "F") + " lays on the shore of the poisoned river,\n"
        "and you can see to the opposite " + text->changeColor("bank", "F") + " from where you stand.\n"
		"To the West is the path back to " + text->changeColor("Holmhaven", "R") + ",\n"
        "and to the South is a wide strech of grass leading into a " + text->changeColor("Valley", "R") + ".\n", 1);
	}
	else {
		text->print("You can hear the sand crunch underneath your boot, as it extends to the shores of the river.\n"
        "Rushing water flows before you, however, you notice the water has a greenish hue and foul odor coming from it.\n"
        "Poisoned.\n"
		"There is a " + text->changeColor("boat", "F") + " laying on the shore, but no oars in sight.\n"
        "You can see the opposite " + text->changeColor("bank", "F") + " of the river from where you stand,\n"
        "and there looks to be some kind of disturbance there.\n"
		"To the West is the path back to " + text->changeColor("Holmhaven", "R") + ",\n"
        "and to the South is a wide strech of grass leading into a " + text->changeColor("Valley", "R") + ".\n", 1);
	}
	bag->inArea();
}

void River::exitDescription(bool e) {
	if (e) {
		text->print("You decide to leave the " + text->changeColor("Zemya River", "R") + " in search for answers elsewhere.\n", 1);
		
	}
	else {
		text->print("You came to the river looking for answers, but all it's done is leave you with more questions.\n"
		"You square your shoulders, and leave the " + text->changeColor("Zemya River", "R") + " behind to continue with your journey.\n", 1);
	}
}

//Bank
void River::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    //If bank is looked at
    if (verb == "LOOK" || verb == "GO"){
        // If sword hasn't been picked up
        if (!getItemInteraction(0)){
            text->print("You look at the raging Zemya river. The water is brackish and smells \n"
            "of sulfur. As you look across the water to the opposite river " + text->changeColor("bank", "F") + ", a glint catches your eye\n"
            "You can sense that whatever it is, it is important to you. However, the current is too strong to "
            "make it across. \n", 1);
        }
        else {
            text->print("You look back across the " + text->changeColor("bank", "F") + " to where the " + text->changeColor("boat", "F") + " was. Your journey was worth it.\n", 1);
        }
    } 
    else if (verb == "TOUCH"){
        text->print("You touch the brackish water and slime gets all over your hand.\n", 1);
    }
    else if (verb == "READ"){
        text->print("There is nothing to read in the river.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You hit the water and some splashes up and gets in your eyes, causing you to lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 5);
    }
    else if (verb == "TALK"){
        text->print("There is no one to talk to.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("You can't give the river anything.\n", 1);
    }
    else if (verb == "USE"){
        text->print("You can't use anything here.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You cannont push the massive river.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit by the river " + text->changeColor("bank", "F") + ", wondering who you are.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You foolishly decide to swim in the river. This is where you were found half dead after all. You jump in \n"
        "and immediately regret it. The polluted water saps away your health as you race back to shore. Your health lessens.\n", 1);
        hero->setHealth(hero->getHealth()-20);
    }
    else if (verb == "CLIMB"){
        text->print("You climb down the " + text->changeColor("bank", "F") + ", going closer to the river. The sulfur smell gives you a headache. \n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

//Boat
void River::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    //If boat is looked at
	if (verb == "LOOK" || verb == "GO"){
        //If you have an oar
        if (!hero->bag->inBag("OAR")){
            text->print("You look at the small " + text->changeColor("boat", "F") + ". It is rusty but looks like it could still be \n"
            "used, if you had something to direct it through the raging river. \n", 1);
        } else {
            text->print("You look at the " + text->changeColor("boat", "F") + ". Could your oar help you make it across the raging \n"
            "river? \n", 1);
        }
        //If you use the boat
    } else if (verb == "USE" || verb == "TOUCH" || verb == "GIVE" || verb == "SIT" || verb == "SWIM" || verb == "PUSH"){
        // If you have the oar
        if (hero->bag->inBag("OAR")){
            // If you haven't gotten the sword
            if (!getItemInteraction(0)){
                // If your bag is not full. Get sword and add it to your bag
                if (!hero->bag->bagFull()){
                    text->print("You grab the rusty " + text->changeColor("boat", "F") + " and bring it to the " + text->changeColor("bank", "F") + ". The rapids start to pull at it\n"
                    "instantly. The pull of the object is too strong to not try for it. You use the oar and make your way across the river.\n"
                    "Water splashes on your skin and you can feel the poisoned water burn your skin. \nAs you reach the opposite " + text->changeColor("bank", "F") + " you see a " + text->changeColor("sword", "I") + ".\n"
                    "You throw your hand in the water, burning you the longer you stay down there. You dig around and make contact with the pommel of the sword,\n"
                    "and grasp it tightly, and pull it out. As you stare at the sword, recognition passes over you, and a brief memory of falling from a great height comes to you.\n"
                    "Lost in your thoughts, you make your way back to the shore.\n", 1);
                    hero->bag->insert(itemArr[1]);
                    setItemInteraction(0, true);
                //Bag is full
                } else {
                    text->print("You feel the object across the river calling for you, but your bag is full. You should\n"
                    "drop something before you make this dangerous journey.\n", 1);
                }
            } else {
                text->print("You already have the " + text->changeColor("sword", "I") + ", so it would be foolish to go out on the water again.\n", 1);
            }
        } else {
            text->print("You have nothing to use steer the " + text->changeColor("boat", "F") + ". The river is too strong.\n", 1);
        }
    }
    else if (verb == "READ"){
        text->print("The " + text->changeColor("boat", "F") + " says 'Rachel' on the side. You wonder about her life.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You hit the " + text->changeColor("boat", "F") + ". It may be old but it is sturdy.\n", 1);
    }
    else if (verb == "TALK"){
        text->print("No need to talk to the " + text->changeColor("boat", "F") + ".\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb on the " + text->changeColor("boat", "F") + ". It is stury and can hold your weight. That is a good sign.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

void River::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
    //Actions with items in room
	if (bag->inBag(itemName)) {
		if (verb == "LOOK") {
			//Get temp copy of item feature
			Item temp = bag->getFeature(itemName);
			text->print(text->firstLetterUpper(temp.getName()) + ": " + temp.getDescription() + ".\n", 1);
		}
		else if (verb == "TAKE") {
			//Check if item will fit in bag
			if (!hero->bag->bagFull()) {
				//Get temp copy of feature we are looking for
				Item temp = bag->getFeature(itemName);
				//Pick up item
				exchangeItem(hero->bag, bag, &temp);
				text->print("You pick up the " + text->toLowerCase(itemName) + " and put it in your bag.\n", 1);
			}
			else {
				text->print("No room in your bag to add the " + text->toLowerCase(itemName) + ".\n",1);
			}
		}     
	}
    //Actions with items in hero's bag

    //Look at item in bag
    //Look at an item in your bag
    else if (verb == "LOOK"){
        if (hero->bag->inBag(itemName)){
            //Get temp copy of item feature
			Item temp = hero->bag->getFeature(itemName);
			text->print(text->firstLetterUpper(temp.getName()) + ": " + temp.getDescription() + ".\n", 1);
        }
    }
	//Drop item
	else if (verb == "DROP") {
		//Check if item is in user bag 
		if (hero->bag->inBag(itemName)) {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
            if (itemName == "WATER") {
                hero->bag->remove(itemArr[11]);
            } else {
			    exchangeItem(bag, hero->bag, &temp);
            }
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the river " + text->changeColor("bank", "F") + ".\n", 1);
		}
		else {
			text->print("You cannot drop the " + text->toLowerCase(itemName) + " as it is not in your bag.\n", 1);
		}
	}
    else if (verb == "THROW") {
        //Check if item is in user bag 
		if (hero->bag->inBag(itemName)) {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item on room floor. If water it goes away
            if (itemName == "WATER") {
                hero->bag->remove(itemArr[11]);
                text->print("You throw the water on the ground.\n", 1);
            }
             else {
			    exchangeItem(bag, hero->bag, &temp);
                text->print("You throw the " + text->toLowerCase(itemName) + " onto the ground.\n", 1);
            }
		}
		else {
			text->print("You cannot throw what you do not have.\n", 1);
		}
    }
    else if (verb == "DRINK"){
        //Check if item is in user bag 
		if (hero->bag->inBag(itemName)) {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drink 
            if (itemName == "WATER") {
                hero->bag->remove(itemArr[11]);
                text->print("You drink the spring water. You feel refreshed and gain some health.\n", 1);
                hero->gainHealth();
            } else if (itemName == "ALE") {
			    text->print("You grab Boyce's ale. You probably shouldn't drink it, but you take a sip. \n"
                "He'll never notice...\n", 1);
            } else if (itemName == "CHEMICALS"){
                text->print("You drink the corrosive chemicals and die instantly.\n", 1);
                hero->setHealth(0);
            } else {
                text->print("You cannot drink the " + text->toLowerCase(itemName) + ".\n", 1);
            }
		}
		else {
			text->print("You cannot drink anything in your bag.\n", 1);
		}
    }
    else if (verb == "EAT"){
        if (hero->bag->inBag(itemName)){
            if (itemName == "JERKY"){
                text->print("You bite down on the jerky but it is rock solid. You cannot eat it.\n"
                "You feel swindled by the merchant\n", 1);
            } else if (itemName == "MUSHROOMS"){
                text->print("You eat the damp mushrooms. You gain some health points. \n", 1);
                hero->gainHealth();
                hero->bag->remove(itemArr[3]);
            } else {
                text->print("You can't eat that.\n", 1);
            }
        }
        else if (hero->bag->getCount() == 0) {
            text->print("You have nothing in your bag.\n", 1);
        } else {
            text->print("You shouldn't be eating anything in your bag.\n", 1);
        }
    }
    else if (verb == "USE") {
        if (hero->bag->inBag(itemName)){
            if (itemName == "OAR"){
                if (!getItemInteraction(0)){
                    if (!hero->bag->bagFull()){
                         text->print("You grab the rusty " + text->changeColor("boat", "F") + " and bring it to the " + text->changeColor("bank", "F") + ". The rapids start to pull at it\n"
                        "instantly. The pull of the object is too strong to not try for it. You use the oar and make your way across the river.\n"
                        "Water splashes on your skin and you can feel the poisoned water burn your skin. \nAs you reach the opposite " + text->changeColor("bank", "F") + " you see a " + text->changeColor("sword", "I") + ".\n"
                        "You throw your hand in the water, burning you the longer you stay down there. You dig around and make contact with the pommel of the sword,\n"
                        "and grasp it tightly, and pull it out. As you stare at the sword, recognition passes over you, and a brief memory of falling from a great height comes to you.\n"
                        "Lost in your thoughts, you make your way back to the shore.\n", 1);
                        hero->bag->insert(itemArr[1]);
                        setItemInteraction(0, true);
                    } else {
                        text->print("You feel the object across the river calling for you, but your bag is full. You should\n"
                        "drop something before you make this dangerous journey.\n", 1);
                    }
                } else {
                    text->print("You already have the " + text->changeColor("sword", "I") + ", so it would be foolish to go out on the water again.\n", 1);
                }
            } else {
			text->print("You cannot use that here.\n", 1);
		    }
        }  
    }
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
	
}

void River::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "UP"){
		text->print("The river rages that way. You cannot go north. \n", 1);
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("The Zemya river rages to the east. You cannot go that way.\n", 1);
	}
	else if(direction == "WEST" || direction == "HOLMHAVEN" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "VALLEY" || direction == "DOWN"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getBottom();
		roomDesc = true;
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void River::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	} 
	else if (verb == "SWIM") {
		text->print("You foolishly decide to swim in the river. This is where you were found half dead after all. You jump in \n"
		"and immediately regret it. The polluted water saps away your health as you race back to shore. Your health lessens.\n", 1);
		hero->setHealth(hero->getHealth() - 20);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void River::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void River::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void River::transition(bool v){
    if(v){
        text->print("The sound of rushing water grows louder as you arrive at the " + text->changeColor("Zemya River", "R") + ".\n", 1);
    }
    else{
        text->print("As you approach the " + text->changeColor("Zemya River", "R") + " you can't help but feel nervous.\n"
        "This is where " + text->changeColor("Linota", "F") + " said she found you. What could have\n"
        "happened to you for you to be found half dead at the river. Or better yet, what kind of person were you\n"
        "when they left you out here and no one came to look for you. Before you know it, you've stepped foot\n"
        "on the banks of the " + text->changeColor("Zemya River", "R") + ".\n", 1);
    }
}

void River::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "BANK") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the " + text->changeColor("bank", "F") + " and it washes into the river, \n"
				"adding some purity to it.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the river " + text->changeColor("bank", "F") + ".\n", 1);
			}
		}
		else if (feature == "BOAT") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the " + text->changeColor("boat", "F") + " and it pools inside.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the " + text->changeColor("boat", "F") + ".\n", 1);
			}
		}
		else {
			text->print("There is no" + text->firstLetterUpper(feature) + " around.\n", 1);
		}
	}
	else {
		text->print("You cannot drop the " + text->toLowerCase(itemName) + " as it is not in your bag.\n", 1);
	}
}