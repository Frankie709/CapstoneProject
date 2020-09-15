#include "desert.hpp"

Desert::Desert(){
    roomName = "DESERT";
	mapName = "the Wastelands";
	feature1 = "TABLET";
	feature2 = "COLUMNS";
    index = 2;
}

void Desert::enterDescription(bool v) {
	if (v) {
		text->print("You look at the stronghold and see the huge " + text->changeColor("columns", "F") + " and the ruined entrance \n"
        "with the " + text->changeColor("tablet", "F") + " lying on the ground.\n"
		"To the North, East, and West, you see nothing but desert as far as the eye can see..\n"
		"To the south you see your footprints, leading back to " + text->changeColor("Holmhaven", "R") + ", slowly fade away.\n", 1);
	}
	else {
		text->print("You look at the stronghold, a poor image compared to what its former glory must have been.\n"
		"There are huge " + text->changeColor("columns", "F") + " forming a semi-circle, with Ancient Order \n"
        "drawings carved into them. In the center of the " + text->changeColor("columns", "F") + " is a huge entrance covered by rubble.\n"
        "On the ground near the entrance you see a " + text->changeColor("tablet", "F") + ".\n"
		"To the North, East, and West, you see nothing but heat and despair..\n"
		"To the south you see your footprints, leading back to " + text->changeColor("Holmhaven", "R") + ", slowly fade away.\n", 1);
	}
	bag->inArea();
}

void Desert::exitDescription(bool e) {
	if (e) {

		text->print("You leave The Order's stronghold behind and walk out of the " + text->changeColor("Wastelands", "R") + ".\n", 1);
	}
	else {
		text->print("The hot, humid wind blasts your face as you leave " + text->changeColor("The Wastelands", "R") + ".\n"
		"As you leave, you look back and see nothing but despair.\n", 1);
	}
}

//Tablet interaction
void Desert::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    
	if(verb == "LOOK" || verb == "TOUCH" || verb == "READ" || verb == "USE"){
		if(!getFeature1Interaction(0)){
			if(hero->bag->inBag("TEXT")){
				text->print("You approach the Stone " + text->changeColor("Tablet", "F") + " in the center of the ring of " + text->changeColor("columns", "F") + ". The tablet contains unrecognizeable symbols alongside the common tongue alphabet. \n"
				"Upon closer inspection, you realize the symbols match the symbols in the " + text->changeColor("Ancient Text", "I") + " you received from " + text->changeColor("Linota", "YELLOW") + "\n"
				"You compare the last page in the book and are able to decipher the following entry...\n", 1);
				text->print(text->changeColor("Date, May 23, 1339..\n"
				"I have met a fair maiden, Isabela, in Nagorny Village, and I believe she is the one, but The Order prohibits me from seeing her.\n"
				"Brother Tobias has provided me access to a secret entrance to the castle through the caves, that would allow me to see Isabela in secret.\n"
				"She wishes to know more about The Order. I know it is not the best idea, but i will show her some of The Order's artifacts so she knows more about us and myself.\n"
				"I will be seeing her again tomorrow. More to come.\n", "YELLOW"), 1);
				text->print("It appears this ancient text is a journal of " + text->changeColor("Linota's", "YELLOW") + " ancestor before he was kicked out of the order.\n"
				"You don't believe it was worth it to sneak Isabela into the castle knowing what happened afterwards.\n"
				"You make a note of the decrypted alphabet in the text. It may be useful elsewhere..\n", 1);
				setFeature1Interaction(0, true);
                hero->setTranslatedText(true);
                hero->bag->remove(itemArr[2]);
                hero->bag->insert(itemArr[19]);
			}
			else{
				text->print("You approach the stone Tablet in the center of the ring of columns. \nThe tablet contains unrecognizeable symbols alongside the common tongue alphabet.\n"
				"You feel as if you have seen the symbols on the tablet somewhere else, but can't place the ancient alphabet.\n", 1);
			}
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "HIT"){
		text->print("You should not hit the " + text->changeColor("tablet", "F") + ". It is old and fragile.\n", 1);
    }
    else if (verb == "TALK"){
		text->print("You speak to the " + text->changeColor("tablet", "F") + ", but it says nothing back.\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is nothng the " + text->changeColor("tablet", "F") + " wants.\n", 1);
    }

    else if (verb == "PUSH"){
		text->print("You try to push the " + text->changeColor("tablet", "F") + ", but it is too heavy..\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit and wonder how long the " + text->changeColor("tablet", "F") + " has been here.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You throw yourself in the dirt, and pretend to swim next to the " + text->changeColor("tablet", "F") + ".\n", 1);
    }
    else if (verb == "CLIMB"){
		text->print("You climb the " + text->changeColor("tablet", "F") + ", but don't see anything new from up there.\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

//Column
void Desert::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "TOUCH" || verb == "READ" || verb == "USE"){
		if(!getFeature2Interaction(0)){
			text->print("You approach the massive stone " + text->changeColor("columns", "F") + ", surprised they haven't collapsed yet.\n"
			"As you stare up at them, you realize the " + text->changeColor("column", "F") + " drawings are painting a story.\n"
			"Based on what you can decipher, The Order identifies special individuals who contain an ancient power within them.\n"
			"They are trained in swordsmanship and taught to harness the power within.\n"
			"The Order's sole mission is to protect the realm from demons and monsters that seek to spread chaos and darkness.\n"
			"The last carving shows warriors in battle with demons of all shapes and sizes.\n"
			"Some fight with swords, others using the elements as weapons.\n"
			"Launching fireballs and lightning bolts at their enemy.\n", 1);
			setFeature2Interaction(0, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "HIT"){
		text->print("You hit the " + text->changeColor("columns", "F") + ", but your hand bruises like a peach and you lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);
    }
    else if (verb == "TALK"){
		text->print("There is no one to talk to.\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("There is no one to give anything to.\n", 1);
    }
    else if (verb == "PUSH"){
		text->print("You try to push the " + text->changeColor("columns", "F") + ", but they don't budge.\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit against the column, and think its a nice place to rest.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You throw yourself in the dirt, and pretend to swim next to the " + text->changeColor("columns", "F") + ".\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You try to climb the " + text->changeColor("columns", "F") + ", but can't find a way up.\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

void Desert::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
                text->print("You drop the water on the wastelands ground and it boils and bursts into steam instantly. \n", 1);
            } else if (itemName == "GOGGLES"){
                text->print("You need your goggles to see! You cannot drop them in the wastelands.\n", 1);
            } else if (itemName == "MUSHROOMS"){
                text->print("You put the mushrooms on the ground and they melt instantly. \n", 1);
                hero->bag->remove(itemArr[3]);
            }
            else{
			    exchangeItem(bag, hero->bag, &temp);
                text->print("You drop the " + text->toLowerCase(itemName) + " onto the ground.\n", 1);
            }
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
                text->print("You throw the water onto the wasteland ground and steam instantly sprouts up. \n", 1);
            } 
            else if (itemName == "GOGGLES"){
                text->print("You will be blinded if you throw the goggles in the wastelands. You must keep them on.\n", 1);
            }
            else if (itemName == "MUSHROOMS"){
                text->print("You throw the mushrooms onto the searing ground and they melt instantly. \n", 1);
                hero->bag->remove(itemArr[3]);
            }
            else
            {
			    exchangeItem(bag, hero->bag, &temp);
                text->print("You throw the " + text->toLowerCase(itemName) + " onto the scorching wasteland sand.\n", 1);
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
    else if (verb == "USE" || verb == "READ"){
        if (hero->bag->inBag(itemName)){
            if (itemName == "TEXT"){
                if (!getFeature1Interaction(0)){
                    text->print("You pull out the " + text->changeColor("Text", "I") + " that " + text->changeColor("Linota", "F") + " gave you and approach the Stone Tablet in the center of the ring of columns.\n"
					"The tablet contains unrecognizeable symbols alongside the common tongue alphabet. \n"
					"Upon closer inspection, you realize the symbols match the symbols in the Acient Text..\n"
					"You compare the last page in the book and are able to decipher the following entry...\n", 1);
					text->print(text->changeColor("Date, May 23, 1339..\n"
					"I have met a fair maiden, Isabela, in Nagorny Village, and I believe she is the one, but The Order prohibits me from seeing her.\n"
					"Brother Tobias has provided me access to a secret entrance to the castle through the caves, that would allow me to see Isabela in secret.\n"
					"She wishes to know more about The Order. I know it is not the best idea, but i will show her some of The Order's artifacts so she knows more about us and myself.\n"
					"I will be seeing her again tomorrow. More to come. ", "YELLOW"), 1);
					text->print("It appears this ancient text is a journal of " + text->changeColor("Linota's", "YELLOW") + " ancestor before he was kicked out of the order.\n"
					"You don't believe it was worth it to sneak Isabela into the castle knowing what happened afterwards.\n"
					"You make a note of the decrypted alphabet in the journal. It may be useful elsewhere..\n", 1);
                    setFeature1Interaction(0, true);
                    hero->setTranslatedText(true);
                    hero->bag->remove(itemArr[2]);
                    hero->bag->insert(itemArr[19]);
                }
                else {
                    text->print("You have already translated the text.\n", 1);
                }
            } 
            else {
                text->print("You cannot use that here.\n", 1);
            }
        }
        else {
            text->print("You have nothing to use here.\n", 1);
        }
    }

	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Desert::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "UP"){
		text->print("The vast wastelands continue north into the horizon. You cannot go that way.\n", 1);
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("There is nothing to the east but despair.\n", 1);
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("Only sadness lies to the west. You cannot go that way.\n",1);
	}
	else if(direction == "SOUTH" || direction == "HOLMHAVEN" || direction == "DOWN"){
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

void Desert::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
    else if (verb == "SLEEP" || verb == "REST"){
        text->print("You lay on the scorching sand and try to sleep. The sun beats down on you and \n"
        "blisters your face. You lose 5 health points. \n", 1);
        hero->setHealth(hero->getHealth() - 5);
    }
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}


void Desert::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "LOOK" || verb == "TOUCH" || verb == "READ"){
		text->print("You approach the stone tablet again, and remember the entry of " + text->changeColor("Linota's", "YELLOW") + " ancestor,\n"
			"and how they snuck Isabella into the castle through the caves.\n", 1);
	}		
}

void Desert::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
    if(verb == "LOOK" || verb == "TOUCH" || verb == "READ"){
		text->print("You approach the columns again, and look at the carvings of the warriors of The Order.\n"
		"Ancient warriors battling monsters and demons. Warriors weilding blades,\n"
		"while others use elements themselves,\n"
		"some launching what appears to be fireballs and lightning bolts at the demons.\n"
		"You flex your hands and feel fire coursing through your veins.\n", 1);
	}	
}


void Desert::transition(bool v){
    if (v){
        text->print("You walk back through the " + text->changeColor("wastelands", "R") + " to the ancient stronghold,\n"
		"thankful for the goggles protecting you from the blinding light and blistering winds.\n", 1);
    }
    else {
        text->print("You walk into the arid " + text->changeColor("wastelands", "R") + ". The sun is glaring, even through your goggles.\n"
        "You look around and see bones scattered about the scorching sands. You wander for hours through\n"
        " the vast nothingness, an odd sensation guiding you through the desert, before you reach an ancient stronghold.\n", 1);
    }
}

void Desert::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "TABLET") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the tablet and it sloshes into its carved writing.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You drop the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the tablet.\n", 1);
			}
		}
		else if (feature == "COLUMNS") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You drop " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the columns and it washes away.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the columns.\n", 1);
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