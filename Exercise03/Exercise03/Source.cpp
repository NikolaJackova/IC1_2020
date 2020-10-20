#include <iostream>
#include "Game.h"
#include "StaticObject.h"
#include "Monster.h"
using namespace std;

int main(int argc, char** argv) {
	Game* game = &Game{};
	StaticObject potomek1 = StaticObject { 1, TypeOfBarrier::Rock };
	potomek1.SetX(5);
	potomek1.SetY(5);
	StaticObject potomek2 = StaticObject{ 2, TypeOfBarrier::SmallPlant };
	potomek2.SetX(10);
	potomek2.SetY(10);
	Monster potomek3 = Monster{ 3, 100 };
	potomek3.SetX(10);
	potomek3.SetY(10);
	potomek3.SetAngle(1);
	Monster potomek4 = Monster{ 4, 200 };
	potomek4.SetX(5);
	potomek4.SetY(10);
	potomek4.SetAngle(3);
	game->AddObject(&potomek1);
	game->AddObject(&potomek2);
	game->AddObject(&potomek3);
	game->AddObject(&potomek4);
	int numberOfStaticObjects = 0;
	int* staticArray = game->FindIdStaticObject(0,6,0,6, numberOfStaticObjects);
	int numberOfMovingObjects = 0;
	MovingObject** movingObjects = game->FindMovingObjectInLocation(0, 0, 15, numberOfMovingObjects);
	cout << "Ids of static objects:" << endl;
	for (int i = 0; i < numberOfStaticObjects; i++)
	{
		cout << staticArray[i] << endl;
	}
	cout << endl;
	cout << "Ids and coordinates of moving objects:" << endl;
	for (int i = 0; i < numberOfMovingObjects; i++)
	{
		cout << "Id: " << movingObjects[i]->GetId() << " x: " << movingObjects[i]->GetX() << " y: " << movingObjects[i]->GetX() 
			<< " angle:"<< movingObjects[i]->GetAngle() << endl;
	}
	delete[] staticArray;
	for (int i = 0; i < numberOfMovingObjects; i++)
	{
		delete[] movingObjects[i];
	}
	delete[] movingObjects;
	return 0;
}