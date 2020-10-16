#pragma once
#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include "MovingObject.h"
class Game
{
private:
	Object** objects;
	int numberOfObjects;
public:
	Game();
	~Game();
	void AddObject(Object* o);
	int* FindIdStaticObject(double xmin, double xmax, double ymin, double  ymax, int& pocet);
	MovingObject** FindMovingObjectInLocation(double x, double y, double r, int& pocet);
	MovingObject** FindMovingObjectInLocation(double x, double y, double r, double umin, double umax, int& pocet);
	int GetNumberOfObjects();
};
#endif

