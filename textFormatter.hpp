#ifndef TEXT_FORMATTER_HPP
#define TEXT_FORMATTER_HPP
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <algorithm>
class TextFormatter{
    protected:
        std::string str;
	public:
		std::string toUpperCase(std::string);
	    std::string toLowerCase(std::string);
		void print(const std::string& str, float time);
        std::string changeColor(std::string, std::string);
        std::string firstLetterUpper(std::string input);
};
#endif
