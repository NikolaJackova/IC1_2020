#include "Game.h"
#include <iostream>
#include "StaticObject.h"
using namespace std;
#define SIZE 100
Game::Game()
{
	numberOfObjects = 0;
	objects = new Object*[SIZE];
}

Game::~Game()
{
	for (int i = 0; i < numberOfObjects; i++)
	{
		delete objects[i];
	}
	delete[] objects;
}

void Game::AddObject(Object* o)
{
	objects[numberOfObjects] = o;
	numberOfObjects++;
}

int* Game::FindIdStaticObject(double xmin, double xmax, double ymin, double ymax, int &pocet)
{
	int* idOfStaticObjects = new int[numberOfObjects];
	int counter = 0;
	for (int i = 0; i < numberOfObjects; i++)
	{
		if (objects[i]->GetX() > xmin && xmax > objects[i]->GetX() && objects[i]->GetY() > ymin && ymax > objects[i]->GetY()) {
			StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
			if (so != nullptr) {
				idOfStaticObjects[counter] = so->GetId();
				counter++;
			}
		}
	}
	pocet = counter;
	return idOfStaticObjects;
}

MovingObject** Game::FindMovingObjectInLocation(double x, double y, double r, int& pocet)
{
	MovingObject** movingObjects = new MovingObject * [numberOfObjects];
	int counter = 0;
	for (int i = 0; i < numberOfObjects; i++)
	{
		movingObjects[i] = new MovingObject{ 0 };
	}
	for (int i = 0; i < numberOfObjects; i++)
	{
			if (((objects[i]->GetX() - x) * (objects[i]->GetX() - x) + (objects[i]->GetY() - y) * (objects[i]->GetY() - y)) < r * r) {
				MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
				if (so != nullptr) {
					movingObjects[counter] = so;
					counter++;
				}
			}
		}
	pocet = counter;
	return movingObjects;
}

MovingObject** Game::FindMovingObjectInLocation(double x, double y, double r, double umin, double umax, int& pocet)
{
	MovingObject** movingObjects = new MovingObject * [numberOfObjects];
	int counter = 0;
	for (int i = 0; i < numberOfObjects; i++)
	{
		movingObjects[i] = new MovingObject{ 0 };
	}
	for (int i = 0; i < numberOfObjects; i++)
	{
		if (((objects[i]->GetX() - x) * (objects[i]->GetX() - x) + (objects[i]->GetY() - y) * (objects[i]->GetY() - y)) < r * r) {
			MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
			if (so != nullptr && so->GetAngle() > umin && so->GetAngle() < umax) {
				movingObjects[counter] = so;
				counter++;
			}
		}
	}
	pocet = counter;
	return movingObjects;
}

int Game::GetNumberOfObjects()
{
	return numberOfObjects;
}
