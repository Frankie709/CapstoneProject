#include "home.hpp"

Home::Home(){
    roomName = "HOME";
	mapName = "Linota's home";
	feature1 = "BOOKSHELF";
	feature2 = "LINOTA";
    index = 0;
}

void Home::enterDescription(bool v) {
	if (v) {
		text->print("The fire has dwindled since you've been there last, but the light still reflects off the " + text->changeColor("bookshelf", "F") + ".\n"
		"" + text->changeColor("Linota", "F") + " looks happy to see you well.\n"
		"To the East is the old door leading out to the town.\n", 1);
	}
	else {
		 text->print("You are in a bare one-roomed hut. The walls are a pocked display of mud and stone.\n"
		"You look up and see a thatched roof, which \n"
        "has the same look and texture as " + text->changeColor("Linota's", "F") + " hair. A fire crackles loudly. \n"
		"Light reflects on the filled " + text->changeColor("bookshelf", "F") + " covering one wall.\n"
        "You look to the east and see an old door made of rotten wood. It is barely hanging on\n"
        "to its hinges and beyond the small sliver that is open you see movement about a town.\n", 1);
	}
	bag->inArea();
}
void Home::exitDescription(bool e) {
	if (e) {
		  text->print("You knew it was time to get back to work, and headed out of " + text->changeColor("Linota's\n", "F"), 1);
		
	}
	else {
		text->print("You hesistantly walk out of " + text->changeColor("Linota's", "F") + ", scared of a world you know nothing about,\n"
		"but terrified of not knowing who you are..\n", 1);
	}
}
void Home::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]) {
	//If feature is the bookshelf
	if(verb == "LOOK" || verb == "GO" || verb == "READ" || verb == "USE"){
        if (!getItemInteraction(0)){
			text->print("The bookshelf is full of worn books, covering the shelves from floor to ceiling.\n"
			"One book catches your eye. It has a leather cover, covered in dust, and looks like its about to break apart.\n", 1);
			text->print(text->changeColor("The book has a history, or so I'm told. My ancestor was said to be part of The Order long ago.\n"
			"He would always get into trouble. One day, he snuck some servants from the local town to see The Order's sacred artifacts.\n"
			"Well one of servants stole a pyxis box housing a trapped demon and unfortunately let it loose in the town. It was a massacre.\n"
			"My ancestor was kicked out, but left with this book in secret. It's meant to tell the origin of The Order, but it's in a language I don't understand.\n"
			"All it has brought my family is troubles and shame. Take it if you wish.\n", "YELLOW"), 1);
			text->print("You stare at the " + text->changeColor("Ancient Text", "I") + " with a familiar sensation in your chest.\n", 1);
            if (!hero->bag->bagFull()){
                text->print("You take it and put it in your bag...  ", 1);
                hero->bag->insert(itemArr[2]);
                setItemInteraction(0, true);
            }
            else {
                text->print("You reach to take the text, but you realize your bag is full.\n", 1);
            }
		}
		else{
			text->print("The " + text->changeColor("bookshelf", "F") + " is full of worn books. You can still see the spot where the text " + text->changeColor("Linota\n", "F")
			+ "gave you was.\n", 1);
			
		}
	}
	else if(verb == "TOUCH"){
		if (!getItemInteraction(0)){
			text->print("You drag your hand across the bookshelf and feel the leather underneath your fingers.\n"
			"A feeling of a memory creeps in your mind, of a past time when you were surrounded by books in a magnificent library..\n"
			"One book catches your eye. It has a leather cover, covered in dust, and looks like its about to break apart.\n", 1);
			text->print(text->changeColor("The book has a history, or so im told. My ancestor was said to be part of The Order long ago.\n"
			"He would always get into trouble. One day, he snuck some servants from the local town to see The Order's sacred artifacts.\n"
			"Well one of servants stole a pyxis box housing a trapped demon and unforttunately let is loose in the town...\n"
			"It was a massacre.\n"
			"My ancestor was kicked out, but left with this book in secret.\n"
			"It's meant to tell the origin of The Order, but it's in a language I don't understand.\n"
			"All its brought my family is troubles and shame. Take it if you wish.\n", "YELLOW"), 1);
			text->print("You stare at the " + text->changeColor("Ancient Text", "I") + " with a familiar sensation in your chest.\n", 1);
            if (!hero->bag->bagFull()){
                text->print("You take the book...  ", 1);
                hero->bag->insert(itemArr[2]);
                setItemInteraction(0, true);
            }
            else {
                text->print("You reach to take the text, but you realize your bag is full.\n", 1);
            }
		}
		else{
			text->print("You run your hand across the books, enjoying the feel of the leather underneath your hand.\n", 1);	
		}
	}
    else if(verb == "TAKE"){
		if (!getItemInteraction(0)){
			text->print("You drag your hand across the bookshelf and feel the leather underneath your fingers.\n"
			"A feeling of a memory creeps in your mind, of a past time when you were surrounded by books in a magnificent library..\n"
			"One book catches your eye. It has a leather cover, covered in dust, and looks like its about to break apart.\n", 1);
			text->print(text->changeColor("The book has a history, or so im told. My ancestor was said to be part of The Order long ago.\n"
			"Rumor was he would always get into trouble. One day, he snuck some servants from the local town to see The Order's sacred artifacts.\n"
			"Well one of servants stole a pyxis box housing a trapped demon and unfortunately let it loose in the town...\n"
			"It was a massacre.\n"
			"My ancestor was kicked out, but left with this book in secret.\n"
			"It's meant to tell the origin of The Order, but it's in a language I don't understand.\n"
			"All its brought my family is troubles and shame. Take it if you wish.\n", "YELLOW"), 1);
			text->print("You stare at the " + text->changeColor("Ancient Text", "I") + " with a familiar sensation in your chest.\n", 1);
            if (!hero->bag->bagFull()){
                text->print("You take the book...  ", 1);
                hero->bag->insert(itemArr[2]);
                setItemInteraction(0, true);
            }
            else {
                text->print("You reach to take the text, but you realize your bag is full.\n", 1);
            }
		}
		else{
			text->print("You run your hand across the books, enjoying the feel of the leather underneath your hand.\n", 1);	
		}
	}
    else if (verb == "HIT"){
        text->print("You hit the bookshelf and dust flies everywhere. A few books move out of place. Linota looks at you with an\n"
        "angry stare.", 1);
    }
    else if (verb == "TALK"){
        text->print("You talk to the bookshelf, but the books don't talk back.\n", 1);
    }
    else if (verb == "GIVE"){
        text->print("You have nothing to give the bookshelf.\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You push the bookshelf and it wobbles but doesn't fall over. Linota gives you an angry stare.\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit by the bookshelf, looking at all the fascinating texts.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You can't swim in here.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You climb on the bookshelf, hoping to find a hidden book. The bookshelf creaks and Linota yells at you \n"
        "to get down\n", 1);
    }
	else{
		text->print("You can't do that to the bookshelf.\n", 1);
	}
}

void Home::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	//If feature is Linota
	if(verb == "LOOK" || verb == "TALK" || verb == "GO"){
		if(!getFeature1Interaction(1)){
			setFeature1Interaction(1, true);
			text->print("You glance over at " + text->changeColor("Linota", "F") + " and she catches your eye.\n", 1);
			text->print(text->changeColor("Things haven't been the same since Queen Helen passed away 3 months ago, but I suppose you wouldn't remember who that is.\n"
			"She was the leader of The Order and The Queen, first time someone was both in their history...\n"
			"The Order is a ancient society of warriors and warlocks, capable of wielding extraordinary power,\n"
			"all in service of protecting the realm from Demons and the Darkness beyond..\n"
			"She was killed hunting a demon, or so they say..\n"
			"All I know is that the drought started right after her death, and the land started dying,\n"
			"and now no one has heard from The Order or The King.\n"
			"These are some dark times..\n", "YELLOW"), 1);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		if(!getFeature1Interaction(2)){
			text->print("You reach over and gently caress " + text->changeColor("Linota's ", "F") + "cheek.\n"
			"She just gives you a blank stare that clearly implies, \"Let's just be friends..\"\n", 1);
			setFeature1Interaction(2, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);	
		}
	}
    else if (verb == "GIVE"){
        text->print("You have nothing that you should be giving to Linota", 1);
    }
    else if (verb == "USE"){
        text->print("You have nothing to use.\n", 1);
    }
    else if (verb == "READ"){
        text->print("You read the sadness on Linota's face.\n", 1);
    }
    else if (verb == "HIT"){
        text->print("You wouldn't hit the woman who saved your life?\n", 1);
    }
    else if (verb == "PUSH"){
        text->print("You wouldn't push the woman who saved your life?\n", 1);
    }
    else if (verb == "SIT"){
        text->print("You sit on the bed by Linota.\n", 1);
    }
    else if (verb == "SWIM"){
        text->print("You can't do that.\n", 1);
    }
    else if (verb == "CLIMB"){
        text->print("You shouldn't climb on Linota.\n", 1);
    }
	else{
		text->print("You can't do that to Linota.\n", 1);
	}
}

void Home::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto Linota's floor.\n", 1);
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

void Home::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	} 
    else if (verb == "SLEEP" || verb == "REST"){
        text->print("You fall into a deep slumber on Linota's straw bed. Your health is restored.\n", 1);
        hero->setHealth(100);
    }
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Home::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if (direction == "NORTH" || direction == "UP") {
		text->print("There is only a wall north.\n", 1);
	}
	else if (direction == "EAST" || direction == "HOLMHAVEN" || direction == "RIGHT" || direction == "DOOR") {
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getRight();
		roomDesc = true;
	}
	else if (direction == "WEST" || direction == "LEFT") {
		text->print("There is nothing that way.\n", 1);
	}
	else if (direction == "SOUTH" || direction == "DOWN") {
		text->print("There is nothing to the south.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void Home::secondFeature1Interaction(std::string verb,Character *&hero, Item* itemArr[], Room* roomArr[]){

}

void Home::secondFeature2Interaction(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	//If feature is Linota
	if(verb == "LOOK" || verb == "TALK"){
		text->print(text->changeColor("Things really haven't been the same since Queen Helen passed away.\n ", "YELLOW"), 1);
	}
	else if(verb == "TOUCH"){
		text->print("You attempt to caress her cheek again, but think better of it considering your previous rejection..\n", 1);
	}
}


void Home::transition(bool v){
	if(v){
		text->print("You are back at " + text->changeColor("Linota's.\n", "F"), 1);
		text->print("The sound of " + text->changeColor("Holmhaven", "R") + " recedes as you close the door behind you.\n", 1);
	}
	else{
		text->print("You gather your wits, and raise yourself from the bed, as you take in " + text->changeColor("Linota's", "F") + " home..\n", 1);
	}
}

void Home::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "BOOKSHELF") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the bookshelf and it gets some books wet.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the bookshelf.\n", 1);
			}
			
		}
		else if (feature == "LINOTA") {
			text->print("Don't bother Linota. She saved your life after all.\n", 1);
		}
		else {
			text->print("There is no" + text->firstLetterUpper(feature) + " around.\n", 1);
		}
	}
	else {
		text->print("You cannot drop the " + text->toLowerCase(itemName) + " as it is not in your bag.\n", 1);
	}
}