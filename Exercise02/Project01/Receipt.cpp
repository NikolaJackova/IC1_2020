#include "Receipt.h"
#include<iostream>
using namespace std;
Receipt::Receipt(int id, double amount, double amountVat)
{
	this->id = id;
	this->amount = amount;
	this->amountVat = amountVat;
}

Receipt::Receipt()
{
}

void Receipt::SetId(int id)
{
	this->id = id;
}

int Receipt::GetId() const
{
	return this->id;
}

void Receipt::SetAmount(double amount)
{
	this->amount = amount;
}

double Receipt::GetAmount() const
{
	return this->amount;
}

void Receipt::SetAmountVat(double amountVat)
{
	this->amountVat = amountVat;
}

double Receipt::GetAmountVat() const
{
	return this->amountVat;
}

void Receipt::WriteReceipt() const
{
	cout << "Receipt number: " << id << endl;
	cout << "Amount: " << amount << endl;
	cout << "Amount VAT: " << amount * (1 + amountVat) << endl;
	cout << "VAT %: " << amountVat * 100 << endl << endl;
}
