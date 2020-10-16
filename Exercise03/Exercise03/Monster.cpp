#include "Monster.h"

Monster::Monster(int id, int maxHp) : MovingObject(id)
{
    this->maxHp = maxHp;
    this->hp = maxHp;
}

int Monster::GetHp() const
{
    return hp;
}

int Monster::GetMaxHp() const
{
    return maxHp;
}

void Monster::SetHp(int hp)
{
    this->hp = hp;
}

void Monster::SetMaxHp(int max)
{
    this->maxHp = max;
}
