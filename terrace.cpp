#include "terrace.hpp"

Terrace::Terrace(){
  roomName = "TERRACE";
	mapName = "the Terrace";
	feature1 = "RIFT";
	feature2 = "BODIES";
  index = 13;
}

void Terrace::enterDescription(bool v){
	if(v){
		text->print("The " + text->changeColor("rift", "F") + " continues to pulse and exude black smoke.\n"
		"The " + text->changeColor("bodies", "F") + " towards the side reminding you of the horrors that have taken place here.\n"
		"You see the castle " + text->changeColor("throne", "R") + " room stand menacingly to your North.\n"
		"The only other exit is back to the " + text->changeColor("bedroom", "F") + " through the door to your East.\n", 1);
	}
	else{
		text->print("You are in a wide open area atop the castle. You can hear the possessed soldiers shouting orders down below.\n"
		"You look to your left, and see what the General was guarding. A blackish-purle " + text->changeColor("rift", "F") + "\n"
		"floats in the air, exuding black vapor and electricity.\n"
		"The " + text->changeColor("rift", "F") + " seems to suck in any warmth or light that gets near it.\n"
		"Even worse, along the edge of the " + text->changeColor("terrace", "R") + " is a pile of " + text->changeColor("bodies", "F") + ".\n"
		"Some stacked together, and some strung up as a declaration to the world.\n"
		"The door to the " + text->changeColor("bedroom", "R") + " is to your East,\n"
		"and to the North, you see a path that will lead you to the castle" + text->changeColor("throne", "R") + " room.\n", 1);
	}
	bag->inArea();
} 

void Terrace::exitDescription(bool e){
	if(e){
		text->print("You leave the " + text->changeColor("terrace", "R") + " knowing you\n" 
		"are close to completing your adventure.\n", 1);
	}
	else{
		text->print("Knowing the Greater Demon will soon reach his end goal, you stride away from\n"
		"the " + text->changeColor("terrace", "R") + " to make sure he doesn't succeed.\n", 1);
		
	}
}

//Rift
void Terrace::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		text->print("You approach the " + text->changeColor("rift", "F") + " and the closer you get, the colder it gets.\n"
		"The " + text->changeColor("rift", "F") + " is pulsing with dark, cold energy.\n"
		"You get close enough that you can hear monstreous howls and screams coming from it.\n"
		"You back away slowly.\n", 1);
	}
	else if(verb == "TOUCH" || verb == "HIT"){
		if(!getFeature1Interaction(0)){
			text->print("You reach out towards the " + text->changeColor("rift", "F") + " and grab hold of the edge..\n"
			"Pain races through your entire body..\n"
			"You feel as if your soul is being sucked out..\n"
			"You summon a blast of Lumen and are able to break free.\n"
			"Trying to catch your breath, you back away from the " + text->changeColor("rift", "F") + ".\n", 1);
			setFeature1Interaction(0, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "READ"){
		text->print("There is nothing to read here.\n", 1);

    }
    else if (verb == "TALK"){
		text->print("There is no one to talk to.\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("You should not give anything to a transdimensional " + text->changeColor("rift", "F") + ".\n", 1);
    }
    else if (verb == "USE"){
		text->print("You try to close the " + text->changeColor("rift", "F") + " but can't figure out how.\n", 1);
    }
    else if (verb == "PUSH"){
		text->print("There is no way to push it.\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit and think, realizing this is how the demons and monsters are entering the realm..\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You should not try to climb the rift..\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
	
}

//Bodies
void Terrace::interactFeature2(std::string verb,  Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		if(!getFeature2Interaction(0)){
			text->print("You hesitantly approach the bodies.\n"
		"Bodies are stacked into a pile. Some are strung up on on poles, a declaration to the world of the horror that has happened here.\n"
		"You fall to your knees and bawl your eyes out.\n"
		"Partly for the loss of innocent lives, but also due to the fact that you can't remember who they are.\n"
		"Your hatred toward the demons intensifies. Lumen flares from your nostrils as you stand up.\n"
		"Determined to put an end to this nightmare..\n", 1);
		setFeature2Interaction(0, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
		
	}
	else if(verb == "TOUCH" || verb == "PUSH"){
		if(!getFeature2Interaction(1)){
			text->print("You search through the pile of bodies, searching for survivors.\n"
			"You start turning bodies over, until you find someone gasping for breath.\n"
			"You pull them out, but they start coughing up blood, and they go still...\n"
			"You stand up, tears streaming down your face, as you swear to put an end to this evil..\n", 1);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "READ"){
		text->print("There is nothing to read here.\n", 1);

    }
    else if (verb == "HIT"){
		text->print("You punch the ground in frustration at all the violence done to these victims.\n", 1);
    }
    else if (verb == "TALK"){
		text->print("You look at the victims, and make a oath to make the monster behind this pay.\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("There is nothing to give to the dead.\n", 1);
    }
    else if (verb == "USE"){
		text->print("How could you think of using the dead??\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit and bow your head as you think back to all the attrocities you have encountered since waking up.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You should not try to climb the dead..\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

void Terrace::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the ground of the terrace.\n", 1);
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

void Terrace::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "THRONE" || direction == "UP" || direction == "THRONE"){
        if (roomArr[12]->getCanEnter()&& hero->bag->inBag("SWORD") && hero->bag->inBag("PYXIS")){
		    curRoom->exitDescription(curRoom->getExited());
		    curRoom->setExited(true);
		    curRoom = curRoom->getTop();
		    roomDesc = true;
        }
        else {
            text->print("It is too dangerous to face the Demon king now.\n"
			"We need a weapon and a way to trap him.\n", 1);
        }
	}
	else if(direction == "EAST" || direction == "BED CHAMBERS" || direction == "RIGHT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("There is nothing west.\n", 1);
	}
	else if(direction == "SOUTH" || direction == "FOYER" || direction == "DOWN"){
		text->print("The door is blocked from the other side. You can't go that way.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Terrace::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Terrace::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "TOUCH"){
		text->print("You reach out towards the rift again\n"
		"but you remember what happened last time.\n"
		"You're not a fan of having your soul sucked out, so you back away.\n", 1);
	}

}

void Terrace::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		text->print("You think about approaching the victims again, but stop yourself..\n"
		"Instead, you make a silent prayer from afar. Unable to bring yourself closer..\n", 1);
	}
	else if(verb == "TOUCH"){
		text->print("You continue to search for survivors,\n"
		"but the demon's wrath left no survivors..\n", 1);
	}
}

void Terrace::transition(bool v){
	if(v){
		text->print("You open the door and watching out for the armed sentries,\n"
		"creep back out to the " + text->changeColor("terrace", "R") + ".\n", 1);
	}
	else{
		
	}
}

void Terrace::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "RIFT") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the rift. It won't come back.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the rift and it washes away.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the rift.\n", 1);
				}
			}
		}
		else if (feature == "BODIES") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the dead bodies. It's disrespectful.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the bodies and it washes away, \n"
					"taking some blood with it.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the bodies.\n", 1);
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
