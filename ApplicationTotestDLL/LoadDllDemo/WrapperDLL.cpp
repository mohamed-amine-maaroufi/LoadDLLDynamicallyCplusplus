#include "WrapperDLL.h"
#include <iostream>


using namespace std;

WrapperDLL* WrapperDLL::m_oStub = nullptr;

WrapperDLL::WrapperDLL() :m_hGetProcIDDLL(NULL), m_bInitialised(false)
{
	clear();
	init();
}

WrapperDLL::~WrapperDLL()
{
	close();
}

WrapperDLL* WrapperDLL::createInstance()
{
	if (m_oStub == nullptr)
	{
		m_oStub = new WrapperDLL();
	}
	return m_oStub;
}

void WrapperDLL::destroyInstance()
{
	if (m_oStub != nullptr)
	{
		delete m_oStub;
		m_oStub = nullptr;
	}
}

bool WrapperDLL::init()
{
	m_hGetProcIDDLL = LoadLibrary(TEXT("..\\..\\DemoDLL\\Release\\DemoDLL.dll"));
	if (!m_hGetProcIDDLL) {
		std::cout << "could not load the dynamic library" << std::endl;
		m_bInitialised = false;
	}
	else
	{
		// resolve function address here
		m_pfMessage = (CLIENT_MESSAGE)GetProcAddress(m_hGetProcIDDLL, "clientMessage");
		m_pfFunctionXX = (CLIENT_FunctionXX)GetProcAddress(m_hGetProcIDDLL, "clientFunctionXX");
		m_bInitialised = true;
	}

	return m_bInitialised;
}


void WrapperDLL::clear()
{
	m_pfMessage = NULL;
	m_pfFunctionXX = NULL;
}


void WrapperDLL::close()
{
	FreeLibrary(m_hGetProcIDDLL);
	clear();
}

int WrapperDLL::clientMessage()
{

	int l_iRet = -1;

	if (m_bInitialised)
	{		
		l_iRet = m_pfMessage();		
	}

	return l_iRet;
}



