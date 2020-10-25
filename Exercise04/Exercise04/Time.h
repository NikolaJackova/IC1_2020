#pragma once
#include "IComparable.h"
#ifndef TIME_H
#define TIME_H

struct Time :
    public IComparable
{
private:
    int hour;
    int minute;
    int second;
    int toSeconds() const;
public:
    Time(int hour, int minute, int second);
    ~Time();
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    int CompareTo(IComparable* obj) const override;
    std::string ToString() override;
};
#endif

