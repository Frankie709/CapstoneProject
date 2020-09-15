#include "filesystem.hpp"

void FileSystem::saveRoomData(Room* saveRoom){
    std::string fileName = "saveData//" + saveRoom->getRoomName() + ".txt";
    std::ofstream roomSaveFile(fileName, std::ofstream::trunc);
    if (roomSaveFile.is_open()){
        if (saveRoom->getVisited()){
            roomSaveFile << "true\n";
        }
        else {
            roomSaveFile << "false\n";
        }

        //Save exited as true or false
        if (saveRoom->getExited()){
            roomSaveFile << "true\n";
        } 
        else {
            roomSaveFile << "false\n";
        }

        //Save canEnter as true or false
        if (saveRoom->getCanEnter()){
            roomSaveFile << "true\n";
        }
        else {
            roomSaveFile << "false\n";
        }

        //Get Feature1 interactions
        for (int i = 0; i < 5; i++){
            if (saveRoom->getFeature1Interaction(i)){
                roomSaveFile << "true\n";
            }
            else {
                roomSaveFile << "false\n";
            }
        }

        //Get Feature2 interactions
        for (int i = 0; i < 5; i++){
            if (saveRoom->getFeature2Interaction(i)){
                roomSaveFile << "true\n";
            }
            else {
                roomSaveFile << "false\n";
            }
        }
        //Get item interactions
        for (int i = 0; i < 10; i++){
            if (saveRoom->getItemInteraction(i)){
                roomSaveFile << "true\n";
            }
            else {
                roomSaveFile << "false\n";
            }
        }
        //Get room changes
        for (int i = 0; i < 2; i++){
            if (saveRoom->getRoomChanges(i)){
                roomSaveFile << "true\n";
            }
            else {
                roomSaveFile << "false\n";
            }
        }

        //Save items in bag
        if (saveRoom->bag->getCount() > 0){
            roomSaveFile << saveRoom->bag->printIndex();
        }
        roomSaveFile.close();
    }
    else {
        std::cout << "Unable to access file\n";
    }
}

bool FileSystem::saveGame(Room*& curRoom, Room* roomArr[], int counter, Character* h, Map* m) {
    std::ofstream saveFile("saveData//save.txt", std::ofstream::trunc);
    if (saveFile.is_open()){
        saveFile << curRoom->getIndex() << std::endl;
        saveFile << counter << std::endl;
        for (int i = 0; i < 18; i++){
		saveFile << roomArr[i]->getIndex() << std::endl;
                saveRoomData(roomArr[i]);
        }
        saveFile.close();
    }
    else {
        return false;
    }
    std::ofstream heroSave("saveData//hero.txt", std::ofstream::trunc);
    if (heroSave.is_open()){
        //Save hero name, health, and armor.
        heroSave << h->getName() << std::endl;
        heroSave << h->getHealth() << std::endl;
        heroSave << h->getArmor() << std::endl;
        //Save fixed sword
        if (h->getFixedSword()){
            heroSave << "true\n";
        }
        else {
            heroSave << "false\n";
        }
        //Save text translator
        if (h->getTranslatedText()){
            heroSave << "true\n";
        }
        else {
            heroSave << "false\n";
        }
        //Save power stone
        if (h->getPowerStone()){
            heroSave << "true\n";
        }
        else {
            heroSave << "false\n";
        }
        //Save items in bag
        if (h->bag->getCount() > 0){
            heroSave << h->bag->printIndex();
        }
        heroSave.close();
    }
    else {
        return false;
    }

    //Save outside map
    std::ofstream outsideSave("saveData//outsideMap.txt", std::ofstream::trunc);
    if (outsideSave.is_open()){
        outsideSave << m->saveMap("OUTSIDE");
        outsideSave.close();
    }
    else {
        return false;
    }
    
    //Save castle map
    std::ofstream castleSave("saveData//castleMap.txt", std::ofstream::trunc);
    if (castleSave.is_open()){
        castleSave << m->saveMap("CASTLE");
        castleSave.close();
    }
    else {
        return false;
    }

    return true;
}

void FileSystem::loadRoomData(int position, Room* roomArr[], Item* itmArr[]){
    std::ifstream loadRoom("saveData//" + roomArr[position]->getRoomName() + ".txt");
    if (loadRoom.is_open()){
        //Set entered room variable
        std::getline(loadRoom, dataRead);
        if (dataRead == "true"){
            roomArr[position]->setVisited(true);
        }
        else {
            roomArr[position]->setVisited(false);
        }
        //Set the exited room variable
        std::getline(loadRoom, dataRead);
        if (dataRead == "true"){
            roomArr[position]->setExited(true);
        } 
        else {
            roomArr[position]->setExited(false);
        }

        //Set can enter variable
        std::getline(loadRoom, dataRead);
        if (dataRead == "true"){
            roomArr[position]->setCanEnter(true);
        }
        else {
            roomArr[position]->setCanEnter(false);
        }

        // Set feature1 interaction variables
        for (int i = 0; i < 5; i++){
            std::getline(loadRoom, dataRead);
            if (dataRead == "true"){
                roomArr[position]->setFeature1Interaction(i, true);
            }
            else {
                roomArr[position]->setFeature1Interaction(i, false);
            }
        }

        // Set feature2 interaction variables
        for (int j = 0; j < 5; j++){
            std::getline(loadRoom, dataRead);
            if (dataRead == "true"){
                roomArr[position]->setFeature2Interaction(j, true);
            }
            else {
                roomArr[position]->setFeature2Interaction(j, false);
            }
        }

        // Set item interaction variables
        for (int k = 0; k < 10; k++){
            std::getline(loadRoom, dataRead);
            if (dataRead == "true"){
                roomArr[position]->setItemInteraction(k, true);
            }
            else {
                roomArr[position]->setItemInteraction(k, false);
            }
        }
         // Set room change variables
        for (int l = 0; l < 2; l++){
            std::getline(loadRoom, dataRead);
            if (dataRead == "true"){
                roomArr[position]->setRoomChanges(l, true);
            }
            else {
                roomArr[position]->setRoomChanges(l, false);
            }
        }
        // Set items into room bag
        while (std::getline(loadRoom, dataRead)){
            num = stoi(dataRead);
            roomArr[position]->bag->insert(itmArr[num]);
            }
    }
    else {
        std::cout << "Unable to access file\n";
    }
}

bool FileSystem::loadGame(Room*& curRoom, Room* roomArr[], Map* m, Character* h, Item* itmArr[], int& flash) {
    std::ifstream loadFile("saveData//save.txt", std::ifstream::in);
    if (loadFile.is_open()){
        //Convert string to int
        std::getline(loadFile, dataRead);
        num = stoi(dataRead);

        //Set the current room based on index value
        curRoom = roomArr[num];

        // Set the flashback counter
        std::getline(loadFile, dataRead);
        num = stoi(dataRead);
        flash = num;

        while(std::getline(loadFile, dataRead)){
            num = stoi(dataRead);
            loadRoomData(num, roomArr, itmArr);
        }
        loadFile.close();
    }
    else {
        return false;
    }

    //Load hero data
    std::ifstream loadHero("saveData//hero.txt", std::ifstream::in);
    if (loadHero.is_open()){
        //Load name, health, armor
        std::getline(loadHero, dataRead);
        h->setName(dataRead);
        std::getline(loadHero, dataRead);
        num = stoi(dataRead);
        h->setHealth(num);
        std::getline(loadHero, dataRead);
        num = stoi(dataRead);
        h->setArmor(num);

        //Set bools for fixedsword, translated text, and power stone
        std::getline(loadHero, dataRead);
        if (dataRead == "true"){
            h->setFixedSword(true);
        }
        else {
            h->setFixedSword(false);
        }
        std::getline(loadHero, dataRead);
        if (dataRead == "true"){
            h->setTranslatedText(true);
        }
        else {
            h->setTranslatedText(false);
        }
        std::getline(loadHero, dataRead);
        if (dataRead == "true"){
            h->setPowerStone(true);
        }
        else {
            h->setPowerStone(false);
        }
        while (std::getline(loadHero, dataRead)){
            num = stoi(dataRead);
            h->bag->insert(itmArr[num]);
            }
        loadHero.close();
    }
    else {
        return false;
    }
    
    // Load outside map
    std::ifstream outsideLoad("saveData//outsideMap.txt", std::ifstream::in);
    if (outsideLoad.is_open()){
        for (int i = 0; i < 19; i++){
		    for (int j = 0; j < 38; j++){
                std::getline(outsideLoad, dataRead);
                m->loadMap(i,j,dataRead, "OUTSIDE");
		    }
	    }
        outsideLoad.close();
    }
    else {
        return false;
    }

    // Load Castle map
    std::ifstream castleLoad("saveData//castleMap.txt", std::ifstream::in);
    if (castleLoad.is_open()){
        for (int i = 0; i < 16; i++){
		    for (int j = 0; j < 26; j++){
                std::getline(castleLoad, dataRead);
                m->loadMap(i,j,dataRead, "CASTLE");
		    }
	    }
        castleLoad.close();
    }
    else {
        return false;
    }
    return true;
}
