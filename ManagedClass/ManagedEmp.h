#pragma once
#include "ExtendedManagedEmp.h"

namespace ManagedClass
{
	public ref struct ManagedEmp
	{
		System::String^ name;
		System::String^ adress;
		int zipCode;

		void ConvertToNative();

		
	};
}


