#include "bedroom.hpp"

Bedroom::Bedroom(){
	roomName = "BED CHAMBERS";
    mapName = "the Bed Chambers";
	feature1 = "JOURNAL";
	feature2 = "PENTAGRAM";
    index = 14;
}

void Bedroom::enterDescription(bool v){
	if(v){
		text->print("You spot the " + text->changeColor("journal", "F") + " underneath the rubble of the old bed.\n"
		"The " + text->changeColor("pentagram", "F") + " on the floor continues to feed dark energy in the room.\n"
		"The door to the South leads back to the " + text->changeColor("dining hall", "R") + ".\n" 
		"And there is a door to the West that leads to the " + text->changeColor("terrace", "R") + ".\n", 1);
	}
	else{
		text->print("The room you stand in smells of sulfur. Demonic energy lingers in the air.\n"
		"The four poster bed has been blasted against one wall, and in the center of the room,\n"
		"you see a large " + text->changeColor("pentagram", "F") + ".\n"
		"The candles at the five points have long been extinguished.\n "
		"You realize this is no typical summoning. Something darker is at play here.\n"
		"Underneath the rubble of the bed, you spot a " + text->changeColor("journal", "F") + ".\n"
		"The door to the South leads back to the " + text->changeColor("dining hall", "R") + ".\n" 
		"And there is a door to the West that appears to lead to a " + text->changeColor("terrace", "R") + ".\n", 1);
	}
    bag->inArea();
} 

void Bedroom::exitDescription(bool e){
	if(e){
		text->print("Feeling as if you are nearing the end of your journey,\n"
		"you leave the " + text->changeColor("bedroom", "R") + ".\n", 1);
	}
	else{
		text->print("The puzzle finally falling into place,\n"
		"you step out of the " + text->changeColor("bedroom", "R") + " in search of the final truth.\n", 1);		
	}
}

// Journal
void Bedroom::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		text->print("You approach the rubble and squat down to pick up the " + text->changeColor("journal", "F") + ".\n"
		"Most of the pages have been destroyed, but there are a couple intact at the end.\n"
		"You return the book to where it was.\n", 1);
	}
	else if(verb == "READ" || verb == "USE"){
		if(!getFeature1Interaction(0)){
			text->print("You pick up the " + text->changeColor("journal", "F") + " and flip to the pages that are intact.\n"
			"The " + text->changeColor("journal", "F") + " appears to have belonged to Queen Helen.\n"
			"There is an entry from a couple of months ago..\n", 1);
			text->print(text->changeColor("July 26, 1532\n"
			"The hunt went badly as soon as we arrived to the demon's stronghold.\n"
			"The demons had opened a rift, and more and more demons were pouring out.\n"
			"We were overwhelmed. I was bit by a huge insectile monster. Pain and then numbness flooded my body.\n"
			"I then woke here, in my bed. I have been kept away from the Elders. I must tell them what I saw.\n"
			"It was a trap to draw me out. The true target is the King. They mean to make this realm their own..\n"
			"I fear I don't have much time left.. The poison has worked its way throughout my system..\n"
			"I only hope someone finds this..\n", "F"), 1);
			setFeature1Interaction(0, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		text->print("You reach to grab the " + text->changeColor("journal", "F") + " and feel it in the palm of your hands.\n"
		"The leather is smooth but burned in most places.\n", 1);

	}
    else if (verb == "HIT"){
		text->print("Why would you hit the journal??", 1);
    }
    else if (verb == "TALK"){
		text->print("You cannot talk to the owner of the " + text->changeColor("journal", "F") + ".\n", 1);
    }
    else if (verb == "GIVE"){
		text->print("There is no one to give anything to.\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("You push the " + text->changeColor("journal", "F") + " around, but nothing comes of it.\n", 1);

    }
    else if (verb == "SIT"){
		text->print("You sit on the floor and inspect the " + text->changeColor("journal", "F") + " closely,\n"
		"thinking about the owner of it.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You cannot swim with the " + text->changeColor("journal", "F") + ".\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("You cannot climb the " + text->changeColor("journal", "F") + ".\n", 1);
        
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

// Pentagram
void Bedroom::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO" || verb == "TOUCH" || verb == "READ"){
		if(!getFeature2Interaction(0)){
			text->print("You carefully approach the " + text->changeColor("pentagram", "F") + ".\n"
			"You can feel dark energy pouring out of it, as if the connection was never broken..\n"
			"All you can think of is that the King much have been truly desperate to come to this..\n", 1);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "HIT"){
		text->print("You cock back and hit the " + text->changeColor("pentagram", "F") + ".\n"
		"Dark energy comes out and hurts you and you lose some health..\n ", 1);
		hero->setHealth(hero->getHealth() - 10);
    }
    else if (verb == "TALK"){
		text->print("You should not talk to the " + text->changeColor("pentagram", "F") + ".\n"
		"That is how this nightmare started.\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("You should not be giving anything to the " + text->changeColor("pentagram", "F") + ".\n", 1);
    }
    else if (verb == "USE"){
		text->print("You should not use to the " + text->changeColor("pentagram", "F") + ".\n"
		"That is how this nightmare started.\n", 1);
    }
    else if (verb == "PUSH"){
		text->print("There is no way to push the " + text->changeColor("pentagram", "F") + ".\n", 1);
    }
    else if (verb == "SIT"){
		text->print("You look at the " + text->changeColor("pentagram", "F") + " on the floor and decide not to sit down.\n", 1);
    }
    else if (verb == "SWIM"){
		text->print("You can't swim here.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("There is no way to climb the " + text->changeColor("pentagram", "F") + ".\n", 1);
        
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}


void Bedroom::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the bed chamber's floor.\n", 1);
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

void Bedroom::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "UP"){
		text->print("There is nothing north\n", 1);
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("There is nothing east\n", 1);
	}
	else if(direction == "WEST" || direction == "TERRACE" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "DINING HALL" || direction == "DOWN"){
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

void Bedroom::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
    else if (verb == "SLEEP"){
        text->print("There is too much evil in here to try to sleep. \n", 1);
    }
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void Bedroom::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "READ"){
		text->print("You flip through the entry again, taking note of the Rift Queen Helen mentioned,\n"
		"and how she was a trap to get to the King.\n", 1);
	}

}

void Bedroom::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO" || verb == "TOUCH"){
		text->print("You inspect the " + text->changeColor("pentagram", "R") + " for additional clues.\n"
		"put all you find is the feeling of sorrow and death..\n", 1);
	}

}

void Bedroom::transition(bool v){
	if(v){
		text->print("You avoid the sight of a passing demon, and make your way into the " + text->changeColor("bedroom", "R") + ".\n", 1);
	}
	else{
		text->print("You creep up the stairs. The air seems to have been sucked of all sound.\n"
		"You can hear your heart throbbing against your rib cage. The hairs on your skin start to prickle.\n"
		"You reach a platform with a lone door. You open and head inside, and find yourself in a " + text->changeColor("bedroom", "R") + ".\n", 1);
	}
}

void Bedroom::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "PENTAGRAM") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the pentagram and it steams off it.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You drop the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the pentagram.\n", 1);
			}
		}
		else if (feature == "JOURNAL") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the journal and it smudges the writing.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the journal.\n", 1);
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

