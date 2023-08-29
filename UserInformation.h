#pragma once
#include "MainWindow.h"
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include "stdlib.h"
#include <cstring>
namespace DietManager {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace msclr::interop;
	using namespace std;
	public ref class UserInformation : public System::Windows::Forms::Form {
	public:
		UserInformation(void) {
			InitializeComponent();
		}
	private:
		bool gender = false; // Man - 0 Woman - 1
		bool isClickedSexButton = false;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	protected:
		~UserInformation() {
			if (components) {
				delete components;
			}
		}
		MainWindow^ persona;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ sexManButton;
	private: System::Windows::Forms::Button^ sexWomanButton;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ informationConfirmButton;
	private:
		System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInformation::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->sexManButton = (gcnew System::Windows::Forms::Button());
			this->sexWomanButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->informationConfirmButton = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label1->Location = System::Drawing::Point(96, 151);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Имя*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label2->Location = System::Drawing::Point(30, 211);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Фамилия*";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox1->Location = System::Drawing::Point(191, 151);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(292, 28);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox2->Location = System::Drawing::Point(191, 211);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(292, 28);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox3->Location = System::Drawing::Point(191, 275);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(292, 28);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label3->Location = System::Drawing::Point(37, 267);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 37);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Возраст*";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox4->Location = System::Drawing::Point(191, 409);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->PasswordChar = '*';
			this->textBox4->Size = System::Drawing::Size(292, 28);
			this->textBox4->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label4->Location = System::Drawing::Point(101, 409);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 37);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Вес*";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox5->Location = System::Drawing::Point(191, 345);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(292, 28);
			this->textBox5->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label5->Location = System::Drawing::Point(88, 336);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 37);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Рост*";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->textBox6->Location = System::Drawing::Point(336, 464);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(147, 28);
			this->textBox6->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label6->Location = System::Drawing::Point(88, 464);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(232, 37);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Идеальный вес";
			// 
			// sexManButton
			// 
			this->sexManButton->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->sexManButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->sexManButton->Location = System::Drawing::Point(191, 97);
			this->sexManButton->Margin = System::Windows::Forms::Padding(2);
			this->sexManButton->Name = L"sexManButton";
			this->sexManButton->Size = System::Drawing::Size(141, 41);
			this->sexManButton->TabIndex = 12;
			this->sexManButton->Text = L"М";
			this->sexManButton->UseVisualStyleBackColor = false;
			this->sexManButton->Click += gcnew System::EventHandler(this, &UserInformation::sexManButton_Click);
			// 
			// sexWomanButton
			// 
			this->sexWomanButton->BackColor = System::Drawing::Color::Pink;
			this->sexWomanButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->sexWomanButton->Location = System::Drawing::Point(336, 97);
			this->sexWomanButton->Margin = System::Windows::Forms::Padding(2);
			this->sexWomanButton->Name = L"sexWomanButton";
			this->sexWomanButton->Size = System::Drawing::Size(147, 41);
			this->sexWomanButton->TabIndex = 13;
			this->sexWomanButton->Text = L"Ж";
			this->sexWomanButton->UseVisualStyleBackColor = false;
			this->sexWomanButton->Click += gcnew System::EventHandler(this, &UserInformation::sexWomanButton_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			this->label7->Location = System::Drawing::Point(135, 534);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 22);
			this->label7->TabIndex = 14;
			// 
			// informationConfirmButton
			// 
			this->informationConfirmButton->BackColor = System::Drawing::Color::Honeydew;
			this->informationConfirmButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->informationConfirmButton->Location = System::Drawing::Point(191, 543);
			this->informationConfirmButton->Margin = System::Windows::Forms::Padding(2);
			this->informationConfirmButton->Name = L"informationConfirmButton";
			this->informationConfirmButton->Size = System::Drawing::Size(292, 69);
			this->informationConfirmButton->TabIndex = 15;
			this->informationConfirmButton->Text = L"Подтвердить";
			this->informationConfirmButton->UseVisualStyleBackColor = false;
			this->informationConfirmButton->Click += gcnew System::EventHandler(this, &UserInformation::informationConfirmButton_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic));
			this->label8->Location = System::Drawing::Point(101, 97);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(85, 37);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Пол*";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(187, 57);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(296, 20);
			this->label9->TabIndex = 20;
			this->label9->Text = L"* - поле обязательно для заполнения";
			// 
			// UserInformation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(571, 647);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->informationConfirmButton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->sexWomanButton);
			this->Controls->Add(this->sexManButton);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"UserInformation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Менеджер диеты";
			this->Load += gcnew System::EventHandler(this, &UserInformation::UserInformation_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Нажатие на кнопку Подтвердить
	private: System::Void informationConfirmButton_Click(System::Object^ sender, System::EventArgs^ e);
		  //Нажатие на кнопку выбора пола Мужской
	private: System::Void sexManButton_Click(System::Object^ sender, System::EventArgs^ e);
		   //Нажатие на кнопку выбора пола Женский
	private: System::Void sexWomanButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void UserInformation_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}



