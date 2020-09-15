#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
class Item{
    protected:
        std::string featureName;
		std::string description;
        int index;
    public:
        Item(std::string name, std::string desc1, int idx);
		Item();
        int getIndex();
        void setDescription(std::string);
		std::string getDescription();
        std::string getName();
};
#endif
