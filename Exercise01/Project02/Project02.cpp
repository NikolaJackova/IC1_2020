#include <iostream>
#include "Trojuhelnik.h"
using namespace std;

int main() {
	//Vytvoøení jednoho trojuhelníku
	Trojuhelnik* ukazatel = new Trojuhelnik();
	cout << "Zadej a:" << endl;
	int a, b, c;
	cin >> a;
	ukazatel->setA(a);
	cout << "Zadej b:" << endl;
	cin >> b;
	ukazatel->setB(b);
	cout << "Zadej c:" << endl;
	cin >> c;
	ukazatel->setC(c);
	if (ukazatel->lzeSestrojit()) {
		cout << "Lze sestrojit" << endl << endl;
	}
	else {
		cout << "Nelze sestrojit" << endl << endl;
	}
	delete(ukazatel);

	//Vytvoøení pole trojuhelníkù
	int pocet;
	cout << "Zadej pocet trojuhelniku:" << endl;
	cin >> pocet;
	Trojuhelnik *pole = new Trojuhelnik[pocet];
	for (int i = 0; i < pocet; i++)
	{
		cout << "Zadej a:" << endl;
		int a, b, c;
		cin >> a;
		pole[i].setA(a);
		cout << "Zadej b:" << endl;
		cin >> b;
		pole[i].setB(b);
		cout << "Zadej c:" << endl;
		cin >> c;
		pole[i].setC(c);
		if (pole[i].lzeSestrojit()) {
			cout << "Lze sestrojit" << endl << endl;
		}
		else {
			cout << "Nelze sestrojit" << endl << endl;
		}
	}
	for (int i = 0; i < pocet; i++)
	{
		cout << "Trojuhelnik cislo: " << i+1 << " a: " << pole[i].getA() << " b: " << pole[i].getB() << " c: " << pole[i].getC();
	}
	delete[](pole);
	cin.get(); cin.get();
	return 0;
}