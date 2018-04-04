#include "StdAfx.h"
#include "Time.h"

Time::Time() : _minute() {}

Time::Time(int minute)
{
	if (minute >= 0) _minute = minute;
}

Time::Time(int hour, int minute)
{
	int min = 0;
	if (hour>0) min += hour*MINUTES_IN_HOUR;
	if (minute>0 && minute<MINUTES_IN_HOUR) min += minute;
	_minute = min;
}

Time::Time(int day, int hour, int minute)
{
	int min = 0;
	if (day>0) min *= day*HOURS_IN_DAY*MINUTES_IN_HOUR;
	if (hour>0) min += hour*MINUTES_IN_HOUR;
	if (minute>0 && minute<MINUTES_IN_HOUR) min += minute;
	_minute = min;
}

Time::Time(const Time& tm)
{
	_minute = tm._minute;
}

int Time::GetHour() const
{
	return _minute / MINUTES_IN_HOUR;
}

int Time::GetMinute() const
{
	return _minute%MINUTES_IN_HOUR;
}

void Time::SetHour(int hour)
{
	int minute = _minute%MINUTES_IN_HOUR;
	_minute = hour*MINUTES_IN_HOUR + minute;
}
void Time::SetMinute(int minute)
{
	if (minute >= 0 && minute<MINUTES_IN_HOUR)
	{
		int h = _minute / MINUTES_IN_HOUR;
		_minute = h*MINUTES_IN_HOUR + minute;
	}
}

Time& Time::operator =(const Time& tm)
{
	_minute = tm._minute;
	return *this;
}


bool Time::operator ==(Time tm) const
{
	if (_minute == tm._minute) return true;
	return false;
}

bool Time::operator !=(Time tm) const
{
	if (_minute != tm._minute) return true;
	return false;
}

bool Time::operator >(Time tm) const
{
	if (_minute> tm._minute) return true;
	return false;
}

bool Time::operator <(Time tm) const
{
	if (_minute < tm._minute) return true;
	return false;
}

Time& Time::operator+= (Time tm)
{
	_minute += tm._minute;
	return *this;
}

Time operator+(Time tm1, Time tm2)
{
	return Time(tm1._minute + tm2._minute);
}

Time operator-(Time tm1, Time tm2)
{
	if (tm1>tm2) return Time(tm1._minute - tm2._minute);
	return Time();
}

int Time::GetDaysAndTime(Time &tm)
{
	int days = tm._minute /
		(Time::HOURS_IN_DAY*Time::MINUTES_IN_HOUR);
	tm._minute = tm._minute % (Time::HOURS_IN_DAY *
		Time::MINUTES_IN_HOUR);
	return days;
}

Time Time::GetRandomTime(Time from, Time to, int dif)
{
	if (to._minute > from._minute)
	{
		int razn = (to._minute - from._minute) / dif;
		int Rand = from._minute + rand() % razn*dif;
		return Time(Rand);
	}
	return from;
}

string Time::ToString() const
{
	stringstream os;
	os << ((GetHour()<10) ? "0" : "") << GetHour() <<
		'-' << ((GetMinute()<10) ? "0" : "") << GetMinute();
	if (os) return os.str();
	else return string();
}
