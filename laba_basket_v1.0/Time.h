#pragma once
#include <string>
#include <sstream>
using namespace std;

class Time
{
public:
	Time();
	Time(int day, int hour, int minute);
	Time(int hour, int minute);
	Time(int minute);
	Time(const Time& tm);

	int GetHour() const;
	int GetMinute() const;
	void SetHour(int hour);
	void SetMinute(int minute);

	Time& operator=(const Time& tm);
	bool operator==(Time tm) const;
	bool operator!=(Time tm) const;
	bool operator>(Time tm) const;
	bool operator<(Time tm) const;

	Time& operator+=(Time tm);
	friend Time operator+(Time tm1, Time tm2);
	friend Time operator-(Time tm1, Time tm2);

	static const int HOURS_IN_DAY = 24;
	static const int MINUTES_IN_HOUR = 60;

	static int GetDaysAndTime(Time& tm);
	static Time GetRandomTime(Time from, Time to, int dif = 15);
	string ToString() const;
private:
	int _minute;
};


