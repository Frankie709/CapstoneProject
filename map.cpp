#include "map.hpp"

Map::Map(){
    setUpOutsideMap();
    setUpCastleMap();
}

void Map::setUpCastleMap(){
for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			castleMap[i][j] = ' ';
		}
	}
    
	// top border
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			castleMap[i][j] = '-';
		}
	}
	// left border
	for (int i = 1; i < 16; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			castleMap[i][j] = '|';
		}
	}
	// bottom border
	for (int i = 15; i < 16; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			castleMap[i][j] = '-';
		}
	}
	// right border
	for (int i = 1; i < 15; i++)
	{
		for (int j = 25; j < 26; j++)
		{
			castleMap[i][j] = '|';
		}
	}

}

void Map::setUpOutsideMap(){
    for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 38; j++)
		{
			outsideMap[i][j] = ' ';
		}
	}
    
	// top border
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 38; j++)
		{
			outsideMap[i][j] = '-';
		}
	}
	// left border
	for (int i = 1; i < 19; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			outsideMap[i][j] = '|';
		}
	}
	// bottom border
	for (int i = 18; i < 19; i++)
	{
		for (int j = 0; j < 38; j++)
		{
			outsideMap[i][j] = '-';
		}
	}
	// right border
	for (int i = 1; i < 18; i++)
	{
		for (int j = 37; j < 38; j++)
		{
			outsideMap[i][j] = '|';
		}
	}
}

void Map::updateMap(Room*& curRoom, Room* roomArr[]){
    updateOutsideMap(curRoom, roomArr);
    updateCastleMap(curRoom, roomArr);
}


void Map::updateOutsideMap(Room*& curRoom, Room* roomArr[]){
    //Home
        if (roomArr[0]->getVisited()){
            outsideMap[5][1] = 'L';
            outsideMap[5][2] = 'i';
            outsideMap[5][3] = 'n';
            outsideMap[5][4] = 'o';
            outsideMap[5][5] = 't';
            outsideMap[5][6] = 'a';
            outsideMap[5][7] = '\'';
            outsideMap[5][8] = 's';
            outsideMap[6][2] = 'h';
            outsideMap[6][3] = 'o';
            outsideMap[6][4] = 'm';
            outsideMap[6][5] = 'e';
            
        }
        //Cave
        if (roomArr[1]->getVisited()){
            outsideMap[14][4] = 'C';
            outsideMap[14][5] = 'a';
            outsideMap[14][6] = 'v';
            outsideMap[14][7] = 'e';
        }
        //Desert
        if (roomArr[2]->getVisited()){
            outsideMap[1][10] = 'W';
            outsideMap[1][11] = 'a';
            outsideMap[1][12] = 's';
            outsideMap[1][13] = 't';
            outsideMap[1][14] = 'e';
            outsideMap[1][15] = 'l';
            outsideMap[1][16] = 'a';
            outsideMap[1][17] = 'n';
            outsideMap[1][18] = 'd';
            outsideMap[1][19] = 's';
        }
        //Forest
        if (roomArr[3]->getVisited()){
            outsideMap[13][11] = 'B';
            outsideMap[13][12] = 'l';
            outsideMap[13][13] = 'a';
            outsideMap[13][14] = 'c';
            outsideMap[13][15] = 'k';
            outsideMap[14][11] = 'F';
            outsideMap[14][12] = 'o';
            outsideMap[14][13] = 'r';
            outsideMap[14][14] = 'e';
            outsideMap[14][15] = 's';
            outsideMap[14][16] = 't';
        }
        //River
        if (roomArr[4]->getVisited()){
            outsideMap[5][23] = 'Z';
            outsideMap[5][24] = 'e';
            outsideMap[5][25] = 'm';
            outsideMap[5][26] = 'y';
            outsideMap[5][27] = 'a';
            outsideMap[6][23] = 'R';
            outsideMap[6][24] = 'i';
            outsideMap[6][25] = 'v';
            outsideMap[6][26] = 'e';
            outsideMap[6][27] = 'r';
        }
        //Mountains
        if (roomArr[5]->getVisited()){
            outsideMap[14][20] = 'O';
            outsideMap[14][21] = 'r';
            outsideMap[14][22] = 'd';
            outsideMap[14][23] = 'e';
            outsideMap[14][24] = 'n';
            outsideMap[15][19] = 'M';
            outsideMap[15][20] = 'o';
            outsideMap[15][21] = 'u';
            outsideMap[15][22] = 'n';
            outsideMap[15][23] = 't';
            outsideMap[15][24] = 'a';
            outsideMap[15][25] = 'i';
            outsideMap[15][26] = 'n';
            outsideMap[15][27] = 's';
        }
        //Holmhaven
        if (roomArr[6]->getVisited()){
            outsideMap[5][11] = 'H';
            outsideMap[5][12] = 'o';
            outsideMap[5][13] = 'l';
            outsideMap[5][14] = 'm';
            outsideMap[5][15] = 'h';
            outsideMap[5][16] = 'a';
            outsideMap[5][17] = 'v';
            outsideMap[5][18] = 'e';
            outsideMap[5][19] = 'n';
        }
        // Nagorny village
        if (roomArr[7]->getVisited()){
            outsideMap[15][30] = 'N';
            outsideMap[15][31] = 'a';
            outsideMap[15][32] = 'g';
            outsideMap[15][33] = 'o';
            outsideMap[15][34] = 'r';
            outsideMap[15][35] = 'n';
            outsideMap[15][36] = 'y';
            outsideMap[16][30] = 'V';
            outsideMap[16][31] = 'i';
            outsideMap[16][32] = 'l';
            outsideMap[16][33] = 'l';
            outsideMap[16][34] = 'a';
            outsideMap[16][35] = 'g';
            outsideMap[16][36] = 'e';
        }
        //Farm
        if (roomArr[8]->getVisited()){
            outsideMap[9][10] = 'D';
            outsideMap[9][11] = 'e';
            outsideMap[9][12] = 'p';
            outsideMap[9][13] = 'i';
            outsideMap[9][14] = 'e';
            outsideMap[9][15] = 't';
            outsideMap[9][16] = 't';
            outsideMap[9][17] = 'o';
            outsideMap[10][12] = 'F';
            outsideMap[10][13] = 'a';
            outsideMap[10][14] = 'r';
            outsideMap[10][15] = 'm';
            
        }
        //Valley
         if (roomArr[9]->getVisited()){
            outsideMap[9][21] = 'V';
            outsideMap[9][22] = 'a';
            outsideMap[9][23] = 'l';
            outsideMap[9][24] = 'l';
            outsideMap[9][25] = 'e';
            outsideMap[9][26] = 'y';
        }
        //Castle
        if (roomArr[10]->getVisited()){
            outsideMap[17][11] = 'C';
            outsideMap[17][12] = 'a';
            outsideMap[17][13] = 's';
            outsideMap[17][14] = 't';
            outsideMap[17][15] = 'l';
            outsideMap[17][16] = 'e';
        }
}

void Map::updateCastleMap(Room*& curRoom, Room* roomArr[]){
    //Dining Hall
    if (roomArr[11]->getVisited()){
        castleMap[11][18] = "D";
        castleMap[11][19] = "i";
        castleMap[11][20] = "n";
        castleMap[11][21] = "i";
        castleMap[11][22] = "n";
        castleMap[11][23] = "g";
        castleMap[12][20] = "h";
        castleMap[12][21] = "a";
        castleMap[12][22] = "l";
        castleMap[12][23] = "l";
    }
    //Tower
    if (roomArr[12]->getVisited()){
        castleMap[1][9] = "T";
        castleMap[1][10] = "o";
        castleMap[1][11] = "w";
        castleMap[1][12] = "e";
        castleMap[1][13] = "r";
        //Access via terrace
        castleMap[2][11] = "|";
        castleMap[3][11] = "|";
        castleMap[4][11] = "|";
        castleMap[5][11] = "|";
        castleMap[6][11] = "|";
        castleMap[7][11] = "|";
    }
    //Terrace
    if (roomArr[13]->getVisited()){
        castleMap[8][8] = "T";
        castleMap[8][9] = "e";
        castleMap[8][10] = "r";
        castleMap[8][11] = "r";
        castleMap[8][12] = "a";
        castleMap[8][13] = "c";
        castleMap[8][14] = "e";
    }
    //Bed Chambers
    if (roomArr[14]->getVisited()){
        castleMap[7][19] = "B";
        castleMap[7][20] = "e";
        castleMap[7][21] = "d";
        castleMap[8][17] = "C";
        castleMap[8][18] = "h";
        castleMap[8][19] = "a";
        castleMap[8][20] = "m";
        castleMap[8][21] = "b";
        castleMap[8][22] = "e";
        castleMap[8][23] = "r";
        castleMap[8][24] = "s";
    }
    //Lab
    if (roomArr[15]->getVisited()){
        castleMap[14][4] = "L";
        castleMap[14][5] = "a";
        castleMap[14][6] = "b";
    }
    //Dungeon
    if (roomArr[16]->getVisited()){
        castleMap[11][2] = "D";
        castleMap[11][3] = "u";
        castleMap[11][4] = "n";
        castleMap[11][5] = "g";
        castleMap[11][6] = "e";
        castleMap[11][7] = "o";
        castleMap[11][8] = "n";
        //Cave access
        castleMap[6][1] = "C";
        castleMap[6][2] = "a";
        castleMap[6][3] = "v";
        castleMap[6][4] = "e";
        castleMap[6][5] = "s";
        castleMap[7][2] = "|";
        castleMap[8][2] = "|";
        castleMap[8][3] = "-";
        castleMap[8][4] = "|";
        castleMap[9][4] = "|";
        castleMap[10][4] = "|";
    }
    // Foyer
    if (roomArr[17]->getVisited()){
        castleMap[11][11] = "F";
        castleMap[11][12] = "o";
        castleMap[11][13] = "y";
        castleMap[11][14] = "e";
        castleMap[11][15] = "r";
    }
}

void Map::displayMap(Room*& curRoom){
    if (curRoom->getIndex() < 11){
        std::cout << std::endl;
        std::cout << "Outer world map\n";
        for (int i = 0; i < 19; i++){
		    for (int j = 0; j < 38; j++){
			    std::cout << outsideMap[i][j] << " ";
		    }
		    std::cout << std::endl;
	    }
        std::cout << "You are currently in " << curRoom->getMapName() << std::endl;
    }
    else {
        std::cout << std::endl;
        std::cout << "Castle map\n";
        for (int i = 0; i < 16; i++){
		    for (int j = 0; j < 26; j++){
			    std::cout << castleMap[i][j] << " ";
		    }
		    std::cout << std::endl;
	    }
        std::cout << "You are currently in " << curRoom->getMapName() << std::endl;
    }
}


std::string Map::saveMap(std::string area){
    std::string output;
    if (area == "OUTSIDE"){
        for (int i = 0; i < 19; i++){
		    for (int j = 0; j < 38; j++){
			    output.append(outsideMap[i][j] + "\n");
		    }
	    }
    }
    else {
        for (int i = 0; i < 16; i++){
		    for (int j = 0; j < 26; j++){
			    output.append(castleMap[i][j] + "\n");
		    }
	    }
    }
    return output;
}

void Map::loadMap(int i, int j, std::string c, std::string area){
    if (area == "OUTSIDE"){
	    outsideMap[i][j] = c;
    }
    else {
        castleMap[i][j] = c;
    }
}
