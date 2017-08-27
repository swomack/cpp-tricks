// ConsoleApplication1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "async_task_library.h"
#include <iostream>
#include "future"

using namespace std;

struct
{
	future<int> value;

	int get()
	{
		return value.get();
	}

}async_res;


// This is an example of an exported variable
CONSOLEAPPLICATION1_API int nConsoleApplication1=0;

// This is an example of an exported function.
CONSOLEAPPLICATION1_API int fnConsoleApplication1(void)
{
	auto f = []() {
		while (true)
		{
			cout << "H";
			this_thread::sleep_for(100ms);
		}
		return 1;
	};

	async_res.value = async(launch::async, f);
	return 1;
}

// This is the constructor of a class that has been exported.
// see ConsoleApplication1.h for the class definition
CConsoleApplication1::CConsoleApplication1()
{
    return;
}
