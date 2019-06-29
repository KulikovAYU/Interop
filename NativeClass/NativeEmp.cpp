#include "stdafx.h"
#include "NativeEmp.h"


NativeEmp::NativeEmp()
{
}


NativeEmp::~NativeEmp()
{
}

void NativeEmp::ChangeValues()
{
	char* pBuf = name;
	name = adress;
	adress = pBuf;
	zipCode += 100;

}
