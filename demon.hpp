#ifndef DEMON_HPP
#define DEMON_HPP
#include "character.hpp"
class Demon : public Character{
    public:
        Demon(std::string setName);
        void increaseHealth(int h);
        void decreaseHealth(int d);
        virtual int attack1();
        virtual int attack2();
        virtual void defend(int damage);
};
#endif