#include "forest.hpp"

Forest::Forest(){
    roomName = "FOREST";
	mapName = "the Black Forest";
	feature1 = "TREE";
	feature2 = "MERCHANT";
    index = 3;
}

void Forest::enterDescription(bool v){
	if(v){
		text->print("You are standing underneath a large " + text->changeColor("tree", "F") + ".\n"
		"The " + text->changeColor("merchant", "R") + " is still at his camp.\n"
		"To the South, you can see a large wall for a " + text->changeColor("castle", "R") + ".\n"
		"To the North is a path leading to a " + text->changeColor("farm", "R") + ".\n"
		"To the East you can see a range of " + text->changeColor("mountains", "R") + ",\n"
		"and to the West is the opening leading into a " + text->changeColor("cave", "R") + ".\n", 1);
	}
	else{
		text->print("You are standing underneath a thick canopy that blocks most of the sun.\n"
		"The sounds of animals, insects, and something darker fills the air.\n"
		"You have stopped underneath a unusually large " + text->changeColor("tree", "F") + ", with a trunk the size of a house.\n"
		"There is a " + text->changeColor("merchant", "F") + " who has set up camp not too far from you.\n"
		"To the South, you can see a large wall surrounding a " + text->changeColor("castle", "R") + ".\n"
		"To the North is a path leading to a " + text->changeColor("farm", "R") + ".\n"
		"To the East you can see a range of " + text->changeColor("mountains", "R") + ",\n"
		"and to the West you can make out a large dark opening leading into a " + text->changeColor("cave", "R") + ".\n", 1);
	}
	bag->inArea();
} 

void Forest::exitDescription(bool e){
	if(e){
		text->print("You leave the forest behind in search of more answers.\n", 1);
	}
	else{
		text->print("You feel as if the forest gave you more questions than answers. You strap your pack tight, and head on out.\n", 1);
	}
}
// Tree
void Forest::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
    if (verb == "TALK"){
        if (getItemInteraction(1)){
            if (!getFeature1Interaction(0)){
                if (!hero->bag->bagFull()){
                    text->print("You say the ancient phrase that Adelina told you. The massive " + text->changeColor("tree", "F") + " rumbles and slowly \n"
                    "opens a massive compartment. There is a " + text->changeColor("pyxis", "I") + " inside. You reach into the compartment and take it\n"
                    "It feels used, with no energy flowing through it. You wonder how you can power it up...\n", 1);
                    hero->bag->insert(itemArr[9]);
                    setFeature1Interaction(0, true);
                }
                else {
                    text->print("You're about to speak with the " + text->changeColor("tree", "F") + ".\n"
                    "but realize you have no room to carry the " + text->changeColor("pyxis", "I") + ".\n", 1);
                }
            }
            else {
                text->print("You speak the words to the tree but its secrets have already been revealed. \n", 1);
            }
        } 
        else {
            text->print("You speak to the tree. It seems like it is listening but nothing happens...\n", 1);
        }
    }
    else if (verb == "LOOK" || verb == "GO"){
        //If secret hasn't been revealed
        if (!getFeature1Interaction(0)){
            text->print("The tree is huge, and looks as if it has been around for thousands of years.\n", 1);
        }
        else {
            text->print("You look at the tree with its secrets revealed.\n", 1);
        }
    }
    else if (verb == "TOUCH"){
        if (!getFeature1Interaction(0)){
            text->print("You place your hand on the " + text->changeColor("tree", "F") + ". You feel an odd energy flowing within the " + text->changeColor("tree", "F") + ".\n", 1);
        }
        else {
            text->print("You feel the magical tree with its secrets.\n", 1);
        }
    }
    else if (verb == "READ"){
        text->print("There is nothing to read on the tree.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You hit the tree. A few branches shake and you hurt your hand, losing health.\n", 1);
        hero->setHealth(hero->getHealth() - 5);
    }
    else if (verb == "GIVE"){
        text->print("You have nothing to give to the tree.\n", 1);
    }
    else if (verb == "USE"){
        text->print("There is nothing to be used on the tree...\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You push the massive tree but it doesn't budge.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit next to the massive tree. It's calming aura gives you some health.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You can swim in the tree's leaves on the ground, but that wouldn't do much.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb the vast tree. To your south you see a better view of the massive Castle tower. \n"
        "In the far distance you see the dotted outlines of Holmhaven and the vast wastelands beyond it.\n", 1);
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}


//Merchant
void Forest::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if (verb == "TALK" || verb == "GO"){
        if (!getItemInteraction(0)){
            if (hero->bag->inBag("MUSHROOMS")){
                text->print("You approach the merchant by his camp.\n"
                "" + text->changeColor("Say, is that mushrooms I smell?", "YELLOW") + "\n"
                "" + text->changeColor("A trader just gave me this fine jerky. How about we make a trade?", "YELLOW") + "\nYou look in your bag and realize \n"
                "that there were plenty of mushrooms in the valley. You give him the mushrooms and take the jerky.\n"
                "The jerky is hard to the touch as you take it.\n"
                "" + text->changeColor("Thanks so much!", "YELLOW") + ", he says as you walk away.\n", 1);
                hero->bag->remove(itemArr[3]);
                hero->bag->insert(itemArr[7]);
                setItemInteraction(0, true);
            } 
            else {
                text->print("You approach the merchant by his camp.\n"
                "" + text->changeColor("Hello fellow traveler.  I've been camped here \n"
                "a few days but the forest is crawling with minions and all kinds of weird creatures. Hard to find any customers \n"
                "these days. Getting a bit hungry myself. If you happen to find any food on your travels, I'll make a trade with ya. \n"
                "A fellow traveler traded me some vegetables for this here jerky a few days back. I'll eat it if it comes to, but I'm \n"
                "more of a vegetarian myself. If you happen to find any plants or fungi, I'll trade ya for it. \n", "YELLOW"), 1);
            }
        } 
        else {
            text->print(text->changeColor("Hello Traveler! Thanks again for the mushrooms. How was the jerky?. hehehe'\n", "YELLOW"), 1);

        }
    }
    else if (verb == "GIVE" || verb == "USE"){
        if (!getItemInteraction(0)){
            if (hero->bag->inBag("MUSHROOMS")){
                text->print("You walk up to the merchant and give him the mushrooms.\n" + text->changeColor("Oh, mushrooms! My favorite! Thanks so much.\n"
                "Here is some jerky in exchange. \n", "YELLOW"), 1);
                hero->bag->remove(itemArr[3]);
                hero->bag->insert(itemArr[7]);
                setItemInteraction(0, true);
            }
            else {
                text->print("You have nothing to give to the merchant.\n", 1);
            }
        }
        else {
            text->print("You have nothing else to give to the merchant.\n", 1);
        }
    } 
    else if (verb == "LOOK"){
        if (!getItemInteraction(0)){
            text->print("You look at the merchant by his encampment. \n", 1);
        }
        else {
            text->print("You see the merchant enjoying the mushrooms. \n", 1);
        }
    }
    else if (verb == "TOUCH"){
        text->print("You go to touch the Merchant but he scoffs at you.\n", 1);
    }
    else if (verb == "READ"){
        text->print("The merchant has various wares, but no books to read.\n", 1);
    }
    else if (verb == "HIT"){
        if (getItemInteraction(0)){
            text->print("You cock back and slug the Merchant for swindling you. He cowers in fear.\n", 1);
        }
        else {
            text->print("You shouldn't hit the merchant for no reason.\n", 1);
        }
    }
    else if (verb == "PUSH"){
         if (getItemInteraction(0)){
            text->print("You push the Merchant over for swindling you. He cowers in fear.\n", 1);
        }
        else {
            text->print("You shouldn't push the merchant for no reason.\n", 1);
        }
    }
    else if (verb == "SIT"){
        text->print("You sit next to the merchant. He is humming to himself at his camp.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("There's no where to swim around here.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You can't do that.\n", 1);
    }
    else {
        text->print("You can't do that. \n", 1);
    }
}

void Forest::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the forest ground.\n", 1);
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
                "You feel swindled by the merchant. Maybe it has use elsewhere...\n", 1);
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
    else if (verb == "GIVE" || verb == "USE"){
        if (hero->bag->inBag(itemName)){
            if (itemName == "MUSHROOMS"){
                if (!getItemInteraction(0)){
                    text->print("You walk up to the merchant and give him the mushrooms.\n" + text->changeColor("Oh, mushrooms! My favorite! Thanks so much.\n"
                    "Here is some jerky in exchange. \n", "YELLOW"), 1);
                    hero->bag->remove(itemArr[3]);
                    hero->bag->insert(itemArr[7]);
                    setItemInteraction(0, true);
                }   
                else {
                    text->print(text->changeColor("The mushrooms you gave me were enough. How was the jerky?", "YELLOW") + " he snickers.\n", 1); 
                }
            }
            else {
                text->print("You shouldn't give the merchant that.\n", 1);
            }
        }
        else {
            text->print("You cannot use that which you do not have.\n", 1);
        }
    }
	else {
		text->print("There is no " + text->toLowerCase(itemName) + " around.\n", 1);
	}
}


void Forest::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "FARM" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "MOUNTAINS" || direction == "RIGHT"){
        if ((hero->bag->inBag("SWORD")) || (curRoom->getRight()->getCanEnter())){
		    curRoom->exitDescription(curRoom->getExited());
		    curRoom->setExited(true);
		    curRoom = curRoom->getRight();
		    roomDesc = true;
        }
        else {
            text->print("It's too dangerous to go through the mountains without a weapon.\n", 1);
        }
	}
	else if(direction == "WEST" || direction == "CAVE" || direction == "LEFT"){
        //If you have the master sword or you have defeated the minion
        if ((hero->getFixedSword() && hero->bag->inBag("SWORD")) || (curRoom->getLeft()->getCanEnter())){
            curRoom->exitDescription(curRoom->getExited());
			curRoom->setExited(true);
			curRoom = curRoom->getLeft();
			roomDesc = true;
        }
        else {
            text->print("You notice a large cave troll near the entrance of the cave. You need a strong weapon to fight it.\n", 1);
        }
			
	}
	else if(direction == "SOUTH" || direction == "CASTLE" || direction == "DOWN"){
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

void Forest::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Forest::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){

}

void Forest::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){

}

void Forest::transition(bool v){
	if(v){
		text->print("You've entered the " + text->changeColor("forest", "R") + " and the canopy quickly blocks the sun.\n", 1);
	}
	else{
		text->print("Leaves crunch underneath your feet as you enter the " + text->changeColor("Black Forest", "R") + ".\n"
		"Animals, or something darker, skirt across the top of the trees.\n"
		"You gather your wits, and plunge deeper into the " + text->changeColor("forest", "R") + ".\n", 1);
	}
}

void Forest::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "TREE") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the tree and its roots soak it up, giving the tree more life.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the tree\n", 1);
			}
		}
		else if (feature == "MERCHANT") {
			if (prep != "NEAR") {
				text->print("You shouldn't drop anything " + text->toLowerCase(prep) + " the Merchant.\n", 1);
			}
			else {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Merchant and it soaks the forest ground.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " near the Merchant.\n", 1);
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
