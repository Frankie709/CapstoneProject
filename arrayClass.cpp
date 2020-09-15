#include "arrayClass.hpp"

ArrayClass::ArrayClass() {}

std::string* ArrayClass::getActionArray() {
	static std::string actionArray[66];
	actionArray[0] = "LOOK";
	actionArray[1] = "THROW";
	actionArray[2] = "DROP";
	actionArray[3] = "TAKE";
	actionArray[4] = "USE";
	actionArray[5] = "TOUCH";
	actionArray[6] = "SLEEP";
	actionArray[7] = "TALK";
	actionArray[8] = "GIVE";
	actionArray[9] = "BUY";
    actionArray[10] = "EAT";
	actionArray[11] = "DANCE";
	actionArray[12] = "HIT";
	actionArray[13] = "SWIM";
    actionArray[14] = "DRINK";
    actionArray[15] = "READ";
    actionArray[16] = "SELL";
    actionArray[17] = "SIT";
    actionArray[18] = "CLIMB";
    actionArray[19] = "PUSH";
    actionArray[20] = "SWIM";
	actionArray[21] = "PUT";
    actionArray[22] = "PUT DOWN";
	actionArray[23] = "PLACE";
	actionArray[24] = "INSERT";
	actionArray[25] = "PUT";
	actionArray[26] = "PUNCH";
	actionArray[27] = "STRIKE";
	actionArray[28] = "TRANSLATE";
	actionArray[29] = "INTREPRET";
	actionArray[30] = "STUDY";
	actionArray[31] = "FEEL";
	actionArray[32] = "REST";
	actionArray[33] = "LIE DOWN";
	actionArray[34] = "NAP";
	actionArray[35] = "ACTIVATE";
	actionArray[36] = "INTERACT";
	actionArray[37] = "PLACE";
	actionArray[38] = "GAZE";
	actionArray[39] = "GLARE";
	actionArray[40] = "LOOK UPON";
	actionArray[41] = "STARE";
	actionArray[42] = "VIEW";
	actionArray[43] = "PEEK";
	actionArray[44] = "EXAMINE";
	actionArray[45] = "SURVEY";
	actionArray[46] = "PEER";
	actionArray[47] = "INSPECT";
	actionArray[48] = "WATCH";
	actionArray[49] = "SCAN";
	actionArray[50] = "GLANCE";
	actionArray[51] = "CHECK";
	actionArray[52] = "GRAB";
	actionArray[53] = "PICK UP";
	actionArray[54] = "CLUTCH";
	actionArray[55] = "GET HOLD OF";
	actionArray[56] = "GRASP";
	actionArray[57] = "TAKE HOLD OF";
	actionArray[58] = "GET";
	actionArray[59] = "SPEAK";
	actionArray[60] = "CHAT";
	actionArray[61] = "CONVERSE";
	actionArray[62] = "TELL";
	actionArray[63] = "COMMUNICATE";
	actionArray[64] = "SAY";
	actionArray[65] = "";
	return actionArray;
}

std::string* ArrayClass::getHeroArray(){
    static std::string heroArray[12];
    heroArray[0] = "INVENTORY";
    heroArray[1] = "CHECK INVENTORY";
    heroArray[2] = "MAP";
    heroArray[3] = "HEALTH";
    heroArray[4] = "CHECK HEALTH";
    heroArray[5] = "SAVE";
    heroArray[6] = "SAVE GAME";
    heroArray[7] = "QUIT";
    heroArray[8] = "LOAD";
    heroArray[9] = "LOAD GAME";
	heroArray[10] = "BAG";
    heroArray[11] = "";
    return heroArray;
}

std::string* ArrayClass::getMovementArray() {
	static std::string movementArray[16];
	movementArray[0] = "WALK";
	movementArray[1] = "RUN";
	movementArray[2] = "JOG";
	movementArray[3] = "MOVE";
	movementArray[4] = "HURRY";
	movementArray[5] = "RUSH";
	movementArray[6] = "ADVANCE";
	movementArray[7] = "TRAVEL";
	movementArray[8] = "CRAWL";
	movementArray[9] = "JUMP";
	movementArray[10] = "LEAP";
	movementArray[11] = "GO";
    movementArray[12] = "EXIT";
    movementArray[13] = "LEAVE TO";
	movementArray[14] = "LEAVE";
	movementArray[15] = "";
	return movementArray;
}

std::string* ArrayClass::getFeatureArray() {
	static std::string featureArray[58];
	featureArray[0] = "BOOKSHELF";
	featureArray[1] = "JOURNAL";
	featureArray[2] = "PENTAGRAM";
	featureArray[3] = "WALL";
	featureArray[4] = "TOWER";
	featureArray[5] = "STREAM";
	featureArray[6] = "TABLET";
	featureArray[7] = "COLUMN";
	featureArray[8] = "TABLE";
	featureArray[9] = "NAPKIN";
	featureArray[10] = "TORTURE RACK";
	featureArray[11] = "PRISONER";
    featureArray[12] = "FARMER";
	featureArray[13] = "BARN";
	featureArray[14] = "TREE";
	featureArray[15] = "MERCHANT";
	featureArray[16] = "PORTRAIT";
	featureArray[17] = "BLOCKED DOOR";
	featureArray[18] = "LINOTA";
	featureArray[19] = "MUTANT";
	featureArray[20] = "EQUIPMENT";
    featureArray[21] = "SHRINE";
    featureArray[22] = "BANK";
	featureArray[23] = "BOAT";
    featureArray[24] = "BODIES";
	featureArray[25] = "RIFT";
	featureArray[26] = "DEMON";
	featureArray[27] = "MARKET PLACE";
	featureArray[28] = "OLD MAN";
	featureArray[29] = "MARKET";
	featureArray[30] = "BLACKSMITH";
    featureArray[31] = "ALCHEMIST";
    featureArray[32] = "CARAVAN";
	featureArray[33] = "BOULDERS";
    featureArray[34] = "MAGIC WALL";
    featureArray[35] = "DRAWING";
    featureArray[36] = "STONE TABLET";
	featureArray[37] = "BOOK SHELF";
	featureArray[38] = "COLUMN";
	featureArray[39] = "BORIN";
	featureArray[40] = "ADELINA";
	featureArray[41] = "DEAD BODIES";
	featureArray[42] = "WAGON";
	featureArray[43] = "WRECKAGE";
	featureArray[44] = "ROCK";
	featureArray[45] = "RACK";
	featureArray[46] = "TORTURE DEVICE";
	featureArray[47] = "SHIP";
	featureArray[48] = "VESSEL";
	featureArray[49] = "BOYCE";
	featureArray[50] = "BLACKSMITH";
	featureArray[51] = "BOOK SHELF";
	featureArray[52] = "MAN";
	featureArray[53] = "BOOKCASE";
	featureArray[54] = "BOULDER";
	featureArray[55] = "ROCKS";
	featureArray[56] = "ROCK";
	featureArray[57] = "";
	return featureArray;
}

std::string* ArrayClass::getItemArray() {
	static std::string itemArray[23];
	itemArray[0] = "RING";
	itemArray[1] = "SWORD";
	itemArray[2] = "TEXT";
	itemArray[3] = "MUSHROOMS";
	itemArray[4] = "GOGGLES";
	itemArray[5] = "TOKEN";
	itemArray[6] = "OAR";
	itemArray[7] = "JERKY";
	itemArray[8] = "PYXIS";
    itemArray[9] = "HEART";
	itemArray[10] = "ALE";
    itemArray[11] = "WATER";
	itemArray[12] = "STONE";
	itemArray[13] = "SOMETHING";
	itemArray[14] = "SCREW";
	itemArray[15] = "CHEMICALS";
	itemArray[16] = "DUNGEON KEY";
	itemArray[17] = "BOOK";
	itemArray[18] = "DOCUMENT";
    itemArray[19] = "CHEMICAL";
	itemArray[20] = "ACID";
	itemArray[21] = "CORROSIVE";
	itemArray[22] = "";
	return itemArray;
}

std::string* ArrayClass::getDirectionArray() {
	static std::string directionArray[58];
	directionArray[0] = "NORTH";
	directionArray[1] = "SOUTH";
	directionArray[2] = "EAST";
	directionArray[3] = "WEST";
	directionArray[4] = "HOME";
	directionArray[5] = "HOLMHAVEN";
	directionArray[6] = "DESERT";
	directionArray[7] = "VALLEY";
	directionArray[8] = "FOREST";
	directionArray[9] = "RIVER";
	directionArray[10] = "MOUNTAINS";
	directionArray[11] = "CAVE";
	directionArray[12] = "FARM";
	directionArray[13] = "FOYER";
	directionArray[14] = "DUNGEON";
	directionArray[15] = "LAB";
	directionArray[16] = "TERRACE";
	directionArray[17] = "DINING HALL";
	directionArray[18] = "BED CHAMBERS";
	directionArray[19] = "TOWER";
	directionArray[20] = "CASTLE";
	directionArray[21] = "UP";
	directionArray[22] = "DOWN";
	directionArray[23] = "LEFT";
	directionArray[24] = "RIGHT";
	directionArray[25] = "NAGORNY VILLAGE";
    directionArray[26] = "TOWN";
    directionArray[27] = "DEPIETTO FARM";
	directionArray[28] = "DEPIETTOS FARM";
	directionArray[29] = "DEPIETTO'S FARM";
	directionArray[30] = "ORDEN MOUNTAINS";
	directionArray[31] = "ORDEN MOUNTAIN";
	directionArray[32] = "ORDEN";
	directionArray[33] = "BEDROOM";
	directionArray[34] = "BED ROOM";
	directionArray[35] = "LABORATORY";
	directionArray[36] = "DINING HALL";
	directionArray[37] = "DININGHALL";
	directionArray[38] = "CAVES";
	directionArray[39] = "DESERT WASTELANDS";
	directionArray[40] = "WASTELANDS";
	directionArray[41] = "WASTELAND";
	directionArray[42] = "NAGORNY";
	directionArray[43] = "VILLAGE";
	directionArray[44] = "NAGORNYVILLAGE";
	directionArray[45] = "TOWN";
	directionArray[46] = "LINOTA'S HOME";
	directionArray[47] = "LINOTA'S";
	directionArray[48] = "LINOTAS";
	directionArray[49] = "LINOTAS HOME";
	directionArray[50] = "ZEMYA RIVER";
	directionArray[51] = "ZEMYA";
	directionArray[52] = "WASTE LANDS";
	directionArray[53] = "WASTE LAND";
	directionArray[54] = "DOOR";
	directionArray[55] = "THRONE ROOM";
	directionArray[56] = "THRONE";
	directionArray[57] = "";
	return directionArray;
}


std::string* ArrayClass::getLookSyn() {
	static std::string lookSyn[15];
	lookSyn[0] = "GAZE";
	lookSyn[1] = "GLARE";
	lookSyn[2] = "LOOK UPON";
	lookSyn[3] = "STARE";
	lookSyn[4] = "VIEW";
	lookSyn[5] = "PEEK";
	lookSyn[6] = "EXAMINE";
	lookSyn[7] = "SURVEY";
	lookSyn[8] = "PEER";
	lookSyn[9] = "INSPECT";
	lookSyn[10] = "WATCH";
	lookSyn[11] = "SCAN";
	lookSyn[12] = "GLANCE";
	lookSyn[13] = "CHECK";
    lookSyn[14] = "";
	return lookSyn;
}

std::string* ArrayClass::getTakeSyn() {
	static std::string takeSyn[8];
	takeSyn[0] = "GRAB";
	takeSyn[1] = "PICK UP";
	takeSyn[2] = "CLUTCH";
	takeSyn[3] = "GET HOLD OF";
	takeSyn[4] = "GRASP";
	takeSyn[5] = "TAKE HOLD OF";
    takeSyn[6] = "GET";
	takeSyn[7] = "";
	return takeSyn;
}

std::string* ArrayClass::getTalkSyn(){
    static std::string talkSyn[7];
    talkSyn[0] = "SPEAK";
    talkSyn[1] = "CHAT";
    talkSyn[2] = "CONVERSE";
    talkSyn[3] = "TELL";
    talkSyn[4] = "COMMUNICATE";
    talkSyn[5] = "SAY";
    talkSyn[6] = "";
    return talkSyn;

}

std::string* ArrayClass::getPrepArray() {
	static std::string prepArr[9];
	prepArr[0] = "ON";
	prepArr[1] = "INTO";
	prepArr[2] = "BELOW";
	prepArr[3] = "IN";
	prepArr[4] = "ABOVE";
	prepArr[5] = "NEAR";
	prepArr[6] = "TO THE RIGHT OF";
	prepArr[7] = "TO THE LEFT OF";
	prepArr[8] = "";
	return prepArr;
}


std::string* ArrayClass::getOneWordArray() {
	static std::string oneWordArr[15];
	oneWordArr[0] = "OLD MAN";
	oneWordArr[1] = "MAGIC WALL";
	oneWordArr[2] = "BLOCKED DOOR";
	oneWordArr[3] = "TORTURE RACK";
	oneWordArr[4] = "NAGORNY VILLAGE";
	oneWordArr[5] = "BED CHAMBERS";
	oneWordArr[6] = "DINING HALL";
	oneWordArr[7] = "LEAVE TO";
	oneWordArr[8] = "ORDEN MOUNTAINS";
	oneWordArr[9] = "ZEMYA RIVER";
	oneWordArr[10] = "DEPIETTO FARM";
	oneWordArr[11] = "BLACK FOREST";
	oneWordArr[12] = "STONE TABLET";
	oneWordArr[13] = "BOOK SHELF";
	oneWordArr[14] = "";
	return oneWordArr;
}














//Returns the number of items in the array
int ArrayClass::getSize(std::string* arr) {
	int i = 0;
	while (arr[i] != "") {
		i++;
	}
	return i;
}

