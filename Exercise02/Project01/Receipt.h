#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H
class Receipt {
	int id;
	double amount;
	double amountVat;
public:
	Receipt(int id, double amount, double amountVat);
	Receipt();
	void SetId(int id);
	int GetId() const;
	void SetAmount(double amount);
	double GetAmount() const;
	void SetAmountVat(double amountVat);
	double GetAmountVat() const;
	void WriteReceipt() const;
};
#endif