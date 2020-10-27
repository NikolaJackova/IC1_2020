#include "Time.h"
#include <iostream>

int Time::toSeconds() const
{
	return second + (hour*60*60 + minute*60);
}

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
	Time* time = dynamic_cast<Time*>(obj);
	if (time == nullptr) {
		throw "Nullptr obj or is not Time";
	}
	int timeSec = time->toSeconds();
	int thisSec = this->toSeconds();
	if (thisSec == timeSec) {
		return 0;
	}
	else if (thisSec < timeSec) {
		return -1;
	}
	return 1;
}

std::string Time::ToString() const
{
	return "Hodiny: " + std::to_string(hour) + " minuty: " + std::to_string(minute) + " sekundy: " + std::to_string(second) + "\n";
}
