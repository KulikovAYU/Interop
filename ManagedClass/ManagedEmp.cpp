#include "stdafx.h"
#include "ManagedEmp.h"
#include "Marshaling.cpp"
#include <msclr/marshal.h>
#include "../NativeClass/NativeEmp.h"

void ManagedClass::ManagedEmp::ConvertToNative()
{
	/*ManagedClass::ManagedEmp^ employee = gcnew ManagedClass::ManagedEmp();

	employee->name = gcnew System::String("Jeff Smith");
	employee->adress = gcnew System::String("123 Main Street");
	employee->zipCode = 98111;*/

	msclr::interop::marshal_context context;
	NativeEmp* result = context.marshal_as<NativeEmp*>(this);
	result->ChangeValues();

	ManagedClass::ManagedEmp^ NewManagedEmployee = msclr::interop::marshal_as<ManagedEmp^>(*result);
	this->name = NewManagedEmployee->name;
	this->adress = NewManagedEmployee->adress;
	this->zipCode = NewManagedEmployee->zipCode;
	

	/*if (result != NULL)
	{
		printf_s("Native name: %s\nNative address: %s\nNative zip code: %d\n",
		         result->name, result->adress, result->zipCode);
	}*/
}
