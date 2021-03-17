#pragma once
#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "VyjimkaKalkulatoru.h"
#include "Operator.h"
#include "Hodnota.h"

template<typename T, int Zaok>
struct Kalkulator
{
	T** prvky;
	int pocet;
	Kalkulator();
	void pridejHodnotu(T* hodnota);
	void pridejOperator(char oper);
	T vypocitej();
};

template<typename T, int Zaok>
inline Kalkulator<T, Zaok>::Kalkulator()
{
	prvky = new T * [20];
	for (int i = 0; i < 20; i++)
	{
		prvky[i] = nullptr;
	}
	pocet = 0;
}

template<typename T, int Zaok>
inline void Kalkulator<T, Zaok>::pridejHodnotu(T* hodnota)
{
	if (pocet == 0) {
		prvky[pocet++] = hodnota;
	}
	else {
		if (dynamic_cast<Hodnota*>(prvky[pocet - 1])==nullptr) {
			throw VyjimkaKalkulatoru();
		}
		prvky[pocet++] = hodnota;
	}
}

template<typename T, int Zaok>
inline void Kalkulator<T, Zaok>::pridejOperator(char oper)
{
	if (pocet == 0) {
		prvky[pocet++] = new Operator(oper);
	}
	else {
		if (dynamic_cast<Operator*>(prvky[pocet - 1]) == nullptr) {
			throw VyjimkaKalkulatoru();
		}
		prvky[pocet++] = new Operator(oper);
	}
}

template<typename T, int Zaok>
inline T Kalkulator<T, Zaok>::vypocitej()
{
	int pocitadlo = 0;
	while (pocitadlo < pocet) {
		switch (1)
		{
		default:
			break;
		}
	}
}

#endif // !KALKULATOR_H