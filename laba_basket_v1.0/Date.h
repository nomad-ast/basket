#pragma once
#include <string> // ��� wstring
#include <sstream> // ��� wostringstream
#include <stdlib.h> // ��� rand()

using namespace std;

class Date
{
public:
	// ������������ ������
	Date(); // ����������� �� ���������
	Date(int year, int month, int day); // ����������� � �����������
	Date(const Date&); // ����������� �����������

	// ������ ��������� � ������������
	int GetDay() const; // �������� ����� ����
	int GetMonth() const; // �������� ����� ����
	int GetYear() const; // �������� ��� ����
	void SetDay(int d); // ���������� ���� ����
	void SetMonth(int m); // ���������� ����� ����
	void SetYear(int y); // ���������� ��� ����

	// ������������� ��������� ��������������� � ���������
	bool operator==(const Date& dt) const; // �������� ==
	bool operator!=(const Date& dt) const; // �������� !=
	bool operator>(const Date& dt) const; // �������� >
	bool operator<(const Date& dt) const; // �������� <
	bool operator>=(const Date& dt) const; // �������� >=
	bool operator<=(const Date& dt) const; // �������� <=

	// ������������� �������������� ���������
	Date& operator=(const Date& orig); // �������� ������������ =
	Date& operator++(); // �������� ++ (����������)
	Date operator++(int); // �������� ++ (�����������)
	Date& operator+=(const int count_day); // �������� +=
	Date& operator--(); // �������� -- (����������)
	Date operator--(int); // �������� -- (�����������)
	Date& operator-=(const int count_day); // �������� -=
	// �������� �������� -
	friend int operator-(const Date& dt1, const Date& dt2);
	// �������� �������� +
	friend Date operator+(const Date& dt1, const int count_day);

	//-------------------------------------------------------------------------------------------
	//���������

	// ���� � ���� (������������)
	static const int DAYS_IN_YEAR = 365;
	static const int MONTHES_IN_YEAR = 12; // ������� � ����
	// ����� ���� ��������� � 1.1.1 �� 1.1.2001
	static const int MILLENIUM_DAYS = 730485;
	// ����� ���� �� ������� ( � ������������ ����)
	static const int DAYS_IN_MONTH[MONTHES_IN_YEAR];

	//-------------------------------------------------------------------------------------------
	// ��������� ��������� ����

	// ���������� ��������� ���� ����� from � to
	static Date GetRandomDate(const Date& from, const Date& to);
	static bool IsLeapYear(int num);   //�������� �� ��� ����������
	bool _isCorrectDate(); // �������� �� ���� ����������
	// ��������� ���� � ��������� �������������
	string ToString() const;

private:
	int _year;   // ��� 
	int _month;	 // �����
	int _day;     // �����
	// ���������� ���� ��������� � ������ ����� ���
	int _number;
	// ���������� ���������� ���� � ������ ����� ���
	int _getNumber(Date& dt);
	//�������� ����������� ��� ����������� �������������
	Date(int num);
	void _changeNumber(int count_day); // ���� ���� count_day ����
	
};

