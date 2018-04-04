#pragma once
#include <string>
#include "stdafx.h"
#using <System.Security.dll>
#using <System.Xml.dll>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Xml;


void MainMenuFunction(void)
{

	if (date_now.GetYear() == 1){
		cout << "������� ����: \n";
		date_now = vvod_data();

		while (date_now.GetYear() < 2000 || !date_now._isCorrectDate()){
			cout << "�������� ����" << endl;
			date_now = vvod_data();
		}
	}
	
	MenuFunction Functions[CountMenuFunctions] = {
		&Exit,
		&AddRandomSp,
		&AddSp,
		&DelSp,
		&ChangeData,
		&AddTrenToSp,
		&TrenMenu,
		&FullInf,
		&showPlay,
		&XMLinp,
		&XMLout,
	};


	do
	{
		int select;

		system("cls");
		cout << "������� ����: " << date_now.ToString()<<endl;
		cout << "������ �������" << endl;
		PrintSpList();
		cout << endl;

		cout << "�������� ������ ��� ����� ����" << endl;
		cout << "1 - �������� � ������ ��������� �������." << endl;
		cout << "2 - �������� ������." << endl;
		cout << "3 - ������� ������." << endl;
		cout << "4 - �������� ����." << endl;
		cout << "5 - ������� ���������� ��� ����������." << endl;
		cout << "6 - ���� ����������." << endl;
		//cout << "7 - ������� � ������ ���������� " << endl;
		cout << "7 - ������� ��������� ������." << endl;
		cout << "8 - �������� ������ �� ��������� ����." << endl;
		cout << "9 - ��������� XML." << endl;
		cout << "10 - ��������� XML." << endl;
		cout << "0 - �����." << endl;

		wcout << "��� �����: ";
		do
		{
			wcin >> select;
		} while (select<0 || select >= CountMenuFunctions);

		wcout << endl;
		(Functions[select])();
	} while (true);
}
int FindNumberOfSp(void)
{
	int id;
	cout << "�������� ���������� " << endl;
	cout << "������� ID ����������:";
	cin >> id;
	int WebsiteNum = FindSp(id);
	if (WebsiteNum == -1) cout << "���������� � ����� ID ���" << endl;
	return WebsiteNum;
}
int FindNumberOfTr(void)
{
	string name;
	cout << "�������� ���������� " << endl;
	cout << "������� �������� ����������:";
	cin >> name;
	int TrNum = FindTren(name);
	
	return TrNum;
}
void Exit(void)//����� �� ������������ ���� ���������
{
	int select;
	cout << "�� ������� � ���, ��� ������ �����?" << endl;
	cout << "1 - ��" << endl;
	cout << "0 - ������" << endl;

	cout << "��� �����: ";

	cin >> select;

	if (select) exit(1);
}

void AddRandomSp(void)//�������� �������� ���������� �����������
{
	int count = rand() % 50+1;
	int prevCount = spList.Count();
	string second_name[15] = { "������ ", "������ ", "�������� ", "������� ", "�������� ", "������ ", "������ ", "��������� ", "���� ", "���������� ", "������ ", "�������� ", "�������� ", "����� ", "����� " };
	string name[15] = { "�������� ", "������� ", "������� ", "������� ", "�������� ", "��������� ", "������� ", "���� ", "������ ", "����� ", "����� ", "������� ", "��������� ", "������ ", "���������� " };
	string otchestvo[15] = { "��������", "�������������", "����������", "�����������", "�������", "���������", "������������", "����������",
		"����������", "���������", "�����", "��������������", "���������", "����������", "����������" };
	string PO[4] = { " ������ ", " ������� ���������� ", "-", " ������� " };
	string priz_otsut[2] = { "������������", "�����������" };

	for (int i = 0; i<count; i++)
	{
		string fio = second_name[rand() % 14] + name[rand() % 14] + otchestvo[rand() % 14];
		int length = rand() % 51 + 160; //�� 160 �� 210
		bool agree = rand() % 2;
		bool PZ = 0;
		string prizn_otstr = PO[rand() % 4];
		string _prizn_otsut = priz_otsut[rand() % 2];
		AddToSpList(sportsman(fio, prizn_otstr, length, agree, PZ,0));
	}
	cout << "���������� ���� ��������� � ������!" << endl;
}
void AddRandomTren(void)
{
	int kol_tren = rand() % 6 + 1;
	string treni[5] = { "��������", "������", "���", "��������", "�������" };
	
	for (int i = 0; i < kol_tren; i++){
		string _type = treni[rand() % 5];
		Date _date = date_now; //�� 0 �� 5
		Time _time = Time(19, 20); //�� 160 �� 210
		Time _durat = Time(1, 30);
		int _ball = rand() % 10;
		string PO[2] = { "������������ ", "����������� " };
		string pr_ot = PO[rand() % 2];
		int NS = rand() % 10;
		AddToTrenList( trena(_type, _date, _time, _durat, 0,NS, ""));
	}
	cout << "���������� ���� ��������� � ������!" << endl;
}
void PrintSpList(void)
{
	int count = spList.Count();
	if (!count)
	{
		cout << "������ ������� ����!" << endl;
		return;
	}
	cout << "ID" << setw(5) << "��� " << setw(5) <<
		"���� " << setw(5) << " ������� ���������� ����������� " << setw(5) << " �������� " << setw(5) <<
		" ������� ���������� " << setw(5)<<" ������� "<<setw(5) << " ���������� ���������� " << endl;
	for (int i = 0; i<count; i++)
		cout << spList[i].ToString(false) << setw(5) << spList[i].GetTrenaCount()<<endl;
}

Date vvod_data()
{
	int y1, d1, m1;
	cout << "���: " << endl; cin >> y1; 
	cout << "�����: " << endl; cin >> m1; 
	cout << "����: " << endl; cin >> d1;
	return Date(y1,m1,d1);

}
Time vvod_time()
{
	int h1, m1;
	Time new_tim;
	cout << "������� �����: " << endl;
	cout << "����: " << endl; cin >> h1; new_tim.SetHour(h1);
	cout << "������: " << endl; cin >> m1; new_tim.SetMinute(m1);
	return new_tim;
}
sportsman InpSp()
{
	string second_name, name, otchestvo, PO, priz_otsut,fio;
	int length; bool agree, PZ;
	cout << "���� ����������: " << endl;
	cout << "�������: " << endl; cin >> second_name;
	cout << "���: " << endl; cin >> name;
	cout << "��������: " << endl; cin >> otchestvo;
	fio = second_name + " " + name + " "+ otchestvo;
	cout << "������� �����������: " << endl; cin >> PO;
	cout << "����: " << endl; cin >> length;
	cout << "��������: " << endl; cin >> agree;
	//cout << "������� ����������: " << endl; cin >> PZ;
	PZ = 0;
	return sportsman(fio, PO, length, agree,PZ,0);
}

Noob InpNsp(sportsman sp)
{
	return Noob(sp.Getfio(), sp.GetPO(), sp.GetLe(), sp.GetAg(), sp.GetPZ(),sp.GetRate());
}
Prof InpPsp(sportsman sp)
{
	return Prof(sp.Getfio(), sp.GetPO(), sp.GetLe(), sp.GetAg(), sp.GetPZ(), sp.GetRate());
}
trena InpTren()                         //���� �����
{
	string _type;
	Date _date;//���� 
	Time _time;//�����
	Time _durat;//�����
	double _ball;
	string _prizn_otsut;
	int _num_sports;
	cout << "������� ��� ���������� "; cin >> _type;
	cout << "���� ���� ����������" << endl; _date = vvod_data();
	while (_date.GetYear() < 2000 || !_date._isCorrectDate())
	{
		cout << "�������� ����" << endl;
		_date = vvod_data();
	};
	cout << "���� ������� ���������� " << endl; _time = vvod_time();
	cout << "���� ������������ ���������� " << endl; _durat = vvod_time();

	cout << "���� �����, �� ������� ��������� ������ ���� ���������� �� �� ����������� "; cin >> _ball;
	cout << "������� ���������� "; cin >> _prizn_otsut;
	cout << "���������� ����������� ������� � ������ ����������";  cin >> _num_sports;

	return trena(_type, _date, _time, _durat, _ball, _num_sports,_prizn_otsut );
}


void AddSp(void)
{
	cout << "���������� ���������� " << endl;
	sportsman sp = InpSp();
	AddToSpList(sp);
	cout << "C�������� �������� �������� � ������!" << endl;
}
void DelSp(void)
{
	int id;
	cout << "�������� ���������� " << endl;
	cout << "������� ID ���������� ";
	cin >> id;
	if (DeleteFromSpList(id))
		cout << "�������� ����������� �������!" << endl;
	else
		cout << "��������� �� ��� ������" << endl;
	system("pause");
};
void AddTrenToSp(void)
{
	
	int id;
	cout << "������� ������ ���������: "; cin >> id; int num = FindSp(id);
	if (spList[num].GetPO()=="-")
	{
		PrintTrensList(false);// �����
		if (trList.Count() == 0)
		{
			system("pause");
		}
		else
		{
			string trName;
			cout << "�������� �� ������ ���������� "; cin >> trName; int tr_num = FindTren(trName); 
			if (trList[tr_num].GetintNumSpInTren() == trList[tr_num].GetintNumSp()){
				
				cout << "T��������� �������������a!!" << endl;
				system("pause");  //���� ���������� �������������a
			}
			else{
				int bal;
				string POts;
				cout << "������� ����: " << endl; cin >> bal; trList[tr_num].SetBall(bal);
				cout << "������� ������� ����������: " << endl; cin >> POts; trList[tr_num].SetPOtsut(POts);
				spList[num].SetRate(bal);
				spList[num].AddTrena(trList[tr_num]);
				cout << "���������� ���������" << endl;
				trList[tr_num].SetintNumSpInTren();
			}
		}
	}
	else
	{
		cout << "���������� �� ���������, �� �������: " << spList[num].GetPO() << endl;
		system("pause");
	}
};

void TrenMenu(void)
{
	MenuFunction Functions[8]
	{
		&MainMenuFunction,
			&AddTren,
			&DelTren,
			&ChangeTren,
			&AddRandomTren,
	
	};
	do
	{
		int select;
		system("cls");
		cout << "������� ����: " << date_now.ToString() << endl;
		cout << "������ ���������� " << endl;
		PrintTrensList(true);
		cout << endl;
		cout << "�������� ������ ��� ����� ����" << endl;
		cout << "1 - �������� ����������." << endl;
		cout << "2 - ������� ����������." << endl;
		cout << "3 - ������������� ����������." << endl;
		/*cout << "4 - ������������� ����������." << endl;*/
		cout << "4 - �������� ��������� ����������" << endl;
		cout << "0 - �����." << endl;
		cout << "��� �����: ";
		do
		{	// ���� ������ ������������� ������ ����
			cin.clear();
			cin.sync();
			cin >> select;
		} while (select<0 || select >= 8 || cin.fail());
		cout << endl;
		// Functions � ������ ���������� �� ������� ����,
		// select � ������ �������� �������, ���������� �� 
		// �������, ����������� ��������� ������ ����
		(Functions[select])(); // ����� ������� ����� ��������� 
	} while (true);
};

void PrintTrensList(bool proove)
{
	int count = trList.Count();
	if (!count)
	{
		cout << "������ ����������  ����!" << endl;
		return;
	}
	cout << setw(7) << "���" << setw(7) << "����" << setw(13) << "�����" << setw(13)
		<< "�����������������" << setw(13)
		<< "���������� �����������" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << trList[i].ToString(false) << endl;
	}
}
void AddTren(void){
	cout << "���������� ���������� " << endl;
	trena tr = InpTren();
	AddToTrenList(tr);
	cout << "���������� �������� ��������� � ������!" << endl;
}
void DelTren(void)
{
	string typ;
	cout << "�������� ���������� " << endl;
	cout << "������� �������� ���������� ";
	cin >> typ;
	if (DeleteFromTrList(typ))
		cout << "�������� ����������� �������!" << endl;
	else
		cout << "���������� �� ���� �������" << endl;
	system("pause");
}
void ChangeTren(void)
{

}
void transfer()
{
	int min_len,co_tr,kol_vak,count=0; Time stT, enT; double sr_rate;
	cout << "������� ����������� � ���������������� ������" << endl;
	cout << "������� ���������� �������� � ���������������� ������: " << endl; cin >> kol_vak;
	cout << "������� �������� ����������� ��� ��������:" << endl;
	cout << "����������� ����: "; cin >> min_len;
	//cout << "\n������: "; stT = vvod_time(); enT = vvod_time();
	cout << "\n����������� ������� ������� �� ��� ������: "; cin >> sr_rate;
	cout << "\n���������� ����������� ����������: "; cin >> co_tr;
	for (int i = 0; i < spList.Count(); i++){
		if ((min_len < spList[i].GetLe()) && (sr_rate < spList[i].GetRate()) && (spList[i].GetAg() == 1)&&(count<kol_vak))
		{
			InpPsp(spList[i]);
			count++;
			spList[i].SetPZ(1);
		}
		else
			InpNsp(spList[i]);
	}
	
}

void bubl_rate()				//���������� ���������
{
	Noob sp1, sp2;
	for (int i=0; i < spList.Count(); i++) // i - ����� �������
	{
		for (int j = i + 1; j < spList.Count(); j++) // ���������� ���� �������
		{
			
			
			if (InpNsp(spList[i]).GetRate() < InpNsp(spList[j]).GetRate())
			{
				spList.swapS(spList._getElement(i), spList._getElement(j));   //����� ���������
				swap(InpNsp(spList[i]), InpNsp(spList[j]));
			}
			/*if (InpNsp(spList[i]).GetRate() == InpNsp(spList[j]).GetRate())
			{
				if (InpNsp(spList[i]).GetLe() < InpNsp(spList[j]).GetLe())
				{
					spList.swapS(spList._getElement(i), spList._getElement(j));   //����� ���������
					swap(InpNsp(spList[i]), InpNsp(spList[j]));
				}
			}*/
			
		}
	}
}

void ChangeData()
{
	/*int ttt = trList.Count();
	for (int i = 0; i < ttt; i++){
		if (trList[i].GetDate() == date_now) {
			trList.Delete(i); cout << "���������� �������\n";
		}
	}*/
	cout << "������� ����� ����" << endl;
	Date old_data = date_now;
	date_now = vvod_data();
	
	
	if ((old_data.GetMonth() < date_now.GetMonth()) || (old_data.GetYear() < date_now.GetYear()))
	{
		
		transfer();
		bubl_rate();
	}
	
}

void FullInf(void)
{
	int id,select;
	string priz_ot;
	cout << "������� ������ ���������: "; cin >> id; int num = FindSp(id); 
	
	do
	{
		cout << spList[num].ToString(true) << endl;
		cout << "�������� ��� �� ������ ��������:" << endl;
		cout << "1 - ����." << endl;
		cout << "2 - ������� �����������." << endl;
		cout << "3 - ��������." << endl;
		cout << "4 - ����� � ����." << endl;

		do
		{	
			cin >> select;
		} while (select<0 || select > 4);
		cout << endl;
		switch (select)
		{
		case 1:
			int rost;
			cout << "������� ����" << endl;
			cin >> rost;
			spList[num].SetLe(rost);
			break;
		case 2:
			cout << "������� ������� �����������" << endl;
			cout << "'-' - �� ���������" << endl;
			cin >> priz_ot;
			spList[num].SetPO(priz_ot);
			break;
		case 3:
			int Ag;
			cout << "������� ��������" << endl;
			cout << "1 - ��������." << endl;
			cout << "0 - �� ��������." << endl;
			cin >> Ag;
			while ((Ag > 1) || (Ag < 0)){ cout << "������� 1 ��� 0" << endl; cin >> Ag; }
				
			spList[num].SetAg(Ag);
			break;
		case 4:
			MainMenuFunction();
			break;
		}
	} while (true);
}

void showPlay()
{
	bool help = false;
	cout << "ID" << setw(5) << "��� " << setw(5) <<
		"���� " << setw(5) << " ������� ���������� ����������� " << setw(5) << " �������� " << setw(5) <<
		" ������� ���������� " << setw(5) << " ������� " << setw(5) << " ���������� ���������� " << endl;
	for (int i = 0; i < spList.Count(); i++){
		if (spList[i].GetPZ())
		{
			cout << spList[i].ToString(false) << setw(5) << spList[i].GetTrenaCount() << endl;
			help = true;
		}
		
	}
	
	if (!help)cout << "������ ����!!!" << endl;
		system("pause");
}
Date convertToDate(string date)
{
	Date test;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	test.SetYear(year);
	test.SetMonth(month);
	test.SetDay(day);
	return test;
}
Time convertToTime(string time)
{
	Time Time;
	int hour = atoi(time.substr(0, 2).c_str());
	int minute = atoi(time.substr(3, 2).c_str());
	Time.SetHour(hour);
	Time.SetMinute(minute);
	return Time;
}
void XMLinp(void){
	XmlDocument^ docXML = gcnew XmlDocument();
	docXML->Load("C:\\Users\\������\\Desktop\\ms.xml");
	int i = 0;
	string fio, priz_ots;
	int id, rate, length;
	bool agree, priz_zach;
	string ShowName;
	Date ShowDate;
	Time ShowTime,ShowPr;
	for each (XmlNode^ n in docXML->SelectNodes("/head/���������"))
	{
		if (n->Attributes["ID"])
		{
			id = Convert::ToInt32(n->Attributes["ID"]->Value);
		}
		if (n->Attributes["���"])
		{
			fio = msclr::interop::marshal_as<string>(n->Attributes["���"]->Value);
		}
		if (n->Attributes["����"])
		{
			length =  Convert::ToInt32(n->Attributes["����"]->Value);
		}
		if (n->Attributes["�������_����������_�����������"])
		{
			priz_ots = msclr::interop::marshal_as<string>(n->Attributes["�������_����������_�����������"]->Value);
		}
		if (n->Attributes["��������"])
		{
			agree = Convert::ToInt32(n->Attributes["��������"]->Value);
		}
		if (n->Attributes["�������_����������"])
		{
			priz_zach = Convert::ToInt32(n->Attributes["�������_����������"]->Value);
		}
		if (n->Attributes["�������"])
		{
			rate = Convert::ToInt32(n->Attributes["�������"]->Value);
		}
		for each (XmlNode^ a in n->SelectNodes("����������"))
		{
			if (a->Attributes["���"])
			{
				ShowName = msclr::interop::marshal_as<std::string>(a->Attributes["���"]->Value);
			}
			if (a->Attributes["����"])
			{
				ShowDate = convertToDate(msclr::interop::marshal_as<string>(a->Attributes["����"]->Value));
			}
			if (a->Attributes["�����"])
			{
				ShowTime = convertToTime(msclr::interop::marshal_as<std::string>(a->Attributes["�����"]->Value));
			}
			if (a->Attributes["�����������������"])
			{
				ShowPr = convertToTime(msclr::interop::marshal_as<std::string>(a->Attributes["�����������������"]->Value));
			}
			/*if (a->Attributes["������������_������"])
			{
				ShowName = msclr::interop::marshal_as<std::int>(a->Attributes["������������_������"]->Value);
			}*/
		}
		AddToSpList(sportsman(fio, priz_ots, length, agree, priz_zach,rate));
		//AddToBannerList(Banner(name, firm, startDate, endDate, min, max, act));
		//BannerList[i].AddShow(Show(ShowName, ShowDate, ShowTime));
		i++;
	}

}
void XMLout(void){
	XmlTextWriter^ textWritter = gcnew XmlTextWriter("C:\\Users\\������\\Desktop\\ms.xml", System::Text::Encoding::UTF8);
	textWritter->WriteStartDocument();
	//����� ������(head) :
	textWritter->WriteStartElement("head");
	//��������� � :
	textWritter->WriteEndElement();
	//� ��������� ��� XmlTextWriter :
	textWritter->Close();

	//��� ��������� ������ �� ����� ������������ ����� XmlDocument 
	XmlDocument^ document = gcnew XmlDocument();
	//��������� ��� ���� :
	document->Load("C:\\Users\\������\\Desktop\\ms.xml");
	//������ XML - ������:
	for (int i = 0; i < spList.Count(); i++)
	{
		XmlElement^ elementVed = document->CreateElement("���������");
		document->DocumentElement->AppendChild(elementVed); // ��������� ��������

		XmlAttribute^ attribute = document->CreateAttribute("ID"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetId()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute); // ��������� �������

		attribute = document->CreateAttribute("���"); // ������ �������
		attribute->Value = gcnew String(spList[i].Getfio().c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute); // ��������� �������

		attribute = document->CreateAttribute("����"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetLe()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute); // ��������� �������

		attribute = document->CreateAttribute("�������_����������_�����������"); // ������ �������
		attribute->Value = gcnew String(spList[i].GetPO().c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("��������"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetAg()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("�������_����������"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetPZ()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("�������"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetRate()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("����������_����������"); // ������ �������
		attribute->Value = gcnew String(to_string(spList[i].GetTrenaCount()).c_str()); // ������������� �������� ��������
		elementVed->Attributes->Append(attribute);
		for (int j = 0; j < spList[i].GetTrenaCount(); j++)
		{
			XmlNode^ subElementStud = document->CreateElement("����������");
			elementVed->AppendChild(subElementStud);

			XmlAttribute^ attributeStud = document->CreateAttribute("���");
			attributeStud->Value = gcnew System::String(trList[i].GetType().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("����");
			attributeStud->Value = gcnew System::String(trList[i].GetDate().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("�����");
			attributeStud->Value = gcnew System::String(trList[i].GetTime().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("�����������������");
			attributeStud->Value = gcnew System::String(trList[i].GetDurat().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			/*attributeStud = document->CreateAttribute("������������_������");
			attributeStud->Value = gcnew System::String(trList[i].GetBall().ToString());
			subElementStud->Attributes->Append(attributeStud);*/

		}

	}
	document->Save("C:\\Users\\������\\Desktop\\ms.xml");
	
}
