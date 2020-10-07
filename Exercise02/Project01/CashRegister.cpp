#include "CashRegister.h"
#include <exception>
#include <iostream>
using namespace std;

int CashRegister::idCounter = 1000;

CashRegister::CashRegister()
{
	receipts = new Receipt[10];
	numberOfReceipts = 0;
	cout << "CashRegister" << endl;
}

CashRegister::~CashRegister()
{
	delete[] receipts;
	cout << "~CashRegister" << endl;
}

Receipt& CashRegister::CreateReceipt(double amount, double amountVat)
{
	if (numberOfReceipts == 10) {
		throw new exception("Cash registry is full!");
	}
	Receipt receipt{ idCounter, amount, amountVat };
	receipts[numberOfReceipts] = receipt;
	idCounter++;
	numberOfReceipts++;
	return receipt;
}

Receipt& CashRegister::GetReceipt(int index)
{
	if (index + 1 <= numberOfReceipts) {
		return receipts[index];
	}
	else if(numberOfReceipts != 0) {
		return receipts[0];
	}
	throw new exception("There is no receipt to return!");
}

double CashRegister::GetAmount() const
{
	double sum = 0;
	for (int i = 0; i < numberOfReceipts; i++)
	{
		sum += receipts[i].GetAmount();
	}
	return sum;
}

double CashRegister::GetAmountVat() const
{
	double sum = 0;
	for (int i = 0; i < numberOfReceipts; i++)
	{
		sum += receipts[i].GetAmount()*(1+receipts[i].GetAmountVat());
	}
	return sum;
}

int CashRegister::GetNumberOfReceipts() const
{
	return numberOfReceipts;
}

void CashRegister::writeReceipts() const
{
	for (int i = 0; i < numberOfReceipts; i++)
	{
		receipts[i].writeReceipt();
	}
}

