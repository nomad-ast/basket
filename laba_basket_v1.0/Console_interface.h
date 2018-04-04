#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "stdafx.h"
#include "SportManager.h"

// ������������ ��� MenuFunction, ������� ����� ������������ 
// ��� ����, ����� �������� ��������� �� ������� ��� ���������� �
// ������������ ������ ��������
void MainMenuFunction(void);
typedef void(*MenuFunction)(void);

const int CountMenuFunctions = 14; // ���������� ������� � ����

//-------------------------------------------------------------------------------------------
// ���������� ���������� ������� ���� (��������� ���� ������� 
// ������������� ���������, ������������ ��� ����  MenuFunction)


void Exit(void);//����� �� ������������ ���� ���������
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
// �������������� �������
void PrintSpList(void);
void PrintTrenList(int numTren);
void PrintTrensList(bool proove);
Date vvod_data(void);
Time vvod_time(void);
sportsman InpSp();
trena InpTren();


// �������������� �������

//-------------------------------------------
//������ � �����
void ChangeData();



