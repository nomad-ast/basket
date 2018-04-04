#pragma once
#include <string> // для wstring
#include <sstream> // для wostringstream
#include <stdlib.h> // для rand()

using namespace std;

class Date
{
public:
	// конструкторы класса
	Date(); // конструктор по умолчанию
	Date(int year, int month, int day); // конструктор с параметрами
	Date(const Date&); // конструктор копирования

	// методы селекторы и модификаторы
	int GetDay() const; // получить число даты
	int GetMonth() const; // получить месяц даты
	int GetYear() const; // получить год даты
	void SetDay(int d); // установить день даты
	void SetMonth(int m); // установить месяц даты
	void SetYear(int y); // установить год даты

	// перегруженные операторы эквивалентности и сравнения
	bool operator==(const Date& dt) const; // оператор ==
	bool operator!=(const Date& dt) const; // оператор !=
	bool operator>(const Date& dt) const; // оператор >
	bool operator<(const Date& dt) const; // оператор <
	bool operator>=(const Date& dt) const; // оператор >=
	bool operator<=(const Date& dt) const; // оператор <=

	// перегруженные арифметические операторы
	Date& operator=(const Date& orig); // оператор присваивания =
	Date& operator++(); // оператор ++ (префиксный)
	Date operator++(int); // оператор ++ (постфиксный)
	Date& operator+=(const int count_day); // оператор +=
	Date& operator--(); // оператор -- (префиксный)
	Date operator--(int); // оператор -- (постфиксный)
	Date& operator-=(const int count_day); // оператор -=
	// бинарный оператор -
	friend int operator-(const Date& dt1, const Date& dt2);
	// бинарный оператор +
	friend Date operator+(const Date& dt1, const int count_day);

	//-------------------------------------------------------------------------------------------
	//константы

	// дней в году (невисокосном)
	static const int DAYS_IN_YEAR = 365;
	static const int MONTHES_IN_YEAR = 12; // месяцев в году
	// число дней прошедших с 1.1.1 по 1.1.2001
	static const int MILLENIUM_DAYS = 730485;
	// число дней по месяцам ( в невисокосном году)
	static const int DAYS_IN_MONTH[MONTHES_IN_YEAR];

	//-------------------------------------------------------------------------------------------
	// генерация случайной даты

	// возвращает случайную дату между from и to
	static Date GetRandomDate(const Date& from, const Date& to);
	static bool IsLeapYear(int num);   //является ли год високосным
	bool _isCorrectDate(); // является ли дата корректной
	// переводит дату в строковое представление
	string ToString() const;

private:
	int _year;   // год 
	int _month;	 // месяц
	int _day;     // число
	// количество дней прошедших с начала новой эры
	int _number;
	// возвращает количество дней с начала новой эры
	int _getNumber(Date& dt);
	//закрытый конструктор для внутреннего использования
	Date(int num);
	void _changeNumber(int count_day); // дата черз count_day дней
	
};

