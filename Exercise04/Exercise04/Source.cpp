#include "IComparable.h"
#include <iostream>
#include <ctime>
#include "Time.h"
using namespace std;

#define SIZE 10

void SortArray(IComparable** array, int sizeOfArray)
{
	IComparable* temp = new Time{ 0,0,0 };
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 1; j < (sizeOfArray - i); j++)
		{
			if (array[j - 1]->CompareTo(array[j]) == 1) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main() {
	srand((unsigned)time(0));
	IComparable** objects = new IComparable * [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		int h = 0 + rand() % ((23 + 1) - 0);
		int min = 0 + rand() % ((59 + 1) - 0);
		int sec = 0 + rand() % ((59 + 1) - 0);
		objects[i] = new Time{ h,min,sec };
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << objects[i]->ToString();
	}
	cout << endl << endl;
	SortArray(objects, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << objects[i]->ToString();
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete[] objects[i];
	}
	delete[] objects;
	return 0;
}