#pragma once
#include <msclr\marshal_cppstd.h>
#include "string.h"
#include <cstring>
#include "regex"
#include <string> 
#include "iostream"
#include "stdlib.h"


//#include "GlobalFunctions.h"
#include "settings.h"
#include "product.h"
#include "usersfood.h"

namespace DietManager {
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace msclr::interop;
	using namespace std;

	public ref class MainWindow : public System::Windows::Forms::Form {
	public:
		MainWindow(void) {
			InitializeComponent();
		}
		int Ufl;
		static String^ Ulogin;
		static int Ukkal;
	private: System::Windows::Forms::Button^ updateButton;
	public:
	private: System::Windows::Forms::Label^ kkalPerDay;
	public:
	public:

	protected:
		~MainWindow() {
			if (components) {
				delete components;
				delete Ulogin;
			}
		}
		usersfood^ user;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ profileButton;


	private: System::Windows::Forms::Button^ breakfastButton;
	private: System::Windows::Forms::Button^ lunchButton;
	private: System::Windows::Forms::Button^ dinnerButton;






	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ kkalEated;



	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->profileButton = (gcnew System::Windows::Forms::Button());
			   this->breakfastButton = (gcnew System::Windows::Forms::Button());
			   this->lunchButton = (gcnew System::Windows::Forms::Button());
			   this->dinnerButton = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->kkalEated = (gcnew System::Windows::Forms::Label());
			   this->kkalPerDay = (gcnew System::Windows::Forms::Label());
			   this->updateButton = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::SpringGreen;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->label1->Location = System::Drawing::Point(37, 31);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(312, 33);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"потреблено калорий:";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::SpringGreen;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->label2->Location = System::Drawing::Point(644, 31);
			   this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(233, 33);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"число кал/день:";
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::Azure;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->button2->Location = System::Drawing::Point(786, 254);
			   this->button2->Margin = System::Windows::Forms::Padding(2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(265, 43);
			   this->button2->TabIndex = 10;
			   this->button2->Text = L"Новый продукт";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &MainWindow::to_product);
			   // 
			   // profileButton
			   // 
			   this->profileButton->BackColor = System::Drawing::Color::Lavender;
			   this->profileButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->profileButton->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->profileButton->Location = System::Drawing::Point(786, 181);
			   this->profileButton->Margin = System::Windows::Forms::Padding(2);
			   this->profileButton->Name = L"profileButton";
			   this->profileButton->Size = System::Drawing::Size(265, 48);
			   this->profileButton->TabIndex = 9;
			   this->profileButton->Text = L"Профиль пользователя";
			   this->profileButton->UseVisualStyleBackColor = false;
			   this->profileButton->Click += gcnew System::EventHandler(this, &MainWindow::profileButton_Click);
			   // 
			   // breakfastButton
			   // 
			   this->breakfastButton->BackColor = System::Drawing::Color::LemonChiffon;
			   this->breakfastButton->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->breakfastButton->Location = System::Drawing::Point(363, 119);
			   this->breakfastButton->Margin = System::Windows::Forms::Padding(2);
			   this->breakfastButton->Name = L"breakfastButton";
			   this->breakfastButton->Size = System::Drawing::Size(363, 84);
			   this->breakfastButton->TabIndex = 12;
			   this->breakfastButton->Text = L"Завтрак";
			   this->breakfastButton->UseVisualStyleBackColor = false;
			   this->breakfastButton->Click += gcnew System::EventHandler(this, &MainWindow::breakfastButton_Click);
			   // 
			   // lunchButton
			   // 
			   this->lunchButton->BackColor = System::Drawing::Color::SeaShell;
			   this->lunchButton->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->lunchButton->Location = System::Drawing::Point(363, 229);
			   this->lunchButton->Margin = System::Windows::Forms::Padding(2);
			   this->lunchButton->Name = L"lunchButton";
			   this->lunchButton->Size = System::Drawing::Size(363, 92);
			   this->lunchButton->TabIndex = 13;
			   this->lunchButton->Text = L"Обед";
			   this->lunchButton->UseVisualStyleBackColor = false;
			   this->lunchButton->Click += gcnew System::EventHandler(this, &MainWindow::lunchButton_Click);
			   // 
			   // dinnerButton
			   // 
			   this->dinnerButton->BackColor = System::Drawing::Color::Gray;
			   this->dinnerButton->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->dinnerButton->Location = System::Drawing::Point(363, 349);
			   this->dinnerButton->Margin = System::Windows::Forms::Padding(2);
			   this->dinnerButton->Name = L"dinnerButton";
			   this->dinnerButton->Size = System::Drawing::Size(363, 85);
			   this->dinnerButton->TabIndex = 14;
			   this->dinnerButton->Text = L"Ужин";
			   this->dinnerButton->UseVisualStyleBackColor = false;
			   this->dinnerButton->Click += gcnew System::EventHandler(this, &MainWindow::dinnerButton_Click);
			   // 
			   // button8
			   // 
			   this->button8->BackColor = System::Drawing::Color::Transparent;
			   this->button8->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->button8->Location = System::Drawing::Point(814, 465);
			   this->button8->Margin = System::Windows::Forms::Padding(2);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(212, 43);
			   this->button8->TabIndex = 18;
			   this->button8->Text = L"выход";
			   this->button8->UseVisualStyleBackColor = false;
			   this->button8->Click += gcnew System::EventHandler(this, &MainWindow::exit);
			   // 
			   // kkalEated
			   // 
			   this->kkalEated->AutoSize = true;
			   this->kkalEated->BackColor = System::Drawing::Color::Aquamarine;
			   this->kkalEated->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->kkalEated->Location = System::Drawing::Point(341, 31);
			   this->kkalEated->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->kkalEated->Name = L"kkalEated";
			   this->kkalEated->Size = System::Drawing::Size(32, 33);
			   this->kkalEated->TabIndex = 20;
			   this->kkalEated->Text = L"0";
			   this->kkalEated->Click += gcnew System::EventHandler(this, &MainWindow::kkalEated_Click);
			   // 
			   // kkalPerDay
			   // 
			   this->kkalPerDay->AutoSize = true;
			   this->kkalPerDay->BackColor = System::Drawing::Color::GreenYellow;
			   this->kkalPerDay->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->kkalPerDay->Location = System::Drawing::Point(877, 31);
			   this->kkalPerDay->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->kkalPerDay->Name = L"kkalPerDay";
			   this->kkalPerDay->Size = System::Drawing::Size(149, 33);
			   this->kkalPerDay->TabIndex = 69;
			   this->kkalPerDay->Text = L"//калории";
			   // 
			   // updateButton
			   // 
			   this->updateButton->BackColor = System::Drawing::Color::LavenderBlush;
			   this->updateButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"updateButton.BackgroundImage")));
			   this->updateButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->updateButton->Location = System::Drawing::Point(520, 23);
			   this->updateButton->Name = L"updateButton";
			   this->updateButton->Size = System::Drawing::Size(63, 58);
			   this->updateButton->TabIndex = 70;
			   this->updateButton->UseVisualStyleBackColor = false;
			   this->updateButton->Click += gcnew System::EventHandler(this, &MainWindow::updateButton_Click);
			   // 
			   // MainWindow
			   // 
			   this->AccessibleRole = System::Windows::Forms::AccessibleRole::Window;
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1063, 519);
			   this->Controls->Add(this->updateButton);
			   this->Controls->Add(this->kkalPerDay);
			   this->Controls->Add(this->kkalEated);
			   this->Controls->Add(this->button8);
			   this->Controls->Add(this->dinnerButton);
			   this->Controls->Add(this->lunchButton);
			   this->Controls->Add(this->breakfastButton);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->profileButton);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"MainWindow";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Менеджер диеты";
			   this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   int fromStringToInt(string str) {
			   int number = 0;
			   int lenght = str.length();
			   int k = 1;
			   for (int i = 0; i < lenght - 1; i++) {
				   k *= 10;
			   }
			   //сначала записываем старшие разряды
			   for (int i = 0; str[i] != 0; i++) {
				   number += (str[i] - '0') * k;
				   k /= 10;
			   }
			   return number;
		   }
		   int userEatAction(int fl) {           
			   usersfood^ us = gcnew usersfood();                     
			   us->Show();
			   Ufl = fl; //
			   static int k;
			   int k1 = 0;
			   int kkal2 = 0;
			   if (user) user->Close();
			   user = gcnew usersfood();
			   this->AddOwnedForm(user);
			   this->user->Ufl = Ufl;
			   String^ kalorise, ^ login_check, ^ product;
			   int kkal;
			   String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=kkal.mdb";
			   OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
			   dbConnection->Open();
			   String^ query = "SELECT * FROM [Таблица1]";
			   OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			   OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
			   while (dbReader->Read()) {

				   login_check = (String^)dbReader["login"];
				   Ulogin = gcnew String(global_login.data());

				   if (login_check == Ulogin) {
					   kalorise = (String^)dbReader["калория"];
					   std::string kkal1 = msclr::interop::marshal_as<std::string>(kalorise); // в системную строку из ^
					   //int al = kkal1.length();
					   kkal2 = fromStringToInt(kkal1);
					   break;
				   }
			   }
			   dbReader->Close();
			   dbConnection->Close();
			   //Кол-во набранных калорий
			   int amountKalorise = 0;
			   int z = 1;
			   if (kalorise != "") {
				   connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=user_food.mdb";
				   dbConnection = gcnew OleDbConnection(connectionString);
				   dbConnection->Open();
				   query = "SELECT * FROM [Таблица1]";
				   dbCommand = gcnew OleDbCommand(query, dbConnection);
				   dbReader = dbCommand->ExecuteReader();
				   while (dbReader->Read()) {
					   login_check = (String^)dbReader["login"];
					   if (login_check == Ulogin) {
						   product = (String^)dbReader["product"];
						   kkal = (int)dbReader["kkal"];
						   int id = (int)dbReader["id"];
						   k = kkal;
						   z = 0;
						   amountKalorise += k;
					   }
				   }
				   dbReader->Close();
				   dbConnection->Close();
				   return amountKalorise;
				   String^ temp = amountKalorise.ToString();
				   kkalEated->Text = temp; // Вывести кол-во набранных калорий
			   }
		   }
	private: System::Void exit(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void profileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		settings^ pers = gcnew settings();
		pers->Show();
	}		   
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ kalorise; // цель калорий в день
		String^ login_check;
		String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=kkal.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
		dbConnection->Open();
		String^ query = "SELECT * FROM [Таблица1]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		while (dbReader->Read()) {
			login_check = (String^)dbReader["login"];
			if (login_check == Ulogin) {
				kalorise = (String^)dbReader["калория"];
				kkalPerDay->Text = kalorise;
				break;
			}
		}
		dbReader->Close();
		dbConnection->Close();
	}
	private: System::Void to_product(System::Object^ sender, System::EventArgs^ e) {
		product^ p = gcnew product();
		p->Show();
	}
	private: System::Void breakfastButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int fl = 1;
		kkalEated->Text = userEatAction(fl).ToString();
	}
	private: System::Void lunchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int fl = 2;
		kkalEated->Text = userEatAction(fl).ToString();
	}
	private: System::Void dinnerButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int fl = 3;
		kkalEated->Text = userEatAction(fl).ToString();
	}
		   //Показать съеденую пользователем еду
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		usersfood^ us = gcnew usersfood();
		us->Show();
		int fl = 4;
		Ufl = fl;
		if (user) user->Close();
		user = gcnew usersfood();
		this->AddOwnedForm(user);
		this->user->Ufl = Ufl;
	}
	private: System::Void kkalEated_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int fl = 4;
	}
};
}
