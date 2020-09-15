#include "room.hpp"

//Base room constructor
Room::Room() {
	roomName = "";
    mapName = "";
	visited = false;
	exited = false;
    canEnter = false;
	top = NULL;
	left = NULL;
	right = NULL;
	bottom = NULL;
    index = 0;
	bag = new Bag(20);
    text = new TextFormatter();
    int i;
    for (i = 0; i < 10; i++) {
        itemInteraction[i] = false;
    }
    for (i = 0; i < 5; i++) {
        feature1Interaction[i] = false;
    }
    for (i = 0; i < 5; i++) {
        feature2Interaction[i] = false;
    }
    for (i = 0; i < 2; i++){
        roomChanges[i] = false;
    }
}

Room::~Room() {
	delete bag;
    delete text;
}

std::string Room::getFeature1(){
    return feature1;
}

std::string Room::getFeature2(){
    return feature2;
}

//Returns room name
std::string Room::getRoomName() {
	return roomName;
}

//Returns bool value of visited variable 
bool Room::getVisited() {
	return visited;
}

//Returns bool value of exited variable
bool Room::getExited() {
	return exited;
}

// Sets visited variable
void Room::setVisited(bool v) {
	visited = v;
}

void Room::setExited(bool e) {
	exited = e;
}

//Returns pointer to room to the top 
Room* Room::getTop() {
	return top;
}

//Returns pointer to room to the left
Room* Room::getLeft() {
	return left;
}

//Returns pointer to room to the right
Room* Room::getRight() {
	return right;
}

//Returns pointer to room to the bottom
Room* Room::getBottom() {
	return bottom;
}

//Sets pointer to room to the top 
void Room::setTop(Room* t) {
	top = t;
}

//Sets pointer to room to the left
void Room::setLeft(Room* l) {
	left = l;
}

//Sets pointer to room to the right
void Room::setRight(Room* r) {
	right = r;
}

//Sets pointer to room to the bottom
void Room::setBottom(Room* b) {
	bottom = b;
}

void Room::exchangeItem(Bag *&insertBag, Bag *&removeBag, Item *item){
	insertBag->insert(item);
	removeBag->remove(item);
}

int Room::getIndex(){
    return index;
}

bool Room::getFeature1Interaction(int i){
    return feature1Interaction[i];
}

bool Room::getFeature2Interaction(int i){
    return feature2Interaction[i];
}

bool Room::getItemInteraction(int i){
    return itemInteraction[i];
}  

void Room::setFeature1Interaction(int i, bool b){
    feature1Interaction[i] = b;
}

void Room::setFeature2Interaction(int i, bool b){
    feature2Interaction[i] = b;
}

void Room::setItemInteraction(int i, bool b){
    itemInteraction[i] = b;
}

void Room::setRoomChanges(int i, bool b){
    roomChanges[i] = b;
}

bool Room::getRoomChanges(int i){
    return roomChanges[i];
}

bool Room::getCanEnter(){
    return canEnter;
}

void Room::setCanEnter(bool b){
    canEnter = b;
}

std::string Room::getMapName(){
    return mapName;
}