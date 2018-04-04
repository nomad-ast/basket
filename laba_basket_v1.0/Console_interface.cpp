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
		cout << "Введите дату: \n";
		date_now = vvod_data();

		while (date_now.GetYear() < 2000 || !date_now._isCorrectDate()){
			cout << "Неверная дата" << endl;
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
		cout << "Текущая дата: " << date_now.ToString()<<endl;
		cout << "Список игроков" << endl;
		PrintSpList();
		cout << endl;

		cout << "Выберите нужный вам пункт меню" << endl;
		cout << "1 - Добавить в список случайных игроков." << endl;
		cout << "2 - Добавить игрока." << endl;
		cout << "3 - Удалить игрока." << endl;
		cout << "4 - Изменить дату." << endl;
		cout << "5 - Выбрать тренеровку для спортсмена." << endl;
		cout << "6 - Меню тренеровок." << endl;
		//cout << "7 - Перейти к списку тренеровок " << endl;
		cout << "7 - Увидеть подробный отсчет." << endl;
		cout << "8 - Показать состав на ближайшую игру." << endl;
		cout << "9 - Загрузить XML." << endl;
		cout << "10 - Выгрузить XML." << endl;
		cout << "0 - Выйти." << endl;

		wcout << "Ваш выбор: ";
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
	cout << "Выберите спортсмена " << endl;
	cout << "Введите ID спортсмена:";
	cin >> id;
	int WebsiteNum = FindSp(id);
	if (WebsiteNum == -1) cout << "Спортсмена с таким ID нет" << endl;
	return WebsiteNum;
}
int FindNumberOfTr(void)
{
	string name;
	cout << "Выберите тренеровку " << endl;
	cout << "Введите название тренеровки:";
	cin >> name;
	int TrNum = FindTren(name);
	
	return TrNum;
}
void Exit(void)//выход из зацикленного меню программы
{
	int select;
	cout << "Вы уверены в том, что хотите выйти?" << endl;
	cout << "1 - да" << endl;
	cout << "0 - отмена" << endl;

	cout << "Ваш выбор: ";

	cin >> select;

	if (select) exit(1);
}

void AddRandomSp(void)//добавить случаное количество спортсменов
{
	int count = rand() % 50+1;
	int prevCount = spList.Count();
	string second_name[15] = { "Аникин ", "Беляев ", "Вачнадзе ", "Абрамов ", "Гаврилов ", "Данеко ", "Зайцев ", "Базикалов ", "Блюм ", "Бектемиров ", "Наумов ", "Аксенкин ", "Прошунин ", "Седов ", "Попов " };
	string name[15] = { "Владимир ", "Евгений ", "Георгий ", "Ярослав ", "Геннадий ", "Александр ", "Людмила ", "Илья ", "Сергей ", "Роман ", "Мария ", "Варвара ", "Анастасия ", "Кирилл ", "Константин " };
	string otchestvo[15] = { "Иванович", "Александрович", "Николаевич", "Анатольевич", "Юрьевич", "Сергеевич", "Владимирович", "Евгениевич",
		"Георгиевич", "Романович", "Ильич", "Константинович", "Артемович", "Дмитриевич", "Михайлович" };
	string PO[4] = { " Травма ", " Пропуск тренеровок ", "-", " Болезнь " };
	string priz_otsut[2] = { "Присутствует", "Отсутствует" };

	for (int i = 0; i<count; i++)
	{
		string fio = second_name[rand() % 14] + name[rand() % 14] + otchestvo[rand() % 14];
		int length = rand() % 51 + 160; //от 160 до 210
		bool agree = rand() % 2;
		bool PZ = 0;
		string prizn_otstr = PO[rand() % 4];
		string _prizn_otsut = priz_otsut[rand() % 2];
		AddToSpList(sportsman(fio, prizn_otstr, length, agree, PZ,0));
	}
	cout << "Спортсмены были добавлены в список!" << endl;
}
void AddRandomTren(void)
{
	int kol_tren = rand() % 6 + 1;
	string treni[5] = { "Разминка", "Броски", "Бег", "Растяжка", "Силовые" };
	
	for (int i = 0; i < kol_tren; i++){
		string _type = treni[rand() % 5];
		Date _date = date_now; //от 0 до 5
		Time _time = Time(19, 20); //от 160 до 210
		Time _durat = Time(1, 30);
		int _ball = rand() % 10;
		string PO[2] = { "Присутствует ", "Отсутствует " };
		string pr_ot = PO[rand() % 2];
		int NS = rand() % 10;
		AddToTrenList( trena(_type, _date, _time, _durat, 0,NS, ""));
	}
	cout << "Тренеровки были добавлены в список!" << endl;
}
void PrintSpList(void)
{
	int count = spList.Count();
	if (!count)
	{
		cout << "Список игроков пуст!" << endl;
		return;
	}
	cout << "ID" << setw(5) << "ФИО " << setw(5) <<
		"Рост " << setw(5) << " Признак временного отстранения " << setw(5) << " Согласие " << setw(5) <<
		" Признак зачисления " << setw(5)<<" Рейтинг "<<setw(5) << " Количество тренеровок " << endl;
	for (int i = 0; i<count; i++)
		cout << spList[i].ToString(false) << setw(5) << spList[i].GetTrenaCount()<<endl;
}

Date vvod_data()
{
	int y1, d1, m1;
	cout << "Год: " << endl; cin >> y1; 
	cout << "Месяц: " << endl; cin >> m1; 
	cout << "День: " << endl; cin >> d1;
	return Date(y1,m1,d1);

}
Time vvod_time()
{
	int h1, m1;
	Time new_tim;
	cout << "Введите время: " << endl;
	cout << "Часы: " << endl; cin >> h1; new_tim.SetHour(h1);
	cout << "Минуты: " << endl; cin >> m1; new_tim.SetMinute(m1);
	return new_tim;
}
sportsman InpSp()
{
	string second_name, name, otchestvo, PO, priz_otsut,fio;
	int length; bool agree, PZ;
	cout << "Ввод спортсмена: " << endl;
	cout << "Фамилию: " << endl; cin >> second_name;
	cout << "Имя: " << endl; cin >> name;
	cout << "Отчество: " << endl; cin >> otchestvo;
	fio = second_name + " " + name + " "+ otchestvo;
	cout << "Признак отстранения: " << endl; cin >> PO;
	cout << "Рост: " << endl; cin >> length;
	cout << "Согласие: " << endl; cin >> agree;
	//cout << "Признак зачисления: " << endl; cin >> PZ;
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
trena InpTren()                         //ввод трены
{
	string _type;
	Date _date;//дата 
	Time _time;//время
	Time _durat;//время
	double _ball;
	string _prizn_otsut;
	int _num_sports;
	cout << "Введите тип тренеровки "; cin >> _type;
	cout << "Ввод дату тренеровки" << endl; _date = vvod_data();
	while (_date.GetYear() < 2000 || !_date._isCorrectDate())
	{
		cout << "Неверная дата" << endl;
		_date = vvod_data();
	};
	cout << "Ввод времени тренеровки " << endl; _time = vvod_time();
	cout << "Ввод длительности тренеровки " << endl; _durat = vvod_time();

	cout << "Ввод балла, на которую оценивает тренер игру спортсмена по ее результатам "; cin >> _ball;
	cout << "Признак отстутсвия "; cin >> _prizn_otsut;
	cout << "Количество спортсменов занятых в данной тренеровку";  cin >> _num_sports;

	return trena(_type, _date, _time, _durat, _ball, _num_sports,_prizn_otsut );
}


void AddSp(void)
{
	cout << "Добавление спортсмена " << endl;
	sportsman sp = InpSp();
	AddToSpList(sp);
	cout << "Cпортсмен успшешно добавлен в список!" << endl;
}
void DelSp(void)
{
	int id;
	cout << "Удаление спортсмена " << endl;
	cout << "Введите ID спортсмена ";
	cin >> id;
	if (DeleteFromSpList(id))
		cout << "Удаление завершилось успешно!" << endl;
	else
		cout << "Спортсмен не был найден" << endl;
	system("pause");
};
void AddTrenToSp(void)
{
	
	int id;
	cout << "Введите индекс спортмена: "; cin >> id; int num = FindSp(id);
	if (spList[num].GetPO()=="-")
	{
		PrintTrensList(false);// вывод
		if (trList.Count() == 0)
		{
			system("pause");
		}
		else
		{
			string trName;
			cout << "Выберите из списка тренировку "; cin >> trName; int tr_num = FindTren(trName); 
			if (trList[tr_num].GetintNumSpInTren() == trList[tr_num].GetintNumSp()){
				
				cout << "Tренировка укомплектованa!!" << endl;
				system("pause");  //если тренеровка укомплектованa
			}
			else{
				int bal;
				string POts;
				cout << "Введите балл: " << endl; cin >> bal; trList[tr_num].SetBall(bal);
				cout << "Введите признак отсутствия: " << endl; cin >> POts; trList[tr_num].SetPOtsut(POts);
				spList[num].SetRate(bal);
				spList[num].AddTrena(trList[tr_num]);
				cout << "Тренировка добавлена" << endl;
				trList[tr_num].SetintNumSpInTren();
			}
		}
	}
	else
	{
		cout << "Тренировка не добавлена, по причине: " << spList[num].GetPO() << endl;
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
		cout << "Текущая дата: " << date_now.ToString() << endl;
		cout << "Список тренеровок " << endl;
		PrintTrensList(true);
		cout << endl;
		cout << "Выберите нужный вам пункт меню" << endl;
		cout << "1 - Добавить тренеровку." << endl;
		cout << "2 - Удалить тренеровку." << endl;
		cout << "3 - Редактировать тренеровку." << endl;
		/*cout << "4 - Отсортировать тренеровки." << endl;*/
		cout << "4 - Добавить случайные тренеровки" << endl;
		cout << "0 - Выйти." << endl;
		cout << "Ваш выбор: ";
		do
		{	// ввод номера интересующего пункта меню
			cin.clear();
			cin.sync();
			cin >> select;
		} while (select<0 || select >= 8 || cin.fail());
		cout << endl;
		// Functions – массив указателей на функции меню,
		// select – индекс элемента массива, ссылающего на 
		// функцию, реализующую выбранный пункта меню
		(Functions[select])(); // вызов функции через указатель 
	} while (true);
};

void PrintTrensList(bool proove)
{
	int count = trList.Count();
	if (!count)
	{
		cout << "Список тренеровок  пуст!" << endl;
		return;
	}
	cout << setw(7) << "Тип" << setw(7) << "Дата" << setw(13) << "Время" << setw(13)
		<< "Продолжительность" << setw(13)
		<< "Количество спортсменов" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << trList[i].ToString(false) << endl;
	}
}
void AddTren(void){
	cout << "Добавление тренеровки " << endl;
	trena tr = InpTren();
	AddToTrenList(tr);
	cout << "Тренеровка успшешно добавлена в список!" << endl;
}
void DelTren(void)
{
	string typ;
	cout << "Удаление тренеровки " << endl;
	cout << "Введите название тренеровки ";
	cin >> typ;
	if (DeleteFromTrList(typ))
		cout << "Удаление завершилось успешно!" << endl;
	else
		cout << "Тренеровка не была найдена" << endl;
	system("pause");
}
void ChangeTren(void)
{

}
void transfer()
{
	int min_len,co_tr,kol_vak,count=0; Time stT, enT; double sr_rate;
	cout << "Перевод спортсменов в профессиональную группу" << endl;
	cout << "Введите количество вакансий в профессиональной группе: " << endl; cin >> kol_vak;
	cout << "Введите критерии спортсменов для перевода:" << endl;
	cout << "Минимальный рост: "; cin >> min_len;
	//cout << "\nПериод: "; stT = vvod_time(); enT = vvod_time();
	cout << "\nМинимальный средний рейтинг за это период: "; cin >> sr_rate;
	cout << "\nКоличество пропущенных тренеровок: "; cin >> co_tr;
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

void bubl_rate()				//сортировка пузырьком
{
	Noob sp1, sp2;
	for (int i=0; i < spList.Count(); i++) // i - номер прохода
	{
		for (int j = i + 1; j < spList.Count(); j++) // внутренний цикл прохода
		{
			
			
			if (InpNsp(spList[i]).GetRate() < InpNsp(spList[j]).GetRate())
			{
				spList.swapS(spList._getElement(i), spList._getElement(j));   //обмен элементов
				swap(InpNsp(spList[i]), InpNsp(spList[j]));
			}
			/*if (InpNsp(spList[i]).GetRate() == InpNsp(spList[j]).GetRate())
			{
				if (InpNsp(spList[i]).GetLe() < InpNsp(spList[j]).GetLe())
				{
					spList.swapS(spList._getElement(i), spList._getElement(j));   //обмен элементов
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
			trList.Delete(i); cout << "Тренеровка удалена\n";
		}
	}*/
	cout << "Введите новую дату" << endl;
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
	cout << "Введите индекс спортмена: "; cin >> id; int num = FindSp(id); 
	
	do
	{
		cout << spList[num].ToString(true) << endl;
		cout << "Выберите что вы хотите изменить:" << endl;
		cout << "1 - Рост." << endl;
		cout << "2 - Признак отстранения." << endl;
		cout << "3 - Согласие." << endl;
		cout << "4 - Выход в меню." << endl;

		do
		{	
			cin >> select;
		} while (select<0 || select > 4);
		cout << endl;
		switch (select)
		{
		case 1:
			int rost;
			cout << "Введите рост" << endl;
			cin >> rost;
			spList[num].SetLe(rost);
			break;
		case 2:
			cout << "Введите признак отстранения" << endl;
			cout << "'-' - не отстранен" << endl;
			cin >> priz_ot;
			spList[num].SetPO(priz_ot);
			break;
		case 3:
			int Ag;
			cout << "Введите согласие" << endl;
			cout << "1 - Согласен." << endl;
			cout << "0 - Не согласен." << endl;
			cin >> Ag;
			while ((Ag > 1) || (Ag < 0)){ cout << "Введите 1 или 0" << endl; cin >> Ag; }
				
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
	cout << "ID" << setw(5) << "ФИО " << setw(5) <<
		"Рост " << setw(5) << " Признак временного отстранения " << setw(5) << " Согласие " << setw(5) <<
		" Признак зачисления " << setw(5) << " Рейтинг " << setw(5) << " Количество тренеровок " << endl;
	for (int i = 0; i < spList.Count(); i++){
		if (spList[i].GetPZ())
		{
			cout << spList[i].ToString(false) << setw(5) << spList[i].GetTrenaCount() << endl;
			help = true;
		}
		
	}
	
	if (!help)cout << "Список пуст!!!" << endl;
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
	docXML->Load("C:\\Users\\Андрей\\Desktop\\ms.xml");
	int i = 0;
	string fio, priz_ots;
	int id, rate, length;
	bool agree, priz_zach;
	string ShowName;
	Date ShowDate;
	Time ShowTime,ShowPr;
	for each (XmlNode^ n in docXML->SelectNodes("/head/Спортсмен"))
	{
		if (n->Attributes["ID"])
		{
			id = Convert::ToInt32(n->Attributes["ID"]->Value);
		}
		if (n->Attributes["ФИО"])
		{
			fio = msclr::interop::marshal_as<string>(n->Attributes["ФИО"]->Value);
		}
		if (n->Attributes["Рост"])
		{
			length =  Convert::ToInt32(n->Attributes["Рост"]->Value);
		}
		if (n->Attributes["Признак_временного_отстранения"])
		{
			priz_ots = msclr::interop::marshal_as<string>(n->Attributes["Признак_временного_отстранения"]->Value);
		}
		if (n->Attributes["Согласие"])
		{
			agree = Convert::ToInt32(n->Attributes["Согласие"]->Value);
		}
		if (n->Attributes["Признак_зачисления"])
		{
			priz_zach = Convert::ToInt32(n->Attributes["Признак_зачисления"]->Value);
		}
		if (n->Attributes["Рейтинг"])
		{
			rate = Convert::ToInt32(n->Attributes["Рейтинг"]->Value);
		}
		for each (XmlNode^ a in n->SelectNodes("Тренеровка"))
		{
			if (a->Attributes["Тип"])
			{
				ShowName = msclr::interop::marshal_as<std::string>(a->Attributes["Тип"]->Value);
			}
			if (a->Attributes["Дата"])
			{
				ShowDate = convertToDate(msclr::interop::marshal_as<string>(a->Attributes["Дата"]->Value));
			}
			if (a->Attributes["Время"])
			{
				ShowTime = convertToTime(msclr::interop::marshal_as<std::string>(a->Attributes["Время"]->Value));
			}
			if (a->Attributes["Продолжительность"])
			{
				ShowPr = convertToTime(msclr::interop::marshal_as<std::string>(a->Attributes["Продолжительность"]->Value));
			}
			/*if (a->Attributes["Выставленная_оценка"])
			{
				ShowName = msclr::interop::marshal_as<std::int>(a->Attributes["Выставленная_оценка"]->Value);
			}*/
		}
		AddToSpList(sportsman(fio, priz_ots, length, agree, priz_zach,rate));
		//AddToBannerList(Banner(name, firm, startDate, endDate, min, max, act));
		//BannerList[i].AddShow(Show(ShowName, ShowDate, ShowTime));
		i++;
	}

}
void XMLout(void){
	XmlTextWriter^ textWritter = gcnew XmlTextWriter("C:\\Users\\Андрей\\Desktop\\ms.xml", System::Text::Encoding::UTF8);
	textWritter->WriteStartDocument();
	//Создём голову(head) :
	textWritter->WriteStartElement("head");
	//Закрываем её :
	textWritter->WriteEndElement();
	//И закрываем наш XmlTextWriter :
	textWritter->Close();

	//Для занесения данных мы будем использовать класс XmlDocument 
	XmlDocument^ document = gcnew XmlDocument();
	//Загружаем наш файл :
	document->Load("C:\\Users\\Андрей\\Desktop\\ms.xml");
	//Создаём XML - запись:
	for (int i = 0; i < spList.Count(); i++)
	{
		XmlElement^ elementVed = document->CreateElement("Спортсмен");
		document->DocumentElement->AppendChild(elementVed); // указываем родителя

		XmlAttribute^ attribute = document->CreateAttribute("ID"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetId()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute); // добавляем атрибут

		attribute = document->CreateAttribute("ФИО"); // создаём атрибут
		attribute->Value = gcnew String(spList[i].Getfio().c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute); // добавляем атрибут

		attribute = document->CreateAttribute("Рост"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetLe()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute); // добавляем атрибут

		attribute = document->CreateAttribute("Признак_временного_отстранения"); // создаём атрибут
		attribute->Value = gcnew String(spList[i].GetPO().c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("Согласие"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetAg()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("Признак_зачисления"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetPZ()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("Рейтинг"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetRate()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute);

		attribute = document->CreateAttribute("Количество_тренеровок"); // создаём атрибут
		attribute->Value = gcnew String(to_string(spList[i].GetTrenaCount()).c_str()); // устанавливаем значение атрибута
		elementVed->Attributes->Append(attribute);
		for (int j = 0; j < spList[i].GetTrenaCount(); j++)
		{
			XmlNode^ subElementStud = document->CreateElement("Тренеровка");
			elementVed->AppendChild(subElementStud);

			XmlAttribute^ attributeStud = document->CreateAttribute("Тип");
			attributeStud->Value = gcnew System::String(trList[i].GetType().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("Дата");
			attributeStud->Value = gcnew System::String(trList[i].GetDate().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("Время");
			attributeStud->Value = gcnew System::String(trList[i].GetTime().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			attributeStud = document->CreateAttribute("Продолжительность");
			attributeStud->Value = gcnew System::String(trList[i].GetDurat().ToString().c_str());
			subElementStud->Attributes->Append(attributeStud);

			/*attributeStud = document->CreateAttribute("Выставленная_оценка");
			attributeStud->Value = gcnew System::String(trList[i].GetBall().ToString());
			subElementStud->Attributes->Append(attributeStud);*/

		}

	}
	document->Save("C:\\Users\\Андрей\\Desktop\\ms.xml");
	
}
