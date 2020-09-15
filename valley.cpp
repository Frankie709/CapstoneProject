#include "valley.hpp"

Valley::Valley(){
    roomName = "VALLEY";
	mapName = "the Valley";
	feature1 = "CARAVAN";
	feature2 = "BOULDERS";
    index = 9;
}


void Valley::enterDescription(bool v) {
	if (v) {
		if(!getRoomChanges(0)){
			text->print("You look around and can see the dog still running around wildly.\n"
			"The set of " + text->changeColor("boulders", "F") + " are in a circle not too far from you.\n"
			"The carnage of a burnt " + text->changeColor("caravan", "F") + " lays at the base of the " + text->changeColor("valley", "R") + "..\n"
			"The " + text->changeColor("mountains", "R") + " are to the south.\n"
			"To the North you see a " + text->changeColor("river", "R") + "\n"
			"And to the West is the path to a " + text->changeColor("farm", "R") + "\n", 1);
		}
		else{
			text->print("You look around and the dog is no longer here..\n"
			"The set of " + text->changeColor("boulders", "F") + " are in a circle not too far from you.\n"
			"The carnage of a burnt " + text->changeColor("caravan", "F") + " lays at the base of the " + text->changeColor("valley", "R") + "..\n"
			"The " + text->changeColor("mountains", "R") + " are to the south.\n"
			"To the North you see a " + text->changeColor("river", "R") + "\n"
			"And to the West is the path to a " + text->changeColor("farm", "R") + "\n", 1);
		}
	}
	else {
        // If dog not found
        if (!getRoomChanges(0)){
            text->print("You look around the valley. In the distance you see a dog running around wildly.\n"
			"There's a peculiar set of " + text->changeColor("boulders", "F") + " set in a circle not too far from you.\n"
			"And the carnage of a burnt " + text->changeColor("caravan", "F") + " lays at the base of the " + text->changeColor("valley", "R") + "..\n"
            "" + text->changeColor("Mushrooms", "I") + " grow abundantly around the " + text->changeColor("valley", "F") + " floor..\n"
			"You feel cold wind rushing from the " + text->changeColor("mountains", "R") + " to the south.\n"
			"To the North you see a " + text->changeColor("river", "R") + "\n"
			"And to the West is the path to a " + text->changeColor("farm", "R") + "\n", 1);
        } else {
            text->print("You look around the cursed " + text->changeColor("valley", "R") + ".\n"
			"Haunted by the remains of the burnt " + text->changeColor("caravan", "F") + ".\n"
			"The odd " + text->changeColor("boulders", "F") + "set in the distance.\n"
			"" + text->changeColor("Mushrooms", "I") + " grow abundantly around the " + text->changeColor("valley", "F") + " floor..\n"
			"A cold wind rushes in from the " + text->changeColor("mountains", "R") + " to the South.\n"
            "To the north you see a wild " + text->changeColor("river", "R") + " flowing.\n"
			"And the path to the " + text->changeColor("farm", "R") + " lies West.\n", 1);
        }
	}
	bag->inArea();
}

void Valley::exitDescription(bool e) {
	if (e) {
		text->print("You leave the " + text->changeColor("valley", "R") + " confident the truth is near.\n", 1);
	}
	else {
		text->print("Your trip to the " + text->changeColor("valley", "R") + " seems to have answered one question,\n"
		"but added two more. You straighten your shoulders as you continue to search for the truth.\n", 1);
	}
}

//Burned Caravan
void Valley::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
	if(verb == "LOOK" || verb == "GO"){
		if(!getFeature1Interaction(0)){
			text->print("You approach the " + text->changeColor("caravan", "F") + " and see the horror before you.\n"
			"Multiple wagons, filled with blankets, goods, personal belongings have been destroyed and set on fire.\n"
			"Skeletal remains can be seen in the smoldering embers.\n"
			"You also see some soldier armor among the remains.\n"
			"You think to yourself,\n" + text->changeColor("Were soldiers the ones who attacked this caravan?", "GREEN") + "\n", 1);
			setFeature1Interaction(0, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		if(!getFeature1Interaction(1)){
			text->print("You wander through the remains, and absently place your hand on a burning wheel of the " + text->changeColor("caravan", "F") + ".\n"
			"When yo finally realize the wheel is on fire, you yank your hand away. Curiously though, you felt no pain or heat,\n"
			"and there was no damage done to your skin.", 1);
			setFeature1Interaction(1, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
		
	}
    else if (verb == "READ"){
        text->print("There is nothing in this mess to read from.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You hit a piece of wood in anger. A large splinter goes into your hand and you lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);
    }
    else if (verb == "TALK"){
        text->print("The only thing to talk to is skeletons...\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There is no one alive to give anything to.\n", 1);
    }
    else if (verb == "USE"){
        text->print("You cannot use anything here.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You push over some charred wheels, hoping to find something useful amongst this carnage, but alas, nothing.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit amongst the wreckage, wondering what evil could have done this.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You cannot swim here but you hear the sound of a river to the north.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb amongst the wreckage. There is nothing you can do to help.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
	
}

// Boulder
void Valley::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "TOUCH" || verb == "GO"){
		if(!getFeature2Interaction(0)){
			text->print("You head out to the " + text->changeColor("boulders", "F") + " looking for clues, but as you approach, you hear a weird snarling sound.\n"
				"You peek around the " + text->changeColor("boulders", "F") + " and catch sight of what you can only describe as 3 hellhounds.\n"
				"Wolf looking creatures, spit that boils and steams as it hits the floor.\n"
				"Blood red eyes, and fur as black as night.\n"
				"The hounds are sniffing and tearing at center " + text->changeColor("boulder", "F") + " as if looking for something.\n"
				"You take a step back to get away, but trip on a rock and make a sudden thump as you hit the floor.\n"
				"Three pairs of eyes lock on you, and their ears stand at attention as if in recognition.\n"
				"The hound on the left launches itself at you and you raise your hand to fend it off..\n"
				"You feel a warmth surge through you, and from your hand erupts a blue fireball that explodes as the hellhound makes contact with it.\n"
				"You get sent flying back and and land on a patch of dirt, dazed, as the hounds take off running.\n"
				"You stare at your hand, but can't replicate the fire, however, a word comes to your mind.. " + text->changeColor("LUMEN", "GREEN") + "\n"
				"A chill settles over you as you wonder, " + text->changeColor("WHO AM I??..", "GREEN") + "\n"
				"You stare at where the hounds were digging, and notice a odd " + text->changeColor("stone", "I") + ", half protruding from the " + text->changeColor("boulders", "F") + ".\n", 1);
				setFeature2Interaction(0, true);
				if(!hero->bag->bagFull()){
					text->print("You grab a hold of the protruding " + text->changeColor("stone", "I") + ",\n"
					"You pull with all your might, heat gathers in your hands, and you're able to wedge it loose.\n"
					"The " + text->changeColor("stone", "I") + " is corroded and doesn't seem very special. But the hounds were after it..\n"
					"You grab the " + text->changeColor("stone", "I") + " and place it in your bag..\n", 1);
					hero->bag->insert(itemArr[12]);
				}
				else{
					text->print("You grab a hold of the protruding " + text->changeColor("stone", "I") + ",\n"
					"You pull with all your might, heat gathers in your hands, and you're able to wedge it loose.\n"
					"The " + text->changeColor("stone", "I") + " is corroded and doesn't seem very special. But the hounds were after it..\n"
					"You would like to take the " + text->changeColor("stone", "I") + ", but have no room for it, and place it back on the " + text->changeColor("boulder", "F") + " platform..\n", 1);
					bag->insert(itemArr[12]);
				}
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "READ"){
		if(hero->bag->inBag("TEXT") && hero->getTranslatedText()){
			//Decipher text
			text->print("You take out the journal containing the deciphered Ancient Language,\n"
			"and compare it to the Ancient Symbols on the " + text->changeColor("boulders", "F") + ".\n"
			"You're able to decipher the following...\n", 1);
			text->print(text->changeColor("For when times are dark..\n"
			"And Death has been let loose..\n"
			"Let the stone power the way to the Light..\n", "YELLOW"), 1);
		}
		else{
			text->print("You attempt to read the Ancient Symbols on the " + text->changeColor("boulders", "F") + ",\n"
			"but can't make out what it says.\n", 1);
		}
	}
    else if (verb == "HIT"){
        text->print("You punch the boulder and it hurts your hand, causing you to lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);
    }
    else if (verb == "TALK"){
        text->print("There's no one around to talk to.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There's nothing to give anything to.\n", 1);
    }
    else if (verb == "USE"){
        text->print("You have nothing to use on the " + text->changeColor("boulders", "F") + ".\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You try to push the giant boulder, but it won't budge.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit by the " + text->changeColor("boulders", "F") + ", wonder who you are...\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You cannot swim here but you hear the sound of a river to the north.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb on top of the boulder. It gives you a better view of your surroundings. You can see the \n"
        "Zemya River to the north and the vast Orden Mountains south of you.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

void Valley::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
			Item temp = bag->getFeature(itemName);
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the valley floor.\n", 1);
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
                text->print("You bite down on the jerky but it is rock solid. You cannot eat it.\n", 1);
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
            if (itemName == "MUSHROOMS"){
                hero->bag->insert(itemArr[3]);
				text->print("You have picked up some " + text->changeColor("mushrooms", "I") + ".\n", 1);
            }
        }
        else {
            text->print("You don't have enough room in your bag to take that.\n", 1);
        }
    }
    else if (verb == "USE" || verb == "GIVE"){
        if (hero->bag->inBag(itemName)){
            if (itemName == "JERKY"){
                //If dog is still around
                if (!getRoomChanges(0)){
                    text->print("You see the startled dog and lure him out with the jerky.\n"
                    "It cautiously comes out and takes the jerky treat. It realizes that not all in \n"
                    "this world is evil. It looks around before heading back towards the farm.\n", 1);
                    //Remove jerky from bag. Change valley so dog isn't in look. Change the farm so the
                    //dog is back.
                    hero->bag->remove(itemArr[7]);
                    setRoomChanges(0, true);
                    roomArr[8]->setRoomChanges(0, true);
                }
			}
			else if(itemName == "TEXT"){
				if(hero->getTranslatedText()){
					//Decipher text
					text->print("You take out the journal containing the deciphered Ancient Language,\n"
					"and compare it to the Ancient Symbols on the " + text->changeColor("boulders", "F") + ".\n"
					"You're able to decipher the following...\n", 1);
					text->print(text->changeColor("For when times are dark..\n"
					"And Death has been let loose..\n"
					"Let the stone power the way to the Light..\n", "YELLOW"), 1);
				} 
				else{
					text->print("You attempt to read the Ancient Symbols on the " + text->changeColor("boulders", "F") + ",\n"
					"but can't make out what it says.\n", 1);
				}
			} 
            else {
                text->print("You can't do that here.\n", 1);
            }
        }

    }
	else if(verb == "READ"){
		if(hero->bag->inBag(itemName)){
			if(itemName == "TEXT"){
				if(hero->getTranslatedText()){
					//Decipher text
					text->print("You take out the journal containing the deciphered Ancient Language,\n"
					"and compare it to the Ancient Symbols on the " + text->changeColor("boulders", "F") + ".\n"
					"You're able to decipher the following...\n", 1);
					text->print(text->changeColor("For when times are dark..\n"
					"And Death has been let loose..\n"
					"Let the stone power the way to the Light..\n", "YELLOW"), 1);
				} 
				else{
					text->print("You attempt to read the Ancient Symbols on the " + text->changeColor("boulders", "F") + ",\n"
					"but can't make out what it says.\n", 1);
				}
			}
			else{
				text->print("There's nothing to read on on that.\n", 1);
			}
		}
		text->print("You do not have that item.\n", 1);
	}
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Valley::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "RIVER" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("It is impossible to continue east. You must turn around.\n",1);
	}
	else if(direction == "WEST" || direction == "FARM" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "MOUNTAINS" || direction == "DOWN"){
        //If you have a sword or you have defeated the minion
        if (hero->bag->inBag("SWORD") || curRoom->getBottom()->getCanEnter()) {
			curRoom->exitDescription(curRoom->getExited());
			curRoom->setExited(true);
			curRoom = curRoom->getBottom();
			roomDesc = true;
		}
		else {
			text->print("A minion is guarding the mountains. It is too dangerous to proceed\n"
            "without a weapon. \n", 1);
		}
	}
    else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Valley::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Valley::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "LOOK" || "GO"){
		text->print("You look around the burned remains for any survivors, but to no avail.\n"
		"You tilt your head and make a silent prayer for the victims of the brutal massacre.\n", 1);
	}
	else if(verb == "TOUCH"){
		text->print("You find another piece of burning wood, and touch it with your bare hand.\n"
		"Again, you feel no pain or heat. To your surprise, the burning wood actually lights up even more with a blue flame.\n"
		"You drop the wood and walk away.\n", 1);
	}
}

// Boulder feature
void Valley::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "TOUCH" || verb == "LOOK" || verb == "GO"){
		text->print("You approach the "+ text->changeColor("boulders", "F") + ", and with no hellhounds in sight, are able to inpect them.\n"
			"The "+ text->changeColor("boulders", "F") + " are arranged in a wide circle around one central flat stone in the middle.\n"
			"The damage the hounds made is evident on the flat stone.\n"
			"The stones have the same phrase repeated on all of them, but they are in the Ancient Language.\n", 1);
	}
}


void Valley::transition(bool v){
	if(v){
		text->print("You walk back to the " + text->changeColor("valley", "R") + ", and notice the rot has spread in the foliage around you.\n", 1);
	}
	else{
		text->print("As you walk, you can't help but notice the foliage seems to be dying off.\n"
		"Dried and rotted plants appear every now and then, and you wonder what is happening to the realm.\n"
		"As you arrive at the " + text->changeColor("valley", "R") + ", you are determined to find some answers.\n", 1);
	}

}

void Valley::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "CARAVAN") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the Caravan. It's disrepectful.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " near the caravan and it soaks into the ground.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the burned Caravan.\n", 1);
				}
			}
		}
		else if (feature == "BOULDER") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the boulder and it splashes off it.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the boulder.\n", 1);
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
