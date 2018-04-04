#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "stdafx.h"
#include "SportManager.h"

// определ€етс€ тип MenuFunction, который можно использовать 
// дл€ того, чтобы объ€вить указатель на функцию без параметров и
// возвращающую пустое значение
void MainMenuFunction(void);
typedef void(*MenuFunction)(void);

const int CountMenuFunctions = 14; // количество функций в меню

//-------------------------------------------------------------------------------------------
// объ€вление прототипов функций меню (сигнатура всех функций 
// соответствует сигнатуре, определенной дл€ типа  MenuFunction)


void Exit(void);//выход из зацикленного меню программы
void AddRandomSp(void);
void AddRandomTren(void);
void AddSp(void);
void DelSp(void);
void AddTrenToSp(void);
void AddTren(void);
void DelTren(void);
void ChangeTren(void);
void FullInf(void);
void TrenMenu(void);
void showPlay(void);
void XMLinp(void);
void XMLout(void);


//------------------------------------------------------------------------
// дополнительные функции
void PrintSpList(void);
void PrintTrenList(int numTren);
void PrintTrensList(bool proove);
Date vvod_data(void);
Time vvod_time(void);
sportsman InpSp();
trena InpTren();


// дополнительные функции

//-------------------------------------------
//работа с датой
void ChangeData();



