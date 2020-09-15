#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP
#include "room.hpp"
#include "map.hpp"
#include "character.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
class FileSystem {
    protected:
        std::string dataRead;
        std::stringstream strInput;
        int num;
	public:
		void saveRoomData(Room*);
        bool saveGame(Room*&, Room* [], int, Character*, Map*);
        bool loadGame(Room*&, Room* [], Map*, Character*, Item*[], int&);
        void loadRoomData(int, Room* [], Item* []);
};
#endif