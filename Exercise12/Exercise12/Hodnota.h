#pragma once
#ifndef HODNOTA_H
#define HODNOTA_H

#include "PrvekVyrazu.h"

struct Hodnota :PrvekVyrazu
{
	double hodnota;
	Hodnota(double hodnota) { this->hodnota = hodnota; };
	~Hodnota() {};
};
#endif // !HODNOTA_H