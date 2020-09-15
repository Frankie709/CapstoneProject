#include "dungeon.hpp"

Dungeon::Dungeon(){
    roomName = "DUNGEON";
	mapName = "the Dungeon";
	feature1 = "PRISONER";
	feature2 = "TORTURE RACK";
    index = 16;
}

void Dungeon::enterDescription(bool v){
	if(v){
        text->print("Cells line up the sides of the long room.\n"
        "The " + text->changeColor("prisoner", "F") + " remains in their cell. Unconscious with their breath coming at an erratic rate..\n"
        "The " + text->changeColor("torture rack", "F") + " sits unmoving, mocking its captives.\n"
        "There is a door to the South, and a gate to the East.\n"
        "The path to the " + text->changeColor("cave", "R") + " lies to the North.\n", 1);
	}
	else{
        text->print("Death and carnage is all around you. Pools of blood pocket the floor.\n"
        "You are in a long dark room. A window set high barely lets in any light.\n"
        "Cells line up both walls. Most contain unmoving bodies, \n"
        "but one cell at the end contains a " + text->changeColor("prisoner", "F") + ",\n"
        "who, against all odds, looks familiar...\n"
        "A " + text->changeColor("torture rack", "F") + " stands in the aisle between the cells\n"
        "in clear view of all the prisoners so they can watch the unlucky individual subjected to it.\n"
        "To the North is the path back to the " + text->changeColor("cave", "R") + ".\n"
        "There is a door to the South. And a wrought iron gate to the East.\n", 1);
	}
	bag->inArea();
} 

void Dungeon::exitDescription(bool e){
	if(e){
		text->print("You hope it can't get worse than this as you leave the " + text->changeColor("dungeon", "R") + ".\n", 1);
	}
	else{
		text->print("You leave the " + text->changeColor("dungeon", "R") + " behind determined to put and end to this evil.\n", 1);
	}
}

//Prisoner
void Dungeon::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK"){
        if(!getFeature1Interaction(0)){
            text->print("You look at the sickly prisoner. She is covered in dirt and there are bloody marks\n"
            "on her arm from the torture rack.\n "
            "You then realize that the reason the " + text->changeColor("prisoner", "F") + " looked familiar,\n"
            "is because she is your friend Adelina from your memories..\n", 1);
            setFeature1Interaction(0, true);
        }
        else{
            secondFeature1Interaction(verb, hero, itemArr, roomArr);
        }
        
    } else if (verb == "TALK") {
        if(!getRoomChanges(0)){
            text->print("You lean in and yell, "
            "" + text->changeColor("ADELINA!!", "GREEN") + ".\n"
            "But all she replies with is, \n"
            "" + text->changeColor("Waa, Waaatteer...", "YELLOW") + ".\n", 1);
        }
        else{
            secondFeature1Interaction(verb, hero, itemArr, roomArr);
        }
        
    }
    else if (verb == "TOUCH"){
        text->print("You reach for the " + text->changeColor("prisoner", "F") + " through the cell wall,\n"
        "but they are just out of reach.\n", 1);
        
    }
    else if (verb == "READ"){
        text->print("There is nothing to read here.\n", 1);
        
    }
    else if (verb == "HIT"){
        text->print("You hit the cell door the " + text->changeColor("prisoner", "F") + " is in,\n"
        "but no damage is done to it. The door remains locked.\n", 1);

    }
    else if (verb == "GIVE"){
        text->print("You look at the " + text->changeColor("prisoner", "F") + ", and see that she could use some water.\n", 1);

    }
    else if (verb == "USE"){
        text->print("Use the " + text->changeColor("prisoner", "F") + "???\n"
        "You're just as bad as the demons. Walk away.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You try to push the cell door to get to the " + text->changeColor("prisoner", "F") + ",\n"
        "but it doesn't budge.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit outside the cell next to the " + text->changeColor("prisoner", "F") + ",\n"
        "and vow to have her released.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("I'm sure the " + text->changeColor("prisoner", "F") + " would like to swim..\n"
        "If they currently weren't in prison..\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You cannot climb the " + text->changeColor("prisoner", "F") + ".\n"
        "What is wrong with you??\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

//Torture rack
void Dungeon::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK"){
        if(!getItemInteraction(0)){
            text->print("You look at the torture rack. It's straps are covered with fresh blood. You follow its dripping \n"
            "to a big pool of blood on the floor. You see a large wheel as part of a pulley system used to stretch the body \n"
            "beyond its breaking point. On the wheel you notice several small lubricated " + text->changeColor("screws", "I") + " used to prevent friction with the frame\n", 1);
        }
        else{
            text->print("You look at the torture rack. It's straps are covered with fresh blood. You follow its dripping \n"
            "to a big pool of blood on the floor. You see a large wheel as part of a pulley system used to stretch the body \n"
            "beyond its breaking point. The " + text->changeColor("screws", "I") + " used to prevent friction with the frame have been broken off.\n", 1);
        }
        
    }
    else if (verb == "HIT"){
        //First time hitting it
        if (!getFeature2Interaction(0)){
            text->print("You hit the torture rack as hard as you can. The wood on the wheel cracks and almost breaks.\n"
            "The " + text->changeColor("screw", "I") + " rattles and almost breaks free...\n", 1);
            setFeature2Interaction(0, true);
        } else {
            secondFeature2Interaction(verb, hero, itemArr, roomArr);
        }
    }
    else if (verb == "TOUCH"){
        text->print("You touch the " + text->changeColor("torture rack", "F") + ", and can feel dried up blood\n"
        "from its previous victims.\n", 1);
    }
    else if (verb == "READ"){
        text->print("There is nothing to read here.\n", 1);
    }
    else if (verb == "TALK"){
        text->print("There is nobody on the " + text->changeColor("torture rack", "F") + " to talk to.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There is nothing to give to the " + text->changeColor("torture rack", "F") + ".\n", 1);
    }
    else if (verb == "USE"){
        text->print("You want to use the " + text->changeColor("torture rack", "F") + "???\n"
        "You monster, walk away..\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You push the " + text->changeColor("torture rack", "F") + ", but it is bolted to the floor and doesn't budge.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You take a seat on the " + text->changeColor("torture rack", "F") + ",\n"
        "and shudder as you think what these poor souls went through.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("There is no where to swim.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb the " + text->changeColor("torture rack", "F") + ", but still can't see out the small window at the top.\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

void Dungeon::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the dungeon floor.\n", 1);
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
    else if (verb == "USE" || verb == "GIVE") {
        if (hero->bag->inBag(itemName)){
            if (itemName == "SCREW"){
                if (!getItemInteraction(1)){
                    text->print("You use the " + text->changeColor("screw", "I") + " on the Laboratory keyhole. You twist it until you hear the door click.\n", 1);
                    setItemInteraction(1, true);
                    //Set can enter true
                    roomArr[15]->setCanEnter(true);   
                } else {
                    text->print("The lab door is already unlocked.\n", 1);
                }

            } else if (itemName == "CHEMICALS"){
                //Checks for key usage
                if (!getItemInteraction(4)){
                    text->print("You pour the chemicals on the large lock. The bolt falls off and the door is unlocked.\n", 1);
                    setItemInteraction(4, true);
                    // changes foyer door to unlocked
                    setItemInteraction(5, true);
			roomArr[17]->setCanEnter(true);
			hero->bag->remove(itemArr[14]); 
                } else {
                    text->print("You already unlocked the foyer door.\n", 1);
                }
            }
            else if(itemName == "WATER"){
                if(!getItemInteraction(2)){
                text->print("You wake up Adelina just long enough to give her the water.\n"
                "She drinks it with a feverish intensity, and lays back down, looking better than before..\n"
                "Maybe she is able to talk more now..\n", 1);
		hero->bag->remove(itemArr[11]);
                setItemInteraction(2, true);
                setRoomChanges(0, true);
                }
                else{
                    text->print("You try to give Adelina more water, but she is sound asleep.\n", 1);
                }
            }
        } 
    }
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Dungeon::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "UP" || direction == "CAVE"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "FOYER" || direction == "RIGHT"){
        //Checks if chemicals has been used
        if (curRoom->getRight()->getCanEnter()){
		    curRoom->exitDescription(curRoom->getExited());
		    curRoom->setExited(true);
		    curRoom = curRoom->getRight();
		    roomDesc = true;
        }
        else {
           text->print("The door to the east is locked by a heavy lock.\n", 1);
        }
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("There is nothing that way.\n", 1);
	}
	else if(direction == "SOUTH" || direction == "LAB" || direction == "DOWN"){
        if (curRoom->getBottom()->getCanEnter()){
		    curRoom->exitDescription(curRoom->getExited());
		    curRoom->setExited(true);
		    curRoom = curRoom->getBottom();
		    roomDesc = true;
        } else {
            text->print("The door to the Lab is locked by a small lock.\n"
		"Maybe you can use something in here to pick it...\n",1);
        }
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Dungeon::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Dungeon::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if(verb == "LOOK"){
        if(!getItemInteraction(2)){
            text->print("You look at Adelina, and feel terrible for what must have happened to her since the last time you saw her in the " + text->changeColor("black forest", "R") + ".\n"
            "There has to be a way to help her.\n", 1);
        }
        else{
            text->print("You look at Adelina, and she is sound asleep, but she looks a bit better since you gave her water.\n"
            "It looks like she has been through hell..\n ", 1);
        }
        
    }
    else if(verb == "TALK"){
        if(!getFeature1Interaction(1)){
            text->print("Adelina looks a lot better since you gave her the water.\n"
            "You lean in and call out to her again, "
            "" + text->changeColor("ADELINA!!", "GREEN") + ".\n"
            "" + text->changeColor(hero->getName() + ", I'm so happy to see you're alive.\n"
            "Quickly, there's no time.\n"
			"The Demon has magically sealed this prison cell, so I can be of no help to you,\n"
			"but there may be something in the lab to the south that you can use to proceed through the Castle.\n"
	        "Try to use something in this room to pick the lock.\n"
            "There's no way to kill a Greater Demon, you must trap it.\n"
            "I hid a " , "YELLOW") + text->changeColor("pyxis", "I") + text->changeColor(" inside the large ", "YELLOW")  + text->changeColor("tree", "F") + text->changeColor(" in the ", "YELLOW") + text->changeColor(" black forest", "R") +".\n"
            ""+ text->changeColor("You must go and talk to the ", "YELLOW")  + text->changeColor("tree", "F") + text->changeColor(" and say the following phrase \"Help me, Tree. You're my only Hope\" in the ancient language.\n"
            "It will then open up and present you with a ", "YELLOW") + text->changeColor("pyxis", "I") + ".\n"
            "" + text->changeColor("The ", "YELLOW") + text->changeColor("pyxis", "I") + text->changeColor(" on its own is no good. \nYou must power up The Order's ", "YELLOW") + text->changeColor("shrine", "F") + "\n"
            "" + text->changeColor("in the ", "YELLOW") + text->changeColor("mountains", "R") + text->changeColor(" and attach some kind of demon signature so the ", "YELLOW") + text->changeColor("pyxis", "I") + text->changeColor(" can target the Greater Demon.\n", "YELLOW"), 1);
            text->print("Adelina's eyes then flutter and she collapses back to the ground, unconscious.\n", 1);
            roomArr[3]->setItemInteraction(1, true);
            setFeature1Interaction(1, true);
        }
        else{
            text->print("You try to talk to Adelina again, but she is sound asleep.\n"
            "You think back to what she told you about talking to the " + text->changeColor("tree", "F") + " in the " + text->changeColor(" black forest", "F") + ".\n"
            "and needing some kind of demon signature to power the " + text->changeColor("shrine", "F"), 1);
        }
    }
}

void Dungeon::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if (verb == "HIT") {
        //Used for screw drop
        if (!getItemInteraction(0)){
            text->print("You hit the torture rack again and the wheel snaps off and a small " + text->changeColor("screw", "I") + " \n"
            "falls to the ground.\n", 1);
            if (!hero->bag->bagFull()){
                text->print("You pick up the small " + text->changeColor("screw", "I") + ". Maybe it could be used as a lockpick?\n", 1);
                hero->bag->insert(itemArr[13]);
            }
            else {
                text->print("You inspect the small " + text->changeColor("screw", "I") + " on the ground, and it looks like it could be used as a lockpick.\n", 1);
                bag->insert(itemArr[13]);
            }
            setItemInteraction(0, true);
        } else {
            text->print("You hit the rack again for good measure. It is already smashed.\n", 1);
        }
    }
}


void Dungeon::transition(bool v){
    if(v){
        text->print("You make your way through the entrance, and enter the " + text->changeColor("dungeon", "R") + ".\n", 1);
    }
    else{
        text->print("You hear moans and cries come from the other side of the opening you made.\n"
        "Alarmed, you rush through the opening ready to help, and stop dead in your tracks.\n"
        "You are standing in the middle of a " + text->changeColor("dungeon", "R") + "..\n", 1);
    }
}

void Dungeon::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "TORTURE RACK") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Torture rack and some blood washes off.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the torture rack.\n", 1);
			}
		}
		else if (feature == "PRISONER"){
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " Adelina.\n", 1);
			}
			else {

				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " Adelina and she stares at you blankly.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near Adelina.\n", 1);
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
