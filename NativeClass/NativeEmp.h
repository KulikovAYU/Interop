#pragma once
struct _declspec(dllexport) NativeEmp
{
	char* name;
	char* adress;
	int zipCode;

	NativeEmp();
	~NativeEmp();
};

