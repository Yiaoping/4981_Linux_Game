
#ifndef INVENTORY_H
#define INVENTORY_H
#include <SDL2/SDL.h>
#include "Weapon.h"

class Inventory {
public:
    void switchCurrent(int slot);//switches currently selected slot
    void pickUp();//picks up weapon in to current slot
    Weapon* getCurrent();//Returns current weapon
    Inventory();
    ~Inventory();

private:
    int current = 0;//current weapon
    Weapon* weapons[3];

};

#endif
