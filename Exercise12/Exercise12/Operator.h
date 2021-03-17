#pragma once
#ifndef OPERATOR_H
#define OPERATOR_H

#include "PrvekVyrazu.h"

struct Operator:PrvekVyrazu
{
	char znak;
	Operator(char znak) { this->znak = znak; };
	~Operator() {};
};
#endif // !OPERATOR_H
