


#define DLL_MAIN_EXPORT __declspec( dllexport )

extern "C"
{
	DLL_MAIN_EXPORT void clientMessage();
	DLL_MAIN_EXPORT int clientFunctionXX();


	typedef int(*CLIENT_MESSAGE)();
	typedef int(*CLIENT_FunctionXX)();
}