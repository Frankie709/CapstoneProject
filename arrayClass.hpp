#ifndef ARRAY_CLASS_HPP
#define ARRAY_CLASS_HPP
#include <string>
#include <iostream>
class ArrayClass {
public:
	ArrayClass();
	std::string* getMovementArray();
	std::string* getDirectionArray();
	std::string* getActionArray();
	std::string* getFeatureArray();
	std::string* getItemArray();
    std::string* getHeroArray();
	std::string* getLookSyn();
	std::string* getTakeSyn();
    std::string* getTalkSyn();
	std::string* getPrepArray();
	std::string* getOneWordArray();
	int getSize(std::string*);
};
#endif

