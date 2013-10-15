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
			this->menu_File->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_File
			// 
			this->menu_File->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->processToolStripMenuItem});
			this->menu_File->Location = System::Drawing::Point(0, 0);
			this->menu_File->Name = L"menu_File";
			this->menu_File->Size = System::Drawing::Size(853, 24);
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
			this->openFilesToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openFilesToolStripMenuItem->Text = L"Abrir archivos";
			this->openFilesToolStripMenuItem->ToolTipText = L"Abrir archivos para procesar.";
			this->openFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::openFilesToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exportToolStripMenuItem->Text = L"Exportar";
			this->exportToolStripMenuItem->ToolTipText = L"Exportar a archivo en formato CSV.";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
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
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->readSelectedFilesToolStripMenuItem});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->processToolStripMenuItem->Text = L"Procesar";
			// 
			// readSelectedFilesToolStripMenuItem
			// 
			this->readSelectedFilesToolStripMenuItem->Name = L"readSelectedFilesToolStripMenuItem";
			this->readSelectedFilesToolStripMenuItem->Size = System::Drawing::Size(220, 22);
			this->readSelectedFilesToolStripMenuItem->Text = L"Leer archivos seleccionados";
			this->readSelectedFilesToolStripMenuItem->ToolTipText = L"Aplica OCR a las imágenes seleccionadas.";
			this->readSelectedFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::readSelectedFilesToolStripMenuItem_Click);
			// 
			// openFilesDialog
			// 
			this->openFilesDialog->Filter = L"Todos los archivos permitidos|*.tif;*.png;*.jpg;*.jpeg";
			this->openFilesDialog->Multiselect = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(853, 443);
			this->Controls->Add(this->menu_File);
			this->MainMenuStrip = this->menu_File;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menu_File->ResumeLayout(false);
			this->menu_File->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
				 API = new tesseract::TessBaseAPI();
				 int res = API->Init(NULL,"spa");
				 //MessageBox::Show(System::Convert::ToString(res));
			 }

/* Manejador que abre el dialogo para seleccionar los archivos a procesar */
private: System::Void openFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->openFilesDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 array<String^>^ filenames = this->openFilesDialog->FileNames;
				 fileNamesGlobal = filenames;
				 //int len = fileNamesGlobal->Length;
				 //System::Array::Resize(fileNamesGlobal,filenames->Length+len);
				 //int fngIndex = len;
				 //int fnIndex = 0; 
				 //for(fnIndex;fnIndex<filenames->Length;fnIndex++)
					// fileNamesGlobal[fngIndex] = filenames[fnIndex];
				 
			
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

System::Void getImageText(System::String^ image_path){
		char *outText;

		pin_ptr<const wchar_t> wch = PtrToStringChars(image_path);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((image_path->Length + 1) * 2);
		errno_t err = 0;
		char *ip = (char *)malloc(sizeInBytes);
		err = wcstombs_s(&convertedChars, 
			ip, sizeInBytes,
			wch, sizeInBytes);
		
		MessageBox::Show(image_path);
		// Open input image with leptonica library
		Pix *image = pixRead(ip);
		API->SetImage(image);
		// Get OCR result
		outText = API->GetUTF8Text();

		String ^ocrstring = gcnew String(outText);
		MessageBox::Show(ocrstring);

		// Destroy used object and release memory
		API->ClearAdaptiveClassifier();
		//delete [] outText;
		/* IMPORTANTE: averiguar como liberar la memoria de outText!!! */
		pixDestroy(&image);

	}

/* Comienza a procesar los archivos seleccionados*/
	private: System::Void readSelectedFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i;
				 for(i = 0; i < fileNamesGlobal->Length;i++){
					String^ msg = fileNamesGlobal[i];
					//MessageBox::Show(msg);
					getImageText(msg);
				 }
			 
			 }
};
}

