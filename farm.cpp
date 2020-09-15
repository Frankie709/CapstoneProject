#include "farm.hpp"

Farm::Farm(){
    roomName = "FARM";
	mapName = "Depietto Farm";
	feature1 = "BARN";
	feature2 = "FARMER";
    index = 8;
}

void Farm::enterDescription(bool v) {
	if (v) {
        // If dog hasn't returned
        if (!getRoomChanges(0)){
		    text->print("The delapidated " + text->changeColor("barn", "F") + " holds on to life in the distance. The " + text->changeColor("farmer", "F") + " \n"
            "stands sullenly in his field. To the South lies a " + text->changeColor("forest", "R") + " and North of you is the path back to " + text->changeColor("Holmhaven", "R") + ".\n"
            "You follow the trail of the broken fence and it leads to a " + text->changeColor("valley", "R") + " in the East. \n", 1);
        } else {
            text->print("The delapidated " + text->changeColor("barn", "F") + " holds on to life in the distance. The " + text->changeColor("farmer", "F") + " \n"
            "watches his dog run around the destroyed crops. To the South lies a " + text->changeColor("forest", "R") + " and North of you is the path back to " + text->changeColor("Holmhaven", "R") + ".\n"
            "You follow the trail of the broken fence and it leads to a " + text->changeColor("valley", "R") + " in the East. \n", 1);
        }
	}
	else {
        //if dog hasn't returned
        if (!getRoomChanges(0)){
		    text->print("You look around and see weathered fields of crops. The farm is surrounded by an old rusty fence \n"
            "that is collapsed in most places. You see an old " + text->changeColor("farmer", "F") + " standing in the middle of the field, \n"
            "looking East towards the vast " + text->changeColor("valley", "R") + ". Behind him there is an old " + text->changeColor("barn", "F") + " where you see a few haggard horses.\n"
            "In the distance to the South you see a " + text->changeColor("forest", "R") + ". \n"
			"And to the North, you can see the outline of " + text->changeColor("Holmhaven", "R") + ".\n", 1);
        } else {
            text->print("You look around and see weathered fields of crops. The farm is surrounded by an old rusty fence \n"
            "that is collapsed in most places. You see an old " + text->changeColor("farmer", "F") + " petting his dog in the middle of the field. \n"
            "It looks like he hasn't been this happy in years. Behind him there is an old " + text->changeColor("barn", "F") + " where you see a few haggard horses.\n"
            "In the distance to the South you see a " + text->changeColor("forest", "R") + ". \n"
			"To the North is " + text->changeColor("Holmhaven", "R") + ",\n"
			"and to East is a " + text->changeColor("valley", "R") + ".\n", 1);
        }
	}
	bag->inArea();
}

void Farm::exitDescription(bool e) {
    if(!e){
		text->print("You ventured to the farm hoping for answers,\n"
		"but all you found was misery and dread of what seems to be spreading in the realm.\n", 1);
	}
	else{
		text->print("As you leave the farm, you shoulder your satchel and hope for good tidings ahead.", 1);
	}
}

// Barn interaction
void Farm::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
	if (verb == "LOOK" || verb == "GO") {
		if (!getFeature1Interaction(0)){
			text->print("You approach the " + text->changeColor("barn", "F") + " looking for help. As you approach, you realize the " + text->changeColor("barn", "F") + " is in terrible shape.\n"
			"The door is missing, the windows are broken in, and there is blood leading inside.\n"
			"You walk inside, but find no signs of life. Instead, on the wall, written in blood says,\n"
            ""+ text->changeColor("They are here. Death, in human form..\n", "RED") + "You have seen enough and walk back outside.\n", 1);
			setFeature1Interaction(0, true);
		}
		else{
            secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "TOUCH"){
        text->print("You touch the " + text->changeColor("barn", "F") + " and feel the rough worn out wood underneath your fingers.\n", 1);

    }
    else if (verb == "READ"){
        text->print("You walk inside, and written in blood says, "+ text->changeColor("They are here. Death, in human form..", "RED") + ".\n You walk back out.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You cock back, but think twice about it, and don't hit the " + text->changeColor("barn", "F") + ".\n"
        "It looks as if any hit will knock it down.\n", 1);
    }
    else if (verb == "TALK"){
        text->print("The " + text->changeColor("barn", "F") + " will not talk back. What are you thinking?\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("There is no one to give anything to.\n", 1);
    }
    else if (verb == "USE"){
        text->print("The " + text->changeColor("barn", "F") + " can not be used.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You gather your strenght, and push the " + text->changeColor("barn", "F") + ".\n"
        "You feel the barn move, and stop before you knock it down.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit down on the " + text->changeColor("barn's", "F") + " steps, but feel an evil lingering,\n"
        "so you stand back up.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You find a small pond by the " + text->changeColor("barn", "F") + " and get in and relax for a bit before getting back out.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You attempt to climb the " + text->changeColor("barn", "F") + ", but it starts creaking so you stop.\n", 1);
    }
	else{
		text->print("You can't do that at the barn.\n", 1);
	}
}

// Farmer interaction
void Farm::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK"){
        //If dog isn't found
		if(!getRoomChanges(0)){  
			text->print("You look at the " + text->changeColor("farmer", "F") + ". His skin is dry and desiccated \n"
            "He is wearing torn rags for clothes as he stumbles through his fields, where there are more weeds growing \n"
            "than viable crops. Maybe you should talk to him and try to find some answers. \n", 1);
			setFeature2Interaction(0, true);
		}
        //Dog found
		else{
			text->print("The farmer is in the field playing with his dog. It is the only happiness he has is this world.\n", 1);
		}
	} else if (verb == "TALK" || "GO"){
        //If dog not found
        if (!getRoomChanges(0)){
            text->print(text->changeColor("My poor dog Maggie got startled by a demon in the field and ran off towards the valley.\n"
            "This world was already cursed. Now my poor Maggie... I'm lost without her. She's probably still spooked \n"
            "so if you see her, you'll need to give her a treat\n", "YELLOW"), 1);
        } else{
            // If first time interacting after dog found
            if (!getFeature2Interaction(1)){
                if (hero->bag->bagFull()){
                    text->print(text->changeColor("Thanks so much for finding my Maggie! I would like to give you this ", "YELLOW") + text->changeColor("oar", "I") + "\n"
                    "" + text->changeColor("but it looks like you can't add any more items to your bag. Talk to me again when you have space in \n"
                    "your bag.", "YELLOW") + "\n", 1);

                }
                else {
                    text->print(text->changeColor("You found my Maggie! Thanks so much!! I finally have some hope in this horrible world.\n"
                    "I know it's not much but take this ", "YELLOW") + text->changeColor("oar", "I") + text->changeColor(". It may help you on your \n"
                    "journey. Thanks again. I don't have much but if you ever need to rest please feel free to stay here. \n", "YELLOW"), 1);
                    hero->bag->insert(itemArr[6]);
                    text->print("You have received an oar!!\n", 1);
                    setFeature2Interaction(1, true);
                }
            } else {
                secondFeature2Interaction(verb, hero, itemArr, roomArr);
            }

        }
    }
    else if (verb == "TOUCH"){
        text->print("You reach to touch the " + text->changeColor("farmer", "F") + ", but it looks like he will hit you,\n"
        "so you decide not to.\n", 1);

    }
    else if (verb == "READ"){
        text->print("The " + text->changeColor("farmer", "F") + " has nothing to read.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You're just looking to start a fight aren't you. Leave the poor " + text->changeColor("farmer", "F") + " alone.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("You can't give the " + text->changeColor("farmer", "F") + " what he wants.\n", 1);
    }
    else if (verb == "USE"){
        text->print("You don't think its ethical to use other people..\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You go up and push the " + text->changeColor("farmer", "F") + ".\n"
        "He looks at you like if you're crazy.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit with the " + text->changeColor("farmer", "F") + " and admire the scenery in silence.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("The " + text->changeColor("farmer", "F") + " looks at you as if you're crazy\n"
        "as you swim in the pond by his " + text->changeColor("barn", "F") + ".\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You realize its a bad idea to try to climb the " + text->changeColor("farmer", "F") + ".\n", 1);
        
    }
	else{
		text->print("I dont understand that command\n", 1);
	}


}



void Farm::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the dried ground.\n", 1);
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

void Farm::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "HOLMHAVEN" || direction == "UP"){
        curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "VALLEY" || direction == "RIGHT"){
        curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if(direction == "WEST" || direction == "LEFT"){
		text->print("Overgrown thickets clog the way. You cannot go west.\n", 1);
	}
	else if(direction == "SOUTH" || direction == "FOREST" || direction == "DOWN"){
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

void Farm::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
    else if (verb == "SLEEP" || verb == "REST"){
        text->print("The " + text->changeColor("farmer", "F") + " leads you to a room in his house and you fall into a deep slumber. Your health is restored.\n", 1);
        hero->setHealth(100);
    }

	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Farm::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if (verb == "LOOK"){
        text->print("You walk towards the barns door, but remember that all that is inside is death and the words,\n"
				"" + text->changeColor("They are here. Death in human form","F") + " and decide to stay outside.\n", 1);
	}
}

void Farm::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
    if (verb == "TALK"){
        text->print("Thanks so much for finding my dog! \n", 1);
    }
}

void Farm::transition(bool v){
    if (v){
        text->print("The rot and decay appears to have spread as you return to " + text->changeColor("Depietto Farm", "R") + ".\n", 1);
    }
    else {
        text->print("You continue to walk across fields of grass. Some places green, but others show signs of rot and decay,\n"
		    "seeming to spread from black scorches in the land. You come to a large farm. You trip over a piece of wood.\n"
            "You pick it up and it says \"" + text->changeColor("Depietto Farm", "R") + "\"\n", 1);
    }
}

void Farm::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "BARN") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Farm and it soaks into the parched ground.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You drop the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the barn.\n", 1);
			}
			
		}
		else if (feature == "FARMER") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the Farmer.\n", 1);
			}
			else {

				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Farmer and the parched ground soaks it up.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You drop the " + text->toLowerCase(itemName) + " near the Farmer.\n", 1);
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
