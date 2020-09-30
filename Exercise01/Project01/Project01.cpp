#include <iostream>
using namespace std;


int main() {
	cout << "Zadej a:" << endl;
	int a, b, c;
	cin >> a;
	cout << "Zadej b:" << endl;
	cin >> b;
	cout << "Zadej c:" << endl;
	cin >> c;
	if ((a + b) > c && (a + c) > b && (b + c) > a) {
		int obvod = a + b + c;
		cout << "Obvod trojuhelniku je: " << obvod << endl;
	}
	else {
		cout << "Trojuhelnik nelze sestrojit!" << endl;
	}
	cin.get(); cin.get();
	return 0;
}