#include "PhoneList.h"
#include <iostream>

using namespace std;

int main() {
	Model::PhoneList* list = new Model::PhoneList{};
	for (int i = 1; i < 30; i++)
	{
		string name = "Osoba" + to_string(i);
		string number = to_string(i)+ to_string(i)+ to_string(i)+ to_string(i)+ to_string(i);
		try {
			Entity::Person p(name, number, i);
			list->addPerson(p);
		}
		catch (invalid_argument& e) {
			cerr << e.what() << endl;
		}
	}
	try {
		cout << list->findNumber("") << endl;
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}
	catch(exception& e) {
		cerr << e.what() << endl;
	}
	return 0;
}