#include "stdafx.h"
#include "NativeEmp.h"


NativeEmp::NativeEmp()
{
}


NativeEmp::~NativeEmp()
{
}

void NativeEmp::ReplaceNames()
{
	char* pBuf = name;
	name = adress;
	adress = pBuf;
	int n = 1;

}
