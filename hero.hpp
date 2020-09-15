#ifndef HERO_HPP
#define HERO_HPP
#include "character.hpp"
class Hero : public Character{
    public:
        Hero();
        void increaseHealth(int h);
        void decreaseHealth(int d);
        virtual int attack1();
        virtual int attack2();
        virtual void defend(int damage);
};
#endif