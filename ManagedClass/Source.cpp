#include "stdafx.h"
#include "Marshaling.cpp"
#include "../NativeClass/NativeEmp.h"
#include "ManagedEmp.h"
#include <msclr/marshal.h>

int main()
{
	//Блок преобразования неуправляемого кода в управляемый 
	/*NativeEmp employee;

	employee.name = "Jeff Smith";
	employee.adress = "123 Main Street";
	employee.zipCode = 98111;

	ManagedEmp^ result = msclr::interop::marshal_as<ManagedEmp^>(employee);

	System::Console::WriteLine("Managed name: {0}", result->name);
	System::Console::WriteLine("Managed address: {0}", result->adress);
	System::Console::WriteLine("Managed zip code: {0}", result->zipCode);*/


	//Блок преобразования управляемого кода в неуправляемый
	{
		ManagedEmp^ employee = gcnew ManagedEmp();

		employee->name = gcnew System::String("Jeff Smith");
		employee->adress = gcnew System::String("123 Main Street");
		employee->zipCode = 98111;

		msclr::interop::marshal_context context;
		NativeEmp* result = context.marshal_as<NativeEmp*>(employee);

		if (result != NULL) {
			printf_s("Native name: %s\nNative address: %s\nNative zip code: %d\n",
				result->name, result->adress, result->zipCode);
		}
	}
	

	return 0;
}
