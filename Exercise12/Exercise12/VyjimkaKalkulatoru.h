#pragma once
#ifndef VYJIMKA_KALKULATORU_H
#define VYJIMKA_KALKULATORU_H

#include <iostream>
#include <exception>

struct VyjimkaKalkulatoru:public std::exception
{
    const char* what() const throw ()
    {
        return "Vyjimka kalkulatoru!";
    }
};
#endif // !VYJIMKA_KALKULATORU_H
