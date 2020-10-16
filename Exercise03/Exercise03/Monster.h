#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "MovingObject.h"
class Monster :
    public MovingObject
{
private:
    int hp;
    int maxHp;
public:
    Monster(int id, int maxHp);
    int GetHp() const;
    int GetMaxHp() const;
    void SetHp(int hp);
    void SetMaxHp(int max);
};
#endif

