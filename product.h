#pragma once
namespace DietManager {
	using namespace System::Data::OleDb;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class product : public System::Windows::Forms::Form {
	public:
		product(void) {
			productName = "";
			kkal = "";
			product_check = "";
			InitializeComponent();
		}
	protected:
		String^ productName;
		String^ kkal, ^ product_check;
	protected:
		~product() {
			if (components) {
				delete components;
				delete productName;
				delete kkal;
				delete product_check;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(product::typeid));
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Lime;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic));
			   this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->label4->Location = System::Drawing::Point(30, 26);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(665, 29);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"Введите название продукта и его калорийность на 100г";
			   this->label4->Click += gcnew System::EventHandler(this, &product::label4_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->textBox1->Location = System::Drawing::Point(35, 98);
			   this->textBox1->Margin = System::Windows::Forms::Padding(2);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(403, 28);
			   this->textBox1->TabIndex = 4;
			   // 
			   // textBox2
			   // 
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->textBox2->Location = System::Drawing::Point(500, 98);
			   this->textBox2->Margin = System::Windows::Forms::Padding(2);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(195, 28);
			   this->textBox2->TabIndex = 5;
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::Transparent;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic));
			   this->button1->Location = System::Drawing::Point(500, 158);
			   this->button1->Margin = System::Windows::Forms::Padding(2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(190, 43);
			   this->button1->TabIndex = 6;
			   this->button1->Text = L"Добавить";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &product::button1_Click);
			   // 
			   // product
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Aquamarine;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(757, 237);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->label4);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"product";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"DietManager";
			   this->Load += gcnew System::EventHandler(this, &product::product_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void product_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
