#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

//array<String^>^ args
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Diccionario::MyForm form;
	Application::Run(%form);
}