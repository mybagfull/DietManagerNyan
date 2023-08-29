#pragma once
#include <Windows.h>
#include <iostream>
#include "product.h"

using namespace std;
using namespace DietManager;
using namespace::System::Data::OleDb;


System::Void DietManager::product::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	productName = textBox1->Text;
	kkal = textBox2->Text;
	int fl = 0;
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=product.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "SELECT * FROM [Таблица1]";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
	if (productName == "" || kkal == "") {
		fl = 1;
		MessageBox::Show("Не все поля заполнены, проверьте форму!", "Ошибка!", MessageBoxButtons::OK);
		dbReader->Close();
		dbConnection->Close();
	}
	else {
		while (dbReader->Read()) {
			if ((String^)dbReader["Продукт"] != "")  product_check = (String^)dbReader["Продукт"];
			if (DBNull::Value != dbReader["Продукт"])product_check = (String^)dbReader["Продукт"];
			if (product_check == productName) {
				MessageBox::Show("Продукт " + productName + " уже есть в базе!", "", MessageBoxButtons::OK);
				fl = 1;
				dbReader->Close();
				dbConnection->Close();
				break;
			}
		}
	}
	//Добавление нового продукта:
	if (fl == 0) {
		String^ query1 = "INSERT INTO [Таблица1] (Продукт,калорийность )VALUES ('" + productName + "' , '" + kkal + "')";
		OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);
		dbCommand1->ExecuteNonQuery();
		MessageBox::Show("Новый продукт " + productName + " добавлен!", "", MessageBoxButtons::OK);
		dbReader->Close();
		dbConnection->Close();
		this->Close();
	}
}