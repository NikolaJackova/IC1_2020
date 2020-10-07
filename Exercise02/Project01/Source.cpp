#include <iostream>
#include "Receipt.h"
#include "CashRegister.h"
using namespace std;

int main(int argc, char** argv) {
	CashRegister cashRegister{};
	cashRegister.CreateReceipt(100, 0.21);
	cashRegister.CreateReceipt(1000, 0.15);
	cashRegister.CreateReceipt(5000, 0.18);
	cashRegister.CreateReceipt(5000, 0.05);
	cashRegister.CreateReceipt(5000, 0.03);
	cashRegister.CreateReceipt(125, 0.17);
	cashRegister.CreateReceipt(5000, 0.18);
	cashRegister.CreateReceipt(5000, 0.18);
	cashRegister.CreateReceipt(750, 0.18);
	cashRegister.CreateReceipt(10000, 0.10);

	//11. prvek
	cashRegister.CreateReceipt(10000, 0.10);

	cashRegister.writeReceipts();

	double amount = cashRegister.GetAmount();
	double amountVat = cashRegister.GetAmountVat();
	cout << "Amount: " << amount << " amount VAT: " << amountVat << endl << endl;
	cashRegister.GetReceipt(0).writeReceipt();
	cashRegister.GetReceipt(9).writeReceipt();
	cashRegister.GetReceipt(11).writeReceipt();
	return 0;
}