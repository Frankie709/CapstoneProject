#include "town1.hpp"

Town1::Town1(){
    roomName = "HOLMHAVEN";
	mapName = "Holmhaven";
	feature1 = "OLD MAN";
	feature2 = "MARKET";
    index = 6;
}


void Town1::enterDescription(bool v) {
	if (v) {
		text->print("Warm dry wind hits you from the northern " + text->changeColor("Wastelands.", "R") + ". To your south \n"
        "you smell the foul odors coming from a " + text->changeColor("Farm", "R") + ". To the west is " + text->changeColor("Linota's home.", "R") + " There is a " + text->changeColor("old man", "F") + " \n"
        "talking to himself and a " + text->changeColor("river", "R") + " behind him raging in the east. You look and see a busy " + text->changeColor("market", "F") + " in the center \n"
        "of town.\n", 1);
	}
	else {
		text->print("You are in a small town with a few stone buildings and a small " + text->changeColor("market", "F") + ". People scurry around miserably.\n"
        "As you look about you see an " + text->changeColor("old man", "F") + " mumbling to himself. To your east you hear the rush of a " + text->changeColor("river", "R") + ".\n"
        "The foul smell of livestock whiffs from a " + text->changeColor("farm", "R") + " to the south of town. To the north, past the crumbling\n"
        "buildings, you see the sun glaring over a vast " + text->changeColor("desert wasteland", "R") + ".\n", 1);
	}
	bag->inArea();
}

void Town1::exitDescription(bool e) {
	if (e) {
		text->print("As you leave the center of Holmhaven, you can still hear the " + text->changeColor("old man", "F") + " muttering to himself.\n", 1);
		
	}
	else {
		text->print("You hunch your shoulders and soldier on as you leave the sounds of the market of Holmhaven behind.\n", 1);
	}
}

//Old man
void Town1::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
	if (verb == "TALK" || verb == "LOOK" || verb == "GO") {
        //If old man doesn't have his wife's ring
        if (!getItemInteraction(0)){
            //If you haven't tried to speak with him before
		    if (!getFeature1Interaction(0)){
				text->print("You cautiously approach the " + text->changeColor("old man", "F") + ". The " + text->changeColor("old man", "F") + " is wearing worn trousers, a fitted vest, an empty sword sheath,\n"
				"and weirdly, has a set of " + text->changeColor("goggles", "I") + " around his neck. You approach to offer help, but you see he is not in his right mind,\n"
                "and keeps on blabbering.\n", 1);
				text->print(text->changeColor("My RING! My RING! It's all I have left of my dear Eleanor! Blast that Demon for attacking me.\n"
				"If he hadn't taken my fingers I would go back there and teach that thing a lesson!\n"
				"He ambushed me in the mountains, he did!.\n", "YELLOW"), 1);
				text->print("You pity the man who has had so much loss in his life as you walk away to continue your journey.\n", 1);
                setFeature1Interaction(0, true);
			}
			else {
                //Try to talk to him again
				secondFeature1Interaction(verb, hero, itemArr, roomArr);
			}
		} else {
                text->print("You approach the old man and see the joy in his face as he holds his wife's ring.\n", 1);
				text->print(text->changeColor("Thank you for returning my wife's ring.\n"
				"Those goggles i gave you should come in handy if you wish to cross the desert.They will protect you\n"
                "from the blinding light! Good luck.\n", "YELLOW"), 1);
				text->print("The way the " + text->changeColor("old man", "F") + " is holding and staring at his wife's " + text->changeColor("ring", "I") + " is almost animalistic, with \n"
                "an obsessed look in his eye.You walk away to the leave the " + text->changeColor("old man", "F") + " to his possessions as you hear him whispering\n", 1);
				text->print(text->changeColor("My precious.. My precious..\n", "YELLOW"), 1);
            } 
    } else if (verb == "GIVE" || verb == "USE") {
        if(hero->bag->inBag("RING")){
            if (!getItemInteraction(0)){
                text->print("You take the ring out of your pack, and approach the old man.\n", 1);
				text->print(text->changeColor("Excuse me sir, I overheard you earlier and found this in the caves. Is it yours?\n", "GREEN"), 1);
				text->print("The old man turns in your direction, and his eyes open impossibly wide as he launches for the ring.\n", 1);
				text->print(text->changeColor("I don't believe it.. My Eleanor's ring! How did you get this..\n"
				"Nevermind, that isn't important. Thank you so much for returning this. I don't have much, but please take these goggles.\n"
				"They may not look like much, but they are made of sturdy material that will shield your eyes from the brightest lights, or the harshest winds.\n"
				"I suppose you can use them to travel across the desert, but only those of The Order can find the sanctuary deep in the desert.\n"
				"But enough of my blabbering, thank you!\n", "YELLOW"), 1);
				text->print("You take the goggles and place them around your head as you walk away. Pondering the old man's words\n", 1);
                //Remove ring, take goggles
                hero->bag->remove(itemArr[0]);
                hero->bag->insert(itemArr[4]);
                //Sets bool to true that old man has ring
                setRoomChanges(0, true);
                setItemInteraction(0, true);
            }
            else {
                text->print("You have already given him the ring. \n", 1);
            }
            
        }
        else{
            text->print("You have nothing that the Old Man wants.\n", 1);
        }
    }
    else if (verb == "TOUCH"){
        text->print("You touch the old man to offer him comfort, but he is lost in his thoughts. \n", 1);
    }
    else if (verb == "READ"){
        text->print("The old man has scribblings around, but they don't make any sense.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You crack the old man upside his head.\n" + text->changeColor("AHHHHHHH, What did you do that for?\n", "YELLOW") + "People across town stare angrily at you.\n",1);
    }
    else if (verb == "PUSH"){
        text->print("You push the old man, but he just mutters to himself.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit next to the old man, wondering about his sorrows.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You can't swim here, but you hear a river nearby.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You shouldn't climb on a feeble old man.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

//Market
void Town1::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK"){
        text->print("You look around the market. You see vendors about, including an ale brewer. ",1);
    } 
    else if (verb == "TOUCH"){
        text->print("You touch some fruit on a vendor's table, but they yell at you to stop touching if you're\n"
        "not going to buy anything.\n", 1);
    }
    else if (verb == "READ"){
        text->print("You see certain vendors selling books, but you have no money.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You hit a vendor for no reason at all. Several people hunt you down and beat you up. You lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 15);
    }
    else if (verb == "TALK" || verb == "GIVE" || verb == "USE" || verb == "GO"){
        if (!getItemInteraction(1)){
            if (hero->bag->inBag("TOKEN")){
                text->print("You walk through the crowded market. There are multiple vendors selling their wares.\n"
                "You spot the Brewery with his ale. You approach him and give him the Blacksmith's token.\n" + text->changeColor("'Ah, I know that\n"
                "sigil anywhere. How is ole Boyce? Drunk as ever? Since he sent you here with that there's one thing that he wants'.\n", "YELLOW") + "\n"
                "The brewer gets out a canister and fills it up with cold, tasty ale.\n" + text->changeColor("Here you are. If this realm every goes back \n"
                "to normal I'd love to see that drunken fool. Send him my regards.\n", "YELLOW") + "The Brewer hands you the ale.\n", 1);
                // Give the token and take the ale
                hero->bag->remove(itemArr[5]);
                hero->bag->insert(itemArr[10]);
                setItemInteraction(1, true);
            }
            else {  
                text->print("You walk through the market, looking at the various vendors including a Brewer. You talk to several people\n"
                "but get no answers. \n", 1);
            }
        }
        else {
            text->print("You walk through the market. The Brewer waves at you. You have nothing else to do here.\n", 1);
        }
    }
    else if (verb == "PUSH"){
        text->print("You push through the market, with people yelling at you.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit on a nice rock outside the market and lose your thoughts for a moment.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You can't swim here but you hear the rush of a river nearby.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb on top of a vendor's stand before he yells at you to get down.\n", 1);
    }
    else if (verb == "BUY"){
        text->print("You look around the crowded market but realize you have no money for anything.\n", 1);
    }
    else if (verb == "SELL"){
        text->print("You have nothing to sell.\n", 1);
    }
	else{
		text->print("You can't do that in the market.\n", 1);
	}
}

void Town1::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the ground of Holmhaven.\n", 1);
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
    else if(verb == "USE" || verb == "GIVE"){
        if(hero->bag->inBag(itemName)){
            if(itemName == "RING"){
                if (!getItemInteraction(0)){
                    text->print("You take the " + text->changeColor("ring", "I") + " out of your pack, and approach the old man.\n", 1);
				    text->print(text->changeColor("Excuse me sir, I overheard you earlier. I was attacked by a minion in the mountains and it had\n"
                    "this ring. Is it yours?\n", "GREEN"), 1);
				    text->print("The old man turns in your direction, and his eyes open impossibly wide as he launches for the ring.\n", 1);
				    text->print(text->changeColor("I don't believe it.. My Eleanor's ring! How did you get this..\n"
				    "Nevermind, that isn't important. Thank you so much for returning this. I don't have much, but please take these goggles.\n"
				    "They may not look like much, but they are made of sturdy material that will shield your eyes from the brightest lights, or the harshest winds.\n"
				    "I suppose you can use them to travel across the desert, but only those of The Order can find the sactuary deep in the desert.\n"
				    "But enough of my blabbering, thank you!\n", "YELLOW"), 1);
				    text->print("You take the goggles and place them around your head as you walk away. Pondering the old man's words\n", 1);
                    //Remove ring, take goggles
                    hero->bag->remove(itemArr[0]);
                    hero->bag->insert(itemArr[4]);
                    //Sets bool to true that old man has ring
                    setRoomChanges(0, true);
                    setItemInteraction(0, true);
                }
                else {
                    text->print("You have already given him the ring. \n", 1);
                }
            }
            else if (itemName == "TOKEN"){
                if (!getItemInteraction(1)){
                    text->print("You walk through the crowded market. There are multiple vendors selling their wares.\n"
                    "You spot the Brewery with his ale. You approach him and give him the Blacksmith's token. 'Ah, I know that\n"
                    "sigil anywhere. How is ole Boyce? Drunk as ever? Since he sent you here with that there's one thing that he wants'.\n"
                    "The brewer gets out a canister and fills it up with cold, tasty ale. 'Here you are. If this realm every goes back \n"
                    "to normal I'd love to see that drunken fool. Send him my regards.' The Brewer hands you the ale.\n", 1);
                    // Give the token and take the ale
                    hero->bag->remove(itemArr[5]);
                    hero->bag->insert(itemArr[10]);
                    setItemInteraction(1, true);
                } 
                else {
                    text->print("You have concluded your business here.\n", 1);
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
}
void Town1::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "DESERT" || direction == "UP"){
		if (hero->bag->inBag("GOGGLES")) {
			curRoom->exitDescription(curRoom->getExited());
			curRoom->setExited(true);
			curRoom = curRoom->getTop();
			roomDesc = true;
		}
		else {
			text->print("The sun is too blinding. You can't enter the " + text->changeColor("Wastelands", "R") + ".\n", 1);
		}
	}
	else if(direction == "EAST" || direction == "RIVER" || direction == "RIGHT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if(direction == "WEST" || direction == "HOME" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "FARM" || direction == "DOWN"){
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

void Town1::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
    else if (verb == "SLEEP") {
        text->print("You look around but don't see an inn around, so you lay in the middle of town and go to sleep.\n"
        "People gawk at the sight of you sleeping in the middle of the town square. Because of the commotion about " + text->changeColor("Holmhaven", "R") + " you don't"
        "get much sleep and your health is not restored.\n", 1);
    }
    else if (verb == "DANCE") {
        text->print("You break it down and start dancing in the town square. A feeble minded peasant \n"
        "looks at you and yells, 'Can U stop dancin? U scarin the kids!'. You ignore them and finish \n"
        "your routine. \n", 1);
    }
    else if (verb == "BUY"){
        text->print("You look around the crowded market but realize you have no money for anything.\n", 1);
    }
    else if (verb == "SELL"){
        text->print("You have nothing to sell.\n", 1);
    }
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

// Old man again
void Town1::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if (verb == "TALK") {
       text->print("You try talking to the " + text->changeColor("old man", "F") + " but he keeps mumbling about the " + text->changeColor("ring", "I") + ".\n",1);
    }
}

void Town1::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Town1::transition(bool v){
    if (v){
        text->print("Your feet start stepping over cobblestone as you look up and see the sign, \n"
		"\"Welcome to " + text->changeColor("Holmhaven", "R") + "\"\n", 1);
    }
    else {
        text->print("You hunch your shoulders and brave a new world as you walk away from " + text->changeColor("Linota's", "F") + " and follow the path into town.\n"
		"Trash is scattered across the land, and the sounds of a lively town grow louder.\n"
		"You pass a sign that says, \"" + text->changeColor("Holmhaven", "R") + "\".\n", 1);

    }
}

void Town1::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "OLD MAN") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the old man.\n", 1);
			}
			else {

				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Old man and it flows down a crack in the ground.\n"
					"'I could've drinken that', he mumbles.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the old man.\n", 1);
				}
			}
		}
		else if (feature == "MARKET") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the market and it washes away.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the market.\n", 1);
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

