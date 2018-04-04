#include "sportsman.h"

int sportsman::_getUniqueId()
{
	static int Id = 1;

	return  Id++;
}



sportsman::sportsman()
{
	Rate = 0;
	//_id = _getUniqueId();
}

sportsman::sportsman(string _fio, string _prizn_otstr, int _length, bool _agree, bool _priz_zach, int _Rate)
:fio(_fio), prizn_otstr(_prizn_otstr), agree(_agree), priz_zach(_priz_zach), Rate(_Rate), arList()
{
	_id = _getUniqueId();

	if (_length > 0 && _length < MAX_LENGTH) 
		this->length = _length;
	else length = 0;
	Rate = 0;

}
sportsman::sportsman(const sportsman &S) {
	this->_id = S._id;
	//this->_countInList = S._countInList;
	this->fio = S.fio;
	/*this->prizn_otsut = S.prizn_otsut;*/
	this -> Rate = S.Rate;
	this->prizn_otstr = S.prizn_otstr;
	this->length = S.length;
	this->agree = S.agree;
	this->priz_zach = S.priz_zach;

};
sportsman::~sportsman()
{
	fio.~basic_string();
	/*prizn_otsut.~basic_string();*/
	prizn_otstr.~basic_string();
	this->length = 0;
	this->agree = 0;
	this->priz_zach = 0;
	this->Rate = 0;
	arList.~TList();
}
void sportsman::CopyFrom(const sportsman &S){
	this->~sportsman();

	this->_id = S._id;
	this->fio = S.fio;
	/*this->prizn_otsut = S.prizn_otsut;*/
	this->Rate = S.Rate;
	this->prizn_otstr = S.prizn_otstr;
	this->length = S.length;
	this->agree = S.agree;
	this->priz_zach = S.priz_zach;

	//arList(S.arList);

};
int sportsman::GetId() const
{
	return _id;
}

string sportsman::Getfio() const
{
	return this->fio;
}
string sportsman::GetPO() const
{
	return this->prizn_otstr;
}
int sportsman::GetLe() const
{
	return this->length;
}
bool sportsman::GetAg() const
{
	return this->agree;
}
bool sportsman::GetPZ() const
{
	return this->priz_zach;
}
int sportsman::GetRate() const
{
	return this->Rate;
}

//wstring sportsman::GetPOtsut() const
//{
//	return prizn_otsut;
//}


void sportsman::Setfio(string _fio)
{
	this->fio = _fio;
}
void sportsman::SetPO(string _PO)
{
	this->prizn_otstr = _PO;
}
void sportsman::SetPZ(bool _PZ)
{
	this->priz_zach = _PZ;
}
void sportsman::SetLe(int _Le)
{
	if (_Le > 0 && _Le < MAX_LENGTH) this->length = _Le;
}
void sportsman::SetAg(bool _Ag)
{
	this->agree = _Ag;
}
void sportsman::SetRate(int R)
{
	this->Rate = this->Rate+R;
}
//void sportsman::SetPOtsut(wstring PO)
//{
//	prizn_otsut = PO;
//}




// добавить тренеровку в список
void sportsman::AddTrena(const trena &app)
{
	arList.Add(app);
}
bool sportsman::DeleteTrena(Date date)
{
	int count = arList.Count();
	for (int i = 0; i < count; i++)
	if ((arList[i].GetDate() == date))
	{
		arList.Delete(i);
		return true;
	}
	return false;
}
int sportsman::GetTrenaCount()
{
	return arList.Count();
}

trena sportsman::FindTrena(Date date, Time time) 
{
	int count = arList.Count();
	for (int i = 0; i<count; i++)
	if ((arList[i].GetTime() == time) && (arList[i].GetDate() == date))
		return arList[i];

	return trena();

}

trena sportsman::FindTrena(int idx) 
{
	if (idx >= 0 && idx<arList.Count())
		return arList[idx];

	return trena();

}

string sportsman::ToString(bool IsFull) const
{
	stringstream os;
	if (!IsFull)
	{
		string ag = "";
		if (agree == 1) ag = " Согласен ";
		else ag = " Не согласен ";
		os << setw(2) << _id << setw(10) << fio << setw(5) << length << " cm" << 
			setw(5) << prizn_otstr << setw(5) << ag << setw(5) << priz_zach << setw(5) << Rate;
	}
	else
	{
		os << "ФИО: " << Getfio()<< endl;
		os << "Рост: " << GetLe() << " cm" << endl;
		os << "Признак временного отстранения от тренеровок: " << GetPO() << endl;
		os << "Согласие: ";
		if (GetAg() == 1) os << "Согласен " << endl;
		else  os << "Не согласен " << endl;
		os << "Признак зачисления в профессиональный состав " <<
			GetPZ() << endl;
		os << "Рейтинг " << GetRate() << endl;
		/*os << "Число тренеровок: " <<
			GetTrenaCount() << endl;*/
		
	}
	if (os) return os.str();
	else return string();
}

Noob::Noob()
{
	sportsman();
	gruup = " Любитель ";
}
Noob::Noob(string fio, string prizn_otstr, int length, bool agree, bool priz_zach,int rate)
{
	this->sportsman::sportsman(fio, prizn_otstr, length, agree, priz_zach, rate);
	gruup = " Любитель ";
}
string Noob::ToString(bool IsFull) 
{
	stringstream os;
	if (!IsFull)
	{
		os << setw(4) << gruup;
	}
	else
	{
		os << "Группа " << Getgruup() << endl;
		

	}
	if (os) return os.str();
	else return string();
}

Prof::Prof()
{
	this->sportsman::sportsman();
	this->razr = "3-юношеский";
	this->gruup = " Профессионал ";
}
Prof::Prof(string fio, string prizn_otstr, int length, bool agree, bool priz_zach,int rate)
{
	this->sportsman::sportsman(fio, prizn_otstr, length, agree, priz_zach,rate);
	//this->razr = _razr;
	Setgruup(" Профессионал ");
}
