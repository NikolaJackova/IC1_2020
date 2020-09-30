#pragma once
class Trojuhelnik
{
private:
	int a, b, c;
public:
	bool lzeSestrojit();
	void setA(int a);
	void setB(int b);
	void setC(int c);
	int getA();
	int getB();
	int getC();
};

