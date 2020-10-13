#include "CashRegister.h"
#include <exception>
#include <iostream>
using namespace std;

int CashRegister::idCounter = 1000;

CashRegister::CashRegister()
{
	receipts = new Receipt[10];
	numberOfReceipts = 0;
}

CashRegister::~CashRegister()
{
	delete[] receipts;
}

Receipt& CashRegister::CreateReceipt(double amount, double amountVat)
{
	if(numberOfReceipts < 10){
		Receipt receipt{ idCounter, amount, amountVat };
		receipts[numberOfReceipts] = receipt;
		idCounter++;
		numberOfReceipts++;
		return receipt;
	}
	else
	{
		throw "You're trying to create 11. receipt. Cash register is full!";
	}
}

Receipt& CashRegister::GetReceipt(int index)
{
	if (index + 1 <= numberOfReceipts) {
		return receipts[index];
	}
	return receipts[0];
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

void CashRegister::WriteReceipts() const
{
	for (int i = 0; i < numberOfReceipts; i++)
	{
		receipts[i].WriteReceipt();
	}
}

