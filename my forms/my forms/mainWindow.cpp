#include "mainWindow.h"
using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	myforms::mainWindow form;
	Application::Run(%form);
}