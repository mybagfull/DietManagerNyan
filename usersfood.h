#pragma once
#include <msclr\marshal_cppstd.h>
#include "regex"
#include <string>
#include "iostream"
#include "stdlib.h"
#include "session.h"
namespace DietManager {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::Data::OleDb;
	public ref class usersfood : public System::Windows::Forms::Form {
	public:
		usersfood(void) {
			food = kkal = food_check = "";
			InitializeComponent();
		}
		static int Ufl;
		String^ Ulogin;
	protected:
		String^ food;
		String^ kkal;
		String^ gram;

	private: System::Windows::Forms::TextBox^ textBox2;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   String^ food_check;
	protected:
		~usersfood() {
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ FindButton;
	protected:
	private: System::Windows::Forms::Button^ AddFoodButton;

	private: System::Windows::Forms::TextBox^ textBox1;	private: System::Windows::Forms::Button^ button3;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(usersfood::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->AddFoodButton = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightPink;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Italic));
			this->label1->Location = System::Drawing::Point(110, 57);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(353, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Поиск продуктов питания";
			this->label1->Click += gcnew System::EventHandler(this, &usersfood::label1_Click);
			// 
			// FindButton
			// 
			this->FindButton->AutoSize = true;
			this->FindButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FindButton->Location = System::Drawing::Point(98, 222);
			this->FindButton->Margin = System::Windows::Forms::Padding(2);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(166, 42);
			this->FindButton->TabIndex = 1;
			this->FindButton->Text = L"Искать";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &usersfood::FindButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(27, 159);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(307, 28);
			this->textBox1->TabIndex = 2;
			// 
			// AddFoodButton
			// 
			this->AddFoodButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddFoodButton->Location = System::Drawing::Point(303, 222);
			this->AddFoodButton->Margin = System::Windows::Forms::Padding(2);
			this->AddFoodButton->Name = L"AddFoodButton";
			this->AddFoodButton->Size = System::Drawing::Size(160, 42);
			this->AddFoodButton->TabIndex = 4;
			this->AddFoodButton->Text = L"Добавить";
			this->AddFoodButton->UseVisualStyleBackColor = true;
			this->AddFoodButton->Click += gcnew System::EventHandler(this, &usersfood::AddFoodButton_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(358, 159);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(136, 28);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(354, 135);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 22);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Масса (грамм)";
			this->label2->Click += gcnew System::EventHandler(this, &usersfood::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(23, 135);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Продукт";
			this->label3->Click += gcnew System::EventHandler(this, &usersfood::label3_Click);
			// 
			// usersfood
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LavenderBlush;
			this->ClientSize = System::Drawing::Size(554, 308);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->AddFoodButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"usersfood";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &usersfood::usersfood_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FindButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddFoodButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void usersfood_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
