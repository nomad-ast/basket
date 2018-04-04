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

// добавление нового  спортсмена в глобальный список 
void AddToSpList(const sportsman &sp);
void AddToSpListNoob(Noob Nsp);
void AddToSpListProf(Prof Psp);
// поиск спортсмена в глобальном списке по идентификатору
int FindSp(int id);
// удаление спортсмена 
bool DeleteFromSpList(int id);

extern TList <trena> trList;
// добавление нового  спортсмена в глобальный список 
void AddToTrenList(const trena &tr);
// поиск спортсмена в глобальном списке по идентификатору
int FindTren(string typ);
// удаление спортсмена 
bool DeleteFromTrList(string typ);