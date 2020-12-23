#include <iostream>
#include "WrapperDLL.h"

int main()
{
	
	int i_lRet = WrapperDLL::createInstance()->clientMessage();

	if (i_lRet <= 0)
	{
		std::cout << "call clientMessage from dll failed" << std::endl;
	}

	
	WrapperDLL::destroyInstance();
}


