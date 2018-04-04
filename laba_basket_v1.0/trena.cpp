#include "stdafx.h"
#include "trena.h"


trena::trena() :type(), data(), time(), durat(), ball(), prizn_otsut(),num_sports()
{
	/*type = "type";
	data = Date();
	time = Time();
	ball = 0;
	num_sports = 1;*/
}

trena::trena(string ty, Date d, Time t, Time du, int ba, int NS, string PO) :type(ty), data(d), time(t), durat(du), ball(), prizn_otsut(PO), num_sports(NS)
{
	if (ba >= 0 && ba <= 10) ball = ba;
}

trena::trena(const trena &S)
{
	type = S.type;
	data = S.data;
	time = S.time;
	durat = S.durat;
	ball = S.ball;
	prizn_otsut = S.prizn_otsut;
	num_sports = S.num_sports;
}
trena::~trena()
{
	type.~basic_string();;
	data.~Date();
	time.~Time();
	durat.~Time();

	num_sports =0;
}

string trena::GetType() const
{
	return type;
}
Date trena::GetDate() const
{
	return data;
}
Time trena::GetTime() const
{
	return time;
}
Time trena::GetDurat() const
{
	return durat;
}
int trena::GetBall() const
{
	return ball;
}
string trena::GetPOtsut() const
{
	return prizn_otsut;
}
int trena::GetintNumSp() const
{
	return num_sports;
}
int trena::GetintNumSpInTren() const
{
	return num_sp_in_tr;
}
//int trena::Getcount_sp()
//{
//	return count_sp;
//}
//èçìåíåíèå ïîëå
void trena::SetType(string ty)
{
	type = ty;
}
void trena::SetDate(Date d)
{
	data = d;
}
void trena::SetTime(Time t)
{
	time = t;
}
void trena::SetDurat(Time du)
{
	durat = du;
}
void trena::SetBall(int ba)
{
	ball = ba;
}
void trena::SetPOtsut(string PO)
{
	prizn_otsut = PO;
}
void trena::SetintNumSp(int NS)
{
	num_sports = NS;
}
void trena::SetintNumSpInTren()
{
	num_sp_in_tr++;
}
//void trena::Setcount_sp()
//{
//	count_sp++;
//}

//-------------------------------------------------------------------------------------------

string trena::ToString(bool IsFull)
{
	stringstream os;

	if (!IsFull)
	{
		os << setw(12) << type << setw(12)<< data.ToString() << setw(10) << time.ToString() <<
			setw(10) << durat.ToString() <<  setw(10) << num_sports;
	}
	else
	{
		os << "Òğåíåğîâêà..." << endl;
		os << "Òèï: " << type << endl;
		os << "Äàòà: " << data.ToString() << endl;
		os << "Âğåìÿ: " << time.ToString() << endl;
		os << "Ïğîäîëæèòåëüíîñòü: " << durat.ToString() << endl;
		os << "Âûñòàâëåííàÿ îöåíêà: " << ball << endl;
	}

	if (os) return os.str();
	return string();
}
