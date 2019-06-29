#include "stdafx.h"
#include "Marshaling.h"
#include "ManagedEmp.h"
#include "../NativeClass/NativeEmp.h"

namespace msclr
{
	//�������������� � �������������� ���� � ����������� ���
	namespace interop
	{
		template<>
		inline ManagedClass::ManagedEmp^ marshal_as<ManagedClass::ManagedEmp^, NativeEmp>(const NativeEmp& from)
		{
			ManagedClass::ManagedEmp^ toValue = gcnew ManagedClass::ManagedEmp;
			toValue->name = marshal_as<System::String^>(from.name);
			toValue->adress = marshal_as<System::String^>(from.adress);
			toValue->zipCode = from.zipCode;
			return toValue;
		}

		template<>
		ref class context_node<NativeEmp*, ManagedClass::ManagedEmp^> : public context_node_base
		{
		private:
			NativeEmp* toPtr;
			marshal_context context;
		public:
			context_node(NativeEmp*& toObject, ManagedClass::ManagedEmp^ fromObject)
			{
				// Conversion logic starts here
				toPtr = NULL;

				// Convert the name from String^ to const char*.
				System::String^ tempValue = fromObject->name;
				const  char*  nativeName = context.marshal_as<const  char*>(tempValue);

				// Convert the address from String^ to const char*.
				tempValue = fromObject->adress;
				const  char*  nativeAddress = context.marshal_as<const  char*>(tempValue);

				toPtr = new NativeEmp();
				toPtr->name = const_cast<char*>(nativeName);
				toPtr->adress = const_cast<char*>(nativeAddress);
				toPtr->zipCode = fromObject->zipCode;

				toObject = toPtr;
			}
			~context_node()
			{
				this->!context_node();
			}
		protected:
			!context_node()
			{
				// When the context is deleted, it will free the memory
				// allocated for toPtr->name and toPtr->address, so toPtr
				// is the only memory that needs to be freed.
				if (toPtr != NULL) {
					delete toPtr;
					toPtr = NULL;
				}
			}
		};

	}
}


