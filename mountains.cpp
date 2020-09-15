#include "mountains.hpp"

Mountains::Mountains(){
    roomName = "MOUNTAINS";
	mapName = "the Orden mountains";
	feature1 = "SHRINE";
	feature2 = "DRAWING";
    index = 5;
}


void Mountains::enterDescription(bool v) {
	if (v) {
		text->print("You are standing in the alcove. The " + text->changeColor("shrine", "F") + " sits at the base,\n"
		"with the " + text->changeColor("drawings", "F") + " surounding it on the wall.\n"
		"To the West you can see " + text->changeColor("The Black Forest", "R") + ".\n"
		"A short distance to the East, you can make out " + text->changeColor("Nagorny Village", "R") + ".\n", 1);
	}
	else {
		text->print("You are standing in a deep alcove, set into the top of the " + text->changeColor("mountain", "R") + ".\n"
		"The entire realm is visible to you. " + text->changeColor("Holmhaven", "R") + " an impossible distance away.\n"
		"The walls of the alcove are polished smooth except for various " + text->changeColor("drawings", "F") + " carved into the walls.\n", 1);
        if (!getRoomChanges(0)){
            text->print("At the base of the alcove stands a " + text->changeColor("shrine", "F") + " that looks to be thousands of years old.\n", 1);
        }
        else {
            text->print("At the base of the alcove the " + text->changeColor("shrine", "F") + " is radiating with power and glowing from the power\n"
            "of the power stone.", 1);
        }
        text->print("To the West you can see " + text->changeColor("The Black Forest", "R") + ".\n"
		"To the East, you can make out " + text->changeColor("Nagorny Village", "R") + ".\n", 1);
	}
	bag->inArea();
}

void Mountains::exitDescription(bool e) {
	if (e) {
		text->print("You get your guard up as you prepare the treacherous journey down the " + text->changeColor("mountain", "R") + ".\n", 1);
	}
	else {
		text->print("You take one last look of the realm from your high vantage point,\n"
		"before starting your descent down the " + text->changeColor("mountain", "R") + ".\n", 1);
	}
}

//Shrine
void Mountains::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
    if (verb == "LOOK" || verb == "GO" || verb == "TOUCH"){
        text->print("You approach the large " + text->changeColor("shrine", "F") + ". \n", 1);
        //If stone not placed
        if (!getItemInteraction(0)){
            text->print("You look and see an indentation where a circular object could be placed. \n", 1);
        }   
        else {
            text->print("The " + text->changeColor("shrine", "F") + " is pulsing with power from the power stone. It is glowing brightly.\n", 1);
        }
        //If Heart placed
        if (!getItemInteraction(2)){
            text->print("There is a grotesque chamber covered in blood. What could that be for? You wonder \n", 1);
        }
        else {
            text->print("The minion heart is secured in the chamber.\n", 1);
        }

        //If pyxis placed
        if (!getItemInteraction(1)){
            text->print("You look and see where a vessel of some type could be placed. \n", 1);
        }
        else if (!roomArr[12]->getCanEnter()){
            text->print("The pyxis is tightly placed in its chamber.\n", 1);
        }
        else {
            text->print("You see the chamber where the powered pyxis was inserted.\n", 1);
        }
        if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            if (!hero->bag->bagFull()){
                text->print("You approach the powered " + text->changeColor("shrine", "F") + " and grab the pyxis. It has been re-energized and has a glow \n"
                "to it. This is the final piece needed to capture the demon and bring peace to the realm. You must head to the \n"
                "tower to confront the possessed King!\n", 1);
                setItemInteraction(3, true);
                hero->bag->insert(itemArr[18]);
                roomArr[12]->setCanEnter(true);
            }
            else {
                text->print("You see the pyxis is powered up but you don't have any room in your bag to take it. \n", 1);
            }
        }
        else if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && getItemInteraction(3)){
            text->print("The power " + text->changeColor("shrine", "F") + " has completed its task. You have the powered pyxis and all that's left is to\n"
            "face the evil Demon king in the Castle tower!\n", 1);
        }
    }
	else if (verb == "USE" || verb == "GIVE" || verb == "PUSH"){
        //To use the power stone
        if (!getItemInteraction(0)){
            if (hero->bag->inBag("STONE") && hero->getPowerStone()){
                text->print("You place the stone and it powers up the " + text->changeColor("shrine", "F") + ".\n", 1);
                setItemInteraction(0, true);
                hero->bag->remove(itemArr[17]);
                setRoomChanges(0, true);
            }
        } 
        //To use the pyxis
        if (!getItemInteraction(1)){
            if (hero->bag->inBag("PYXIS")){
                text->print("You secure the pyxis in its chamber.\n", 1);
                setItemInteraction(1, true);
                hero->bag->remove(itemArr[9]);
            }
        }
        if (!getItemInteraction(2)){
            if (hero->bag->inBag("HEART")){
                text->print("You place the heart into its bloody chamber.\n", 1);
                setItemInteraction(2, true);
                hero->bag->remove(itemArr[8]);
            }
        }
        //If all 3 items used
        if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
			"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
			"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
			"Now you can hope to restore peace to the realm", 1);
            hero->bag->insert(itemArr[18]);
            //Open up the tower room
            roomArr[12]->setCanEnter(true);
            setItemInteraction(3, true);
        }
    }
    else if (verb == "READ"){
        text->print("You look at the massive " + text->changeColor("shrine", "F") + ", but there's nothing around to read.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You punch the " + text->changeColor("shrine", "F") + ", damaging your already injured hand. You lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 5);
    }
    else if (verb == "TALK"){
        text->print("You talk to the " + text->changeColor("shrine", "F") + ", but it holds on to its secrets.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit by the " + text->changeColor("shrine", "F") + ", fascinated by it.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You cannot swim anywhere nearby.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You try to climb on the massive " + text->changeColor("shrine", "F") + ", but you cannot.\n", 1);
    }
    else {
        text->print("You can't do that to the " + text->changeColor("shrine", "F") + ".\n", 1);
    }
}

//Drawing
void Mountains::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK" || verb == "GO" || verb == "TOUCH" || verb == "USE" || verb == "READ" || verb == "GIVE"){
        if (hero->bag->inBag("TEXT") && hero->getTranslatedText()){
            text->print("You look at the drawings and it reminds you of something from your text. You open your \n"
            "text and start to translate the drawings.\n" + text->changeColor("Once the great shrine is powered, a sacrifice must be made \n"
            "for the full power of the pyxis to be realized. Only then can the demons of this realm be contained","F") + " it reads\n", 1);
        }
        else {
            text->print("You look at the vast drawings on the mountain side. They must mean something but you \n"
            "have nothing to translate them with.\n", 1);
        }
    } 
    else if (verb == "HIT"){
        text->print("You hit the drawings, hoping for something to be revealed, but you just hurt your hand.\n", 1);
        hero->setHealth(hero->getHealth() - 5);
    }
    else if (verb == "TALK"){
        text->print("You talk to the drawings, but none respond.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You try to push the mountain wall, but then you realize your place in the world.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit next to the ancient drawings, wondering about the people who drew them.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You look around but there is nowhere close to swim.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb the rocky wall where the drawings are. You get a better picture of them and the surrounding areas.\n", 1);
    }
	else{
		text->print("You can't do that here\n", 1);
	}
}

void Mountains::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the rocky ground.\n", 1);
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
    else if (verb == "USE"){
        if (hero->bag->inBag(itemName)){
            if ((itemName == "STONE") && (hero->getPowerStone()) ){
                if (!getItemInteraction(0)){
                    text->print("You place the stone and it powers up the " + text->changeColor("shrine", "F") + ".\n", 1);
                    setItemInteraction(0, true);
                    hero->bag->remove(itemArr[17]);
                    setRoomChanges(0, true);
			//If all 3 items used
        		if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            		text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
					"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
					"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
					"Now you can hope to restore peace to the realm", 1);
            		hero->bag->insert(itemArr[18]);
            		//Open up the tower room
            		roomArr[12]->setCanEnter(true);
            		setItemInteraction(3, true);
       		 }



                }
                else {
                    text->print("You have already used the power stone.\n", 1);
                }
            }
            else if ((itemName == "PYXIS") && (!roomArr[12]->getCanEnter())){
                if (!getItemInteraction(1)){
                    text->print("You secure the pyxis in its chamber.\n", 1);
                    setItemInteraction(1, true);
                    hero->bag->remove(itemArr[9]);
			//If all 3 items used
        	if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            	text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
				"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
				"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
				"Now you can hope to restore peace to the realm", 1);
            	hero->bag->insert(itemArr[18]);
            	//Open up the tower room
            	roomArr[12]->setCanEnter(true);
            	setItemInteraction(3, true);
        }


                }
                else {
                    text->print("You have already used the pyxis.\n", 1);
                }
            }
            else if (itemName == "HEART"){
                if (!getItemInteraction(2)){
                    text->print("You place the heart into its bloody chamber.\n", 1);
                    setItemInteraction(2, true);
                    hero->bag->remove(itemArr[8]);
			//If all 3 items used
		        if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
					text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
					"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
					"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
					"Now you can hope to restore peace to the realm", 1);
					hero->bag->insert(itemArr[18]);
					//Open up the tower room
            		roomArr[12]->setCanEnter(true);
            		setItemInteraction(3, true);
        }	
                }
                else {
                    text->print("You have already placed the heart.\n", 1);
                }
            }
            else if ((itemName == "TEXT") && (hero->getTranslatedText())){
                text->print("You read the text\n", 1);
            }
            else {
                text->print("You can't use that here.\n", 1);
            }
        }
        else {
            text->print("You cannot use what you do not have.\n", 1);
        }
    }
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Mountains::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "VALLEY" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "NAGORNY VILLAGE" || direction == "RIGHT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if(direction == "WEST" || direction == "FOREST" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "DOWN"){
		text->print("The mountains are impassable to the south.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Mountains::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Mountains::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Mountains::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}


void Mountains::transition(bool v){
	if(v){
		text->print("As you make your way through to the " + text->changeColor("mountains", "R") + ", you can't help but notice,\n"
		"that the realm, currently in peril, looks oddly beautiful from up there.\n", 1);
	}
	else{
		text->print("You walk with care on the rocky terrain. The air is thin and crisp so high up.\n", 1);
	}
}

void Mountains::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "DRAWING") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the drawings and it splashes off.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the rock drawings.\n", 1);
			}
		}
		else if (feature == "SHRINE") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the " + text->changeColor("shrine", "F") + " and it drains down the floor.\n", 1);
			}
			else {
				if (prep == "INTO" || prep == "IN") {
					if ((itemName == "STONE") && (hero->getPowerStone())) {
						if (!getItemInteraction(0)) {
							text->print("You put the stone " + text->toLowerCase(prep) + " the " + text->changeColor("shrine", "F") + " and it powers it up.\n", 1);
							setItemInteraction(0, true);
							hero->bag->remove(itemArr[17]);
							setRoomChanges(0, true);

							//If all 3 items used
        		if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            		text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
					"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
					"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
					"Now you can hope to restore peace to the realm", 1);
					hero->bag->insert(itemArr[18]);
            		//Open up the tower room
            		roomArr[12]->setCanEnter(true);
            		setItemInteraction(3, true);
       		 }

						}
						else {
							text->print("You have already put the power stone into the shrine.\n", 1);
						}
					}
					else if ((itemName == "PYXIS") && (!roomArr[12]->getCanEnter())) {
						if (!getItemInteraction(1)) {
							text->print("You put the pyxis " + text->toLowerCase(prep) + " the compartment.\n", 1);
							setItemInteraction(1, true);
							hero->bag->remove(itemArr[9]);
							//If all 3 items used
        		if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            		text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
					"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
					"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
					"Now you can hope to restore peace to the realm", 1);
					hero->bag->insert(itemArr[18]);
					//Open up the tower room
					roomArr[12]->setCanEnter(true);
					setItemInteraction(3, true);
       		 }

						}
						else {
							text->print("You have already used the pyxis.\n", 1);
						}
					}
					else if (itemName == "HEART") {
						if (!getItemInteraction(2)) {
							text->print("You drop the heart " + text->toLowerCase(prep) + " its bloody chamber.\n", 1);
							setItemInteraction(2, true);
							hero->bag->remove(itemArr[8]);
							//If all 3 items used
        						if (getItemInteraction(0) && getItemInteraction(1) && getItemInteraction(2) && !getItemInteraction(3)){
            						text->print("The shrine hums to life with the power stone inserted. \nFeeding on the General's heart, the shrine energy blasts"
									"into the pyxis. \nThe pyxis radiates with power as the transformation takes place. \nThe shrine's glow radiates across the realm.\n"
									"The General's heart feeds all its energy into the pyxis until it is used up. \nThe pyxis is powered up. Now you can fight " + text->changeColor("Agaros", "RED") + ", the Demon King..\n"
									"Now you can hope to restore peace to the realm", 1);
            						hero->bag->insert(itemArr[18]);
            						//Open up the tower room
            						roomArr[12]->setCanEnter(true);
            						setItemInteraction(3, true);
       		 					}

						}
						else {
							text->print("You have already placed the heart.\n", 1);
						}
					}

				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the " + text->changeColor("shrine", "F") + ".\n", 1);
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
