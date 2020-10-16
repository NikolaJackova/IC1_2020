#include "MovingObject.h"

#define MATH_PI 3.14159265359

MovingObject::MovingObject(int id) : Object(id)
{
}

double MovingObject::GetAngle() const
{
    return angle;
}

void MovingObject::SetAngle(double angle)
{
    if (!(0 <= angle && angle <= 2 * MATH_PI)) {
        throw "Angle is not valid!";
    }
    this->angle = angle;
}
