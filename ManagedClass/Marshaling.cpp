#include "stdafx.h"
#include "Marshaling.h"
#include "ManagedEmp.h"
#include "../NativeClass/NativeEmp.h"
#include "ExtendedManagedEmp.h"
#include "../NativeClass/ExtendedNativeEmp.h"
#include <vector>

namespace msclr
{
	//Преобразование неуправляемого кода в управляемый код
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

		//Преобразование управляемый кода в неуправляемый код
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

		//Преобразование неуправляемого кода в управляемый код
		template<>
		inline ManagedClass::ITestManagedInterface^ marshal_as<ManagedClass::ITestManagedInterface^, ITestNativeInterface>(const ITestNativeInterface& from)
		{
			ManagedClass::ITestManagedInterface^ toValue = gcnew ManagedClass::ExtendedManagedEmp;
			toValue->Name = marshal_as<System::String^>(from.GetName());
			toValue->Adress = marshal_as<System::String^>(from.GetAdress());
			toValue->ZipCode = from.GetZipCode();
			return toValue;
		}


		//Преобразование управляемый кода в неуправляемый код
		template<>
		ref class context_node<ITestNativeInterface*, ManagedClass::ExtendedManagedEmp^> : public context_node_base
		{
		private:
			ITestNativeInterface* toPtr;
			marshal_context context;
		public:
			context_node(ITestNativeInterface*& toObject, ManagedClass::ExtendedManagedEmp^ fromObject)
			{
				// Conversion logic starts here
				toPtr = NULL;

				// Convert the name from String^ to const char*.
				System::String^ tempValue = fromObject->Name;
				const  char* nativeName = context.marshal_as<const  char*>(tempValue);

				// Convert the address from String^ to const char*.
				tempValue = fromObject->Adress;
				const  char* nativeAddress = context.marshal_as<const  char*>(tempValue);

				toPtr = new ExtendedNativeEmp();
				toPtr->SetName(const_cast<char*>(nativeName));
				toPtr->SetAdress(const_cast<char*>(nativeAddress));
				toPtr->SetZipCode(fromObject->ZipCode);

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

		//Преобразование неуправляемого кода в управляемый код (массивы)
		template<>
		inline array<ManagedClass::ITestManagedInterface^>^ marshal_as<array<ManagedClass::ITestManagedInterface^>^, std::vector<ITestNativeInterface*>>(const std::vector<ITestNativeInterface*>& from)
		{
			array<ManagedClass::ITestManagedInterface^>^ managedArray = gcnew array<ManagedClass::ITestManagedInterface^>(from.size());
			int nCount = 0;
			for (const auto& object : from)
			{
				//managedArray[nCount] = gcnew ManagedClass::ExtendedManagedEmp{};
				
				ManagedClass::ITestManagedInterface^ toValue = gcnew ManagedClass::ExtendedManagedEmp;
				toValue->Name = marshal_as<System::String^>(object->GetName());
				toValue->Adress = marshal_as<System::String^>(object->GetAdress());
				toValue->ZipCode = object->GetZipCode();
				managedArray[nCount] = toValue;
				nCount++;
			}
			return managedArray;
		}


		//Преобразование управляемый кода в неуправляемый код (массивы)
		template<>
		ref class context_node<std::vector<ITestNativeInterface*>*, array<ManagedClass::ExtendedManagedEmp^>^> : public context_node_base
		{
		private:
			std::vector<ITestNativeInterface*>* toPtr;
		//	std::vector<ITestNativeInterface*>* _toObj;
			marshal_context context;
		public:
			context_node(std::vector<ITestNativeInterface*>*& toObject, array<ManagedClass::ExtendedManagedEmp^>^ fromObject)
			{
				// Conversion logic starts here
				//toPtr = NULL;

				toPtr = new std::vector<ITestNativeInterface*>();

				for (int i = 0; i < fromObject->Length; ++i)
				{
					ManagedClass::ITestManagedInterface^ currentObject = fromObject[i];
					// Convert the name from String^ to const char*.
					System::String^ tempValue = currentObject->Name;
					const  char* nativeName = context.marshal_as<const  char*>(tempValue);
					// Convert the address from String^ to const char*.
					tempValue = currentObject->Adress;
					const  char* nativeAddress = context.marshal_as<const  char*>(tempValue);
				
					ITestNativeInterface* pNativeObject = new ExtendedNativeEmp;
					
					pNativeObject->SetName(const_cast<char*>(nativeName));
					pNativeObject->SetAdress(const_cast<char*>(nativeAddress));
					pNativeObject->SetZipCode(currentObject->ZipCode);

					toPtr->emplace_back(pNativeObject);

				}
				
				toObject = toPtr;
			
			}
			~context_node()
			{
				this->!context_node();
			}
		protected:
			!context_node()
			{
				if(toPtr->capacity() != 0 )
				{
					for(auto &ptrTodel : *toPtr)
					{
						delete ptrTodel;
						ptrTodel = NULL;
					}

					delete toPtr;
					toPtr = NULL;
				}

			}
		};

	}
}


