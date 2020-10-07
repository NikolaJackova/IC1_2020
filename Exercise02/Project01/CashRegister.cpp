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
	if(numberOfReceipts < 10){
		Receipt receipt{ idCounter, amount, amountVat };
		receipts[numberOfReceipts] = receipt;
		cout << "Receipt " << idCounter << " was created" << endl;
		idCounter++;
		numberOfReceipts++;
		return receipt;
	}
	else
	{
		cout << "You're trying to create 11. receipt. Cash register is full!" << endl << endl;
	}
}

Receipt& CashRegister::GetReceipt(int index)
{
	if (index + 1 <= numberOfReceipts) {
		return receipts[index];
	}
	else if(numberOfReceipts != 0) {
		return receipts[0];
	}
	cout << "There is no receipt to return!" << endl << endl;
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

