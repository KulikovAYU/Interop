#include "stdafx.h"
#include "ManagedEmp.h"
#include "Marshaling.cpp"
#include <msclr/marshal.h>
#include "../NativeClass/NativeEmp.h"

void ManagedClass::ManagedEmp::ConvertToNative()
{
	ManagedClass::ManagedEmp^ employee = gcnew ManagedClass::ManagedEmp();

	employee->name = gcnew System::String("Jeff Smith");
	employee->adress = gcnew System::String("123 Main Street");
	employee->zipCode = 98111;

	msclr::interop::marshal_context context;
	NativeEmp* result = context.marshal_as<NativeEmp*>(employee);
	result->ReplaceNames();
	if (result != NULL)
	{
		printf_s("Native name: %s\nNative address: %s\nNative zip code: %d\n",
		         result->name, result->adress, result->zipCode);
	}
}
