#include "castle.hpp"

Castle::Castle(){
	roomName = "CASTLE";
    mapName = "the Castle grounds";
	feature1 = "WALL";
	feature2 = "TOWER";
    index = 10;
}

void Castle::enterDescription(bool v) {
	if(v){
		text->print("You see the stone " + text->changeColor("wall", "F") + " still has its gates shut.\n"
		"The " + text->changeColor("tower", "F") + " keeps its watch over the " + text->changeColor("castle grounds", "R") + "./n"
		"The " + text->changeColor("Black Forest", "R") + " lays to your North.\n", 1);
	}
	else{
		text->print("You see a 20 foot stone " + text->changeColor("wall", "F") + " before you, its gates firmly shut.\n"
		"Soldiers with blood red eyes patrol the parapet, weapons at their side.\n"
		"You see the massive castle just behind the "+ text->changeColor("wall", "F") + ". It's windows broken and blood stained.\n"
		"A tall " + text->changeColor("tower", "F") + " oversees the castle. You can see a shadowy figure at the top.\n"
		"The " + text->changeColor("Black Forest", "R") + " encirlces the castle to the North.\n", 1);
	}
	bag->inArea();
} 

void Castle::exitDescription(bool e){
	if(e){
		text->print("You back away from the " + text->changeColor("castle grounds", "F") + " thinking of a way to get in.\n", 1);
	}
	else{
		text->print("Terrified of what you just witnessed, you slowly back away from the " + text->changeColor("castle grounds", "R") + ".\n", 1);
	}
}

//Castle wall
void Castle::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if (verb == "LOOK" || verb == "GO"){
        text->print("You stare up at the fortified castle " + text->changeColor("wall", "F") + ". You keep hidden as you scan the area. You see armed sentries\n"
        "patrolling the area. In the middle there is a massive gate. You realize it is impossible to get into the castle this way.\n"
        "You must find another way into the castle!\n", 1);
    }
    else if (verb == "TOUCH"){
		text->print("You try to get close to the " + text->changeColor("wall", "F") + " but there are too many guards\n"
		"and you can't get close.\n", 1);
    }
    else if (verb == "READ"){
		text->print("You look at the " + text->changeColor("wall", "F") + " and see that there is writing on it.\n"
		"It says, " + text->changeColor("We walk in the Light, in the face of Darkness", "F") + ".\n", 1);

    }
    else if (verb == "HIT"){
		text->print("You can't get close enough to hit the " + text->changeColor("wall", "F") + ".\n", 1);

    }
    else if (verb == "TALK"){
		text->print("There is no one to talk to. At least, No one that doesn't want to kill you..\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("There is nothing to give the " + text->changeColor("wall", "F") + ".\n", 1);
    }
    else if (verb == "USE"){
		text->print("You can't use it.\n", 1);
    }
    else if (verb == "PUSH"){
		text->print("You can't get close enough to push the " + text->changeColor("wall", "F") + ".\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit down, and think there has to be another way to enter the castle.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("There is no where to swim.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("You think to climb the " + text->changeColor("wall", "F") + ", but there are too many gaurds around.\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

//Tower
void Castle::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK" || verb == "GO") {
        text->print("You look up at the massive " + text->changeColor("tower", "F") + " which is \n"
        "dominating the sky. Lightning flashes around the tower, casting the what appears to be the king's \n"
        "silhouette across the landscape.\n", 1);
    } 
    else if (verb == "TOUCH"){
		text->print("The " + text->changeColor("tower", "F") + " is to far to touch.\n", 1);

    }
    else if (verb == "READ"){
		text->print("There is nothing to read on the " + text->changeColor("tower", "F") + ".\n", 1);

    }
    else if (verb == "HIT"){
		text->print("The " + text->changeColor("tower", "F") + " is to far to hit.\n", 1);
    }
    else if (verb == "TALK"){
		text->print("You are sure the " + text->changeColor("tower", "F") + " will not talk back to you.\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("There is nothing to give to the " + text->changeColor("tower", "F") + ".\n", 1);
    }
    else if (verb == "USE"){
		text->print("There is no use for the " + text->changeColor("tower", "F") + ".\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("The " + text->changeColor("tower", "F") + " is to far away to push.\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit and wonder what is going on inside the " + text->changeColor("tower", "F") + ".\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("Swimming should not be a priority when you are surrounded by enemies.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("Climbing the " + text->changeColor("tower", "F") + " would be a good idea.. If you could get closer without being killed..\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}



void Castle::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the ground of the castle.\n", 1);
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
            } 
            else if (itemName == "MUSHROOMS"){
                text->print("You eat the damp mushrooms. You gain some health points. \n", 1);
                hero->gainHealth();
				hero->bag->remove(itemArr[3]);
            }
            else {
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

void Castle::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "FOREST" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if (direction == "EAST" || direction == "RIGHT") {
		text->print("Impassable mountains lie to the east. You cannot go that way.\n",1);
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("Armed sentries are that way. You cannot go west.\n",1);
	}
	else if(direction == "SOUTH" || direction == "DOWN"){
		text->print("An impenetrable wall guards the castle, you cannot go that way.\n",1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Castle::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
    else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Castle::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){

}

void Castle::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){

}


void Castle::transition(bool v){
	if(v){
		text->print("Wary of the danger ahead, you sneak from tree to boulder until you arrive at the " + text->changeColor("castle grounds", "R") + "./n", 1);
	}
	else{
		text->print("As you approach the " + text->changeColor("castle grounds", "R") + ", you hear demonic voices, and quickly hide behind a tree.\n"
		"You stealthily creep from tree to boulder, until the " + text->changeColor("castle", "R") + " stands before you.\n", 1);
	}
}

void Castle::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "TOWER") {
			text->print("You cannot go near the tower.\n", 1);
		}
		else if (feature == "WALL") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the wall and it pours off it.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the wall.\n", 1);
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