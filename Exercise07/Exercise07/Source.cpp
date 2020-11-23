#include <ostream>
#include "Date.h"
#include "Address.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define SIZE_OF_ARRAY 3

void save() {
	Date d1(1, 1, 2010);
	Date d2(1, 2, 2015);
	Date d3(1, 3, 2020);
	Address a1("Dvorska", "Pardubice", "12345");
	Address a2("Pardubicka", "Pardubice", "12345");
	Address a3("Hradecka", "Pardubice", "12345");

	Person arrayOfPersons[SIZE_OF_ARRAY] = {
		{"Jan", "Novak", a1, d1 },
		{"Jan", "Novy", a2, d2},
		{"Honza", "Novotny", a3, d3}
	};

	ofstream vystupniSoubor{};
	vystupniSoubor.open("outputPersons.txt");
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		vystupniSoubor << arrayOfPersons[i] << endl;
	}
	vystupniSoubor.close();
}

Person* load() {
	ifstream is{};
	is.open("outputPersons.txt");
	string line;
	int sizeOfArray = 0;
	if (is.is_open()) {
		while (getline(is, line)) {
			sizeOfArray++;
		}
		Person* arrayOfPersons = new Person[sizeOfArray];
		is.clear();
		is.seekg(0);

		for (int i = 0; i < sizeOfArray; i++)
		{
			Person per;
			is >> per;
			arrayOfPersons[i] = per;
		}
		is.close();
		return arrayOfPersons;
	}
	return nullptr;
}

int main() {
	save();
	Person* p = load();
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		cout << p[i] << endl;
	}
}