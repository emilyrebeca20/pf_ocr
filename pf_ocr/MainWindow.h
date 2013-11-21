#pragma once

namespace pf_ocr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Reflection;
	using namespace System::Resources;
	using namespace System::Drawing::Imaging;
	using namespace System::Diagnostics;

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
	private: array <Bitmap^>^ imagesNamesGlobal;
	private: array <String^>^ sectionNamesGlobal;
	private: tesseract::TessBaseAPI *API;
	private: String ^ocrstring; 
	private: Int32 PRE_PROCESS;

	private: array <Label^>^ labelsArray;
	private: array <Button^>^ buttonsArray;
	private: array <Label^>^ fnlabelsArray;
	private: array <Button^>^ fnbuttonsArray;
	private: array <String^>^ fieldNames;
	
	private: System::Windows::Forms::SplitContainer^  mainContainer;
	private: System::Windows::Forms::SplitContainer^  leftContainer;
	private: System::Windows::Forms::Button^  addField;

	private: System::Windows::Forms::TextBox^  addFieldName;
	private: System::Windows::Forms::ToolStripMenuItem^  preProcessFilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  extractFieldInfoToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  fieldTable;
	private: System::Windows::Forms::ToolStripMenuItem^  readformsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  readidToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBoxT;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->menu_File = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preProcessFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readSelectedFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readformsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readidToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extractFieldInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFilesDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->mainContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->leftContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->addFieldName = (gcnew System::Windows::Forms::TextBox());
			this->addField = (gcnew System::Windows::Forms::Button());
			this->pictureBoxT = (gcnew System::Windows::Forms::PictureBox());
			this->fieldTable = (gcnew System::Windows::Forms::DataGridView());
			this->menu_File->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainContainer))->BeginInit();
			this->mainContainer->Panel1->SuspendLayout();
			this->mainContainer->Panel2->SuspendLayout();
			this->mainContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leftContainer))->BeginInit();
			this->leftContainer->Panel1->SuspendLayout();
			this->leftContainer->Panel2->SuspendLayout();
			this->leftContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fieldTable))->BeginInit();
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
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exportToolStripMenuItem_Click);
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
			// preProcessFilesToolStripMenuItem
			// 
			this->preProcessFilesToolStripMenuItem->CheckOnClick = true;
			this->preProcessFilesToolStripMenuItem->Name = L"preProcessFilesToolStripMenuItem";
			this->preProcessFilesToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->preProcessFilesToolStripMenuItem->Text = L"Pre-procesar archivos seleccionados";
			this->preProcessFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::preProcessFilesToolStripMenuItem_Click);
			// 
			// readSelectedFilesToolStripMenuItem
			// 
			this->readSelectedFilesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->readformsToolStripMenuItem, 
				this->readidToolStripMenuItem});
			this->readSelectedFilesToolStripMenuItem->Name = L"readSelectedFilesToolStripMenuItem";
			this->readSelectedFilesToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->readSelectedFilesToolStripMenuItem->Text = L"Leer archivos seleccionados";
			this->readSelectedFilesToolStripMenuItem->ToolTipText = L"Aplica OCR a las imágenes seleccionadas.";
			// 
			// readformsToolStripMenuItem
			// 
			this->readformsToolStripMenuItem->Name = L"readformsToolStripMenuItem";
			this->readformsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->readformsToolStripMenuItem->Text = L"Formularios";
			this->readformsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::readformsToolStripMenuItem_Click);
			// 
			// readidToolStripMenuItem
			// 
			this->readidToolStripMenuItem->Name = L"readidToolStripMenuItem";
			this->readidToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->readidToolStripMenuItem->Text = L"Cédulas";
			this->readidToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::readidToolStripMenuItem_Click);
			// 
			// extractFieldInfoToolStripMenuItem
			// 
			this->extractFieldInfoToolStripMenuItem->Name = L"extractFieldInfoToolStripMenuItem";
			this->extractFieldInfoToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->extractFieldInfoToolStripMenuItem->Text = L"Extraer información de campos";
			this->extractFieldInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::extractFieldInfoToolStripMenuItem_Click);
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
			// 
			// mainContainer.Panel2
			// 
			this->mainContainer->Panel2->Controls->Add(this->fieldTable);
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
			this->leftContainer->Panel1->AutoScroll = true;
			this->leftContainer->Panel1->Controls->Add(this->addFieldName);
			this->leftContainer->Panel1->Controls->Add(this->addField);
			// 
			// leftContainer.Panel2
			// 
			this->leftContainer->Panel2->AutoScroll = true;
			this->leftContainer->Panel2->Controls->Add(this->pictureBoxT);
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
			// pictureBoxT
			// 
			this->pictureBoxT->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxT->Location = System::Drawing::Point(0, 0);
			this->pictureBoxT->Name = L"pictureBoxT";
			this->pictureBoxT->Size = System::Drawing::Size(300, 183);
			this->pictureBoxT->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxT->TabIndex = 0;
			this->pictureBoxT->TabStop = false;
			// 
			// fieldTable
			// 
			this->fieldTable->AllowUserToAddRows = false;
			this->fieldTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->fieldTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->fieldTable->Location = System::Drawing::Point(0, 0);
			this->fieldTable->Name = L"fieldTable";
			this->fieldTable->Size = System::Drawing::Size(704, 537);
			this->fieldTable->TabIndex = 0;
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu_File;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"pf_ocr";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menu_File->ResumeLayout(false);
			this->menu_File->PerformLayout();
			this->mainContainer->Panel1->ResumeLayout(false);
			this->mainContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainContainer))->EndInit();
			this->mainContainer->ResumeLayout(false);
			this->leftContainer->Panel1->ResumeLayout(false);
			this->leftContainer->Panel1->PerformLayout();
			this->leftContainer->Panel2->ResumeLayout(false);
			this->leftContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leftContainer))->EndInit();
			this->leftContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fieldTable))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/* Codigo a ejecutarse al cargar la ventana principal de la aplicacion, consiste principalmente de
inicializaciones de variables y arreglos */
private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
				 API = new tesseract::TessBaseAPI();
				 int res = API->Init(NULL,"spa");
				 fileNamesGlobal = gcnew array<String^>(0);		//Arreglo con los nombres de archivos
				 labelsArray = gcnew array<Label^>(0);			//Arreglos con las etiquetas de campos
				 buttonsArray = gcnew array<Button^>(0);		//Arreglo con los botones para borrar campos
				 fnlabelsArray = gcnew array<Label^>(0);		//Arreglo con las etiquetas de los nombres de archivos
				 buttonsArray = gcnew array<Button^>(0);		//Arreglo con los botones para borrar archivos
				 PRE_PROCESS = 0;
				 //MessageBox::Show(System::Convert::ToString(res));
			 }

/* Manejador invoca el dialogo para seleccionar los archivos a procesar y luego almacenar sus rutas,
en un arreglo global. Puede seleccionarse mas de un archivo a la vez */
private: System::Void openFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Bitmap^ tempImg;
			 if(this->openFilesDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 array<String^>^ filenames = this->openFilesDialog->FileNames;
				 int len = fileNamesGlobal->Length;
				 int fngIndex = len;
				 int fnIndex = 0;
				 Array::Resize(fileNamesGlobal,len+(filenames->Length));
				 Array::Resize(imagesNamesGlobal,len+(filenames->Length));
				 Array::Resize(sectionNamesGlobal,len+(filenames->Length * 2));
				 for(fnIndex;fnIndex<filenames->Length;fnIndex++){
					fileNamesGlobal[fngIndex] = filenames[fnIndex];
					tempImg = gcnew Bitmap(filenames[fnIndex]);
					imagesNamesGlobal[fngIndex] = tempImg;
					fngIndex++;
				 }
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

/* Devuelve una cadena con el texto extraido de la imagen */
System::String^ getImageText(System::String^ image_path){
		char *outText;
		//Se convierte la ruta
		pin_ptr<const wchar_t> wch = PtrToStringChars(image_path);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((image_path->Length + 1) * 2);
		errno_t err = 0;
		char *ip = (char *)malloc(sizeInBytes);
		err = wcstombs_s(&convertedChars, 
			ip, sizeInBytes,
			wch, sizeInBytes);
		//Se lee la imagen utilizando leptonica
		Pix *image = pixRead(ip);
		//Se verifica si esta seleccionada la etapa de preprocesamiento
		/*if(PRE_PROCESS){
			image = preprocessingImg(image);
		}*/
		API->SetImage(image);
		outText = API->GetUTF8Text();
		ocrstring = gcnew String(outText);
		API->ClearAdaptiveClassifier();
		pixDestroy(&image);
		return ocrstring;
	}

/* Agrega un campo a buscar en el formulario y su respectivo boton de eliminar */
private: System::Void addField_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->addFieldName->Text->Length){
				System::Windows::Forms::Label^  labeln;
				System::Windows::Forms::Button^ buttonn;
				labeln = gcnew System::Windows::Forms::Label();
				buttonn = gcnew System::Windows::Forms::Button(); 

				int len = labelsArray->Length;
				int offset = 52+((15+10)*len);

				labeln->AutoSize = true;
				labeln->Location = System::Drawing::Point(50,offset+5);
				labeln->Name = L"l" + this->addFieldName->Text;
				labeln->Size = System::Drawing::Size(this->addFieldName->Text->Length,15);
				labeln->TabIndex = 3;
				labeln->Text = this->addFieldName->Text;
				labeln->BringToFront();

				Assembly^ assembly = Assembly::GetExecutingAssembly();
				AssemblyName^ assemblyName = assembly->GetName();
				ResourceManager^ rm = gcnew ResourceManager(assemblyName->Name+".MainWindow", assembly);
				Bitmap^ myicon = (Bitmap^)rm->GetObject("delete");
				Bitmap^ dicon = gcnew Bitmap(myicon,16,16);
				buttonn->AutoSize = true;
				buttonn->Location = System::Drawing::Point(20,offset);
				buttonn->Name = L"" + Convert::ToString(len);
				buttonn->Size = System::Drawing::Size(this->addFieldName->Text->Length,15);
				buttonn->TabIndex = 3;
				buttonn->Image = dicon;
				buttonn->UseVisualStyleBackColor = false;
				buttonn->BackColor = Color::Empty;
				buttonn->Click += gcnew System::EventHandler(this,&MainWindow::deleteFieldClick);
				buttonn->BringToFront();
				
				System::Array::Resize(labelsArray,len+1);
				System::Array::Resize(buttonsArray,len+1);
				this->labelsArray[len] = labeln;
				this->buttonsArray[len] = buttonn;
				leftContainer->Panel1->Controls->Add(labelsArray[len]);
				leftContainer->Panel1->Controls->Add(buttonsArray[len]);
				this->addFieldName->Text = "";
			 }else{
				 MessageBox::Show("El campo no puede ser una cadena vacía.");
			 }
		 }

/* Funcion que maneja el evento al hacer click para borrar un campo */
private: System::Void deleteFieldClick(System::Object^ sender,System::EventArgs^ e){
			 Button ^b = safe_cast<Button^>(sender);
			 deleteField(Convert::ToInt32(b->Name));
		 }

/* Borra el campo con indice index */
private: System::Void deleteField(int index){
			 if((index < labelsArray->Length)&&(index >= 0)){
				 int balen, lalen, offset;
				 lalen = labelsArray->Length;
				 balen = buttonsArray->Length;
				 //Debug::WriteLine(Convert::ToString(balen));
				 for(int i = 0; i < lalen;i++){
					 leftContainer->Panel1->Controls->Remove(labelsArray[i]);
					 leftContainer->Panel1->Controls->Remove(buttonsArray[i]);
				 }
				 array <Label^>^ lArray = gcnew array<Label^>(0);
				 array <Button^>^ bArray = gcnew array<Button^>(0);
				 System::Array::Resize(lArray,lalen-1);
				 System::Array::Resize(bArray,balen-1);
				 System::Array::Copy(labelsArray,0,lArray,0,index);
				 System::Array::Copy(buttonsArray,0,bArray,0,index);
				 System::Array::Copy(labelsArray,index+1,lArray,index,lalen-index-1);
				 System::Array::Copy(buttonsArray,index+1,bArray,index,balen-index-1);
				 labelsArray = lArray;
				 buttonsArray = bArray;
				 lalen = labelsArray->Length;
				 balen = buttonsArray->Length;
				 for(int i = 0; i < lalen;i++){
					 offset = 52+((15+10)*i);
					 labelsArray[i]->Location = System::Drawing::Point(50,offset+5);
					 buttonsArray[i]->Location = System::Drawing::Point(20,offset);
					 buttonsArray[i]->Name = L"" + Convert::ToString(i);
					 leftContainer->Panel1->Controls->Add(labelsArray[i]);
					 leftContainer->Panel1->Controls->Add(buttonsArray[i]);
				 }
			 }else{
				 MessageBox::Show("Error eliminando campo.");
			 }
			 
		 }

/* Agrega los nombres de campos a la tabla*/
private: System::Void extractFieldInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->fieldNames = gcnew array <String^>(this->labelsArray->Length);
			for (int i=0; i<labelsArray->Length; i++)
			{
				fieldNames[i] = this->labelsArray[i]->Text;
			}
			fieldTable->ColumnCount = fieldNames->Length+1;
			fieldTable->Columns[0]->Name = "#";
			int j = 0;
			for (int i=1; i<=fieldNames->Length; i++){
				fieldTable->Columns[i]->Name = fieldNames[j];
				j++;
			}
		 }

/* Extrae el contenido de la imagen y lo almacena en la tabla segun los campos agregados */
private: System::Void extractFieldContent(){
				this->fieldNames = gcnew array <String^>(this->labelsArray->Length);
				for (int i=0; i<labelsArray->Length; i++)
				{
					fieldNames[i] = this->labelsArray[i]->Text;
				}
				array <String^>^ fieldContent = gcnew array <String^>(this->labelsArray->Length);
				fieldContent = this->ocrstring->Split(fieldNames,StringSplitOptions::None);	
				fieldTable->ColumnCount = fieldNames->Length+1;
				fieldTable->Columns[0]->Name = "#";
				int j = 0;
				for (int i=1; i<=fieldNames->Length; i++){
					fieldTable->Columns[i]->Name = fieldNames[j];
					j++;
				}
				int^ rowNumber = (fieldTable->Rows->Count) + 1;
				fieldContent[0] = Convert::ToString(rowNumber);
				DataGridViewRowCollection^ rows = this->fieldTable->Rows;
				rows->Add(fieldContent);
		 }

/* Exporta los datos a un archivo CSV */
private: System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog ^ saveFileCSV = gcnew SaveFileDialog();
			 saveFileCSV->Filter = "Archivo CSV|*.csv";
			 saveFileCSV->Title = "Exportar a archivo CSV";
			 saveFileCSV->ShowDialog();
			 String^ fileName = saveFileCSV->FileName;
			 if(saveFileCSV->FileName != ""){
				StreamWriter^ pwriter = gcnew StreamWriter(fileName); 
				Int32 nRow = fieldTable->RowCount;
				Int32 nCol = fieldTable->ColumnCount;
				String^ cell = "";
				String^ line = "";
				DataGridViewRowCollection^ rows = this->fieldTable->Rows;
				if (nRow && nCol){
					for (int i=0; i < nRow; i++){
						DataGridViewRow^ dgvr = rows->default[i];	
						for (int j=1; j<nCol; j++){
							DataGridViewCell^ dgvcc= dgvr->Cells->default[j];
							cell = Convert::ToString(dgvcc->Value);
							line = line + cell->Remove(cell->Length-1);
							if (j < nCol-1){
								line = line + ";";
							}
						}
					pwriter->WriteLine(line);
					line = "";
					}
				}
				pwriter->Close();
			}
		 }

private: System::Void  generateImageSections(){
			 int i;
			 String^ fileName;
			 Bitmap^ cImg;
			 System::Drawing::Rectangle cropNum =  System::Drawing::Rectangle(1425,685,950,150);
			 System::Drawing::Rectangle cropNam =  System::Drawing::Rectangle(97,873,2009,450);
			 
			 for (i=0;i<imagesNamesGlobal->Length;i++)
			 {
				 fileName = FileInfo(fileNamesGlobal[i]).Name;
				 
				 cImg = imagesNamesGlobal[i]->Clone(cropNum,imagesNamesGlobal[i]->PixelFormat);
				 cImg->Save("temp/cropNum"+fileName,ImageFormat::Png);
				 sectionNamesGlobal[i] = "temp/cropNum"+fileName;

				 cImg = imagesNamesGlobal[i]->Clone(cropNam,imagesNamesGlobal[i]->PixelFormat);
				 cImg->Save("temp/cropNam"+fileName,ImageFormat::Png);
				 sectionNamesGlobal[i+1] = "temp/cropNam"+fileName;
				
				 /*
				 cropImage(imagesNamesGlobal[i],1,fileName);
				 cropImage(imagesNamesGlobal[i],2,fileName);
				 */
			 }
}

/* Comienza a procesar los archivos seleccionados (formulario)*/
private: System::Void readformsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(fileNamesGlobal->Length){
				 if(labelsArray->Length){
					 int i;
					 for(i = 0; i < fileNamesGlobal->Length;i++){
						 String^ msg = fileNamesGlobal[i];
						 String^ ocrtext = getImageText(msg);
						 extractFieldContent();
					 }
				 }else{
					 MessageBox::Show("Debe indicar al menos un campo a buscar.");
				 }
			 }else{
				 MessageBox::Show("Debe seleccionar al menos un archivo.");
			 }		 
		 }

/* Comienza a procesar los archivos seleccionados (cedula)*/
private: System::Void readidToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->generateImageSections();
			 int i;
			 String^ msg;
			 String^ ocrtext;
			 for(i = 0; i < sectionNamesGlobal->Length;i++){
				 msg = sectionNamesGlobal[i];
				 MessageBox::Show(msg);
				 ocrtext = getImageText(msg);
				 msg = sectionNamesGlobal[i+1];
				 ocrtext += getImageText(msg);
				 MessageBox::Show(msg);
				 i++;
				 extractFieldContent();
				 //MessageBox::Show(ocrtext);
			 }
		 }

/* Procesamiento previo de la imagen a analizar */
private: Pix *preprocessingImg(Pix * image){
			 /* Convierte a escala de grises y binariza */
			 Pix *grayimage = pixConvertRGBToGray(image,0,0,0);
			 PIX *thresimage;
			 l_int32 w_8, h_8, d;
			 pixGetDimensions(grayimage, &w_8, &h_8, &d);
			 pixOtsuAdaptiveThreshold(grayimage,w_8,h_8,1,1,0.1,NULL,&thresimage);
			 //Pix *medianimage = pixMedianFilter(thresimage,1,1);
			 
			 //Para probar
			 HBITMAP hbmp = pixGetWindowsHBITMAP(thresimage);
			 Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hbmp);
			 pictureBoxT->Image = bmp;		 
			 return thresimage;
		 }

/* Se cambia la bandera dependiendo de la seleccion */
private: System::Void preProcessFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(PRE_PROCESS) PRE_PROCESS = 0;
			else PRE_PROCESS = 1;
		 }
};
}

