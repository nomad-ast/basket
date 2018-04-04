#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "trena.h"
#include "sportsman.h"

using namespace std;

extern Date date_now;

extern TList <sportsman> spList;

// ���������� ������  ���������� � ���������� ������ 
void AddToSpList(const sportsman &sp);
void AddToSpListNoob(Noob Nsp);
void AddToSpListProf(Prof Psp);
// ����� ���������� � ���������� ������ �� ��������������
int FindSp(int id);
// �������� ���������� 
bool DeleteFromSpList(int id);

extern TList <trena> trList;
// ���������� ������  ���������� � ���������� ������ 
void AddToTrenList(const trena &tr);
// ����� ���������� � ���������� ������ �� ��������������
int FindTren(string typ);
// �������� ���������� 
bool DeleteFromTrList(string typ);