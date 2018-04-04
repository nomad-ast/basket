#pragma once

#include "stdafx.h"

#include <string>
#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

TList <sportsman> spList;
//TList <Prof> prList;
TList <trena> trList;
Date date_now;



 void AddToSpList(const sportsman& sp)
{
	spList.Add(sp);
}
 void AddToSpListNoob(const Noob &Nsp)
{
	 spList.Add(Nsp);
}
 void AddToSpListProf(const Prof &Psp)
 {
	 spList.Add(Psp);
 }
// ����� � ������
int FindSp(int id)
{
	int idx = -1;
	for (int i = 0; i<spList.Count(); i++)
	if (spList[i].GetId() == id)
	{
		idx = i;
		break;
	}
	return idx;

}
// �������� ���������� 
bool DeleteFromSpList(int id)
{
	if (!spList.Count()) return false;
	int num = FindSp(id);
	if (num == -1) return false;
	spList.Delete(num);
	return true;
}

// ���������� ���������� � ������
void AddToTrenList(const trena& tr)
{
	trList.Add(tr);
}
// ����� � ������
int FindTren(string typ)
{
	int num = -1;
	for (int i = 0; i < trList.Count(); i++)
	{
		if (trList[i].GetType() == typ)
		{
			num = i;
			break;
		}
	}
	/*if (num == -1)
	{
		string trName;
		cout << "���������� �� �������. ������� �������� ����������!\n";
		cin >> trName;
		FindTren(trName);
	}*/
	return num;
}
// �������� ���������� �� ������
bool DeleteFromTrList(string typ)
{
	if (!trList.Count()) return false;
	int num = FindTren(typ);
	if (num == -1) return false;
	trList.Delete(num);
	return true;
}

