#include "MyForm_laba7.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	OP2laba7::MyForm_laba7 form;
	Application::Run(% form);
	return 0;
}