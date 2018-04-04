#include "StdAfx.h"
#include "Date.h"

const int Date::DAYS_IN_MONTH[] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date()
{
	_year = 1;
	_month = 1;
	_day = 1;
	_number = _getNumber(*this);
}

Date::Date(int y, int m, int d)
{
	_year = y;
	_month = m;
	_day = d;

	_number = _getNumber(*this);
}

Date::Date(const Date& orig)
{
	_year = orig._year;
	_month = orig._month;
	_day = orig._day;
	_number = orig._number;
}

void Date::_changeNumber(int count_day)
{
	_number = _number + count_day;
	Date temp(_number);
	_year = temp._year;
	_month = temp._month;
	_day = temp._day;
}

bool Date::_isCorrectDate()
{
	if (_month<1 || _month>12) return false;

	if (Date::IsLeapYear(_year) && _month == 2 && _day == 29)
		return true;

	if (_day<1 || _day>DAYS_IN_MONTH[_month - 1]) return false;
	return true;
}

bool Date::IsLeapYear(int num)
{
	if (num % 4 == 0)
	{
		if (num % 100 == 0 && num % 400 != 0) return false;
		else return true;
	}
	else return false;
}

int Date::_getNumber(Date &dt)
{
	int y;

	int result = 0;

	if (dt._year >= 2001)
	{
		result += Date::MILLENIUM_DAYS;
		y = 2001;

		while (y<dt._year)
		{
			result += Date::DAYS_IN_YEAR;
			if (Date::IsLeapYear(y)) result++;
			y++;
		}

		y = 1;
		while (y<dt._month)
		{
			result += DAYS_IN_MONTH[y - 1];
			if (y == 2 && Date::IsLeapYear(dt._year))
				result++;
			y++;
		}
		result += dt._day;
		result--;  // уменьшаем на 1 для корректного результата
	}
	else
	{
		y = 1;
		while (y<dt._year)
		{
			result += Date::DAYS_IN_YEAR;
			if (Date::IsLeapYear(y)) result++;
			y++;
		}

		y = 1;
		while (y<dt._month)
		{
			result += DAYS_IN_MONTH[y - 1];
			if (y == 2 && Date::IsLeapYear(dt._year))
				result++;
			y++;
		}
		result += dt._day;
	}

	return result;
}
Date::Date(int num)
{
	_number = num;
	int y = 1;
	int m = 1;
	if (num>Date::MILLENIUM_DAYS)
	{
		num++;
		num -= Date::MILLENIUM_DAYS;
		y = 2001;
		while (num>Date::DAYS_IN_YEAR)
		{
			num -= DAYS_IN_YEAR;
			if (Date::IsLeapYear(y)) num--;
			y++;
		}

		if (num == 0)
		{
			num = 366;
			y--;
		}

		while (num>DAYS_IN_MONTH[m - 1])
		{
			num -= DAYS_IN_MONTH[m - 1];
			m++;
			if (m == 2 && Date::IsLeapYear(y))
			{
				if (num == 29) break;
				num--;
			}
		}
	}
	else
	{
		while (num>Date::DAYS_IN_YEAR)
		{
			num -= DAYS_IN_YEAR;
			if (Date::IsLeapYear(y)) num--;
			y++;
		}
		if (num == 0)
		{
			num = 366;
			y--;
		}

		while (num>DAYS_IN_MONTH[m - 1])
		{
			num -= DAYS_IN_MONTH[m - 1];
			m++;

			if (m == 2 && Date::IsLeapYear(y))
			{
				if (num == 29) break;
				num--;
			}
		}
	}

	_day = num;
	_month = m;
	_year = y;
}

//-------------------------------------------------------------------------------------------
// перегрузка операторов

int operator-(const Date& dt1, const Date& dt2)
{
	return dt1._number - dt2._number;
}

Date& Date::operator ++()
{
	this->_changeNumber(1); return *this;
}

Date Date::operator ++(int)
{
	Date dt = *this; this->_changeNumber(1); return dt;
}
Date& Date::operator +=(const int count_day)
{
	this->_changeNumber(count_day);
	return *this;
}

Date& Date::operator --()
{
	this->_changeNumber(-1);
	return *this;
}

Date Date::operator --(int)
{
	Date dt = *this;
	this->_changeNumber(-1);
	return dt;
}

Date& Date::operator -=(const int count_day)
{
	this->_changeNumber(-count_day);
	return *this;
}

Date operator+(const Date& dt1, const int count_day)
{
	return Date(dt1._number + count_day);
}

Date& Date::operator =(const Date &orig)
{
	_year = orig._year;
	_month = orig._month;
	_day = orig._day;
	_number = orig._number;
	return *this;
}


//-------------------------------------------------------------------------------------------

void Date::SetDay(int d)
{
	Date temp(_year, _month, d);

	if (temp._isCorrectDate())
	{
		_day = temp._day;
		_number = temp._number;
	}
}

void Date::SetMonth(int m)
{
	Date temp(_year, m, _day);

	if (temp._isCorrectDate())
	{
		_month = temp._month;
		_number = temp._number;
	}
}

void Date::SetYear(int y)
{
	_year = y;
	_number = this->_getNumber(*this);
}

Date Date::GetRandomDate(const Date& from, const Date& to)
{
	int fr = from._number;
	int t = to._number;
	int per = t - fr + 1;

	if (per <= 0) return Date();

	int rnd = rand() % per;
	return Date(fr + rnd);
}
string Date::ToString() const
{
	stringstream os;
	os << _year << '-' << _month << '-' << _day;

	if (os) return os.str();
	else return string();
}

bool Date::operator==(const Date& dt) const
{
	return _number == dt._number;
}

bool Date::operator!=(const Date& dt) const
{
	return _number != dt._number;
}

bool Date::operator>(const Date& dt) const
{
	return _number>dt._number;
}

bool Date::operator<(const Date& dt) const
{
	return _number<dt._number;
}

bool Date::operator>=(const Date& dt) const
{
	return _number>dt._number;
}

bool Date::operator<=(const Date& dt) const
{
	return _number <= dt._number;
}

int Date::GetDay() const { return _day; }
int Date::GetMonth() const { return _month; }
int Date::GetYear() const { return _year; }
