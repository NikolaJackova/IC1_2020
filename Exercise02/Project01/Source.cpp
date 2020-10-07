#include <iostream>
#include "Receipt.h"
#include "CashRegister.h"
using namespace std;

int main(int argc, char** argv) {
	CashRegister cashRegister{};
	cashRegister.CreateReceipt(100, 0.21);
	cashRegister.CreateReceipt(1000, 0.15);
	cashRegister.CreateReceipt(5000, 0.18);

	cashRegister.writeReceipts();

	double amount = cashRegister.GetAmount();
	double amountVat = cashRegister.GetAmountVat();
	cout << "Amount: " << amount << " amount VAT: " << amountVat << endl << endl;
	cashRegister.GetReceipt(0).writeReceipt();
	cashRegister.GetReceipt(2).writeReceipt();
	return 0;
}