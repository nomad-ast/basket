#pragma once
#include <string> // для строк
#include <sstream> // для wostringstream
#include <iomanip> // для setw()

#include "Time.h"
#include "Date.h"

#include "trena.h"
using namespace std; // стандартное пространство имен

class trena
{
	string type;
	Date data;//дата 
	Time time;//время
	Time durat;
	int ball;
	int num_sports;
	int num_sp_in_tr=0; //количество спортсменов в тренировке
	string prizn_otsut;  //признак отсутвия на тренеровке
public:
	trena();
	trena(string, Date, Time, Time, int, int, string);
	trena(const trena &S);
	~trena();

	string GetType() const;
	Date GetDate() const;
	Time GetTime() const;
	Time GetDurat() const;
	int GetBall() const;
	int GetintNumSp() const;
	int GetintNumSpInTren() const;
	string GetPOtsut() const;

	//int Getcount_sp();
	//изменение поле
	void SetType(string);
	void SetDate(Date);
	void SetTime(Time);
	void SetDurat(Time);
	void SetBall(int);
	void SetintNumSp(int);
	void SetintNumSpInTren();
	void SetPOtsut(string);
	//void Setcount_sp();

	string ToString(bool IsFull = false);
};

