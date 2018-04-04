#pragma once
#include <string> // включаем описание класса string
#include <sstream> // для строковых потоков (wstringstream)
#include <iomanip> // для setw()
#include "TList.h"
#include "trena.h"
class sportsman
{
	int _id=0;
	int _getUniqueId();
	void _setUniqueId();

	string fio, prizn_otstr; //ФИО, признак отстранения
	int length;  //рост
	bool agree;		//cогласие
	bool priz_zach;	
	int Rate;

	
	TList<trena> arList ;
	//int _countInList; // число тренеровок в списке
public:
	sportsman();
	sportsman(string fio, string prizn_otstr, int length, bool agree, bool priz_zach, int Rate);
	sportsman(const sportsman &S);
	~sportsman();
	// метод, создающий копию объекта класса Suitor
	void CopyFrom(const sportsman& suitor);


	int GetId() const;
	string Getfio() const;
	string GetPO() const;
	bool GetPZ() const;
	int GetLe() const;
	bool GetAg() const;
	int GetRate() const;
	
	//void AddTren(int i,string &T);

	void Setfio(string);
	void SetPO(string);
	void SetPZ(bool);
	void SetLe(int);
	void SetAg(bool);
	void SetRate(int);

	

	//-------------------------------------------------------------------------------------------
	// работа со списком тренеровок

	// добавить тренеровку в список
	void AddTrena(const trena& app);
	// удалить тренеровку из списка по дате и времени проведения
	bool DeleteTrena(Date date);
	// получить количество тренеровок
	int GetTrenaCount() ;
	// поиск тренеровки по дате и времени проведения
	trena FindTrena(Date date, Time time) ;
	// получить тренеровку по индексу в списке
	trena FindTrena(int idx) ;
	string ToString(bool IsFull = false) const;

	//-------------------------------------------------------------------------------------------
	static const int MAX_LENGTH = 300; //ограничение на рост
	
};


class Prof :public sportsman
{
	string razr;
	string gruup;

public:
	Prof();
	Prof(string fio, string prizn_otstr, int length, bool agree, bool priz_zach, int rate);
	string Getgruup();
	string Getrazr(){ return this->razr; }

	void Setgruup(string gr){ this->gruup = gr; }
	void Setrazr(string _razr){ this->razr = _razr; }

	string ToString(bool IsFull = false) const;
	void GetRate();
};
class Noob :public sportsman
{
	string gruup;
public:
	Noob();
	Noob(string fio, string prizn_otstr, int length, bool agree, bool priz_zach,int rate);
	string Getgruup(){ return this->gruup; }
	void Setgruup(string gr){ this->gruup = gr; }
	string ToString(bool IsFull = false);

	//void GetRate();
};

