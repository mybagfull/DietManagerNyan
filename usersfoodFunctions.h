#pragma once
#include "usersfood.h"
#include "ActionsClass.h"

#include <Windows.h>
#include <iostream>

using namespace std;
using namespace DietManager;
using namespace::System::Data::OleDb;

System::Void DietManager::usersfood::FindButton_Click(System::Object^ sender, System::EventArgs^ e) {
	FindFood search(textBox1->Text->ToString()); //создаём объект поиска
	search.findFood(); //ищем по таблице
}

System::Void DietManager::usersfood::AddFoodButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int fl = Ufl; // определяет приём пищи
	AddFood toAdd(textBox1->Text->ToString(), textBox2->Text->ToString(), fl);
	toAdd.addFood();
}

