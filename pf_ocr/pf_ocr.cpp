// pf_ocr.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "MainWindow.h"

using namespace pf_ocr;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MainWindow());


	return 0;
}
