#ifndef WEAPONDROP_H
#define WEAPONDROP_H

#include <string>
#include <SDL2/SDL.h>

#include "../collision/HitBox.h"
#include "../basic/Entity.h"
#include "../collision/CollisionHandler.h"
#include "weapons/Weapon.h"


class WeaponDrop: public Entity{
public:
    WeaponDrop(const int32_t id, const SDL_Rect& dest, const SDL_Rect& pickupSize, const int32_t wId);

    ~WeaponDrop();
    void setPosition(const int x, const int y);
    void onCollision();
    int32_t getId() const;

    void collidingProjectile(const int damage);

    int getX() const;
    int getY() const;
    int32_t getWeaponId() const;


private:
    int xCoord;
    int yCoord;
    int32_t weaponId;
};


#endif
