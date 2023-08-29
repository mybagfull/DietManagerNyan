#pragma once
#include <msclr\marshal_cppstd.h>
#include "MainWindow.h"

namespace DietManager {
	using namespace System::Data::OleDb;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Authorization : public System::Windows::Forms::Form {
	public:
		Authorization(void) {
			InitializeComponent();
		}
	public:

	protected:
		~Authorization() {
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;

	private:
		settings^ nastr;
		MainWindow^ persona;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Authorization::typeid));
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Transparent;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->label2->Location = System::Drawing::Point(96, 95);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(67, 22);
			   this->label2->TabIndex = 25;
			   this->label2->Text = L"логин :";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->label1->Location = System::Drawing::Point(84, 149);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(79, 22);
			   this->label1->TabIndex = 24;
			   this->label1->Text = L"пароль :";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(169, 146);
			   this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->PasswordChar = '*';
			   this->textBox2->Size = System::Drawing::Size(488, 28);
			   this->textBox2->TabIndex = 23;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(169, 92);
			   this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(488, 28);
			   this->textBox1->TabIndex = 22;
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::LightGray;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->button3->Location = System::Drawing::Point(383, 200);
			   this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(274, 37);
			   this->button3->TabIndex = 21;
			   this->button3->Text = L"Выйти";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &Authorization::button3_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::LightGray;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->button2->Location = System::Drawing::Point(169, 200);
			   this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(200, 37);
			   this->button2->TabIndex = 19;
			   this->button2->Text = L"Авторизация";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Authorization::button2_Click);
			   // 
			   // Authorization
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(774, 303);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->Name = L"Authorization";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Менеджер диеты";
			   this->Load += gcnew System::EventHandler(this, &Authorization::Authorization_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void Authorization_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		bool check = false;
		String^ login;
		String^ password;
		String^ login_check, ^ password_check;
		login = textBox1->Text;
		password = textBox2->Text;
		String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=logpass.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();//открываем соединение
		String^ query = "SELECT * FROM [Таблица1]";// запрос
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);//открываем соединение с БД
		OleDbDataReader^ dbReader1 = dbCommand->ExecuteReader();// считываем данные
		while (dbReader1->Read()) {

			login_check = (String^)dbReader1["log"];
			password_check = (String^)dbReader1["pass"];

			if (DBNull::Value != dbReader1["log"] && DBNull::Value != dbReader1["pass"]) {
				if (login_check == login && password_check == password) {

					String^ keylog = login; //получить логин пользователя
					//до завершения программы хранится логин пользователя
					global_login = msclr::interop::marshal_as<std::string>(keylog);

					MessageBox::Show("Пользователь " + login + " успешно авторизован!", "Успешный вход!", MessageBoxButtons::OK);
					check = true;
					dbReader1->Close();// закрываем соединение
					dbConnection->Close();

					if (nastr) nastr->Close();
					nastr = gcnew settings();
					this->AddOwnedForm(nastr);
					if (persona) persona->Close();
					persona = gcnew MainWindow();
					this->AddOwnedForm(persona);
					MainWindow^ pers = gcnew MainWindow();// создаем новый экземпляр
					pers->Show();//открывается персональная страница
					Authorization::Hide();// закрываем
					break;
				}
			}
		}
		if (check == false) {
			MessageBox::Show(this, "Вы ввели  неверный логин или пароль", "Cообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			dbReader1->Close();// закрываем соединение
			dbConnection->Close();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
