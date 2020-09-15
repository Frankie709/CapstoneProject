#include "foyer.hpp"

Foyer::Foyer(){
    roomName = "FOYER";
	mapName = "the foyer";
	feature1 = "PORTRAIT";
	feature2 = "BLOCKED DOOR";
    index = 17;
}

void Foyer::enterDescription(bool v){
	if(v){
		text->print("The makeshift wall continues to guard the " + text->changeColor("blocked door", "F") + ".\n"
		"The " + text->changeColor("portraits", "F") + " keeping watch of all who pass through the domed room.\n"
		"You see the stairs leading down to the " + text->changeColor("dungeon", "R") + " to the West.\n "
		"An unobstructed door is to the East.\n", 1);
	}
	else{
		text->print("You are in a grand dome like room. You must be in the center of the castle.\n"
		"The windows lining the front wall have been broken out, but you can make out the wall and castle grounds.\n"
		"Armed sentries patrol the outside.\n"
		"Blood stains the ground that leads West to the " + text->changeColor("dungeon", "R") + ".\n"
		"There are huge " + text->changeColor("portraits", "F") + " lining the wall high above.\n"
		"There is a make shift wall, creating a " + text->changeColor("blocked door", "F") + ". The wall comprises of\n"
		"tables, chairs... bodies.. \nIt seems The Order was trying to keep something out.. and failed..\n"
		"There is an unobstructed door to the East.\n", 1);
	}
	bag->inArea();
} 

void Foyer::exitDescription(bool e){
	if(e){
		text->print("Ears and eyes on alert, you leave the " + text->changeColor("foyer", "R") + ".\n", 1);
	}
	else{
		text->print("Getting a better understanding of what happened to The Order,\n"
		"you leave the " + text->changeColor("foyer", "R") + " in search of more answers.\n", 1);
	}
}

//Portrait
void Foyer::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		if(!getFeature1Interaction(0)){
			text->print("You get closer and look up at the " + text->changeColor("portraits", "F") + ".\n"
			"Most have been destroyed due to the recent battles, but there are 2 still standing.\n"
			"One of them is of young couple. The man is sitting on a throne, and the woman is standing next to him.\n"
			"The other is of a group of about 7 teenagers. You recognize yourself and Adelina in the second one.\n"
			"There are name plates underneath the portraits.", 1);
			setFeature1Interaction(0, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "READ"){
		if(!getFeature1Interaction(1)){
			text->print("You strain to read the name plates underneath the portraits. \n"
			"The first one reads, " + text->changeColor("King Elias and Queen Helen", "F") + ".\n"
			"The second one reads, " + text->changeColor("Initiation Class of 1530", "F") + ".\n", 1);
			setFeature1Interaction(1, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		text->print("You walk over to the " + text->changeColor("portraits", "F") + ",\n"
		"but they are too high to touch.\n", 1);
	}
    else if (verb == "HIT"){
		text->print("You try to hit the " + text->changeColor("portraits", "F") + ", but they are too high.\n", 1);

    }
    else if (verb == "TALK"){
		text->print("You look up to the " + text->changeColor("portraits", "F") + " and declare a promise to restore The Order.\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is no one to give anything to.\n", 1);

    }
    else if (verb == "USE"){
		text->print("You cannot use the " + text->changeColor("portraits", "F") + ".\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("The " + text->changeColor("portraits", "F") + " are too high to push.\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You sit and stare at the " + text->changeColor("portraits", "F") + ",\n"
		"and think how could things have gotten so dark.\n",1);
    }
    else if (verb == "SWIM"){
		text->print("You cannt not swim with the " + text->changeColor("portraits", "F") + ".\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You attempt to climb up to the " + text->changeColor("portraits", "F") + ", but there is no way up.\n", 1);
    }
	else{
		text->print("You can't do that.\n", 1);
	}
}

//blocked doors
void Foyer::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		if(!getFeature2Interaction(0)){
			text->print("You walk towards the " + text->changeColor("blocked door", "F") + ".\n"
			"Chairs, tables, any kind of wood that was around was used to construct a barrier."
			"It appears they were trying to keep someone, or something.. out of the castle.\n"
			"You can see through the barrier and can see the " + text->changeColor("castle grounds", "R") + " on the other side.\n", 1);
			setFeature2Interaction(0, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		if(!getFeature2Interaction(1)){
			text->print("You grab hold of one of the tables creating the " + text->changeColor("blocked door", "F") + " and try to open it,\n"
			"but the barrier holds on tight.\n", 1);
			setFeature2Interaction(1, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "READ"){
		text->print("There is nothing to read here.\n", 1);

    }
    else if (verb == "HIT"){
		text->print("You hit the wall creating the " + text->changeColor("blocked door", "F") + ". A large splinter goes into your hand and you lose some health.\n", 1);
        hero->setHealth(hero->getHealth() - 10);
    }
    else if (verb == "TALK"){
		text->print("There is no one to talk to here.\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is no one to accept anything here.\n", 1);

    }
    else if (verb == "USE"){
		text->print("The " + text->changeColor("blocked door", "F") + " has nothing of use.\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("You try to push open the " + text->changeColor("blocked door", "F") + ", but it holds on tight.\n", 1);

    }
    else if (verb == "SIT"){
		text->print("You sit and wonder what could have been after The Order for them to create a wall like this.\n", 1);

    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("You climb the wall creating the " + text->changeColor("blocked door", "F") + ".\n"
		"You see over the top and see armed soldiers and monsters out in the " + text->changeColor("castle grounds", "R") + ".\n"
		"You climb back down.\n", 1);
        
    }
	else{
		text->print("You can't do that.\n", 1);
	}
}


void Foyer::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the foyer floor.\n", 1);
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

void Foyer::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "TERRACE" || direction == "UP"){
		text->print("You cannot go that way. It is boarded up.\n", 1);
        setFeature2Interaction(0, true);
	}
	else if(direction == "EAST" || direction == "DINING HALL" || direction == "RIGHT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if(direction == "WEST" || direction == "DUNGEON" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "DOWN"){
		text->print("There is nothing to the south.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Foyer::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

//Portrait
void Foyer::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		text->print("The first " + text->changeColor("portrait", "F") + " is of a man and woman by the throne.\n"
		"The second " + text->changeColor("portrait", "F") + " is of a group of teenagers. You and Adelina are seen in this one.\n", 1);
	}
	else if(verb == "READ"){
		text->print("First " + text->changeColor("portrait", "F") + ": " + text->changeColor("King Elias and Queen Helen", "F") + ".\n"
		"Second " + text->changeColor("portrait", "F") + ": " + text->changeColor("Initiation Class of 1530", "F") + ".\n", 1);
	}
}

//Blocked door
void Foyer::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		text->print("The " + text->changeColor("blocked door", "F") + " is creating a barrier between the\n "
		"" + text->changeColor("foyer", "R") + " and the " + text->changeColor("castle grounds.", "F") + ".\n", 1);
	}
	else if(verb == "TOUCH"){
		text->print("You attempt to open the blocked door, but it doesnt budge..\n", 1);
	}
    
}

void Foyer::transition(bool v){
	if(v){
		text->print("Wary of any demons, you walk up the stairs to the " + text->changeColor("foyer", "R") + ".\n", 1);
	}
	else{
		text->print("You enter a staircase leading to a higher floor. You press your back against the wall,\n"
		"as you hear demonic voices upstairs. Once they go quiet, you continue on up,\n"
		"and find yourself in a grand " + text->changeColor("foyer", "R") + ".\n", 1);
	}
}

void Foyer::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "PORTRAIT") {
			if (prep != "IN" && prep != "INTO") {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the portrait and it soaks the Foyer floor.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the portrait.\n", 1);
				}
			}
			else {
				text->print("You cannot put the " + text->toLowerCase(itemName) + "in the portrait.\n", 1);
			}
		}
		else if (feature == "BLOCKED DOOR") {
			if (prep != "IN" && prep != "INTO") {
				//Get temp copy of feature we are looking for
				Item temp = hero->bag->getFeature(itemName);
				//Drop item
				if (itemName == "WATER") {
					hero->bag->remove(itemArr[11]);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the blocked door and it soaks the Foyer floor.\n", 1);
				}
				else {
					exchangeItem(bag, hero->bag, &temp);
					text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the blocked door", 1);
				}
				
			}
			else {
				text->print("You cannot put the " + text->toLowerCase(itemName) + "in the blocked door.\n", 1);
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
