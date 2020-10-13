#pragma once
#ifndef CASH_REGISTRY_H
#define CASH_REGISTRY_H
#include "Receipt.h"

class CashRegister {
	static int idCounter;
public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double amount, double Vat);
	Receipt& GetReceipt(int index);
	double GetAmount() const;
	double GetAmountVat() const;
	int GetNumberOfReceipts() const;
	void WriteReceipts() const;
private:
	Receipt* receipts;
	int numberOfReceipts;
};
#endif
