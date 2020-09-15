#include "lab.hpp"

Lab::Lab(){
    roomName = "LAB";
	mapName = "the Laboratory";
	feature1 = "EQUIPMENT";
	feature2 = "MUTANT";
    index = 15;
}

void Lab::enterDescription(bool v){
	if(v){
		text->print("You are in a bright room. The light shines on the rusted " + text->changeColor("equipment", "F") + "\n"
		"hanging on the wall. The " + text->changeColor("mutant", "F") + " lays on the stone slab.\n"
		"The door to the North is the only exit.\n", 1);

	}
	else{
		text->print("You are standing in a brightly lit room, with all kinds of bloody and rusted\n"
		"medical " + text->changeColor("equipment", "F") + " hanging on the walls.\n"
		"All around the room are stone slabs. Your stomach lurches as you see bodies, laying on the slabs, that \n"
		"have been torn apart, injected with unknown substance, and had demon appendages sown on to them.\n"
		"One body looks to be further experimented on than others. You can only describe it as looking like a " + text->changeColor("mutant", "F") + ".\n"
		"The only exit is the door to the North that leads to the " + text->changeColor("dungeon", "R") + ".\n", 1);
	}
	bag->inArea();
} 

void Lab::exitDescription(bool e){
	if(e){
		text->print("You yank the door open as you leave the " + text->changeColor("lab", "R") + ".\n", 1);
	}
	else{
		text->print("Tired of all the horrors these demons have created,\n"
		"you gather your courage and stride out of the " + text->changeColor("lab", "R") + ".\n", 1);
	}
}

//Equipment
void Lab::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "TOUCH" || verb == "LOOK" || verb == "GO"){
		text->print("You approach the medical " + text->changeColor("equipment", "F") + " and inspect it closely.\n"
		"The equipment is rusty and worn. It appears it has been used a lot lately.\n", 1);
    }
    else if (verb == "READ"){
		text->print("You attempt to read the labels, but the rust and blood make it illegible.\n", 1);

    }
    else if (verb == "HIT"){
		text->print("You hit the " + text->changeColor("equipment", "F") + " in anger, and cut your hand with a scalpel and you lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);

    }
    else if (verb == "TALK"){
		text->print("There is no one to talk to..\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is no one to give anything to..\n", 1);

    }
    else if (verb == "USE"){
		text->print("You attempt to use the " + text->changeColor("equipment", "F") + ", but are no medical professional,\n"
		"and don't know what you're doing.\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("You push aside some of the tools, but there is nothing else of interest.\n", 1);

    }
    else if (verb == "SIT"){
		text->print("You sit and poder what they could have been using the tools for.\n", 1);

    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("There is nothing to climb.\n", 1);
        
    }
	else{
		text->print("You can't do that.\n", 1);
	}
}

//Mutant
void Lab::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "TOUCH" || verb == "LOOK" || verb == "GO"){
		text->print("You approach the " + text->changeColor("mutant", "F") + " and inspect it closely.\n"
		"The " + text->changeColor("mutant", "F") + " looks to be an Order member. He has been injected with various liquids,\n"
		"and his body was starting to take demon characteristics.\n"
		"It appears as if his body was being prepared as a host.\n", 1);
    }
    else if (verb == "READ"){
		text->print("There is nothing to read here.\n", 1);

    }
    else if (verb == "HIT"){
		text->print("You really shouldn't be hitting victims of torture..\n", 1);

    }
    else if (verb == "TALK"){
		text->print("You lean in to the " + text->changeColor("mutant", "F") + " and swear to seek justice for him.\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is no one alive to give anything to..\n", 1);

    }
    else if (verb == "USE"){
		text->print("Hasn't the " + text->changeColor("mutant", "F") + " been used enough??.\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("You try to push the " + text->changeColor("mutant", "F") + ", but there is no response from him.\n", 1);

    }
    else if (verb == "SIT"){
		text->print("You sit and think of what they were planning on doing with the " + text->changeColor("mutant", "F") + ".\n", 1);

    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("There is nothing to climb.\n", 1);
        
    }
	else{
		text->print("You can't do that.\n", 1);
	}
}

void Lab::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
	//Items in room
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the ground.\n", 1);
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
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Lab::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "DUNGEON" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("There is nothing east of you.\n", 1);
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("There is nothing west of you.\n", 1);
	}
	else if(direction == "SOUTH" || direction == "DOWN"){
		text->print("There is nothing south of you.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Lab::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Lab::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Lab::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Lab::transition(bool v){
	if(v){
		text->print("You open the door and walk into the " + text->changeColor("lab", "R") + ".\n", 1);
	}
	else{
		
	}
}

void Lab::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "EQUIPMENT") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the equipment and it drains down to the floor.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the scientific equipment.\n", 1);
			}
		}
		else if (feature == "MUTANT") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the mutant.\n", 1);
			}
			else {

				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the mutant and it drains down to the floor.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the mutant.\n", 1);
				}
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
