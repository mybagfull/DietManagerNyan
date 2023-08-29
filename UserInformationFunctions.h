#pragma once
#include "UserInformation.h"
#include "ActionsClass.h"

#include <Windows.h>
#include <iostream>

using namespace std;
using namespace DietManager;
using namespace::System::Data::OleDb;

bool isClickedSexButton = false;

	//Нажатие на кнопку Подтвердить
	System::Void DietManager::UserInformation::informationConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isClickedSexButton) {
			AddAction AddRec1(textBox1->Text->ToString(), textBox2->Text->ToString(), textBox3->Text->ToString(),
				textBox5->Text->ToString(), textBox4->Text->ToString(), textBox6->Text->ToString(), gender);
			AddRec1.AddRecord();
		}
		MainWindow^ registr = gcnew MainWindow();// создаем новый экземпляр
		registr->Show();// открыть регистрацию
		UserInformation::Hide();// скрыть элемент управления
	}

	//Нажатие на кнопку выбора пола Мужской
	System::Void DietManager::UserInformation::sexManButton_Click(System::Object^ sender, System::EventArgs^ e) {
		gender = 0;
		isClickedSexButton = true; // Для проверки нажатия
	}
	//Нажатие на кнопку выбора пола Женский
	System::Void DietManager::UserInformation::sexWomanButton_Click(System::Object^ sender, System::EventArgs^ e) {
		gender = 1; // Флаг определения пола = woman
		isClickedSexButton = true;
	}
