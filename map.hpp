#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <string>
#include "room.hpp"
class Map {
    protected:
        std::string outsideMap[19][38];
        std::string castleMap[16][26];
    public:
        Map();
        void setUpOutsideMap();
        void setUpCastleMap();
        void displayMap(Room*&);
        std::string saveMap(std::string);
        void loadMap(int, int, std::string, std::string);
        void updateMap(Room*&, Room*[]);
        void updateOutsideMap(Room*&, Room*[]);
        void updateCastleMap(Room*&, Room*[]);
};
#endif
