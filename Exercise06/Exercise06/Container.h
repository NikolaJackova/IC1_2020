#pragma once
#include <iostream>
template<typename DateType, int Size, int GrowingSize>
struct Array {
private:
	DateType* _array;
	unsigned _sizeOfArray;
	unsigned _numberOfElements;
	void growArray();
public:
	Array();
	~Array();
	bool isFreeSpace() const;
	void add(const DateType& o);
	DateType& operator[](int index);
	DateType operator[](int index) const;
	unsigned int count() const;
	void remove(int index);
	unsigned getSize() const { return _sizeOfArray; };
	unsigned getNumber() const { return _numberOfElements; };
	DateType* getArray() const { return _array; };
};

template<typename DateType, int Size, int GrowingSize>
Array<DateType, Size, GrowingSize>::Array(){
	_array = new DateType[Size];
	_sizeOfArray = Size;
	_numberOfElements = 0;
}

template<typename DateType, int Size, int GrowingSize>
Array<DateType, Size, GrowingSize>::~Array() {
	delete[] _array;
}

template<typename DateType, int Size, int GrowingSize>
bool Array<DateType, Size, GrowingSize>::isFreeSpace() const {
	return _numberOfElements < _sizeOfArray;
}

template<typename DateType, int Size, int GrowingSize>
void Array<DateType, Size, GrowingSize>::growArray()
{
	DateType* temp = new DateType[_sizeOfArray * GrowingSize];
	for (int i = 0; i < _sizeOfArray; i++)
	{
		temp[i] = _array[i];
	}
	delete[] _array;
	_array = temp;
	_sizeOfArray = _sizeOfArray * GrowingSize;
}

template<typename DateType, int Size, int GrowingSize>
void Array<DateType, Size, GrowingSize>::add(const DateType& o)
{
	if (&o == nullptr) {
		throw std::invalid_argument("Object is null!");
	}
	if (!isFreeSpace()) {
		growArray();
	}
	_array[_numberOfElements++] = o;
}

template<typename DateType, int Size, int GrowingSize>
DateType& Array<DateType, Size, GrowingSize>::operator[](int index)
{
	if (index >= _numberOfElements || index < 0) {
		throw std::invalid_argument("Invalid index!");
	}
	return _array[index];
}

template<typename DateType, int Size, int GrowingSize>
DateType Array<DateType, Size, GrowingSize>::operator[](int index) const
{
	if (index >= _numberOfElements || index < 0) {
		throw std::invalid_argument("Invalid index!");
	}
	return _array[index];
}

template<typename DateType, int Size, int GrowingSize>
unsigned int Array<DateType, Size, GrowingSize>::count() const
{
	return _numberOfElements;
}

template<typename DateType, int Size, int GrowingSize>
void Array<DateType, Size, GrowingSize>::remove(int index)
{
	if (index >= _numberOfElements || index < 0) {
		throw std::invalid_argument("Invalid index!");
	}
	for (int i = index+1; i < _numberOfElements; i++)
	{
		_array[i - 1] = _array[i];
	}
	_numberOfElements--;
}
