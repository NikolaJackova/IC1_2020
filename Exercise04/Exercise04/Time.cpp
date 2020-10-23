#include "Time.h"
#include <iostream>

Time::Time(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

Time::~Time()
{
}

int Time::GetHour() const
{
	return hour;
}

int Time::GetMinute() const
{
	return minute;
}

int Time::GetSecond() const
{
	return second;
}

int Time::CompareTo(IComparable* obj) const
{
	if (this == obj) {
		return 0;
	}
	else if (this < obj) {
		return -1;
	}
	else if (this > obj) {
		return 1;
	}
}

std::string Time::ToString()
{
	return "Hodiny: " + std::to_string(hour) + " minuty: " + std::to_string(minute) + " sekundy: " + std::to_string(second) + "\n";
}
