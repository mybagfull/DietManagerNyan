#pragma once
#include <Windows.h>
#include <iostream>
#include "Registration.h"
#include <string> 
#include <sstream>
using namespace std;
using namespace DietManager;
using namespace::System::Data::OleDb;


void insertCalories(int kal);
int fromStringToInt(std::string str);

String^ ConvertToSystem(string str) { return gcnew String(str.data()); } //�� stl � system string



	template <typename T>
	std::string toString(T val)
	{
	std::ostringstream oss;
	oss << val;
	return oss.str();
	}

//������� ��� ����������� ������ � ����� �����
int fromStringToInt(string str) {
	int number = 0;
	int lenght = str.length();
	int k = 1;
	for (int i = 0; i < lenght - 1; i++) {
		k *= 10;
	}
	//������� ���������� ������� �������
	for (int i = 0; str[i] != 0; i++) {
		number += (str[i] - '0') * k;
		k /= 10;
	}
	return number;
}
//���������� ����� ��������/���� � �������
void insertCalories(int kal) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=kkal.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "SELECT * FROM [�������1]";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
	String^ query1 = "INSERT INTO [�������1] (�������,login)VALUES ('" + kal + "', '" + ConvertToSystem(global_login) + "')";
	OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);
	try
	{
		dbCommand1->ExecuteNonQuery();
	}
	catch (InvalidOperationException^)
	{
		MessageBox::Show("������ ���������� �������!");
		dbReader->Close();
		dbConnection->Close();
		return;
	}
	dbReader->Close();
	dbConnection->Close();
}
