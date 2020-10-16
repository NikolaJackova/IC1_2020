#pragma once
#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "Object.h"

class MovingObject :
    public Object
{
private:
    double angle;
public:
    MovingObject(int id);
    double GetAngle() const;
    void SetAngle(double angle);
};
#endif

