#include <ostream>
#include "Date.h"
#include "Address.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define SIZE_OF_ARRAY 3

void saveBin() {
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

	ofstream out{};
	out.open("outputPersons.dat", ios_base::binary);
	if (out.is_open()) {
		out.write((const char*)&arrayOfPersons, sizeof(arrayOfPersons));
		out.close();
	}
}

Person* loadBin() {
	ifstream is{};
	is.open("outputPersons.dat", ios_base::binary);
	string line;
	if (is.is_open()) {
		is.seekg(0, ios::end);
		int sizeOfArray = is.tellg() / sizeof(Person);
		is.seekg(0);
		Person* arrayOfPersons = new Person[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
		{
			is.read((char*)&arrayOfPersons[i], sizeof(Person));
			
		}
		is.close();
		return arrayOfPersons;
	}
	return nullptr;
}

int main() {
	saveBin();
	Person* p = loadBin();
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		cout << p[i] << endl;
	}
}