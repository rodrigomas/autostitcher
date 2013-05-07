#pragma once

namespace sticher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProgressDialog
	/// </summary>
	public ref class ProgressDialog : public System::Windows::Forms::Form
	{
	public:
		ProgressDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgressDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  MainLabel;
	protected: 
	public: System::Windows::Forms::ProgressBar^  Progress;
	public: System::Windows::Forms::ListBox^  LogBox;
	public: System::Windows::Forms::Button^  CloseBtn;


	public: 

	public: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MainLabel = (gcnew System::Windows::Forms::Label());
			this->Progress = (gcnew System::Windows::Forms::ProgressBar());
			this->LogBox = (gcnew System::Windows::Forms::ListBox());
			this->CloseBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// MainLabel
			// 
			this->MainLabel->AutoSize = true;
			this->MainLabel->Location = System::Drawing::Point(13, 13);
			this->MainLabel->Name = L"MainLabel";
			this->MainLabel->Size = System::Drawing::Size(41, 13);
			this->MainLabel->TabIndex = 0;
			this->MainLabel->Text = L"[TEXT]";
			// 
			// Progress
			// 
			this->Progress->Location = System::Drawing::Point(16, 29);
			this->Progress->Name = L"Progress";
			this->Progress->Size = System::Drawing::Size(461, 23);
			this->Progress->TabIndex = 1;
			// 
			// LogBox
			// 
			this->LogBox->FormattingEnabled = true;
			this->LogBox->Location = System::Drawing::Point(16, 58);
			this->LogBox->Name = L"LogBox";
			this->LogBox->Size = System::Drawing::Size(461, 95);
			this->LogBox->TabIndex = 2;
			// 
			// CloseBtn
			// 
			this->CloseBtn->Location = System::Drawing::Point(402, 159);
			this->CloseBtn->Name = L"CloseBtn";
			this->CloseBtn->Size = System::Drawing::Size(75, 23);
			this->CloseBtn->TabIndex = 3;
			this->CloseBtn->Text = L"Cancel";
			this->CloseBtn->UseVisualStyleBackColor = true;
			// 
			// ProgressDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 193);
			this->Controls->Add(this->CloseBtn);
			this->Controls->Add(this->LogBox);
			this->Controls->Add(this->Progress);
			this->Controls->Add(this->MainLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ProgressDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Progress ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
