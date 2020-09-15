#include "town2.hpp"

Town2::Town2(){
    roomName = "NAGORNY VILLAGE";
	mapName = "Nagorny village";
	feature1 = "BLACKSMITH";
	feature2 = "ALCHEMIST";
    index = 7;
}


void Town2::enterDescription(bool v) {
	if (v) {
		text->print("The village is noisy as people pass by you.\n"
        "The " + text->changeColor("blacksmith", "F") + " sits idly by,\n"
        "the " + text->changeColor("alchemist's", "F") + " shop continues to exhume vapors.\n"
        "The path to the " + text->changeColor("mountains", "F") + " lies to the west.\n", 1);
	}
	else {
		text->print("You stand at the center of the village. The air is hazy as you are amongst the clouds. In the far distance\n"
        "you spy the castle tower. You ponder at the evil that lies in wait there.\n"
        "A sullen " + text->changeColor("blacksmith", "F") + " sits on the ground. \n"
        "Strange odors spew out of an " + text->changeColor("alchemist's", "F") + " shop.\n"
        "To the West lies the path back to the " + text->changeColor("mountains", "R") + ".\n", 1);
	}
	bag->inArea();
}

void Town2::exitDescription(bool e) {
	if (e) {
		text->print("You stretch your legs and head back towards the " + text->changeColor("mountains", "F") + ".\n", 1);
	}
	else {
		text->print("Wind blasts you in the face as you head out of the village towards the " + text->changeColor("mountains", "F") + ".\n", 1);
	}
}
// Blacksmith
void Town2::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
	if (verb == "TALK" || verb == "GO") {
        //If not interacted with before
        if (!getItemInteraction(0)){
            //If you don't have his ale
            if (!hero->bag->inBag("ALE")){
                //If you can take his token
                if (!hero->bag->bagFull()){
                    text->print(text->changeColor("'OYE! You happen to been in Holmhaven? They 'ave the best\n"
                    "Ale in the realm. I 'aven't had any in weeks, with what's going on n\n"
                    "all, demons and all. I need it to steady my hand. Borin told me about your broken sword. Im terribly sorry.\n"
                    "No warrior should be without their sword.\n"
                    "If you get me some Ale from the market there,\n" 
                    "I'll fix that broken sword of yours right up! Make it \n"
                    "twice as strong I will. Take this token and use it in the market, they'll \n"
                    "know my sigil and have the ale flowing in no time!\n", "YELLOW"), 1);
                    text->print("You received the token!", 1);
                    hero->bag->insert(itemArr[5]);

                } else {
                    text->print(text->changeColor("'Oye, I'd love to fix yer broken sword, but I need some ale first.\n"
                    "Drop something from yer bag and I'll help ya and ya can help me!\n", "YELLOW"), 1);
                }
            //If you have his ale
            } else {
                //If you are carrying the sword
                if(hero->bag->inBag("SWORD")){
                    text->print(text->changeColor("'Oye! You got me Ale! Oh happy days. Give it here and I'll fix that broken sword right up\n"
                    "and make it strong enough to slay the strongest minion!", "YELLOW") + "\nYou hand over the ale to Boyce\n"
                    "" + text->changeColor("'SHAZAAMM!' Haven't had ale like that in weeks! Give me that broken sword and I'll fix it right up\n", "YELLOW") + "\n"
                    "He hacks away at it as you wander around the village. After a few hours he hands you your new \n"
                    "master sword. You can feel its power pulsing in your hands.", 1);
                    hero->bag->remove(itemArr[10]);
                    hero->bag->remove(itemArr[15]);
                    hero->bag->insert(itemArr[16]);
                    hero->setFixedSword(true);
                    setItemInteraction(0, true);
                }
                else{
                    text->print(text->changeColor("'Oye! You got me Ale! But I would feel terribly if I took it without given ya anything in return!\n"
                    "I know! Bring me something broke, and I'll fix er right up!\n", "YELLOW"), 1);
                }   
            } 
        } else {
            text->print(text->changeColor("'OYE! How's that sword holding up? <buurrrp>\n", "YELLOW"), 1);
            }
    } else if (verb == "LOOK"){
        if (!getItemInteraction(0)){
            text->print("Boyce the blacksmith is sitting sullenly by his shop. He looks like\n"
            "he needs something. Maybe you should talk to him...\n", 1);
        } else {
            text->print("Boyce is drunkenly pounding steel in his shop. Doesn't have a care in the world\n", 1);
        }
    } else if (verb == "HIT") {
        if (!getFeature1Interaction(2)){
            text->print(text->changeColor("'OYE, Don't do that. I'll hit you if you do that again!\n", "YELLOW"), 1);
            setFeature1Interaction(2, true);
        } else {
            secondFeature1Interaction(verb, hero, itemArr, roomArr);
        }
    } else if (verb == "GIVE" || verb == "USE") {
        if (getItemInteraction(0)){
            text->print(text->changeColor("'Oye, You've given me all I could ever want!< Burrrp>\n", "YELLOW"), 1);
        } else {
            if (hero->bag->inBag("ALE")){
                //If you are carrying the sword
                if(hero->bag->inBag("SWORD")){
                    text->print(text->changeColor("'Oye! You got me Ale! Oh happy days. Give it here and I'll fix that broken sword right up\n"
                    "and make it strong enough to slay the strongest minion!", "YELLOW") + "\nYou hand over the ale to Boyce\n"
                    "" + text->changeColor("'SHAZAAMM!' Haven't had ale like that in weeks! Give me that broken sword and I'll fix it right up\n", "YELLOW") + "\n"
                    "He hacks away at it as you wander around the village. After a few hours he hands you your new \n"
                    "master sword. You can feel its power pulsing in your hands.", 1);
                    hero->bag->remove(itemArr[10]);
                    hero->bag->remove(itemArr[15]);
                    hero->bag->insert(itemArr[16]);
                    hero->setFixedSword(true);
                    setItemInteraction(0, true);
                }
                else{
                    text->print(text->changeColor("'Oye! You got me Ale! But I would feel terribly if I took it without given ya anything in return!\n"
                    "I know! Bring me something broke, and I'll fix er right up!\n", "YELLOW"), 1);
                }
            } else {
                text->print(text->changeColor("'Oye! If you ain't got ale then there's nothing else I want.\n", "YELLOW"), 1);
            }
        }
    }
    else if (verb == "TOUCH"){
        text->print(text->changeColor("'Oye, Don't touch me!\n", "YELLOW"), 1);
    }
    else if (verb == "READ"){
        text->print("There is nothing to read in Boyce's shop.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You push Boyce.\n" + text->changeColor("'OYE! Don't push me mate!\n", "YELLOW"), 1);
    }
    else if (verb == "SIT"){
        text->print("You sit in Boyce's shop. It feels good to rest for a moment.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("Up on the mountain, there is nowhere to swim around.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You try to climb on Boyce's back but he throws you off.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

//Alchemist
void Town2::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "LOOK") {
        text->print("You walk into the Alchemist's shop and see all the chemicals and tinctures. \n"
        "The alchemist is busy working.\n", 1);
    } else if (verb == "GIVE") {
        if (hero->bag->inBag("STONE")){
            text->print(text->changeColor("Oh, what is that there? Let me have a look. I have just the right\n"
            "chemical to clean this up.\n","YELLOW") + "He mixes a tincture together and then puts the dirty stone in the mix\n"
            "He keeps the stone in the mixture for a few minutes before taking it out and washing it off. He looks at \n"
            "the stone for a minute and then pauses." + text->changeColor("'Oh my... This.. this is one of the legendary soul stones. Where on \n"
            "earth did you get this?\n", "YELLOW") + "You take the power stone\n", 1);
            hero->bag->remove(itemArr[12]);
            hero->bag->insert(itemArr[17]);
            hero->setPowerStone(true);
            setItemInteraction(1, true);
        }
        else {
            text->print("There's nothing else to give him.\n", 1);
        }
    } else if (verb == "TALK" || verb == "GO" || verb == "USE" || verb == "GIVE"){
        // If you already have the power stone.
        if (getItemInteraction(1)){
            text->print(text->changeColor("Where did you ever find that power stone?\n", "YELLOW"), 1);
        } else if (hero->bag->inBag("STONE") && !getItemInteraction(1)){
            text->print("You go up to the Alchemist.\n" + text->changeColor("'Oh, what is that stone you have? 'I have just the right\n"
            "chemical to clean it up'.\n", "YELLOW") + "You hand him the stone and he mixes a tincture together and then puts the dirty stone in the mix\n"
            "He keeps the stone in the mixture for a few minutes before taking it out and washing it off. He looks at \n"
            "the stone for a minute and then pauses.\n" + text->changeColor("'Oh my... This.. this is one of the legendary soul stones. Legend has it the \n"
            "Order used these to power their shrines to perform rituals. Where on earth did you get this?\n", "YELLOW") + "He hands you the " + text->changeColor("power stone", "I") + "\n", 1);
            text->print("You hold it in your hand and look at it in awe\n", 1);
            hero->bag->remove(itemArr[12]);
            hero->bag->insert(itemArr[17]);
            hero->setPowerStone(true);
            setItemInteraction(1, true);
        }
        else{
            text->print(text->changeColor("If you ever need anything cleaned, I have just the chemicals and mixtures for it!\n", "YELLOW"), 1);
        }
    }
    else if (verb == "TOUCH"){
        text->print("You touch the Alchemists beard. He gives you a weird look and mumbles something about the poison\n"
        "affecting your brain.\n", 1);
    }
    else if (verb == "READ"){
        text->print("There are vast Alchemy books around, but you don't understand the first thing about it.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("The Alchemist saved your life, you shouldn't hit him.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("The Alchemist saved your life, you shouldn't push him.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit in the Alchemist's shop, looking at all his tinctures.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("Up on the mountain, there is nowhere to swim around.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("The Alchemist saved your life, you shouldn't climb on him.\n", 1);
    }
	else{
		text->print("I dont understand that command\n", 1);
	}
}

void Town2::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            } else {
			    exchangeItem(bag, hero->bag, &temp);
            }
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the village floor.\n", 1);
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
    // If you give him the stone
    else if (verb == "GIVE" || verb == "USE") {
        if (hero->bag->inBag(itemName)){
            if (itemName == "STONE"){
                if (!getItemInteraction(1)){
                    text->print("You walk into the Alchemist's house and hand him the dirty stone.\n" + text->changeColor("'Oh, what is that stone you have? 'I have just the right\n"
                    "chemical to clean it up.\n", "YELLOW") + "You hand him the stone and he mixes a tincture together and then puts the dirty stone in the mix\n"
                    "He keeps the stone in the mixture for a few minutes before taking it out and washing it off. He looks at \n"
                    "the stone for a minute and then pauses.\n" + text->changeColor("'Oh my... This.. this is one of the legendary soul stones. Legend has it the \n"
                    "Order used these to power their shrines to perform rituals. Where on earth did you get this?\n", "YELLOW") + "He hands you the power stone\n"
                    "and you look at it in awe\n", 1);
                    hero->bag->remove(itemArr[12]);
                    hero->bag->insert(itemArr[17]);
                    hero->setPowerStone(true);
                    setItemInteraction(1, true);
                }
                else {
                    text->print("You have already given him the stone.\n", 1);
                }
            }
            else if (itemName == "ALE"){
                if (!getItemInteraction(0)){
                    //If you are carrying the sword
                    if(hero->bag->inBag("SWORD")){
                    text->print(text->changeColor("'Oye! You got me Ale! Oh happy days. Give it here and I'll fix that broken sword right up\n"
                    "and make it strong enough to slay the strongest minion!", "YELLOW") + "\nYou hand over the ale to Boyce\n"
                    "" + text->changeColor("'SHAZAAMM!' Haven't had ale like that in weeks! Give me that broken sword and I'll fix it right up\n", "YELLOW") + "\n"
                    "He hacks away at it as you wander around the village. After a few hours he hands you your new \n"
                    "master sword. You can feel its power pulsing in your hands.", 1);
                    hero->bag->remove(itemArr[10]);
                    hero->bag->remove(itemArr[15]);
                    hero->bag->insert(itemArr[16]);
                    hero->setFixedSword(true);
                    setItemInteraction(0, true);
                    }
                    else{
                        text->print(text->changeColor("'Oye! You got me Ale! But I would feel terribly if I took it without given ya anything in return!\n"
                        "I know! Bring me something broke, and I'll fix er right up!\n", "YELLOW"), 1);
                    }
                }
                else {
                    text->print("Boyce is already content with his ale.\n", 1);
                }
            }
            else {
                text->print("You cannot give that here.\n", 1);
            }
        }
        else {
            text->print("You cannot give what you do not have.\n", 1);
        }
    }
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}

void Town2::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "UP"){
		text->print("The terrain is impassable that way. You can't go there.\n", 1);
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("There is a steep cliff that way. You cannot go east.\n", 1);
	}
	else if(direction == "WEST" || direction == "MOUNTAINS" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "DOWN"){
		text->print("A sharp cliff lies to the south. You cannot go that way.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Town2::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	} 
    else if (verb == "SLEEP"){
        text->print("You go to the Alchemist's house and he lets you rest upstairs. You feel refreshed. \n", 1);
        hero->setHealth(100);
    }
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Town2::secondFeature1Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if (verb == "HIT") {  
        text->print(text->changeColor("OYE!! What did I say?\n", "YELLOW") + "Boyce cocks back and clocks you in the face\n"
        "You fall back and hit your head on the ground, losing 10 health points.\n", 1);
        hero->setHealth(hero->getHealth() - 10);
    }
}

void Town2::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Town2::transition(bool v){
    if (v){
        text->print("You climb the rugged mountain until you reach " + text->changeColor("Nagorny Village", "R") + ".\n", 1);
    } else {

    }
}

void Town2::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "ALCHEMIST") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the Alchemist.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Alchemist and it soaks into his stone floor.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the Alchemist", 1);
				}
			}
		}
		else if (feature == "BLACKSMITH") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the Blacksmith.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Blacksmith and it washes to the floor"
					"" + text->changeColor("'OYE! Least it ain't Ale!","YELLOW") + "he shouts .\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
				}
				text->print("You put the " + text->toLowerCase(itemName) + " near the Blacksmith", 1);
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
