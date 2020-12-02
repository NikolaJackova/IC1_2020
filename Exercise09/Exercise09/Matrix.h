#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <exception>
#include <iostream>

template<typename T>
class Matrix {
private:
	int columns;
	int rows;
	T** matrix;
public:
	Matrix(int columns, int rows);
	Matrix(const Matrix<T>& matrix);
	~Matrix();
	void SetValue(int column, int row, T value);
	void SetArray(T* arr, int size);
	T& GetValue(int col, int row);
	const T& GetValue(int column, int row) const;
	Matrix<T> Transpose() const;
	Matrix<T> Multiply(const Matrix& matrixx) const;
	Matrix<T> Multiply(T scalar) const;
	Matrix<T> Addition(const Matrix& matrixx) const;
	Matrix<T> Addition(T scalar) const;
	void toString() const;
	bool Equals(const Matrix& matrixx) const;
	template<typename R>
	Matrix<R> Cast() const;
};

template<typename T>
Matrix<T>::Matrix(int columns, int rows)
{
	if (columns < 0 || rows < 0) {
		throw std::invalid_argument("Invalid columns and rows!");
	}
	this->rows = rows;
	this->columns = columns;

	matrix = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[columns];
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrixx)
{
	rows = matrixx.rows;
	columns = matrixx.columns;
	T** newM = new T * [matrixx.rows];
	for (int i = 0; i < matrixx.rows; i++)
	{
		newM[i] = new T[matrixx.columns];
		for (int j = 0; j < matrixx.columns; j++)
		{
			newM[i][j] = matrixx.GetValue(i, j);
		}
	}
	matrix = newM;
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < columns; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

template<typename T>
void Matrix<T>::SetValue(int column, int row, T value)
{
	if (column < 0 || column > columns || row<0 || row>rows) {
		throw std::invalid_argument("Invalid row or column!");
	}
	matrix[row][column] = value;
}

template<typename T>
T& Matrix<T>::GetValue(int column, int row)
{
	if (column < 0 || column > columns || row<0 || row>rows) {
		throw std::invalid_argument("Invalid row or column!");
	}
	return matrix[row][column];
}

template<typename T>
const T& Matrix<T>::GetValue(int column, int row) const
{
	if (column < 0 || column > columns || row<0 || row>rows) {
		throw std::invalid_argument("Invalid row or column!");
	}
	return matrix[row][column];
}

template<typename T>
void Matrix<T>::SetArray(T* arr, int size)
{
	if (rows*columns != size) {
		throw std::invalid_argument("Invalid size of array!");
	}
	int arraySize = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = arr[arraySize];
			arraySize++;
		}
	}
}

template<typename T>
Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> matrixx{ columns, rows };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixx.SetValue(j, i, matrix[i][j]);
		}
	}
	return matrixx;
}

template<typename T>
void Matrix<T>::toString() const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
Matrix<T> Matrix<T>::Addition(const Matrix& matrix) const
{
	if (columns != matrix.columns || rows != matrix.rows) {
		throw std::invalid_argument("Columns and rows must be same number!");
	}
	Matrix<T> addition{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			addition.matrix[i][j] = matrix[i][j] + matrix[i][j];
		}
	}
	return addition;
}

template<typename T>
Matrix<T> Matrix<T>::Addition(T scalar) const
{
	Matrix<T> mat{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat.SetValue(i, j, matrix[i][j] + scalar);
		}
	}
	return mat;
}

template<typename T>
Matrix<T> Matrix<T>::Multiply(const Matrix& matrixx) const
{
	if (columns != matrixx.rows) {
		throw std::invalid_argument("Invalid size of matrix!");
	}
	Matrix multiply{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			multiply.matrix[i][j] = 0;
			for (int k = 0; k < columns; k++)
			{
				multiply.matrix[i][j] += matrix[i][k] * matrixx.matrix[k][j];
			}
		}
	}
	return multiply;
}

template<typename T>
Matrix<T> Matrix<T>::Multiply(T scalar) const
{
	Matrix<T> m{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m.matrix[i][j] = matrix[i][j] * scalar;
		}
	}
	return m;
}

template<typename T>
bool Matrix<T>::Equals(const Matrix& matrixx) const
{
	if (matrixx.rows != this->rows || matrixx.columns != this->columns) {
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrixx.GetValue(i, j) != matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::Cast() const
{
	Matrix<R> matrixx{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixx.SetValue(i, j, static_cast<R>(matrix[i][j]));
		}
	}
	return matrixx;
}
#endif