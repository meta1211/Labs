#pragma once
#include"List.h"
#include <string>
#include <vector>
namespace myforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ mainWindow
	/// </summary>
	List a;
	List b;
	List c;
	
	public ref class mainWindow : public System::Windows::Forms::Form
	{
	public:
		mainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		array<TextBox^>^ aNodes = gcnew array<TextBox^>(10);
		array<TextBox^>^ bNodes = gcnew array<TextBox^>(10);
		array<TextBox^>^ cNodes = gcnew array<TextBox^>(20);
		int aCount = 0;
		int bCount = 0;
	private: 
		System::Windows::Forms::TextBox^  AddAInput;
		System::Windows::Forms::TextBox^  AddBInput;
		System::Windows::Forms::Button^  AddToATail;
		System::Windows::Forms::TextBox^  FirstInput;
		System::Windows::Forms::TextBox^  SecondInput;
		System::Windows::Forms::Button^  Create1;
		System::Windows::Forms::Button^  Create2;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Button^  Merge;
		System::Windows::Forms::Button^  AddToAToHead;
		System::Windows::Forms::Button^  AddToBTail;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Button^  ClearA;
		System::Windows::Forms::Button^  ClearB;
		System::Windows::Forms::Label^  ValueA;
		System::Windows::Forms::Label^  ValueB;
		System::Windows::Forms::TextBox^  IndexOfB;
		System::Windows::Forms::TextBox^  IndexOfA;
		System::Windows::Forms::Label^  IndexA;
		System::Windows::Forms::Label^  IndexB;
		System::Windows::Forms::Button^  AfterIndexA;
		System::Windows::Forms::Button^  AddAfterKeyB;
		System::Windows::Forms::Button^  AddAfterKeyA;
		System::Windows::Forms::Button^  AfterIndexB;
		System::Windows::Forms::Label^  AddToA;
		System::Windows::Forms::Label^  label4;
		System::ComponentModel::Container ^components;
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~mainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			for (int i = 0; i < 10; i++)
			{
				aNodes[i] = (gcnew System::Windows::Forms::TextBox());
				InitializeTextBox(aNodes[i], "aNode" + Convert::ToString(i), 10 + 40 * i, 125);
				bNodes[i] = (gcnew System::Windows::Forms::TextBox());
				InitializeTextBox(bNodes[i], "bNode" + Convert::ToString(i), 10 + 40 * i, 175);
			}
			for (int i = 0; i < 20; i++)
			{
				cNodes[i] = (gcnew System::Windows::Forms::TextBox());
				InitializeTextBox(cNodes[i], "cNode" + Convert::ToString(i), 10 + 40 * i, 225);
			}
			this->FirstInput = (gcnew System::Windows::Forms::TextBox());
			this->SecondInput = (gcnew System::Windows::Forms::TextBox());
			this->Create1 = (gcnew System::Windows::Forms::Button());
			this->Create2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AddAInput = (gcnew System::Windows::Forms::TextBox());
			this->AddBInput = (gcnew System::Windows::Forms::TextBox());
			this->AddToATail = (gcnew System::Windows::Forms::Button());
			this->Merge = (gcnew System::Windows::Forms::Button());
			this->AddToAToHead = (gcnew System::Windows::Forms::Button());
			this->AddToBTail = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ClearA = (gcnew System::Windows::Forms::Button());
			this->ClearB = (gcnew System::Windows::Forms::Button());
			this->ValueA = (gcnew System::Windows::Forms::Label());
			this->ValueB = (gcnew System::Windows::Forms::Label());
			this->IndexOfB = (gcnew System::Windows::Forms::TextBox());
			this->IndexOfA = (gcnew System::Windows::Forms::TextBox());
			this->IndexA = (gcnew System::Windows::Forms::Label());
			this->IndexB = (gcnew System::Windows::Forms::Label());
			this->AfterIndexA = (gcnew System::Windows::Forms::Button());
			this->AddAfterKeyB = (gcnew System::Windows::Forms::Button());
			this->AddAfterKeyA = (gcnew System::Windows::Forms::Button());
			this->AfterIndexB = (gcnew System::Windows::Forms::Button());
			this->AddToA = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// FirstInput
			// 
			this->FirstInput->Location = System::Drawing::Point(12, 26);
			this->FirstInput->Name = L"FirstInput";
			this->FirstInput->Size = System::Drawing::Size(217, 20);
			this->FirstInput->TabIndex = 0;
			// 
			// SecondInput
			// 
			this->SecondInput->Location = System::Drawing::Point(426, 26);
			this->SecondInput->Name = L"SecondInput";
			this->SecondInput->Size = System::Drawing::Size(217, 20);
			this->SecondInput->TabIndex = 0;
			// 
			// Create1
			// 
			this->Create1->Location = System::Drawing::Point(15, 53);
			this->Create1->Name = L"Create1";
			this->Create1->Size = System::Drawing::Size(74, 24);
			this->Create1->TabIndex = 2;
			this->Create1->Text = L"Create";
			this->Create1->UseVisualStyleBackColor = true;
			this->Create1->Click += gcnew System::EventHandler(this, &mainWindow::Create1_Click);
			// 
			// Create2
			// 
			this->Create2->Location = System::Drawing::Point(426, 52);
			this->Create2->Name = L"Create2";
			this->Create2->Size = System::Drawing::Size(75, 24);
			this->Create2->TabIndex = 2;
			this->Create2->Text = L"Create";
			this->Create2->UseVisualStyleBackColor = true;
			this->Create2->Click += gcnew System::EventHandler(this, &mainWindow::Create2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"List a:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"List b:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Result:";
			// 
			// AddAInput
			// 
			this->AddAInput->Location = System::Drawing::Point(235, 26);
			this->AddAInput->Name = L"AddAInput";
			this->AddAInput->Size = System::Drawing::Size(50, 20);
			this->AddAInput->TabIndex = 0;
			// 
			// AddBInput
			// 
			this->AddBInput->Location = System::Drawing::Point(649, 26);
			this->AddBInput->Name = L"AddBInput";
			this->AddBInput->Size = System::Drawing::Size(41, 20);
			this->AddBInput->TabIndex = 0;
			// 
			// AddToATail
			// 
			this->AddToATail->Location = System::Drawing::Point(167, 54);
			this->AddToATail->Name = L"AddToATail";
			this->AddToATail->Size = System::Drawing::Size(56, 24);
			this->AddToATail->TabIndex = 4;
			this->AddToATail->Text = L"Tail";
			this->AddToATail->UseVisualStyleBackColor = true;
			this->AddToATail->Click += gcnew System::EventHandler(this, &mainWindow::AddToATail_Click);
			// 
			// Merge
			// 
			this->Merge->Location = System::Drawing::Point(341, 57);
			this->Merge->Name = L"Merge";
			this->Merge->Size = System::Drawing::Size(50, 50);
			this->Merge->TabIndex = 6;
			this->Merge->Text = L"Merge";
			this->Merge->UseVisualStyleBackColor = true;
			this->Merge->Click += gcnew System::EventHandler(this, &mainWindow::Merge_Click);
			// 
			// AddToAToHead
			// 
			this->AddToAToHead->Location = System::Drawing::Point(229, 53);
			this->AddToAToHead->Name = L"AddToAToHead";
			this->AddToAToHead->Size = System::Drawing::Size(56, 24);
			this->AddToAToHead->TabIndex = 7;
			this->AddToAToHead->Text = L"Head";
			this->AddToAToHead->UseVisualStyleBackColor = true;
			this->AddToAToHead->Click += gcnew System::EventHandler(this, &mainWindow::AddToAToHead_Click);
			// 
			// AddToBTail
			// 
			this->AddToBTail->Location = System::Drawing::Point(569, 54);
			this->AddToBTail->Name = L"AddToBTail";
			this->AddToBTail->Size = System::Drawing::Size(56, 24);
			this->AddToBTail->TabIndex = 8;
			this->AddToBTail->Text = L"ToTail";
			this->AddToBTail->UseVisualStyleBackColor = true;
			this->AddToBTail->Click += gcnew System::EventHandler(this, &mainWindow::AddToBTail_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(631, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 24);
			this->button1->TabIndex = 9;
			this->button1->Text = L"To head";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainWindow::button1_Click);
			// 
			// ClearA
			// 
			this->ClearA->Location = System::Drawing::Point(15, 82);
			this->ClearA->Name = L"ClearA";
			this->ClearA->Size = System::Drawing::Size(74, 24);
			this->ClearA->TabIndex = 10;
			this->ClearA->Text = L"Clear";
			this->ClearA->UseVisualStyleBackColor = true;
			this->ClearA->Click += gcnew System::EventHandler(this, &mainWindow::ClearA_Click);
			// 
			// ClearB
			// 
			this->ClearB->Location = System::Drawing::Point(427, 82);
			this->ClearB->Name = L"ClearB";
			this->ClearB->Size = System::Drawing::Size(74, 24);
			this->ClearB->TabIndex = 11;
			this->ClearB->Text = L"Clear";
			this->ClearB->UseVisualStyleBackColor = true;
			this->ClearB->Click += gcnew System::EventHandler(this, &mainWindow::ClearB_Click);
			// 
			// ValueA
			// 
			this->ValueA->AutoSize = true;
			this->ValueA->Location = System::Drawing::Point(239, 10);
			this->ValueA->Name = L"ValueA";
			this->ValueA->Size = System::Drawing::Size(36, 13);
			this->ValueA->TabIndex = 12;
			this->ValueA->Text = L"value:";
			// 
			// ValueB
			// 
			this->ValueB->AutoSize = true;
			this->ValueB->Location = System::Drawing::Point(651, 9);
			this->ValueB->Name = L"ValueB";
			this->ValueB->Size = System::Drawing::Size(36, 13);
			this->ValueB->TabIndex = 12;
			this->ValueB->Text = L"value:";
			// 
			// IndexOfB
			// 
			this->IndexOfB->Location = System::Drawing::Point(696, 26);
			this->IndexOfB->Name = L"IndexOfB";
			this->IndexOfB->Size = System::Drawing::Size(41, 20);
			this->IndexOfB->TabIndex = 13;
			// 
			// IndexOfA
			// 
			this->IndexOfA->Location = System::Drawing::Point(291, 26);
			this->IndexOfA->Name = L"IndexOfA";
			this->IndexOfA->Size = System::Drawing::Size(41, 20);
			this->IndexOfA->TabIndex = 14;
			// 
			// IndexA
			// 
			this->IndexA->AutoSize = true;
			this->IndexA->Location = System::Drawing::Point(288, 10);
			this->IndexA->Name = L"IndexA";
			this->IndexA->Size = System::Drawing::Size(57, 13);
			this->IndexA->TabIndex = 12;
			this->IndexA->Text = L"index/key:";
			// 
			// IndexB
			// 
			this->IndexB->AutoSize = true;
			this->IndexB->Location = System::Drawing::Point(693, 9);
			this->IndexB->Name = L"IndexB";
			this->IndexB->Size = System::Drawing::Size(57, 13);
			this->IndexB->TabIndex = 12;
			this->IndexB->Text = L"index/key:";
			// 
			// AfterIndexA
			// 
			this->AfterIndexA->Location = System::Drawing::Point(167, 83);
			this->AfterIndexA->Name = L"AfterIndexA";
			this->AfterIndexA->Size = System::Drawing::Size(56, 24);
			this->AfterIndexA->TabIndex = 15;
			this->AfterIndexA->Text = L"Index";
			this->AfterIndexA->UseVisualStyleBackColor = true;
			this->AfterIndexA->Click += gcnew System::EventHandler(this, &mainWindow::AfterIndexA_Click);
			// 
			// AddAfterKeyB
			// 
			this->AddAfterKeyB->Location = System::Drawing::Point(631, 83);
			this->AddAfterKeyB->Name = L"AddAfterKeyB";
			this->AddAfterKeyB->Size = System::Drawing::Size(56, 24);
			this->AddAfterKeyB->TabIndex = 16;
			this->AddAfterKeyB->Text = L"Key";
			this->AddAfterKeyB->UseVisualStyleBackColor = true;
			this->AddAfterKeyB->Click += gcnew System::EventHandler(this, &mainWindow::AddAfterKeyB_Click);
			// 
			// AddAfterKeyA
			// 
			this->AddAfterKeyA->Location = System::Drawing::Point(229, 84);
			this->AddAfterKeyA->Name = L"AddAfterKeyA";
			this->AddAfterKeyA->Size = System::Drawing::Size(56, 24);
			this->AddAfterKeyA->TabIndex = 17;
			this->AddAfterKeyA->Text = L"Key";
			this->AddAfterKeyA->UseVisualStyleBackColor = true;
			this->AddAfterKeyA->Click += gcnew System::EventHandler(this, &mainWindow::AddAfterKeyA_Click);
			// 
			// AfterIndexB
			// 
			this->AfterIndexB->Location = System::Drawing::Point(569, 82);
			this->AfterIndexB->Name = L"AfterIndexB";
			this->AfterIndexB->Size = System::Drawing::Size(56, 24);
			this->AfterIndexB->TabIndex = 18;
			this->AfterIndexB->Text = L"Index";
			this->AfterIndexB->UseVisualStyleBackColor = true;
			this->AfterIndexB->Click += gcnew System::EventHandler(this, &mainWindow::AfterIndexB_Click);
			// 
			// AddToA
			// 
			this->AddToA->AutoSize = true;
			this->AddToA->Location = System::Drawing::Point(116, 53);
			this->AddToA->Name = L"AddToA";
			this->AddToA->Size = System::Drawing::Size(41, 13);
			this->AddToA->TabIndex = 19;
			this->AddToA->Text = L"Add to:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(507, 53);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Add to:";
			// 
			// mainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(829, 270);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->AddToA);
			this->Controls->Add(this->AfterIndexB);
			this->Controls->Add(this->AddAfterKeyA);
			this->Controls->Add(this->AddAfterKeyB);
			this->Controls->Add(this->AfterIndexA);
			this->Controls->Add(this->IndexOfA);
			this->Controls->Add(this->IndexOfB);
			this->Controls->Add(this->ValueB);
			this->Controls->Add(this->IndexB);
			this->Controls->Add(this->IndexA);
			this->Controls->Add(this->ValueA);
			this->Controls->Add(this->ClearB);
			this->Controls->Add(this->ClearA);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->AddToBTail);
			this->Controls->Add(this->AddToAToHead);
			this->Controls->Add(this->Merge);
			this->Controls->Add(this->AddToATail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Create2);
			this->Controls->Add(this->Create1);
			this->Controls->Add(this->SecondInput);
			this->Controls->Add(this->AddBInput);
			this->Controls->Add(this->AddAInput);
			this->Controls->Add(this->FirstInput);
			this->Name = L"mainWindow";
			this->Text = L"List visualisation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Boolean IsCorrect(System::String ^data)
		{
			int numberCount = 0;
			int numLen = 0;
			for (int i = 0; i < data->Length; i++)
			{
				if (data[i] >= '0' && data[i] <= '9')
					numLen++;
				else if (data[i] == ' ')
				{
					if (numLen)
					{
						numberCount++;
						numLen = 0;
					}
				}
				else
				{
					return false;
				}
			}
			return numberCount <= 10; //10 is maximum list size.
		}
		System::Boolean IsCorrect(TextBox^ box)
		{
			if (box->Text->Length)
			{
				auto input = box->Text;
				for (int i = 0; i < input->Length; i++)
				{
					if (!(input[i] >= '0' && input[i] <= '9'))
					{
						return false;
					}
				}
			}
			return true;
		}
		System::Void InitializeTextBox(TextBox ^tb, System::String ^name, int xPos, int yPos)
		{
			tb->Size = System::Drawing::Size(30, 20);
			tb->Location = System::Drawing::Point(xPos, yPos);
			tb->Name = name;
			tb->ReadOnly = true;
			tb->TabIndex = 0;
			tb->Visible = false;
			tb->Text = Convert::ToString(tb);
			this->Controls->Add(tb);
		}
		System::Void RecreateList(List &list, System::String ^data)
		{
			list.Clear();
			std::string num;
			for (int i = 0; i < data->Length; i++)
			{
				if (data[i] == ' ')
				{
					if (num.size())
					{
						list.AddToTail(std::stoi(num));
						num.clear();
					}
				}
				else
				{
					num.push_back(data[i]);
				}
			}
			if (num.size())
			{
				list.AddToTail(std::stoi(num));
				num.clear();
			}
		}
		System::Void Redraw(List &a, array<TextBox^>^ Nodes)
		{
			for (int i = 0; i < a.GetSize() && i < 10; i++)
			{
				Nodes[i]->Visible = true;
				Nodes[i]->Text = Convert::ToString(a[i]);
			}
			for (int i = a.GetSize(); i < 10; i++)
			{
				Nodes[i]->Visible = false;
			}
		}
		System::Void Create1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (FirstInput->Text->Length)
			{
				if (IsCorrect(FirstInput->Text))
				{
					RecreateList(a, FirstInput->Text);
					Redraw(a, aNodes);
				}
				else
				{
					FirstInput->Text = "Wrong input! Try again please.";
				}
			}
		}
		System::Void Create2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (SecondInput->Text->Length)
			{
				if (IsCorrect(SecondInput->Text))
				{
					RecreateList(b, SecondInput->Text);
					Redraw(b, bNodes);
				}
				else
				{
					SecondInput->Text = "Wrong input! Try again please.";
				}
			}
		}
		System::Void AddToATail_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddAInput))
			{
				if (a.GetSize() < 10)
				{
					a.AddToTail(Convert::ToInt16(AddAInput->Text));
					Redraw(a, aNodes);
				}
			}
			else
			{
				AddAInput->Text = "Cant add.";
			}
		}
		System::Void Merge_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (a.GetSize() || b.GetSize())
			{
				c = a + b;
				Redraw(c, cNodes);
			}
		}
		System::Void AddToAToHead_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddAInput))
			{
				if (a.GetSize() < 10)
				{
					a.AddToHead(Convert::ToInt16(AddAInput->Text));
					Redraw(a, aNodes);
				}
			}
			else
			{
				AddAInput->Text = "Cant add.";
			}
		}
		System::Void AddToBTail_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddBInput))
			{
				if (b.GetSize() < 10)
				{
					b.AddToTail(Convert::ToInt16(AddBInput->Text));
					Redraw(b, bNodes);
				}
			}
			else
			{
				AddBInput->Text = "Cant add.";
			}
		}
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (IsCorrect(AddAInput))
			{
				if (b.GetSize() < 10)
				{
					b.AddToHead(Convert::ToInt16(AddBInput->Text));
					Redraw(b, bNodes);
				}
			}
			else
			{
				AddBInput->Text = "Cant add.";
			}
		}
		System::Void ClearA_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			a.Clear();
			FirstInput->Text = "";
			Redraw(a, aNodes);
		}
		System::Void ClearB_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			b.Clear();
			SecondInput->Text = "";
			Redraw(b, bNodes);
		}
		System::Void AfterIndexA_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddAInput) && IsCorrect(IndexOfA->Text) && Convert::ToInt16(IndexOfA->Text) >= 0 && Convert::ToInt16(IndexOfA->Text) < a.GetSize())
			{
				if (a.GetSize() < 10)
				{
					a.AddToIndex(Convert::ToInt16(IndexOfA->Text), Convert::ToInt16(AddAInput->Text));
					Redraw(a, aNodes);
				}
			}
			else
			{
				AddAInput->Text = "Cant add.";
			}
		}
		System::Void AfterIndexB_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddBInput) && IsCorrect(IndexOfB->Text) && Convert::ToInt16(IndexOfB->Text) > 0 && Convert::ToInt16(IndexOfB->Text) < b.GetSize())
			{
				if (b.GetSize() < 10)
				{
					b.AddToIndex(Convert::ToInt16(IndexOfB->Text), Convert::ToInt16(AddBInput->Text));
					Redraw(b, bNodes);
				}
			}
			else
			{
				AddBInput->Text = "Cant add.";
			}
		}
		System::Void AddAfterKeyA_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddAInput) && IsCorrect(IndexOfA) && a.FindKey(Convert::ToInt16(IndexOfA->Text)))
			{
				if (a.GetSize() < 10)
				{
					a.AddToKey(Convert::ToInt16(IndexOfA->Text), Convert::ToInt16(AddAInput->Text));
					Redraw(a, aNodes);
				}
			}
			else
			{
				AddAInput->Text = "Cant add.";
			}
		}
		System::Void AddAfterKeyB_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (IsCorrect(AddBInput) && IsCorrect(IndexOfB) && b.FindKey(Convert::ToInt16(IndexOfB->Text)))
			{
				if (b.GetSize() < 10)
				{
					b.AddToKey(Convert::ToInt16(IndexOfB->Text), Convert::ToInt16(AddBInput->Text));
					Redraw(b, bNodes);
				}
			}
			else
			{
				AddBInput->Text = "Cant add.";
			}
		}
};
}
