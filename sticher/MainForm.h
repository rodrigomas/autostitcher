#pragma once

#include <opencv2/stitching/stitcher.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>

#include "Utils.h"
#include "ProgressDialog.h"
#using <mscorlib.dll>

namespace sticher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			MaxFrame = Int32::MaxValue;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  AddSeq;
	protected: 
	private: System::Windows::Forms::Button^  RemSeq;
	private: System::Windows::Forms::Button^  Clear;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListView^  ItensBox;

	private: System::Windows::Forms::ColumnHeader^  PathHeader;
	private: System::Windows::Forms::ColumnHeader^  CntHeader;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  Undistort;
	private: System::Windows::Forms::CheckBox^  Stabilize;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  FrameID;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  VideoFormat;
	private: System::Windows::Forms::CheckBox^  MotionVideo;
	private: System::Windows::Forms::CheckBox^  ExportVideo;
	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  Export;

	private: System::Windows::Forms::Button^  About;
	private: System::ComponentModel::BackgroundWorker^  ExportWorker;
	private: System::Windows::Forms::OpenFileDialog^  OpenDialog;
	private: System::Windows::Forms::SaveFileDialog^  SaveDialog;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		int MaxFrame;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AddSeq = (gcnew System::Windows::Forms::Button());
			this->RemSeq = (gcnew System::Windows::Forms::Button());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ItensBox = (gcnew System::Windows::Forms::ListView());
			this->PathHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->CntHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Undistort = (gcnew System::Windows::Forms::CheckBox());
			this->Stabilize = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FrameID = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->VideoFormat = (gcnew System::Windows::Forms::ComboBox());
			this->MotionVideo = (gcnew System::Windows::Forms::CheckBox());
			this->ExportVideo = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Export = (gcnew System::Windows::Forms::Button());
			this->About = (gcnew System::Windows::Forms::Button());
			this->ExportWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->OpenDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FrameID))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// AddSeq
			// 
			this->AddSeq->Location = System::Drawing::Point(12, 275);
			this->AddSeq->Name = L"AddSeq";
			this->AddSeq->Size = System::Drawing::Size(25, 23);
			this->AddSeq->TabIndex = 1;
			this->AddSeq->Text = L"+";
			this->AddSeq->UseVisualStyleBackColor = true;
			this->AddSeq->Click += gcnew System::EventHandler(this, &MainForm::AddSeq_Click);
			// 
			// RemSeq
			// 
			this->RemSeq->Enabled = false;
			this->RemSeq->Location = System::Drawing::Point(43, 275);
			this->RemSeq->Name = L"RemSeq";
			this->RemSeq->Size = System::Drawing::Size(25, 23);
			this->RemSeq->TabIndex = 2;
			this->RemSeq->Text = L"-";
			this->RemSeq->UseVisualStyleBackColor = true;
			this->RemSeq->Click += gcnew System::EventHandler(this, &MainForm::RemSeq_Click);
			// 
			// Clear
			// 
			this->Clear->Location = System::Drawing::Point(411, 275);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(75, 23);
			this->Clear->TabIndex = 3;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MainForm::Clear_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Video Sequencies:";
			// 
			// ItensBox
			// 
			this->ItensBox->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->PathHeader, this->CntHeader});
			this->ItensBox->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->ItensBox->Location = System::Drawing::Point(12, 31);
			this->ItensBox->Name = L"ItensBox";
			this->ItensBox->Size = System::Drawing::Size(474, 238);
			this->ItensBox->TabIndex = 6;
			this->ItensBox->UseCompatibleStateImageBehavior = false;
			this->ItensBox->View = System::Windows::Forms::View::Details;
			this->ItensBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ItensBox_SelectedIndexChanged);
			// 
			// PathHeader
			// 
			this->PathHeader->Text = L"Parh";
			this->PathHeader->Width = 378;
			// 
			// CntHeader
			// 
			this->CntHeader->Text = L"Count";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Undistort);
			this->groupBox1->Controls->Add(this->Stabilize);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->FrameID);
			this->groupBox1->Location = System::Drawing::Point(12, 304);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(137, 119);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Production Properties";
			// 
			// Undistort
			// 
			this->Undistort->AutoSize = true;
			this->Undistort->Location = System::Drawing::Point(16, 93);
			this->Undistort->Name = L"Undistort";
			this->Undistort->Size = System::Drawing::Size(68, 17);
			this->Undistort->TabIndex = 4;
			this->Undistort->Text = L"Undistort";
			this->Undistort->UseVisualStyleBackColor = true;
			// 
			// Stabilize
			// 
			this->Stabilize->AutoSize = true;
			this->Stabilize->Location = System::Drawing::Point(16, 70);
			this->Stabilize->Name = L"Stabilize";
			this->Stabilize->Size = System::Drawing::Size(65, 17);
			this->Stabilize->TabIndex = 3;
			this->Stabilize->Text = L"Stabilize";
			this->Stabilize->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Frame Reference:";
			// 
			// FrameID
			// 
			this->FrameID->Location = System::Drawing::Point(16, 44);
			this->FrameID->Name = L"FrameID";
			this->FrameID->Size = System::Drawing::Size(89, 20);
			this->FrameID->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->VideoFormat);
			this->groupBox2->Controls->Add(this->MotionVideo);
			this->groupBox2->Controls->Add(this->ExportVideo);
			this->groupBox2->Location = System::Drawing::Point(155, 314);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(158, 109);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Video Export";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Formats:";
			// 
			// VideoFormat
			// 
			this->VideoFormat->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->VideoFormat->Enabled = false;
			this->VideoFormat->FormattingEnabled = true;
			this->VideoFormat->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"1920x1080", L"1280x720", L"720x468", L"640x480"});
			this->VideoFormat->Location = System::Drawing::Point(7, 79);
			this->VideoFormat->Name = L"VideoFormat";
			this->VideoFormat->Size = System::Drawing::Size(145, 21);
			this->VideoFormat->TabIndex = 12;
			// 
			// MotionVideo
			// 
			this->MotionVideo->AutoSize = true;
			this->MotionVideo->Enabled = false;
			this->MotionVideo->Location = System::Drawing::Point(7, 43);
			this->MotionVideo->Name = L"MotionVideo";
			this->MotionVideo->Size = System::Drawing::Size(91, 17);
			this->MotionVideo->TabIndex = 11;
			this->MotionVideo->Text = L"Motion Based";
			this->MotionVideo->UseVisualStyleBackColor = true;
			// 
			// ExportVideo
			// 
			this->ExportVideo->AutoSize = true;
			this->ExportVideo->Location = System::Drawing::Point(6, 19);
			this->ExportVideo->Name = L"ExportVideo";
			this->ExportVideo->Size = System::Drawing::Size(86, 17);
			this->ExportVideo->TabIndex = 10;
			this->ExportVideo->Text = L"Export Video";
			this->ExportVideo->UseVisualStyleBackColor = true;
			this->ExportVideo->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ExportVideo_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Location = System::Drawing::Point(319, 323);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(167, 100);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Cluster Options ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(76, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(110, 34);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(41, 20);
			this->textBox2->TabIndex = 15;
			this->textBox2->Text = L"8888";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(107, 14);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Port:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Manager IP:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(89, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"192.168.0.1";
			// 
			// Export
			// 
			this->Export->Location = System::Drawing::Point(369, 429);
			this->Export->Name = L"Export";
			this->Export->Size = System::Drawing::Size(117, 23);
			this->Export->TabIndex = 11;
			this->Export->Text = L"Export/Submit";
			this->Export->UseVisualStyleBackColor = true;
			this->Export->Click += gcnew System::EventHandler(this, &MainForm::Export_Click);
			// 
			// About
			// 
			this->About->Location = System::Drawing::Point(12, 429);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(75, 23);
			this->About->TabIndex = 12;
			this->About->Text = L"About";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MainForm::About_Click);
			// 
			// ExportWorker
			// 
			this->ExportWorker->WorkerReportsProgress = true;
			this->ExportWorker->WorkerSupportsCancellation = true;
			this->ExportWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::ExportWorker_DoWork);
			this->ExportWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::ExportWorker_ProgressChanged);
			this->ExportWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::ExportWorker_RunWorkerCompleted);
			// 
			// OpenDialog
			// 
			this->OpenDialog->DefaultExt = L"exr";
			this->OpenDialog->Filter = L"OpenEXR Files (*.exr)|*.exr|JPEG Files (*.jpg)|*.jpg";
			// 
			// SaveDialog
			// 
			this->SaveDialog->DefaultExt = L"exr";
			this->SaveDialog->Filter = L"OpenEXR (*.exr)|*.exr";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(498, 464);
			this->Controls->Add(this->About);
			this->Controls->Add(this->Export);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->ItensBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->RemSeq);
			this->Controls->Add(this->AddSeq);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Auto-Sticher ";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FrameID))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Windows::Forms::DialogResult result1 = MessageBox::Show( L"Do you really want to remove all elements?", L"Auto Video Sticher", MessageBoxButtons::YesNo);

				 if( result1 == Windows::Forms::DialogResult::Yes)
				 {
					 ItensBox->Items->Clear();

					 MaxFrame = 0;
					 FrameID->Value = 0;
					 FrameID->Maximum = 0;
				 }
			 }

private: System::Void ItensBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RemSeq->Enabled = ItensBox->SelectedItems->Count != 0;			 			 
		 }
private: System::Void ExportVideo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MotionVideo->Enabled = ExportVideo->Checked;
			 VideoFormat->Enabled = ExportVideo->Checked && !MotionVideo->Checked;

		 }
private: System::Void About_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show( L"Auto Video Sticher v0.1.0.2\n\nDeveloped By: Rodrigo Marques", L"Auto Video Sticher");
		 }
private: System::Void AddSeq_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(OpenDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
			 {
				 String^ FileName = OpenDialog->FileName;

				 String^ Dir = System::IO::Path::GetDirectoryName(FileName);

				 String^ Ext = Path::GetExtension(FileName);

				 ListViewItem^ it = gcnew ListViewItem();
				 it->Text = FileName;				

				 DirectoryInfo ^ di = gcnew DirectoryInfo(Dir);

				 array<FileInfo ^> ^ aryFiles = di->GetFiles(L"*" + Ext, SearchOption::AllDirectories);
				
				 it->SubItems->Add(aryFiles->Length.ToString());

				 ItensBox->Items->Add(it);

				 if( aryFiles->Length < MaxFrame )
				 {
					 MaxFrame = aryFiles->Length;

					 if( FrameID->Value > MaxFrame )
					 {
						 FrameID->Value = MaxFrame;
					 }

					 FrameID->Maximum = MaxFrame;
				 }
			 }
		 }
private: System::Void RemSeq_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(ItensBox->SelectedItems->Count != 0)
			 {
				 for (int i = ItensBox->SelectedItems->Count - 1; i >= 0 ; i--)
				 {
					 ItensBox->Items->Remove(ItensBox->SelectedItems[i]);
				 }

				 RecomputeMax();
			 }
		 }

		 private: System::String^ ExportFileName;
		 private: System::Collections::Generic::List<String^>^ SeqFiles;
		 private: int FrameBase;
		 private: ProgressDialog^ pbDialog;

private: System::Void Export_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 using namespace std;
			 using namespace cv;

			 if( ItensBox->Items->Count == 0 )
				 return;

			 if(SaveDialog->ShowDialog() != Windows::Forms::DialogResult::OK)
				 return;

			 SeqFiles = GetAllFiles();

			 ExportFileName = System::IO::Path::GetFileNameWithoutExtension(SaveDialog->FileName);			 
						 

			 MaxFrame = GetMaxFrameID();

			 if( FrameID->Value > MaxFrame )
				 FrameID->Value = MaxFrame;			 

			 FrameBase = (int)FrameID->Value;			 							 

			 if( pbDialog != nullptr)
			 {
				 pbDialog = gcnew ProgressDialog();
			 } 

			 pbDialog->MainLabel->Text = "Starting Stiting...";
			 pbDialog->Progress->Value = 0;
			 pbDialog->CloseBtn->Click += gcnew System::EventHandler(this, &MainForm::Cancel_Click); 

			 pbDialog->Show();

			 ExportWorker->RunWorkerAsync();
		 }

private: System::Void Cancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ExportWorker->CancelAsync();

			 if( pbDialog != nullptr)
			 {
				 pbDialog->Close();			 

				 pbDialog = nullptr;
			 }			 
		 }

private: System::Boolean  GenerateParameters(System::Collections::Generic::List<String^>^ files, int FrameID, std::vector<std::vector<cv::Rect>>& rois )
		 {
			 using namespace std;
			 using namespace cv;

			 Stitcher stitcher = Stitcher::createDefault(true);

			 vector<Mat> imgs;

			 LoadImages(files, FrameID, imgs);

			 Stitcher::Status status = stitcher.estimateTransform(imgs, rois);

			 if (status != Stitcher::OK)
			 {
				 System::String^ Error = "";

				 Error = "Can't stitch images, error code = " + Int32(status).ToString();

				 MessageBox::Show( Error, L"Auto Video Sticher");

				 //cout << "Can't stitch images, error code = " << int(status) << endl;
				 return false;
			 }

			 return true;
		 }

private: void LoadImages(System::Collections::Generic::List<String^>^ files, int FrameID, std::vector<cv::Mat> &imgs )
		 {
				for(register int i = 0; i < files->Count; i++)
				{
					String^ FileName = files[i];

					System::String^ Dir = System::IO::Path::GetDirectoryName(FileName);

					String^ Ext = Path::GetExtension(FileName);

					DirectoryInfo ^ di = gcnew DirectoryInfo(Dir);

					array<FileInfo ^> ^ aryFiles = di->GetFiles(L"*" + Ext, SearchOption::AllDirectories);

					int j = 0;
					for each(FileInfo ^ fle in aryFiles)
					{
						if( j == FrameID )
						{
							std::string filename;

							MarshalString(fle->FullName, filename);

							cv::Mat img = cv::imread(filename);

							if (img.empty())
							{
								System::String^ Error = "";

								Error = "Can't read image '" + fle->FullName + "'";

								MessageBox::Show( Error, L"Auto Video Sticher");
								break;
							}

							imgs.push_back(img);
							break;
						}

						j++;
					}				
				}
		 }

private: System::Int32 GetMaxFrameID()
		 {
			 int minimum = Int32::MaxValue;

			 for each ( ListViewItem^ it in ItensBox->Items )
			 {
				 
				 Int32 v = System::Int32::Parse(it->SubItems[0]->Text);

				 if( v < minimum )
				 {
					 minimum = v;
				 }
			 }

			 return minimum;
		 }

private: void RecomputeMax()
		 {
			 int minimum = Int32::MaxValue;

			 for each ( ListViewItem^ it in ItensBox->Items )
			 {
				 Int32 v = System::Int32::Parse(it->SubItems[0]->Text);

				 if( v < minimum )
				 {
					 minimum = v;
				 }
			 }

			 MaxFrame = minimum;

			 if(FrameID->Value > MaxFrame)
			 {
				 FrameID->Value = MaxFrame;
			 }

			 FrameID->Maximum = MaxFrame;
		 }

private: System::Collections::Generic::List<String^>^ GetAllFiles()
		{
			 System::Collections::Generic::List<String^>^ files = gcnew System::Collections::Generic::List<String^>();

			 for(register int i = 0; i < ItensBox->Items->Count; i++)
			 {
				 files->Add(ItensBox->Items[i]->Text);

			 }

			 return files;
		}


private: System::Void ExportWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
		 {

			 using namespace std;
			 using namespace cv;

			 System::String^ Dir = System::IO::Path::GetDirectoryName(ExportFileName);			 

			 vector<vector<Rect>> rois;		

			 // Compute Base

			 if( GenerateParameters(SeqFiles, FrameBase, rois) )
			 {
				 System::String^ Error = "";

				 Error = "Can't stitch images, error code = ";

				 MessageBox::Show( Error, L"Auto Video Sticher");

				 return;
			 }

			 for(register int i = 0; i < MaxFrame ; i++)
			 {
				 Stitcher stitcher = Stitcher::createDefault(true);

				 vector<Mat> imgs;

				 Mat pano;

				 LoadImages(SeqFiles, i, imgs);

				 Stitcher::Status status = stitcher.stitch(imgs, rois, pano);

				 if (status != Stitcher::OK)
				 {
					 System::String^ Error = "";

					 Error = "Can't stitch images, error code = " + Int32(status).ToString();

					 MessageBox::Show( Error, L"Auto Video Sticher");

					 //cout << "Can't stitch images, error code = " << int(status) << endl;
					 //return -1;
					 continue;
				 }

				 System::String^ FinalName = System::IO::Path::Combine(Dir, System::String::Format("{0}{1:00000}.exr", ExportFileName, i));

				 string filename;

				 MarshalString(FinalName, filename);

				 imwrite(filename, pano);				
			 }			 			 
		 }
private: System::Void ExportWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
		 {
			 if(pbDialog != nullptr)
			 {
				 pbDialog->Close();

//				 pbDialog->Dispose();

				 pbDialog = nullptr;
			 }			 
		 }
private: System::Void ExportWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
		 {
			 if(pbDialog != nullptr)
			 {
				 String^ Val = (String^)e->UserState;

				 if( pbDialog->MainLabel->Text != Val)
				 {
					 //pbDialog->LogBox->Items->Add()
					 pbDialog->MainLabel->Text = Val;
				 }

				 if(pbDialog->Progress->Value != e->ProgressPercentage)
				 {
					 pbDialog->Progress->Value = e->ProgressPercentage;

					 ///pbDialog->LogBox->Items->Add
				 }				 				 
			 }
		 }
};
}

