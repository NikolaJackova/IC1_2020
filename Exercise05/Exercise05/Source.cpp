#include "PhoneList.h"
#include <iostream>

using namespace std;

int main() {
	Model::PhoneList* list = new Model::PhoneList{};
	for (int i = 1; i < 30; i++)
	{
		string name = "Osoba" + to_string(i);
		string number = to_string(i)+ to_string(i)+ to_string(i)+ to_string(i)+ to_string(i);
		Entity::Person p(name, number, i);
		list->addPerson(p);
	}
	cout << list->findNumber(2) << endl;
	cout << list->findNumber(70) << endl;
	cout << list->findNumber(-5) << endl;
	cout << list->findNumber("Osoba5") << endl;
	cout << list->findNumber("12") << endl;
	cout << list->findNumber("") << endl;
	return 0;
}