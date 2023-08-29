#include "MyForm.h"
#include "UserInformationFunctions.h"

#include "MainWindowFunctions.h"
#include "productFunctions.h"
#include "usersfoodFunctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::OleDb;
using namespace std;
[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ myform = gcnew MyForm;
	Application::Run(myform);
	return 0;
}
//Здесь точка входа в программу, открытие первого окна