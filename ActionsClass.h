#pragma once
#include <Windows.h>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include "stdlib.h"
#include <cstring>

#include "GlobalFunctions.h"
#include "container.h"
#include "session.h"

using namespace DietManager;
using namespace System::Data::OleDb;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Runtime::InteropServices;
using namespace std;


class Food
{
protected:
	string food;
	string kkal;
	string food_check;
public:
	String^ ConvertToSystem(string str) { return gcnew String(str.data()); } //из stl в system string
};

class AddFood : public Food
{
protected:
	string gram;
	string login;
	int fl;
public:
	AddFood(String^ food, String^ gram, int fl);
	void AddFood::addFood();
	int kkalProduct(int lenght);
};

int AddFood::kkalProduct(int h) {
	string kkal1 = kkal;
	string gram1 = gram;
	int kkal2 = 0, gram2 = 0;
	int k = 1;
	for (int i = 0; i < h - 1; i++) {
		k *= 10;
	}
	for (int i = 0; kkal1[i] != 0; i++) {
		kkal2 += (kkal1[i] - '0') * k;
		k /= 10;
	}
	h = gram1.length();
	k = 1;
	for (int i = 0; i < h - 1; i++) {
		k *= 10;
	}
	for (int i = 0; gram1[i] != 0; i++) {
		gram2 += (gram1[i] - '0') * k;
		k /= 10;
	}
	return (gram2 * kkal2 / 100);
}

AddFood::AddFood(String^ food, String^ gram, int fl)
{
	this->fl = fl;
	this->food = msclr::interop::marshal_as<std::string>(food);
	this->gram = msclr::interop::marshal_as<std::string>(gram);
	string login = global_login;
}


void AddFood::addFood()
{
	bool added = false;
	bool check = false;
	int fl1 = 0, gram2 = 0;
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=product.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();//открываем соединение
	String^ query = "SELECT * FROM [Таблица1]";// запрос
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);//команда
	OleDbDataReader^ dbReader1 = dbCommand->ExecuteReader();// считываем данные
	while (dbReader1->Read()) {
		food_check = msclr::interop::marshal_as<std::string>((String^)dbReader1["Продукт"]);
		if (DBNull::Value != dbReader1["Продукт"]) {
			if (food_check == food) {
				check = true;
				MessageBox::Show(" " + ConvertToSystem(food) + " есть в базе!", "", MessageBoxButtons::OK);
				kkal = msclr::interop::marshal_as<std::string>((String^)dbReader1["калорийность"]);
				string kkal1 = kkal;
				int kkal3 = kkalProduct(kkal1.length());
				MessageBox::Show("Калорийность данного продукта = " + ConvertToSystem(kkal) + "", "", MessageBoxButtons::OK);
				dbReader1->Close();
				dbConnection->Close();
				added = true;
				break;
			}
		}
	}
	if (added == true) {
		connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=user_food.mdb";
		dbConnection = gcnew OleDbConnection(connectionString);
		dbConnection->Open();
		query = "SELECT * FROM [Таблица1]";
		dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		string kkal1 = kkal;
		int kkal3 = kkalProduct(kkal1.length());
		query = "INSERT INTO [Таблица1] (id,product,kkal,login )VALUES ('" + fl + "' , '" + ConvertToSystem(food) + "','" + kkal3 + "','" + ConvertToSystem(global_login) + "')";
		dbCommand = gcnew OleDbCommand(query, dbConnection);
		try
		{
			dbCommand->ExecuteNonQuery();
		}
		catch (InvalidOperationException^)
		{
			MessageBox::Show("Ошибка выполнения запроса!");
			dbConnection->Close();
			return;
		}
		MessageBox::Show("продукт" + ConvertToSystem(food) + "", "добавлен в сегодняшний рацион", MessageBoxButtons::OK);
		dbReader->Close();
		dbConnection->Close();
	}
	if (check == false) {
		MessageBox::Show("Извините, данного продукта пока нет в базе данных, если вы точно знаете калорийность, то можете его добавить сами", "Cообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		dbReader1->Close();// закрываем соединение
		dbConnection->Close();
	}
}

class FindFood : public Food
{
public:
	FindFood(String^ food);
	void FindFood::findFood();
};

FindFood::FindFood(String^ food)
{
	this->food = msclr::interop::marshal_as<std::string>(food);
}

void FindFood::findFood() 
{
	bool check = false;
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=product.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();//открываем соединение
	String^ query = "SELECT * FROM [Таблица1]";// запрос
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);//команда
	OleDbDataReader^ dbReader1 = dbCommand->ExecuteReader();// считываем данные
	while (dbReader1->Read()) {
		food_check = msclr::interop::marshal_as<std::string>(((String^)dbReader1["Продукт"]));
		if (DBNull::Value != dbReader1["Продукт"]) {
			if (food_check == food) {
				MessageBox::Show(" " + ConvertToSystem(food) + " есть в базе!", "", MessageBoxButtons::OK);
				kkal = msclr::interop::marshal_as<std::string>((String^)dbReader1["калорийность"]);
				MessageBox::Show("Калорийность данного продукта = " + ConvertToSystem(kkal) + "", "", MessageBoxButtons::OK);
				check = true;
				dbReader1->Close();// закрываем соединение
				dbConnection->Close();
				break;
			}
		}
	}

	if (check == false) {
		MessageBox::Show("Извините, данного продукта пока нет в базе данных, если вы точно знаете калорийность, то можете его добавить сами", "Cообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		dbReader1->Close();// закрываем соединение
		dbConnection->Close();
	}
}





//класс действий c информацией о пользователе
class BaseAction
{
protected:
	list<record> Records;
	record* Rec = new record;
	int age = 0, height = 0, weight = 0, end_weight = 0;
	bool gender;
public:
	String^ ConvertToSystem(string str) { return gcnew String(str.data()); } //из stl в system string
	void sexSelectionHandler(int end_weight, int weight, int height, int age, bool gender);
	int autoEndWeightCalculate(bool gender, int height, int age);
	~BaseAction() { delete Rec; }
};


//Расчет идеального веса по формуле Шульгиной
int BaseAction::autoEndWeightCalculate(bool gender, int height, int age) { 
	if (!gender) { return (50 + (height - 150) * 0.75 + (age - 21) / 4); } //for man
	else { return (50 + (height - 150) * 0.32 + (age - 21) / 5); } //for woman
}

//Вычисляем кол-во калорий для поддержания текущего веса
void BaseAction::sexSelectionHandler(int end_weight, int weight, int height, int age, bool gender) {
	float physicalActivityCoefficient = (12 / 10);
	//если начальный и конечный вес примерно равны и нужно поддерживать вес
	float upDownWeight = (11/10); 
	int sexFactor = 5; //По умолчанию для мужчин
	if (gender) sexFactor = -181;
	if (end_weight - 2 >= weight) upDownWeight = (12 / 10);
	if (end_weight + 2 <= weight) upDownWeight = (10 / 10);
	// BMR РАССЧЁТ КАЛОРИЙ В ДЕНЬ
	int kal = (9.99 * weight + 6.25 * height - 4.92 * age + sexFactor)*upDownWeight; 
	//TEE кол-во калорий для поддержания/увеличения/уменьшения текущего веса
	kal *= physicalActivityCoefficient; 
	insertCalories(kal);
}


//добавить запись в файл
class AddAction : public BaseAction
{
protected:
	//string login;
public:
	AddAction(String^ name, String^ name2, String^ age, String^ height, String^ weight, String^ end_weight, bool gender);
	//bool CheckIfRepeating(); //проверим, не существует ли уже такой записи
	bool AddAction::infoChek();
	void AddAction::AddRecord(); //добавим новую запись в файл
};

bool AddAction::infoChek() {
	bool est = false;
	int i = 0;
	if (((Rec->ageRec[i] >= 'A') && (Rec->ageRec[i] <= 'Z'))
		|| ((Rec->ageRec[i] >= 'a') && (Rec->ageRec[i] <= 'z') || Rec->ageRec == "") || ((Rec->heightRec[i] >= 'A') && (Rec->heightRec[i] <= 'Z'))
		|| ((Rec->heightRec[i] >= 'a') && (Rec->heightRec[i] <= 'z') || Rec->heightRec == "") || ((Rec->weightRec[i] >= 'A') && (Rec->weightRec[i] <= 'Z'))
		|| ((Rec->weightRec[i] >= 'a') && (Rec->weightRec[i] <= 'z') || Rec->weightRec == "") || ((Rec->end_weightRec[i] >= 'A') && (Rec->end_weightRec[i] <= 'Z'))
		|| ((Rec->end_weightRec[i] >= 'a') && (Rec->end_weightRec[i] <= 'z')))
	{
		est = true;
	}

	if (est == false) {
		age = fromStringToInt(Rec->ageRec);
		height = fromStringToInt(Rec->heightRec);
		weight = fromStringToInt(Rec->weightRec);
		if (Rec->end_weightRec == "") {
			end_weight = autoEndWeightCalculate(gender, height, age);
			Rec->end_weightRec = toString(end_weight);
		}
		else end_weight = fromStringToInt(Rec->end_weightRec);
	}
	return est;
}

//Добавляем записи в БД information
void AddAction::AddRecord()
{
	bool est = infoChek();
	if (age > 16 && height >= 130 && weight > 29 && end_weight > 29) {
		String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=information.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
		dbConnection->Open();
		String^ query = "SELECT * FROM [information]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		if (Rec->nameRec == "" || Rec->name2Rec == "" || est == true) {
			MessageBox::Show("Не все поля заполнены или заполнены некорректно, проверьте форму!", "Ошибка!", MessageBoxButtons::OK);
			dbReader->Close();
			dbConnection->Close();
		}
		else {
			while (dbReader->Read()) {
				// Проверка: можно ли записать в поле таблицы
				if (DBNull::Value != dbReader["name"]) {
					break;
				}
			}
			string genderString;
			if (!gender) { genderString = "М"; }
			else { genderString = "Ж"; }
			String^ query1 = "INSERT INTO [information] (name,name2, age,height,weight,end_weight,gender, login)VALUES ('" + ConvertToSystem(Rec->nameRec) + "' , '" + ConvertToSystem(Rec->name2Rec) + "', '" + ConvertToSystem(Rec->ageRec) + "', '" + ConvertToSystem(Rec->heightRec) + "', '" + ConvertToSystem(Rec->weightRec) + "', '" + ConvertToSystem(Rec->end_weightRec) + "', '" + ConvertToSystem(genderString) + "', '" + ConvertToSystem(global_login) + "')";
			OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);
			try
			{
				dbCommand1->ExecuteNonQuery();
			}
			catch (InvalidOperationException^)
			{
				MessageBox::Show("Ошибка выполнения запроса!");
				dbConnection->Close();
				return;
			}
			dbReader->Close();
			dbConnection->Close();
			sexSelectionHandler(end_weight, weight, height, age, gender); //Расчёт нормы потребления калорий в день
		}
	}
	else
		MessageBox::Show("Ваши данные неправильны! Проверьте их!", "Ошибка!", MessageBoxButtons::OK);
}

//Конструктор с параметрами
AddAction::AddAction(String^ name, String^ name2, String^ age, String^ height, String^ weight, String^ end_weight, bool gender)
{
	this->gender = gender;
	Rec->nameRec = msclr::interop::marshal_as<std::string>(name);
	Rec->name2Rec = msclr::interop::marshal_as<std::string>(name2);
	Rec->ageRec = msclr::interop::marshal_as<std::string>(age);
	Rec->heightRec = msclr::interop::marshal_as<std::string>(height);
	Rec->weightRec = msclr::interop::marshal_as<std::string>(weight);
	if (end_weight != "")Rec->end_weightRec = msclr::interop::marshal_as<std::string>(end_weight);
	else Rec->end_weightRec = "";
}