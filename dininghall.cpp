#include "dininghall.hpp"

DiningHall::DiningHall(){
    roomName = "DINING HALL";
	mapName = "the Dining Hall";
	feature1 = "TABLE";
	feature2 = "NAPKIN";
    index = 11;
}

void DiningHall::enterDescription(bool v){
	if(v){
		text->print("You are standing next to the knocked over " + text->changeColor("table", "F") + ".\n"
		"The " + text->changeColor("napkin", "F") + " lays not too far from you.\n"
		"The hallway to the West, leading to the " + text->changeColor("foyer", "R") + " is quiet.\n"
		"Shadows flicker atop the stairwell heading North.\n", 1);
	}
	else{
		text->print("You are standing in the middle of a destroyed room.\n"
		"The recent fights here have knocked the mahogany " + text->changeColor("table", "F") + " on its side, broken it down the middle.\n"
		"The walls have carved indentations from an unknown attack.. Blood spatters the floor and walls.\n"
		"Bodies lay in pieces all over the place.\n"
		"A crumpled " + text->changeColor("napkin", "F") + " lays underneath the table.\n"
		"To the West is the hallway leading to the " + text->changeColor("foyer", "R") + ",\n"
		"and there is a staircase headed North.\n", 1);
	}
	bag->inArea();
} 

void DiningHall::exitDescription(bool e){
	if(e){
		text->print("With determination in your eyes, you leave the " + text->changeColor("dining room", "R") + ".\n", 1);
	}
	else{
		text->print("Tired of the chaos these monsters have created, you grip your sword tight,\n"
		"and leave the " + text->changeColor("dining room", "R") + ".\n", 1);
	}
}

//Table
void DiningHall::interactFeature1(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		if(!getFeature1Interaction(0)){
			text->print("You approach the broken " + text->changeColor("table", "F") + ".\n"
			"The once solid piece of wood has a deep impact right in the middle that caused it to break in half.\n"
			"Deep scorch marks are evident all around it.\n", 1);
			setFeature1Interaction(0, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "TOUCH"){
		if(!getFeature1Interaction(1)){
			text->print("You place your hand on the " + text->changeColor("table", "F") + ",\n"
			"and can feel the damage the table recently sustained. It must have been some battle.\n", 1);
			setFeature1Interaction(1, true);
		}
		else{
			secondFeature1Interaction(verb, hero, itemArr, roomArr);
		}
	}
  else if (verb == "READ"){
	  text->print("There is nothing to read.\n", 1);

  }
  else if (verb == "HIT"){
	  text->print("You hit the piece of wood in anger. Your hand swells up and you lose some health.\n", 1);
	  hero->setHealth(hero->getHealth() - 10);

  }
  else if (verb == "TALK"){
	  text->print("No one is around to talk except the dead.\n", 1);

  }
  else if (verb == "GIVE"){
	  text->print("Thre is no one around to give anything to.\n", 1);

  }
  else if (verb == "USE"){
	  text->print("You cnnot use the " + text->changeColor("table", "F") + ".\n", 1);

  }
  else if (verb == "PUSH"){
	  text->print("You try to push the " + text->changeColor("table", "F") + ", but it is wedged on something and doesn't budge.\n", 1);

  }
  else if (verb == "SIT"){
	  text->print("You sit on the " + text->changeColor("table", "F") + " and shed some tears for your fallen comrades. You stand back up with, vowing vengence.\n", 1);

 }
 else if (verb == "SWIM"){
	 text->print("There is nowhere to swim here.\n", 1);

 }
 else if (verb == "CLIMB"){
	 text->print("You climb on top of the " + text->changeColor("table", "F") + ", but there isn't much up here.\n"
	 "You climb back down.\n", 1);
        
 }
 else{
		text->print("You can't do that here.\n", 1);
	}
}

//Napkin
void DiningHall::interactFeature2(std::string verb, Character *&hero, Item* itemArr[], Room* roomArr[]){
	if(verb == "GO" || verb == "LOOK"){
		if(!getFeature2Interaction(0)){
			text->print("You navigate through the rubble and look at the napkin.\n"
			"It is spotted with blood and has some writing on it.\n", 1);
			setFeature2Interaction(0, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
	else if(verb == "READ"){
		if(!getFeature2Interaction(1)){
			text->print("You look at the bloody " + text->changeColor("napkin", "F") + " and can make out the following,\n"
			"" + text->changeColor("The Order has blocked the castle doors but the demons have gotten in through somewhere else.\n"
			"They've unleashed their monsters on us..\n"
			"They are dragging prisoners away..\n"
			"Darkness is upon us..\n", "F") + "", 1);
			setFeature2Interaction(1, true);
		}
		else{
			secondFeature2Interaction(verb, hero, itemArr, roomArr);
		}
	}
    else if (verb == "TOUCH"){
	  text->print("You touch the " + text->changeColor("napkin", "F") + " and can feel the dried up blood.\n", 1);

    }
    else if (verb == "HIT"){
		text->print("Why would you hit a napkin???", 1);

    }
    else if (verb == "TALK"){
		text->print("You cannot talk to the " + text->changeColor("napkin", "F") + ".\n", 1);

    }
    else if (verb == "GIVE"){
		text->print("There is no one to give anything to.\n", 1);

    }
    else if (verb == "USE"){
		text->print("There is no use for the " + text->changeColor("napkin", "F") + ".\n", 1);

    }
    else if (verb == "PUSH"){
		text->print("The " + text->changeColor("napkin", "F") + " is too small to push.\n", 1);

    }
    else if (verb == "SIT"){
		text->print("You sit and wonder at the message on the " + text->changeColor("napkin", "F") + ".\n", 1);

    }
    else if (verb == "SWIM"){
		text->print("You cannot swim here.\n", 1);

    }
    else if (verb == "CLIMB"){
		text->print("There is nothing to climb.\n", 1);
        
    }
	else{
		text->print("You can't do that here.\n", 1);
	}
}

void DiningHall::interactItem(std::string verb, std::string itemName, Character *&hero, Item* itemArr[], Room* roomArr[]){
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
            text->print("You drop the " + text->toLowerCase(itemName) + " onto the dining hall floor.\n", 1);
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

void DiningHall::changeRoom(Room *&curRoom, std::string direction, bool& roomDesc, Character *&hero, Room* roomArr[]) {
	if(direction == "NORTH" || direction == "BED CHAMBERS" || direction == "UP"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getTop();
		roomDesc = true;
	}
	else if(direction == "EAST" || direction == "RIGHT"){
		text->print("There is nothing east.\n", 1);
	}
	else if(direction == "WEST" || direction == "FOYER" || direction == "LEFT"){
		curRoom->exitDescription(curRoom->getExited());
		curRoom->setExited(true);
		curRoom = curRoom->getLeft();
		roomDesc = true;
	}
	else if(direction == "SOUTH" || direction == "LOFT" || direction == "DOWN"){
		text->print("There is nothing south.\n", 1);
	}
	else if (direction == curRoom->getRoomName()){
        enterDescription(false);
    }
	else{
		text->print("There is no " + text->firstLetterUpper(direction) + " around.\n", 1);
	}
}

void DiningHall::interactVerb(Room*& curRoom, Room* roomArr[], std::string verb, Character *&hero) {
	if (verb == "LOOK") {
		enterDescription(false);
	}
	else {
		text->print("You can't " + text->toLowerCase(verb) + " here.\n", 1);
	}
}

void DiningHall::secondFeature1Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		text->print("You approach the knocked over table. " + text->changeColor("table", "F") + " and see that it is made of solid mahogany.\n"
		"Whatever caused it to break in half must have been powerful..\n", 1);
	}
	else if(verb == "TOUCH"){
		text->print("You place your hand on the " + text->changeColor("table", "F") + ".\n"
		"You get the impression that it had been there for generations. Such a shame for it to be in this state.", 1);
	}

}

void DiningHall::secondFeature2Interaction(std::string verb, Character *&hero, Item* [], Room* roomArr[]){
	if(verb == "LOOK" || verb == "GO"){
		text->print("You look at the " + text->changeColor("napkin", "F") + " and see that it has blood and writing on it.\n", 1);
	}
	else if(verb == "READ"){
		text->print("You read the following,\n"
			"" + text->changeColor("The Order has blocked the castle doors but the demons have gotten in through somewhere else.\n"
			"They've unleashed their monsters on us..\n"
			"They are dragging prisoners away..\n"
			"Darkness is upon us..\n", "F") + "", 1);
	}

}


void DiningHall::transition(bool v){
	if(v){
		text->print("Without attracting attention, you sneak through the castle and arrive at the " + text->changeColor("dining hall", "R") + ".\n", 1);
	}
	else{
		
	}
}

void DiningHall::itemFeatureDrop(std::string itemName, std::string prep, std::string feature, Character *&hero, Item *itemArr[], Room* roomArr[]) {
	if (hero->bag->inBag(itemName)) {
		if (feature == "TABLE") {
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the Table and it spills off the side.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You drop the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the table.\n", 1);
			}
		}
		else if (feature == "NAPKIN"){
			//Get temp copy of feature we are looking for
			Item temp = hero->bag->getFeature(itemName);
			//Drop item
			if (itemName == "WATER") {
				hero->bag->remove(itemArr[11]);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the napkin and it smudges the writing.\n", 1);
			}
			else {
				exchangeItem(bag, hero->bag, &temp);
				text->print("You put the " + text->toLowerCase(itemName) + " " + text->toLowerCase(prep) + " the napkin.\n", 1);
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
