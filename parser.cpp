#include "parser.hpp"

Parser::Parser() {
	arr = new ArrayClass();
    text = new TextFormatter();
}

Parser::~Parser() {
    delete arr;
    delete text;
}

// Prompts user and valids input
std::string Parser::validateInput(std::string prompt, std::string questionType) {
	std::string input;
    std::string originalInput;
	while (true) {
		text->print(prompt, 1);
		std::getline(std::cin, input);
        originalInput = input;
        input = text->toUpperCase(input);
		if (input == "") {
			std::cout << "No input. Please try again" << std::endl;
			std::cin.clear();
		}
        else if (questionType == "yesNo"){
            if (input == "Y" || input == "N" || input == "YES" || input == "NO"){
                return originalInput;
            }
            else {
                std::cout << "I don't understand that.\n";
                std::cin.clear();
            }
        }
        else if (questionType == "number"){
            if (input == "1" || input == "2"){
                return originalInput;
            }
            else {
                std::cout << "Please make a valid selection.\n";
                std::cin.clear();
            }
        }
		else {
            return originalInput;
		}
	}
}

// Prints commands for the user
void Parser::printCommands() {
	text->print( "Help Menu\n"
    "------------------------Movement-------------------------------------\n"
    "To move, simply enter a direction(North, South, East, West), a movement verb\n"
    "with a direction, or the name of an adjacent area.\n"
    "E.g. 'I want to go north', 'south', 'walk to town', or 'town'\n"
    "\n"
    "------------------------Area features--------------------------------\n"
    "To interact with features in an area, use a verb with the feature name\n"
    "Common verbs include: climb, give, hit, push, read, sit, swim, talk, touch, and use. \n"
    "E.g. 'look at the wall', 'Touch the picture'\n"
    "\n"
    "------------------------Items in area--------------------------------\n"
    "Certain areas have items that can be interacted with. These items can be \n"
    "picked up, dropped, used, examined, etc. Once an item is picked up, it can be \n"
    "placed and dropped in any other area.\n" 
    "E.g. 'Pick up the item', 'Drop item', 'Use item',\n"
	"'Look at item': Look at item or feature.\n" 
	"They can also be placed on or around certain features.\n"
	"E.g. 'Drop the book on the table', Put the item near the stone.\n"
    "To check your currently held items and \n"
    "see their descriptions, enter the command, 'Inventory'\n"
    "\n"
    "------------------------Other commands-------------------------------\n"
    "To get a full description of your current area, enter 'look'.\n"
    "Other commands might work in certain areas but not work in others, like 'Sleep', \n"
    " 'Swim', 'Look', etc. See what works and what doesn't!\n"
    "To save your current progress, enter 'Save'. To load a saved game, enter 'Load'.\n"
    "To view your map, enter 'Map'. To check your health enter 'Health'\n"
	"Finally, to quit the game, enter 'Quit'\n", 0.5);
}

// Prompts user for input and parses output to be sent to the game class
std::string Parser::parseInput(std::string& output1, std::string& output2, std::string& output3) {
	while (true) {
		std::cout.flush();
		// Validate input and make upper case
		originalInput = validateInput(">> ");
        originalInput = text->toUpperCase(originalInput);

		//Checks if only 1 word is entered
		oneWordInput = oneWord(originalInput);

		verbFound = false;
		featureFound = false;
		itemFound = false;
		prepFound = false;
		//Search for verb
		curArray = arr->getActionArray();
		actionOutput = find(verbFound, arr->getSize(curArray), originalInput, curArray);
		if (verbFound) {
			actionOutput = actionSynonym(actionOutput);
			//Search for feature
			curArray = arr->getFeatureArray();
			featureOutput = find(featureFound, arr->getSize(curArray), originalInput, curArray);
			//Search for item
			curArray = arr->getItemArray();
			itemOutput = find(itemFound, arr->getSize(curArray), originalInput, curArray);
			if (featureFound) {
				if (itemFound) {
					//Search for prep
					curArray = arr->getPrepArray();
					prepOutput = find(prepFound, arr->getSize(curArray), originalInput, curArray);
					//If verb, item, prep, and feature
					if (prepFound && actionOutput == "DROP") {
						featureOutput = featureSynonym(featureOutput);
						itemOutput = itemSynonym(itemOutput);
						output1 = itemOutput;
						output2 = prepOutput;
						output3 = featureOutput;
						return "itemFeatureDROP";
					}
				}
				//Return Verb and Feature
				featureOutput = featureSynonym(featureOutput);
				output1 = actionOutput;
				output2 = featureOutput;
				return "verbFEATURE";
			}
			//Return verb and item
			if (itemFound) {
				itemOutput = itemSynonym(itemOutput);
				output1 = actionOutput;
				output2 = itemOutput;
				return "verbITEM";
			}
		}

		verbFound = false;
		featureFound = false;
		itemFound = false;
		directionFound = false;
		// Searches for movement verb and direction/room. "Run north" "Go up"
		curArray = arr->getMovementArray();
		actionOutput = find(verbFound, arr->getSize(curArray), originalInput, curArray);
		if (verbFound) {
            //If going to a direction
			curArray = arr->getDirectionArray();
			directionOutput = find(directionFound, arr->getSize(curArray), originalInput, curArray);
			if (directionFound) {
				directionOutput = directionSynonym(directionOutput);
				output1 = directionOutput;
				return "DIRECTION";
			}

           // If going to a feature
			curArray = arr->getFeatureArray();
			featureOutput = find(featureFound, arr->getSize(curArray), originalInput, curArray);
			if (featureFound) {
				featureOutput = featureSynonym(featureOutput);
				output1 = "GO";
				output2 = featureOutput;
				return "verbFEATURE";
			}

			oneWordInput = oneWord(originalInput);
            // If only a direction verb is input, e.g. "Go"
            if (oneWordInput){
                newInput = validateInput(text->firstLetterUpper(originalInput) + " where? >> ");
                newInput = text->toUpperCase(newInput);
                //Checks for direction
                curArray = arr->getDirectionArray();
                directionOutput = find(directionFound, arr->getSize(curArray), newInput, curArray);
			    if (directionFound) {
					directionOutput = directionSynonym(directionOutput);
				    output1 = directionOutput;
				    return "DIRECTION";
			    }

                //Checks if going to a feature
                curArray = arr->getFeatureArray();
			    featureOutput = find(featureFound, arr->getSize(curArray), newInput, curArray);
			    if (featureFound) {
					featureOutput = featureSynonym(featureOutput);
				    output1 = "GO";
				    output2 = featureOutput;
				    return "verbFEATURE";
			    }
            }
		}
        
        //Checks for Hero specific actions, e.g. "Save", "Map", "Inventory"
        verbFound = false;
        curArray = arr->getHeroArray();
		find(verbFound, arr->getSize(curArray), originalInput, curArray);
        if (verbFound){
            output1 = originalInput;
            return "HERO";
        }

		//Searches if only feature is input, e.g. "Bookcase"
		curArray = arr->getFeatureArray();
		if (oneWordSearch(originalInput, featureOutput, oneWordInput, curArray)) {
			output1 = featureSynonym(featureOutput);
			return "FEATURE";
		}

		// Searches if only direction input entered e.g. "NORTH"
		curArray = arr->getDirectionArray();
		if (oneWordSearch(originalInput, directionOutput, oneWordInput, curArray)) {
			directionOutput = directionSynonym(directionOutput);
			output1 = directionOutput;
			return "DIRECTION";
		}

		// Searches if single input verb matches the list of action verbs
		curArray = arr->getActionArray();
		if (oneWordSearch(originalInput, actionOutput, oneWordInput, curArray)) {
			output1 = actionSynonym(actionOutput);
			return "VERB";
		}

        // Searches if only item is entered, it looks at it
		itemOutput = find(itemFound, arr->getSize(curArray), originalInput, curArray);
		itemOutput = itemSynonym(itemOutput);
		oneWordInput = oneWord(itemOutput);
        if (oneWordSearch(originalInput, itemOutput, oneWordInput, curArray)){
			itemOutput = itemSynonym(itemOutput);
            output1 = "LOOK";
            output2 = itemOutput;
            return "verbITEM";
        }

		// If "HELP" entered, print commands, otherwise print command not found.
		if (originalInput == "HELP" || originalInput == "I NEED HELP") {
			printCommands();
		}
		else {
			text->print("'" + text->firstLetterUpper(originalInput) + "' is not understood here. Please try again or enter 'Help' for more options.\n", 1);
		}
		std::cout.flush();
	}
}

// Searches if single word input is in specified array. 
bool Parser::oneWordSearch(std::string input, std::string &output, bool exists, std::string* oneWordArr) {
	if (exists) {
		for (int i = 0; i < arr->getSize(oneWordArr); i++) {
			if (input == oneWordArr[i]) {
				output = curArray[i];
				return true;
			}
		}
	}
	return false;
}

// Checks for synonyms. If none are found it returns the input string.
std::string Parser::actionSynonym(std::string input) {
	// Checks for "LOOK" synonyms
	curArray = arr->getLookSyn();
	if (searchSynonym(input, curArray, arr->getSize(curArray))) {
		return "LOOK";
	}
	// Checks for "TAKE" synonyms
	curArray = arr->getTakeSyn();
	if (searchSynonym(input, curArray, arr->getSize(curArray))) {
		return "TAKE";
	}
    // Checks for "TALK" synonyms
    curArray = arr->getTalkSyn();
    if (searchSynonym(input, curArray, arr->getSize(curArray))) {
		return "TALK";
	}
    if (input == "CHECK INVENTORY"){
        return "INVENTORY";
    }
    if (input == "PUT DOWN" || input == "PLACE" || input == "INSERT" || input == "PUT"){
        return "DROP";
    }
    if (input == "LEAVE"){
        return "LEAVE TO";
    }
    if (input == "PUNCH" || input == "STRIKE"){
        return "HIT";
    }
    if (input == "TRANSLATE" || input == "INTERPRET" || input == "STUDY"){
        return "READ";
    }
    if (input == "FEEL"){
        return "TOUCH";
    }
    if (input == "REST" || input == "LIE DOWN" || input == "NAP"){
        return "SLEEP";
    }
    if (input == "ACTIVATE" || input == "INTERACT" || input == "PLACE"){
        return "USE";
    }
	return input;
}

// Searches for synonym from the synonym array. 
bool Parser::searchSynonym(std::string input, std::string* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (search(input, arr[i])) {
			return true;
		}
	}
	return false;
}

// Checks if the input is only 1 word, e.g. "LOOK"
bool Parser::oneWord(std::string input) {
	// Rare cases where it should be 1 word
	bool one;
	std::string extra;
	curArray = arr->getOneWordArray();
	extra = find(one, arr->getSize(curArray), input, curArray); 
	if (one) {
		return true;
	}
	else if (input.find(' ') != std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

/* Looks for a string within a string. The first argument is the
sentence entered. The second argument is the word being looked for */
bool Parser::search(std::string &sentence, std::string word) {
	std::size_t found;
	found = sentence.find(word);
	if (found != std::string::npos) {
		sentence = word;
		return true;
	}
	else {
		return false;
	}
}

/* Searches through array and returns string if found.*/
std::string Parser::find(bool& returnIt, int size, std::string input, std::string* arr) {
	for (int i = 0; i < size; i++) {
		returnIt = search(input, arr[i]);
		if (returnIt) {
			return arr[i];
		}
	}
	return input;
}

std::string Parser::itemSynonym(std::string item) {
	
	if (item == "BOOK" || item == "DOCUMENT") {
		return "TEXT";
	}
	if (item == "SPRING WATER") {
		return "WATER";
	}
	if (item == "CHEMICAL" || item == "ACID" || item == "CORROSIVE") {
		return "CHEMICALS";
	}
	return item;
}

std::string Parser::featureSynonym(std::string feature) {
	if (feature == "STONE TABLET") {
		return "TABLET";
	}
	if (feature == "BOOK SHELF" || feature == "BOOKCASE") {
		return "BOOKSHELF";
	}
	if (feature == "COLUMN") {
		return "COLUMNS";
	}
	if (feature == "BORIN") {
		return "ALCHEMIST";
	}
	if (feature == "ADELINA") {
		return "PRISONER";
	}
	if (feature == "DEAD BODIES") {
		return "BODIES";
	}
	if (feature == "WAGON" || feature == "WRECKAGE") {
		return "CARAVAN";
	}
	if (feature == "ROCKS" || feature == "BOULDER" || feature == "ROCK") {
		return "BOULDERS";
	}
	if (feature == "RACK" || feature == "TORTURE DEVICE") {
		return "TORTURE RACK";
	}
	if (feature == "VESSEL" || feature == "SHIP") {
		return "BOAT";
	}
	if (feature == "BOYCE" || feature == "BLACK SMITH") {
		return "BLACKSMITH";
	}
	if (feature == "MAN") {
		return "OLD MAN";
	}
	return feature;
}

std::string Parser::directionSynonym(std::string direction) {
	if (direction == "DEPIETTO FARM" || direction == "DEPIETTOS FARM" || direction == "DEPIETTO'S FARM") {
		return "FARM";
	}
	if (direction == "BLACK FOREST" || direction == "THE BLACK FOREST") {
		return "FOREST";
	}
	if (direction == "ORDEN MOUNTAINS" || direction == "ORDEN MOUNTAIN" || direction == "ORDEN") {
		return "MOUNTAINS";
	}
	if (direction == "BEDROOM" || direction == "BED ROOM") {
		return "BED CHAMBERS";
	}
	if (direction == "LABORATORY") {
		return "LAB";
	}
	if (direction == "DINING ROOM" || direction == "DININGHALL") {
		return "DINING HALL";
	}
	if (direction == "CAVES") {
		return "CAVE";
	}
	if (direction == "DESERT WASTELANDS" || direction == "WASTELANDS" || direction == "WASTELAND") {
		return "DESERT";
	}
	if (direction == "NAGORNY" || direction == "VILLAGE" || direction == "NAGORNYVILLAGE") {
		return "NAGORNY VILLAGE";
	}
	if (direction == "TOWN") {
		return "HOLMHAVEN";
	}
	if (direction == "LINOTA'S HOME" || direction == "LINOTA'S" || direction == "LINOTAS" || direction == "LINOTAS HOME") {
		return "HOME";
	}
	if (direction == "ZEMYA RIVER" || direction == "ZEMYA") {
		return "RIVER";
	}
	return direction;
}
