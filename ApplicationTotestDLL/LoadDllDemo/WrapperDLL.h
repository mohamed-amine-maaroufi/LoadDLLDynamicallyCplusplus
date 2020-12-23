#pragma once
#include "dllMain.h"
#include <windows.h>

class WrapperDLL
{
protected:
	static WrapperDLL* m_oStub;

	HINSTANCE m_hGetProcIDDLL;
	CLIENT_MESSAGE m_pfMessage;
	CLIENT_FunctionXX m_pfFunctionXX;
	bool m_bInitialised;
	

protected:
	WrapperDLL();
	~WrapperDLL();

	bool init();
	void close();
	void clear();

private:
	WrapperDLL(const WrapperDLL&);
	WrapperDLL& operator=(const WrapperDLL&);

public:
	static WrapperDLL* createInstance();
	static void destroyInstance();
	int clientMessage();


};

