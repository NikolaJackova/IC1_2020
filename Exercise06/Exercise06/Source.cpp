#include <string>
#include "Container.h"
using namespace std;

int main() {
	Array<string, 5, 2> _array {};
	cout << _array.isFreeSpace() << endl;
	_array.add("Ahoj");
	_array.add("Dobry den");
	_array.add("Cau");
	_array.add("Nazdar");
	_array.add("Cauky");
	cout << _array.isFreeSpace() << endl;
	_array.add("Mnauky");
	int number = _array.count();
	cout << "Number of elements: " << number << endl;
	for (int i = 0; i < number; i++)
	{
		string s = _array.operator[](i);
		cout << s << endl;
	}
	_array.remove(2);
	number = _array.count();
	cout << number << endl << endl;
	for (int i = 0; i < number; i++)
	{
		string s = _array.operator[](i);
		cout << s << endl;
	}
	return 0;
}