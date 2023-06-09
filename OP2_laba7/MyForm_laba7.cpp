#include "MyForm_laba7.h"

OP2laba7::MyForm_laba7::MyForm_laba7(void)
{
	InitializeComponent();
	//
	//TODO: добавьте код конструктора
	//
}

OP2laba7::MyForm_laba7::~MyForm_laba7()
{
	if (components)
	{
		delete components;
	}
}

void OP2laba7::MyForm_laba7::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_laba7::typeid));
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->textBox2 = (gcnew System::Windows::Forms::TextBox());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label3 = (gcnew System::Windows::Forms::Label());
	this->label4 = (gcnew System::Windows::Forms::Label());
	this->textBox4 = (gcnew System::Windows::Forms::TextBox());
	this->textBox3 = (gcnew System::Windows::Forms::TextBox());
	this->label5 = (gcnew System::Windows::Forms::Label());
	this->label6 = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// textBox1
	// 
	this->textBox1->BackColor = System::Drawing::SystemColors::MenuBar;
	this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox1->ForeColor = System::Drawing::Color::OrangeRed;
	this->textBox1->Location = System::Drawing::Point(148, 118);
	this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->textBox1->Name = L"textBox1";
	this->textBox1->Size = System::Drawing::Size(132, 22);
	this->textBox1->TabIndex = 0;
	// 
	// textBox2
	// 
	this->textBox2->BackColor = System::Drawing::SystemColors::MenuBar;
	this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox2->ForeColor = System::Drawing::Color::OrangeRed;
	this->textBox2->Location = System::Drawing::Point(449, 118);
	this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->textBox2->Name = L"textBox2";
	this->textBox2->Size = System::Drawing::Size(132, 22);
	this->textBox2->TabIndex = 1;
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label1->Location = System::Drawing::Point(151, 82);
	this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(84, 16);
	this->label1->TabIndex = 2;
	this->label1->Text = L"Введіть n1";
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label2->Location = System::Drawing::Point(453, 82);
	this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(88, 16);
	this->label2->TabIndex = 3;
	this->label2->Text = L"Введіть m1";
	// 
	// button1
	// 
	this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
	this->button1->Cursor = System::Windows::Forms::Cursors::Arrow;
	this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1->ForeColor = System::Drawing::Color::Khaki;
	this->button1->Location = System::Drawing::Point(243, 384);
	this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(241, 48);
	this->button1->TabIndex = 4;
	this->button1->Text = L"Порівняти два вирази";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MyForm_laba7::button1_Click);
	// 
	// label3
	// 
	this->label3->AutoSize = true;
	this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label3->Location = System::Drawing::Point(453, 219);
	this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label3->Name = L"label3";
	this->label3->Size = System::Drawing::Size(88, 16);
	this->label3->TabIndex = 8;
	this->label3->Text = L"Введіть m2";
	// 
	// label4
	// 
	this->label4->AutoSize = true;
	this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label4->Location = System::Drawing::Point(148, 219);
	this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label4->Name = L"label4";
	this->label4->Size = System::Drawing::Size(84, 16);
	this->label4->TabIndex = 7;
	this->label4->Text = L"Введіть n2";
	// 
	// textBox4
	// 
	this->textBox4->BackColor = System::Drawing::SystemColors::MenuBar;
	this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox4->ForeColor = System::Drawing::Color::DodgerBlue;
	this->textBox4->Location = System::Drawing::Point(449, 256);
	this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->textBox4->Name = L"textBox4";
	this->textBox4->Size = System::Drawing::Size(132, 22);
	this->textBox4->TabIndex = 6;
	// 
	// textBox3
	// 
	this->textBox3->BackColor = System::Drawing::SystemColors::MenuBar;
	this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox3->ForeColor = System::Drawing::Color::DodgerBlue;
	this->textBox3->Location = System::Drawing::Point(144, 256);
	this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->textBox3->Name = L"textBox3";
	this->textBox3->Size = System::Drawing::Size(132, 22);
	this->textBox3->TabIndex = 5;
	// 
	// label5
	// 
	this->label5->AutoSize = true;
	this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label5->Location = System::Drawing::Point(254, 315);
	this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label5->Name = L"label5";
	this->label5->Size = System::Drawing::Size(0, 16);
	this->label5->TabIndex = 9;
	// 
	// label6
	// 
	this->label6->AutoSize = true;
	this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label6->ForeColor = System::Drawing::Color::DarkRed;
	this->label6->Location = System::Drawing::Point(286, 44);
	this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label6->Name = L"label6";
	this->label6->Size = System::Drawing::Size(135, 16);
	this->label6->TabIndex = 10;
	this->label6->Text = L"Формула: (n-m)*n!";
	// 
	// MyForm_laba7
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::DarkSeaGreen;
	this->ClientSize = System::Drawing::Size(749, 551);
	this->Controls->Add(this->label6);
	this->Controls->Add(this->label5);
	this->Controls->Add(this->label3);
	this->Controls->Add(this->label4);
	this->Controls->Add(this->textBox4);
	this->Controls->Add(this->textBox3);
	this->Controls->Add(this->button1);
	this->Controls->Add(this->label2);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->textBox2);
	this->Controls->Add(this->textBox1);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
	this->Name = L"MyForm_laba7";
	this->Text = L"laba7";
	this->ResumeLayout(false);
	this->PerformLayout();

}

void OP2laba7::MyForm_laba7::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	try {
		label5->Text = "";
		double n1, m1, n2, m2;
		if (!Double::TryParse(textBox1->Text, n1) || !Double::TryParse(textBox2->Text, m1) ||
			!Double::TryParse(textBox3->Text, n2) || !Double::TryParse(textBox4->Text, m2)) {
			throw "Invalid input: Please enter numeric values";
		}

		Expression^ expr1 = gcnew Expression(n1, m1);
		Expression^ expr2 = gcnew Expression(n2, m2);

		double result1 = expr1->calculate();
		double result2 = expr2->calculate();

		if (result1 > result2) {
			label5->Text = "Перший вираз дорівнює: " + result1.ToString() + "\n" + "Другий вираз дорівнює: " + result2.ToString() + "\n" + "Перший вираз більше";
		}
		else if (result1 < result2) {
			label5->Text = "Перший вираз дорівнює: " + result1.ToString() + "\n" + "Другий вираз дорівнює: " + result2.ToString() + "\n" + "Другий вираз більше";
		}
		else {
			label5->Text = "Перший вираз дорівнює: " + result2.ToString() + "\n" + "Другий вираз дорівнює: " + result1.ToString() + "\n" + "Вирази рівні";
		}
	}
	catch (const char* ex) {
		String^ message = gcnew String(ex);
		MessageBox::Show(message, "Error");
	}
}