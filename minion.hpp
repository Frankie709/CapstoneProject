#ifndef MINION_HPP
#define MINION_HPP
#include "character.hpp"
class Minion : public Character{
    public:
        Minion(std::string setName);
        void increaseHealth(int h);
        void decreaseHealth(int d);
        virtual int attack1();
        virtual int attack2();
        virtual void defend(int damage);
};
#endif