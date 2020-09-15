#include "caves.hpp"

Caves::Caves(){
  roomName = "CAVE";
	mapName = "the Cave";
	feature1 = "WALL";
	feature2 = "STREAM";
  index = 1;
}

void Caves::enterDescription(bool v) {
    if (!v) {
        text->print("You are surrounded by dead animals. The " + text->changeColor("cave", "R") + " smells of death.\n"
            "You look around and see the walls are slick with blood and scratches made by the cave troll.\n"
            "In the face of all the death, however, there is a " + text->changeColor("stream", "F") + " feeding fresh water into a small pool.\n"
            "to the South, you find a unnatturally flat " + text->changeColor("wall", "F") + ", with some ancient symbols surrounding it.\n"
            "Back to the East, you see the entrace of the " + text->changeColor("cave", "R") + " leading to " + text->changeColor("The Black Forest", "R") + ".\n", 1);
    }
    else {
        if (!getRoomChanges(0)) {
            text->print("The " + text->changeColor("stream", "F") + " continues to spout water.\n"
                "The flat " + text->changeColor("wall", "F") + " to the South remains undisturbed,\n"
                "To the East is the entrance to the " + text->changeColor("cave", "R") + ", leading to " + text->changeColor("The Black Forest", "R") + ".\n", 1);
        }
        else {
            text->print("The flat " + text->changeColor("wall", "F") + " to the South now shows an opening leading into the " + text->changeColor("dungeon", "R") + ".\n"
                "The " + text->changeColor("stream", "F") + " remains spouting water.\n"
                "To the East is the entrance to the " + text->changeColor("cave", "R") + ", leading to " + text->changeColor("The Black Forest", "R") + ".\n", 1);
        }
    }
	bag->inArea();
}

void Caves::exitDescription(bool e) {
    if (e) {
        text->print("You leave the caves behind, continuing on your journey.\n", 1);
    }
    else {
        text->print("So far into your journey, you leave the caves feeling as if the truth is just outside your grasp.\n", 1);
    }
}

// Wall
void Caves::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    //If you read the wall with the deciphered text
    if (verb == "LOOK" || verb == "GO" || verb == "TOUCH") {
        if (getRoomChanges(0)) {
            text->print("You place your hand on the wall and see the opening you created using Lumen.\n"
            "The room on the otherside is dark, and you can hear cries, growls, and shouts.\n", 1);
        }
        else {
            text->print("You approach the wall and place your hand on it.\n"
                "The surface is unnaturally smooth, with indentations that, to your surprise,\n"
                "are actually carvings of symbols in the Ancient Language.\n", 1);
        }
    }
    else if (verb == "READ") {
        if (getRoomChanges(0)) {
            text->print("You have already translated the writing and opened the secret door.\n", 1);
        }
        else {
            // Has it been translated?
            if (hero->bag->inBag("TEXT") && hero->getTranslatedText()) {
                text->print("You pull out the Ancient Text, and with a start,\n"
                "You realize this is the secret entrance " + text->changeColor("Linota's", "F") + " ancestor must have used.\n"
                "You compare it to the symbols on the " + text->changeColor("wall", "F") + " to the Ancient Text.\n"
                "You are able to decipher the following..\n", 1);
                text->print(text->changeColor("If you be of The Order, unleash your divine ability..\n", "F"), 1);
                text->print("You stand before the Ancient " + text->changeColor("Wall", "F") + ", and place your palms on it. \nYou close your eyes and concentrate.\n"
				"You feel warmth and power gather in your chest, as your hands are engulfed in blue flames.\n"
                "You stare in awe, as the fire is absorbed by the " + text->changeColor("wall", "F") + ", the ancient symbols glow, and the seam of a door forms, and opens before you.\n"
				"The opening leaves an entrace into a dark hallway. Hot air and human cries rushes past you.\n", 1);
                //Open the path to the dungeon
                roomArr[16]->setCanEnter(true);
                // For enter description
                setRoomChanges(0, true);
            }
            else {
                text->print("You attempt to read the Ancient symbols,\n"
                "but you do not understand what it says.\n", 1);
            }
        }
    }
    else if (verb == "HIT"){
        text->print("You hit the " + text->changeColor("wall", "F") + ", but your hand bruises like a peach and you lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);

    }
    else if (verb == "TALK"){
        text->print("You talk to the " + text->changeColor("wall", "F") + ", then stop.. because you're talking to a " + text->changeColor("wall", "F") + "...\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There is nothing to give the " + text->changeColor("wall", "F") + ".\n", 1);

    }
    else if (verb == "USE"){
        text->print("You can't figure out a way to use the " + text->changeColor("wall", "F") + ".\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You try to push the " + text->changeColor("wall", "F") + ", but it doesn't budge.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit, and wonder what this mysterious wall could be.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("There is no where to swim on the " + text->changeColor("wall", "F") + ".\n", 1);

    }
    else if (verb == "CLIMB"){
        text->print("There is nowhere to climb the wall.\n", 1);
    }
    else {
        text->print("You can't do that here.\n", 1);
    }
}
// Underground stream
void Caves::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    if (verb == "LOOK") {
        text->print("You look at the clear spring water. It is the only pure thing you have seen\n"
            "in this land. The caves must have filtered out all the decay. \n", 1);
    }
    else if (verb == "DRINK" || verb == "USE") {
        text->print("You cup your filthy hands and drink a large gulp of the spring water.\n"
            "You feel refreshed to your core. You regain some health.\n", 1);
        hero->gainHealth();
    }
    else if (verb == "TAKE") {
        //Take the spring water
        if (!hero->bag->bagFull()) {
            text->print("You take a handful of spring " + text->changeColor("water", "I") + " and put it in a cup in your bag.\n", 1);
            hero->bag->insert(itemArr[11]);
        }
        else {
            text->print("You try to take the water but there's no room to store it in your bag.\n", 1);
        }
    }
    else if (verb == "SWIM") {
        text->print("You jump into the clear, cool, stream and feel refreshed, regaining some of your health.\n", 1);
        hero->gainHealth();
    }
    else if (verb == "TOUCH"){
        text->print("You reach down and touch the " + text->changeColor("stream", "F") + ".\n"
        "The water is cool as it flows between your fingers.\n", 1);

    }
    else if (verb == "READ"){
        text->print("There is nothing to read here.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You punch the " + text->changeColor("stream", "F") + ", but you just make a splash of water.\n", 1);

    }
    else if (verb == "TALK"){
        text->print("There is no one to talk too. Only the dead cave troll, but he won't reply.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There is nothing to give the " + text->changeColor("stream", "F") + ".\n", 1);
    }

    else if (verb == "PUSH"){
        text->print("You start to think, how are you going to push a " + text->changeColor("stream", "F") + "?\n"
        "Come on.\n", 1);

    }
    else if (verb == "SIT"){
        text->print("You sit by the " + text->changeColor("stream", "F") + " and just enjoy a monent of peace.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("There is no way to climb a " + text->changeColor("stream", "F") + ".\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}


void Caves::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    if (bag->inBag(itemName)) {
        if (verb == "LOOK") {
            //Get temp copy of item feature
            Item temp = bag->getFeature(itemName);
            text->print(text->firstLetterUpper(temp.getName()) + ": " + temp.getDescription() + ".\n", 1);
        }
        else if (verb == "TAKE") {
            //Check if item will fit in bag
            if (!hero->bag->bagFull()) {
                if (itemName == "WATER") {
                    hero->bag->insert(itemArr[11]);
                }
                else {
                    //Get temp copy of feature we are looking for
                    Item temp = bag->getFeature(itemName);
                    //Pick up item
                    exchangeItem(hero->bag, bag, &temp);
                }
                text->print("You pick up the " + text->toLowerCase(itemName) + " and put it in your bag.\n", 1);
            }
            else {
                text->print("No room in your bag to add the " + text->toLowerCase(itemName) + ".\n", 1);
            }
        }
    }
    //Actions with items in hero's bag
    
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the caves damp ground.\n", 1);
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
                text->print("You throw the " + text->toLowerCase(itemName) + " onto the cave ground.\n", 1);
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
    else if (verb == "TAKE"){
        if (!hero->bag->bagFull()){
            if (itemName == "WATER"){
                hero->bag->insert(itemArr[11]);
				text->print("You take a handfull of spring " + text->changeColor("water", "I") + " and put it in a cup in your bag.\n", 1);
            }
        }
        else {
            text->print("You try to take the water but there's no room to store it in your bag.\n", 1);
        }
    }
    else if (verb == "READ") {
        if (hero->bag->inBag(itemName)) {
            if (itemName == "TEXT") {
                if (getRoomChanges(0)) {
                    text->print("You have already translated the writing and opened the secret door.\n", 1);
                }
                else {
                    // Has it been translated?
                    if (hero->bag->inBag("TEXT") && hero->getTranslatedText()) {
                        text->print("You pull out the Ancient Text, and with a start,\n"
                        "You realize this is the secret entrance " + text->changeColor("Linota's", "F") + " ancestor must have used.\n"
                        "You compare it to the symbols on the wall to the Ancient Text.\n"
                        "You are able to decipher the following..", 1);
                        text->print(text->changeColor("If you be of The Order, unleash your divine ability..", "F"), 1);
                        text->print("You stand before the Ancient Wall, and place your palms on it. You close your eyes and concentrate.\n"
                        "You feel warmth and power gather in your chest, as your hands are engulfed in blue flames.\n"
                        "You stare in awe, as the fire is absorbed by the wall, the ancient symbols glow, and the seam of a door forms, and opens before you.\n"
                        "The opening leaves an entrace into a dark hallway. Hot air and human cries rushes past you.\n", 1);
                        //Open the path to the dungeon
                        roomArr[16]->setCanEnter(true);
                        // For enter description
                        setRoomChanges(0, true);
                    }
                    else {
                        text->print("You attempt to read the Ancient symbols,\n"
                        "but you do not understand what it says.\n", 1);
                    }
                }
            }
            else {
                text->print("You have nothing to read here.\n", 1);
            }
        }
        else{
            text->print("You have no item by that name.\n", 1);
        }
    }
    else if (verb == "USE") {
        if (hero->bag->inBag(itemName)) {
            if (itemName == "TEXT") {
                if (getRoomChanges(0)) {
                    text->print("You have already translated the writing and opened the secret door.\n", 1);
                }
                else {
                    // Has it been translated?
                    if (hero->bag->inBag("TEXT") && hero->getTranslatedText()) {
                        text->print("You pull out the Ancient Text, and with a start,\n"
                        "You realize this is the secret entrance " + text->changeColor("Linota's", "F") + " ancestor must have used.\n"
                        "You compare it to the symbols on the wall to the Ancient Text.\n"
                        "You are able to decipher the following..", 1);
                        text->print(text->changeColor("If you be of The Order, unleash your divine ability..", "F"), 1);
                        text->print("You stand before the Ancient Wall, and place your palms on it. You close your eyes and concentrate.\n"
                        "You feel warmth and power gather in your chest, as your hands are engulfed in blue flames.\n"
                        "You stare in awe, as the fire is absorbed by the wall, the ancient symbols glow, and the seam of a door forms, and opens before you.\n"
                        "The opening leaves an entrace into a dark hallway. Hot air and human cries rushes past you.\n", 1);
                        //Open the path to the dungeon
                        roomArr[16]->setCanEnter(true);
                        // For enter description
                        setRoomChanges(0, true);
                    }
                    else {
                        text->print("You attempt to read the Ancient symbols,\n"
                        "but you do not understand what it says.\n", 1);
                    }
                }
            }
            else {
                text->print("You have nothing to use here.\n", 1);
            }
        }
        else{
            text->print("You have no item by that name.\n", 1);
        }
    }
    else {
        text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
    }
}

void Caves::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
    if (direction == "NORTH" || direction == "UP") {
        text->print("It is pitch dark to the north. You cannot go that way.\n", 1);
    }
    else if (direction == "EAST" || direction == "FOREST" || direction == "RIGHT") {
        curRoom->exitDescription(curRoom->getExited());
        curRoom->setExited(true);
        curRoom = curRoom->getRight();
        roomDesc = true;
    }
    else if (direction == "WEST" || direction == "LEFT") {
        text->print("There is nothing that way. \n", 1);
    }
    else if (direction == "SOUTH" || direction == "DUNGEON" || direction == "DOWN") {
        if (curRoom->getBottom()->getCanEnter()) {
            curRoom->exitDescription(curRoom->getExited());
            curRoom->setExited(true);
            curRoom = curRoom->getBottom();
            roomDesc = true;
        }
        else {
            text->print("There is nothing south, it seems...", 1);
        }
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Caves::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
    if (verb == "LOOK") {
        enterDescription(false);
    }
    else if(verb == "SWIM"){
        text->print("You jump into the clear, cool, " + text->changeColor("stream", "F") + " and feel refreshed, regaining some of your health.\n", 1);
        hero->gainHealth();
    }
    else {
        text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
    }
}

void Caves::secondFeature1Interaction(std::string verb, Character *&hero, Item*[], Room* roomArr[]) {

}

void Caves::secondFeature2Interaction(std::string verb, Character *&hero, Item*[], Room* roomArr[]) {

}

void Caves::transition(bool v) {
    if (v) {
        text->print("You cautiously walk back into the " + text->changeColor("cave", "R") + ", wary of any dangers in its dark corners.\n", 1);
    }
    else {
        text->print("You see the light slowly dim as you make your way into the " + text->changeColor("cave", "R") + ".\n"
            "" + text->changeColor("Sword", "I") + " held high, ready to fend off any enemies brave enough to cross your path.\n", 1);
    }
}

void Caves::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "WALL") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the wall and it splashes off the side.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You drop the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the wall.\n", 1);
			}
		}
		else if (feature == "STREAM") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the stream and it goes back to wence it came.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the stream.\n", 1);
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
