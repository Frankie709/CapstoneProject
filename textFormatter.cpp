#include "textFormatter.hpp"
// Print speed is based on time input
void TextFormatter::print(const std::string& str, float time){
    time = time * 50000;
	for (size_t i = 0; i != str.size(); ++i) {
		std::cout << str[i];
        std::cout.flush();
		usleep(time);
	}
}

//Converts string to upper case
std::string TextFormatter::toUpperCase(std::string input) {
	str = input;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string TextFormatter::firstLetterUpper(std::string input) {
    input = toLowerCase(input);
    input[0] = toupper(input[0]);
    return input;
}

//Converts string to lower case
std::string TextFormatter::toLowerCase(std::string input) {
	str = input;
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string TextFormatter::changeColor(std::string inputText, std::string color){
    std::string regular = "\033[0m";
    if (color == "RED") {
        return "\033[0;31m" + inputText + regular;
    }
    if (color == "GREEN") {
        return "\033[0;32m" + inputText + regular;
    }
    if (color == "YELLOW") {
        return "\033[0;33m" + inputText + regular;
    }
    if (color == "BLUE") {
        return "\033[0;34m" + inputText + regular;
    }
    if (color == "CYAN") {
        return "\033[0;36m" + inputText + regular;
    }
    if (color == "MAGENTA") {
        return "\033[0;35m" + inputText + regular;
    }
    if (color == "F"){
        return "\033[1;35m" + inputText + regular;
    }
    if (color == "I"){
        return "\033[1;36m" + inputText + regular;
    }
    if (color == "R"){
        return "\033[1;34m" + inputText + regular;
    }
    
}
