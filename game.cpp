#include "game.hpp"

Game::Game(){
    setupRooms();
	linkRooms();
    createCharacters();
    setupItems();
	parser = new Parser();
    text = new TextFormatter();
    map = new Map();
    fs = new FileSystem();
    story = new Interaction();
}

Game::~Game(){
	deleteRooms();
    deleteCharacters();
    deleteItems();
    delete story;
	delete parser;
    delete text;
    delete map;
    delete fs;
}

// Deletes and remakes objects for loaded game within game
void Game::reloadGame(){
    deleteRooms();
    deleteCharacters();
    deleteItems();
    setupRooms();
    createCharacters();
    setupItems();
    skipTransition = true;
}

void Game::deleteItems(){
    delete ring; 
    delete sword;
    delete book;
    delete mushrooms;
    delete goggles;
    delete token;
    delete oar;
    delete jerky;
    delete heart; 
    delete ale;
    delete water;
    delete stone;
    delete screw; 
    delete chemicals;
    delete brokenSword; 
    delete pyxis;
    delete masterSword;
    delete poweredPyxis;
    delete powerStone;
    delete translatedText;
}


void Game::setupItems(){
    //Create items
    ring = new Item("RING", "a gold ring", 0);
    sword = new Item("SWORD", "a large sword. Feels worn and brittle to the touch", 1);
    book = new Item("TEXT", "Ancient text. Unknown language.", 2);
    mushrooms = new Item("MUSHROOMS", "Big edible mushrooms.", 3);
    goggles = new Item("GOGGLES", "Worn, but sturdy goggles.", 4);
    token = new Item("TOKEN", "Blacksmith's token", 5);
    oar = new Item("OAR", "Sturdy oar", 6);
    jerky = new Item("JERKY", "Smelly, hard to the touch", 7);
    heart = new Item("HEART", "Heart from slain minion", 8);
    pyxis = new Item("PYXIS", "Captures demons", 9);
    ale = new Item("ALE", "A tasty beverage", 10);
    water = new Item("WATER", "Clean purifying spring water", 11);
    stone = new Item("STONE", "Corroded stone that is covered in dirt", 12);
    screw = new Item("SCREW", "Small screw, could be used to open something..", 13);
    chemicals = new Item("CHEMICALS", "Corrosive chemicals.", 14);
    brokenSword = new Item("SWORD", "Badly damaged sword. Unusable", 15);
    masterSword = new Item("SWORD", "Fixed sword. Brimming with power", 16);
    powerStone = new Item("STONE", "Power Stone! Ancient Order stone", 17);
    poweredPyxis = new Item("PYXIS", "Powered pyxis. Can capture demons", 18);
    translatedText = new Item("TEXT", "Ancient text with deciphered alphabet", 19);
    
    
    //Add items to array
    itemArray[0] = ring;
    itemArray[1] = sword;
    itemArray[2] = book;
    itemArray[3] = mushrooms;
    itemArray[4] = goggles;
    itemArray[5] = token;
    itemArray[6] = oar;
    itemArray[7] = jerky;
    itemArray[8] = heart;
    itemArray[9] = pyxis;
    itemArray[10] = ale;
    itemArray[11] = water;
    itemArray[12] = stone;
    itemArray[13] = screw;
    itemArray[14] = chemicals; 
    itemArray[15] = brokenSword;
    itemArray[16] = masterSword;
    itemArray[17] = powerStone;
    itemArray[18] = poweredPyxis;
    itemArray[19] = translatedText;
    
}


void Game::setupRooms(){
	//Outside rooms
	home = new Home();
	caves = new Caves();
	desert = new Desert();
	forest = new Forest();
	river = new River();
	mountains = new Mountains();
	town1 = new Town1();
    town2 = new Town2();
    farm = new Farm();
	valley = new Valley();
    castle = new Castle();
	//Castle Rooms
	diningHall = new DiningHall();
	tower = new Tower();
	terrace = new Terrace();
	bedroom = new Bedroom();
	dungeon = new Dungeon();
	foyer = new Foyer();
	lab = new Lab();
    //Link room connections
    linkRooms();
    //Put rooms in roomArray
    roomArray[0] = home;
    roomArray[1] = caves;
    roomArray[2] = desert;
    roomArray[3] = forest;
    roomArray[4] = river;
    roomArray[5] = mountains;
    roomArray[6] = town1;
    roomArray[7] = town2;
    roomArray[8] = farm;
    roomArray[9] = valley;
    roomArray[10] = castle;
    //Inside castle
    roomArray[11] = diningHall; 
	roomArray[12] = tower;
	roomArray[13] = terrace;
	roomArray[14] = bedroom;
	roomArray[15] = lab;
	roomArray[16] = dungeon;
	roomArray[17] = foyer;
}

// Create hero, demon, and minion objects
void Game::createCharacters(){
	//Create Character object
	hero = new Hero();
    demon = new Demon("Aragos");
    minion1 = new Minion("The Possessed solider");
    minion2 = new Minion("The Scientist");
    minion3 = new Minion("The Cave troll");
    minion4 = new Minion("The Butcher");
    minion5 = new Minion("The General");
}

void Game::deleteCharacters(){
    delete hero;
    delete demon;
    delete minion1;
    delete minion2;
    delete minion3;
    delete minion4;
    delete minion5;
}

void Game::deleteRooms(){
	//Delete outside rooms
	delete home;
	delete caves;
	delete desert;
	delete forest;
	delete river;
	delete mountains;
	delete town1;
    delete town2;
    delete farm;
	delete valley;
    delete castle;
	//Delete castle rooms
	delete diningHall;
	delete tower;
	delete terrace;
	delete bedroom;
	delete dungeon;
	delete foyer;
	delete lab;
}

bool Game::setUp() {
	//Title
	text->print(text->changeColor("AGAROS and the Cursed Realm\n\n", "RED"), 3);
	std::string gameEnter;
	gameEnter = parser->validateInput("1.New Game\n2.Load Game\n>> ", "number");
	if(gameEnter == "1"){
		return true;
	}
	else{
        return false;
	}
}

void Game::run(){
	//If new game
	if (setUp()){
		currentRoom = home;
        hero->setName(story->intro());
	}
	else {
        
        if (fs->loadGame(currentRoom, roomArray, map, hero, itemArray,flash)){
            text->print( "Loading........\n", 1);
            story->setFlashbackCounter(flash);
        }
        else {
            text->print("Load game not available. Starting new game.\n", 1);
            currentRoom = home;
            hero->setName(story->intro());
        }
	}
	// Runs the game loop until false.
	while (gameLoop(currentRoom));
}


bool Game::gameLoop(Room*& curRoom){
	play = true;
    displayRoomDesc = true;
    skipTransition = true;
	bool victory = false;
	while(play){
        // Triggers certain story elements, such as flashbacks and fights
        if (!story->storyElements(curRoom, roomArray, itemArray, hero, minion1, minion2, 
        minion3, minion4, minion5, demon, skipTransition, victory)){
            text->print("You have been vanquished. You will never know your true identity and the \n"
            "Demon Agaros will rule the realm forever.\n", 1);
            text->print("GAME OVER\n",10);
            return false;
        }
		//If you win the game.
		if (victory) {
			return false;
		}
		/* Display the long/short form entry of room.
		If "LOOK" is entered, it repeats long form entry
		If statement is used to repeat displaying description twice */
		if (displayRoomDesc) {
            //Skips transition for new or loaded games
            if (!skipTransition){
                curRoom->transition(curRoom->getVisited());
            }
			curRoom->enterDescription(curRoom->getVisited());
		}
        skipTransition = false;
		//Turns room description off unless room is changed. 
		displayRoomDesc = false;
		// sets room visited to true.
		curRoom->setVisited(true);
        map->updateMap(curRoom, roomArray);
		// Get user input.
		userInput = parser->parseInput(output1, output2, output3);

        // If a hero command is entered such as, Save, Health, Map. 
        if (userInput == "HERO"){
            heroCommands(output1, curRoom, hero);
        }
		// If a item is placed with a preposition on a feature
		else if (userInput == "itemFeatureDROP") {
			curRoom->itemFeatureDrop(output1, output2, output3, hero, itemArray, roomArray);
		}
		// If a direction is entered e.g. "NORTH", "LEFT".
		else if(userInput == "DIRECTION"){
			curRoom->changeRoom(curRoom, output1, displayRoomDesc, hero, roomArray);
		}
		// If a single verb is input e.g. "LOOK"
		else if (userInput == "VERB") {
			curRoom->interactVerb(curRoom, roomArray, output1, hero);
		}
		// If a verb and feature are entered e.g. "LOOK AT THE TREE"
        else if(userInput == "verbFEATURE"){
            if (output2 == curRoom->getFeature1())
                curRoom->interactFeature1(output1, hero, itemArray, roomArray);
            else if (output2 == curRoom->getFeature2())
                curRoom->interactFeature2(output1, hero, itemArray, roomArray);
            else {
                text->print("There is no " + text->toLowerCase(output2) + " around.\n", 1);
            }
        }
        // If a single feature is input, such as "BOOKSHELF" shows the "look"
        else if (userInput == "FEATURE"){
            if (output1 == curRoom->getFeature1())
                curRoom->interactFeature1("LOOK", hero, itemArray, roomArray);
            else if (output1 == curRoom->getFeature2())
                curRoom->interactFeature2("LOOK", hero, itemArray, roomArray);
            else {
                text->print("There is no " + text->toLowerCase(output2) + " around.\n", 1);
            }
        }
		// If a verb and item are entered e.g. "PICK UP BOOK"
        else if(userInput == "verbITEM"){
            curRoom->interactItem(output1, output2, hero, itemArray, roomArray);
        }
		std::cout << std::endl;
        if (hero->getHealth() <= 0){
            text->print("You are ", 1);
			text->print(text->changeColor("DEAD!\n", "RED"), 10);
            play = false;
        }
	}
	return false;
}

// Will link all rooms together
// Directions not set are already set to NULL from constructor
void Game::linkRooms(){
	//Link home room
	home->setRight(town1);

	//Link Town1
	town1->setRight(river);
	town1->setTop(desert);
	town1->setBottom(farm);
	town1->setLeft(home);

	//Link Desert
	desert->setBottom(town1);
	
	//Link Valley
	valley->setTop(river);
	valley->setBottom(mountains);
	valley->setLeft(farm);

    // Link farm
    farm->setRight(valley);
    farm->setTop(town1);
    farm->setBottom(forest);

	//Link Forest
	forest->setRight(mountains);
	forest->setTop(farm);
	forest->setBottom(castle);
	forest->setLeft(caves);

	//Link River
	river->setLeft(town1);
	river->setBottom(valley);

	//Link Mountains
	mountains->setTop(valley);
	mountains->setRight(town2);
	mountains->setLeft(forest);

	//Link Caves
	caves->setRight(forest);
	caves->setBottom(dungeon);

	//Link Castle
	castle->setTop(forest);

    //Link nagory village
    town2->setLeft(mountains);

    //Inside Castle rooms

	//Link Foyer
	foyer->setLeft(dungeon);
	foyer->setRight(diningHall);

	//Link Dungeon
    dungeon->setTop(caves);
	dungeon->setRight(foyer);
	dungeon->setBottom(lab);

	//Link lab 
	lab->setTop(dungeon);

	//Link Terrace
	terrace->setTop(tower);
    terrace->setRight(bedroom);

	//Link Bedroom
	bedroom->setLeft(terrace);
	bedroom->setBottom(diningHall);

	//Link tower
	tower->setBottom(terrace);

    //Link dining room
    diningHall->setTop(bedroom);
    diningHall->setLeft(foyer);
	
}

void Game::heroCommands(std::string command, Room*& curRoom, Character* h){
    std::string answer;
    if (command == "SAVE" || command == "SAVE GAME"){
        if(fs->saveGame(curRoom, roomArray,story->getFlashbackCounter(), hero, map)){
            text->print("Game saved.\n", 1);
        } else {
            text->print("Error saving game.\n", 1);
        }   
    } 
    else if (command == "MAP") {
        map->displayMap(curRoom);
    } 
    else if (command == "INVENTORY" || command == "BAG") {
        h->bag->display();
    } 
    else if (command == "HEALTH"){
        text->print("Your health is: " + std::to_string(hero->getHealth()), 1);
    } 
    else if (command == "QUIT") {
        answer = parser->validateInput("Do you really want to quit? (Y/N): ", "yesNo");
        answer = text->toUpperCase(answer);
        if (answer == "Y" || answer == "YES") {
            play = false;
            answer = parser->validateInput("Would you like to save your game? (Y/N): ", "yesNo");
            if (answer == "Y" || answer == "YES"){
                if(fs->saveGame(curRoom, roomArray, story->getFlashbackCounter(), hero, map)){
                    text->print("Game saved.\n", 1);
                } else {
                    text->print("Error saving game.\n", 1);
                } 
            }
			text->print("You exit the realm, leaving people to their cursed fate.\n", 1);
		}
    } 
    else if (command == "LOAD" || command == "LOAD GAME") {
        answer = parser->validateInput("Do you want to load your saved game? (Y/N): ", "yesNo");
        answer = text->toUpperCase(answer);
        if (answer == "Y" || answer == "YES") {
            // Resets the maps in the game loop
            map->setUpOutsideMap();
            map->setUpCastleMap();
            // Resets the game rooms
            reloadGame();
            if (fs->loadGame(currentRoom, roomArray, map, hero, itemArray, flash)){
                story->setFlashbackCounter(flash);
                text->print( "Loading........\n", 1);
                curRoom->enterDescription(true);
            }
            else {
                text->print("Load game not available. Continuing game.\n", 1);
            }
		}
    }
}
