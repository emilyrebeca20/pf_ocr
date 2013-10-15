#pragma once

namespace pf_ocr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu_File;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openFilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  readSelectedFilesToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFilesDialog;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;


	/* Declared by us */
	private: array <String^>^ fileNamesGlobal;
	private: tesseract::TessBaseAPI *API;
	private: array <Label^>^ labelsArray;
	private: array <Label^>^ fnlabelsArray;

	private: System::Windows::Forms::SplitContainer^  mainContainer;
	private: System::Windows::Forms::SplitContainer^  leftContainer;
	private: System::Windows::Forms::Button^  addField;

	private: System::Windows::Forms::TextBox^  addFieldName;
	private: System::Windows::Forms::ToolStripMenuItem^  preProcessFilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  extractFieldInfoToolStripMenuItem;




			 /*-----------------*/

	protected: 

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
			this->menu_File = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readSelectedFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFilesDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->mainContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->leftContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->addFieldName = (gcnew System::Windows::Forms::TextBox());
			this->addField = (gcnew System::Windows::Forms::Button());
			this->preProcessFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extractFieldInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_File->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainContainer))->BeginInit();
			this->mainContainer->Panel1->SuspendLayout();
			this->mainContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leftContainer))->BeginInit();
			this->leftContainer->Panel1->SuspendLayout();
			this->leftContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_File
			// 
			this->menu_File->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->processToolStripMenuItem});
			this->menu_File->Location = System::Drawing::Point(0, 0);
			this->menu_File->Name = L"menu_File";
			this->menu_File->Size = System::Drawing::Size(1008, 24);
			this->menu_File->TabIndex = 0;
			this->menu_File->Text = L"menu_bar";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openFilesToolStripMenuItem, 
				this->exportToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->fileToolStripMenuItem->Text = L"Archivo";
			// 
			// openFilesToolStripMenuItem
			// 
			this->openFilesToolStripMenuItem->Name = L"openFilesToolStripMenuItem";
			this->openFilesToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->openFilesToolStripMenuItem->Text = L"Abrir archivos";
			this->openFilesToolStripMenuItem->ToolTipText = L"Abrir archivos para procesar.";
			this->openFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::openFilesToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->exportToolStripMenuItem->Text = L"Exportar";
			this->exportToolStripMenuItem->ToolTipText = L"Exportar a archivo en formato CSV.";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(144, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->exitToolStripMenuItem->Text = L"Salir";
			this->exitToolStripMenuItem->ToolTipText = L"Salir de la aplicación.";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->editToolStripMenuItem->Text = L"Editar";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->preProcessFilesToolStripMenuItem, 
				this->readSelectedFilesToolStripMenuItem, this->extractFieldInfoToolStripMenuItem});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->processToolStripMenuItem->Text = L"Procesar";
			// 
			// readSelectedFilesToolStripMenuItem
			// 
			this->readSelectedFilesToolStripMenuItem->Name = L"readSelectedFilesToolStripMenuItem";
			this->readSelectedFilesToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->readSelectedFilesToolStripMenuItem->Text = L"Leer archivos seleccionados";
			this->readSelectedFilesToolStripMenuItem->ToolTipText = L"Aplica OCR a las imágenes seleccionadas.";
			this->readSelectedFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::readSelectedFilesToolStripMenuItem_Click);
			// 
			// openFilesDialog
			// 
			this->openFilesDialog->Filter = L"Todos los archivos permitidos|*.tif;*.png;*.jpg;*.jpeg";
			this->openFilesDialog->Multiselect = true;
			// 
			// mainContainer
			// 
			this->mainContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainContainer->Location = System::Drawing::Point(0, 24);
			this->mainContainer->Name = L"mainContainer";
			// 
			// mainContainer.Panel1
			// 
			this->mainContainer->Panel1->Controls->Add(this->leftContainer);
			this->mainContainer->Size = System::Drawing::Size(1008, 537);
			this->mainContainer->SplitterDistance = 300;
			this->mainContainer->TabIndex = 1;
			// 
			// leftContainer
			// 
			this->leftContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->leftContainer->Location = System::Drawing::Point(0, 0);
			this->leftContainer->Name = L"leftContainer";
			this->leftContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// leftContainer.Panel1
			// 
			this->leftContainer->Panel1->Controls->Add(this->addFieldName);
			this->leftContainer->Panel1->Controls->Add(this->addField);
			this->leftContainer->Size = System::Drawing::Size(300, 537);
			this->leftContainer->SplitterDistance = 350;
			this->leftContainer->TabIndex = 0;
			// 
			// addFieldName
			// 
			this->addFieldName->Location = System::Drawing::Point(13, 15);
			this->addFieldName->Name = L"addFieldName";
			this->addFieldName->Size = System::Drawing::Size(179, 20);
			this->addFieldName->TabIndex = 2;
			// 
			// addField
			// 
			this->addField->Location = System::Drawing::Point(198, 14);
			this->addField->Name = L"addField";
			this->addField->Size = System::Drawing::Size(90, 23);
			this->addField->TabIndex = 0;
			this->addField->Text = L"Agregar campo";
			this->addField->UseVisualStyleBackColor = true;
			this->addField->Click += gcnew System::EventHandler(this, &MainWindow::addField_Click);
			// 
			// preProcessFilesToolStripMenuItem
			// 
			this->preProcessFilesToolStripMenuItem->Name = L"preProcessFilesToolStripMenuItem";
			this->preProcessFilesToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->preProcessFilesToolStripMenuItem->Text = L"Pre-procesar archivos seleccionados";
			// 
			// extractFieldInfoToolStripMenuItem
			// 
			this->extractFieldInfoToolStripMenuItem->Name = L"extractFieldInfoToolStripMenuItem";
			this->extractFieldInfoToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->extractFieldInfoToolStripMenuItem->Text = L"Extraer información de campos";
			this->extractFieldInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::extractFieldInfoToolStripMenuItem_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1008, 561);
			this->Controls->Add(this->mainContainer);
			this->Controls->Add(this->menu_File);
			this->MainMenuStrip = this->menu_File;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menu_File->ResumeLayout(false);
			this->menu_File->PerformLayout();
			this->mainContainer->Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainContainer))->EndInit();
			this->mainContainer->ResumeLayout(false);
			this->leftContainer->Panel1->ResumeLayout(false);
			this->leftContainer->Panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leftContainer))->EndInit();
			this->leftContainer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
				 API = new tesseract::TessBaseAPI();
				 int res = API->Init(NULL,"spa");
				 fileNamesGlobal = gcnew array<String^>(0);
				 labelsArray = gcnew array<Label^>(0);
				 fnlabelsArray = gcnew array<Label^>(0);
				 //MessageBox::Show(System::Convert::ToString(res));
			 }

/* Manejador que abre el dialogo para seleccionar los archivos a procesar */
private: System::Void openFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->openFilesDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 array<String^>^ filenames = this->openFilesDialog->FileNames;
				 int len = fileNamesGlobal->Length;
				 int fngIndex = len;
				 int fnIndex = 0;
				 Array::Resize(fileNamesGlobal,len+(filenames->Length));
				 for(fnIndex;fnIndex<filenames->Length;fnIndex++){
					fileNamesGlobal[fngIndex] = filenames[fnIndex];
					fngIndex++;
				 }
			
				 /*
				 char *outText;
				 tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
				 // Initialize tesseract-ocr with English, without specifying tessdata path
				 //int res = api->Init(".\\", "spa");
				 //MessageBox::Show(System::Convert::ToString(res));
				 api->Init(NULL,"spa");
				 if (!api->SetVariable("save_blob_choices","T"))
					 MessageBox::Show("Setting variable failed!!!\n");
				 // Open input image with leptonica library
				 Pix *image = pixRead("image_gallery.png");
				 api->SetImage(image);
				 MessageBox::Show("Entry");
				 outText = api->GetUTF8Text();
				 String ^ocrstring = gcnew String(outText);
				 MessageBox::Show(ocrstring);
				 api->End();
				 //delete [] outText;
				 MessageBox::Show("Out");
				 pixDestroy(&image);
				 */

				 /*
				 //MessageBox::Show(image_path);
				 // Abrir imagen de entrada con la biblioteca leptonica
				 Pix *image = pixRead("image_gallery.png");
				 API->SetImage(image);
				 // Obtener el resultado OCR
				 char *outText;
				 outText = API->GetUTF8Text();
				 String ^ocrstring = gcnew String(outText);
				 MessageBox::Show(ocrstring);
				 //Destruir objetos y liberar memoria
				 //API->ClearAdaptiveClassifier();
				 //delete [] outText;
				 pixDestroy(&image);
				 MessageBox::Show("Bye!");
				 */				 
			 }
		 }

/* Salir de la aplicación */
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ message = "¿Está seguro de que desea salir de la aplicación?\n\nTodos los cambios que no han sido exportados se perderán.";
			 String^ caption = "Salir";
			 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			 System::Windows::Forms::DialogResult result;
			 result = MessageBox::Show( this, message, caption, buttons );
			 if ( result == System::Windows::Forms::DialogResult::Yes )
			 {
				 API->End();
				 Application::Exit();
			 }
			 
		 }

System::String^ getImageText(System::String^ image_path){
		char *outText;

		pin_ptr<const wchar_t> wch = PtrToStringChars(image_path);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((image_path->Length + 1) * 2);
		errno_t err = 0;
		char *ip = (char *)malloc(sizeInBytes);
		err = wcstombs_s(&convertedChars, 
			ip, sizeInBytes,
			wch, sizeInBytes);
		
		//MessageBox::Show(image_path);
		// Open input image with leptonica library
		Pix *image = pixRead(ip);
		API->SetImage(image);
		// Get OCR result
		outText = API->GetUTF8Text();

		String ^ocrstring = gcnew String(outText);
		//MessageBox::Show(ocrstring);

		// Destroy used object and release memory
		API->ClearAdaptiveClassifier();
		//delete [] outText;
		/* IMPORTANTE: averiguar como liberar la memoria de outText!!! */
		pixDestroy(&image);
		return ocrstring;
	}

/* Comienza a procesar los archivos seleccionados*/
	private: System::Void readSelectedFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i;
				 for(i = 0; i < fileNamesGlobal->Length;i++){
					String^ msg = fileNamesGlobal[i];
					//MessageBox::Show(msg);
					String^ ocrtext = getImageText(msg);
					//MessageBox::Show(ocrtext);
				 }
			 
			 }

private: System::Void addField_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->addFieldName->Text->Length){
				System::Windows::Forms::Label^  labeln;
				labeln = gcnew System::Windows::Forms::Label();
				
				int len = labelsArray->Length;
				int offset = 52+((15+5)*len);

				labeln->AutoSize = true;
				labeln->Location = System::Drawing::Point(20,offset);
				labeln->Name = L"l" + this->addFieldName->Text;
				labeln->Size = System::Drawing::Size(this->addFieldName->Text->Length,15);
				labeln->TabIndex = 3;
				labeln->Text = this->addFieldName->Text;
				labeln->BringToFront();

				System::Array::Resize(labelsArray,len+1);
				this->labelsArray[len] = labeln;
				leftContainer->Panel1->Controls->Add(labelsArray[len]);

				//MessageBox::Show(labeln->Text);
				//MessageBox::Show(labeln->Name);

				this->addFieldName->Text = "";
			 }
		 }
private: System::Void extractFieldInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

