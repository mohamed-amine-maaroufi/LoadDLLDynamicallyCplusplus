#include "pch.h"
#include "C_ClassWillBeExported.h"
#include <iostream>

using namespace std;


void C_ClassWillBeExported::message()
{
	cout << "hello world !!!" << endl;
}

int C_ClassWillBeExported::functionXX()
{
	cout << "other function to export" << endl;

	return 0;
}

C_ClassWillBeExported& C_ClassWillBeExported::createInstance()
{
	static C_ClassWillBeExported s_oInstance;

	return s_oInstance;
}
