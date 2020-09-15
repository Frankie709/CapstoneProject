#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include "arrayClass.hpp"
#include "textFormatter.hpp"
class Parser {
private:
	ArrayClass *arr;
    TextFormatter *text;
	std::string* curArray; // Holds the current array.
	std::string originalInput;
	std::string featureOutput;
	std::string itemOutput;
	std::string actionOutput;
	std::string prepOutput;
	std::string directionOutput;
    std::string newInput;
	bool verbFound;
	bool itemFound;
	bool featureFound;
	bool prepFound;
	bool directionFound;
	bool oneWordInput;
public:
	Parser();
    ~Parser();
	void printCommands();
	bool oneWord(std::string);
	bool searchSynonym(std::string, std::string*, int);
	std::string parseInput(std::string&, std::string&, std::string&);
	std::string validateInput(std::string, std::string questionType = "");
	std::string actionSynonym(std::string);
	std::string itemSynonym(std::string);
	std::string featureSynonym(std::string);
	std::string directionSynonym(std::string);
	bool search(std::string&, std::string);
	std::string find(bool&, int, std::string, std::string*);
	bool oneWordSearch(std::string, std::string&, bool, std::string*);
};
#endif