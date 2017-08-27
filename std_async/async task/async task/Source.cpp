#include <iostream>
#include <future>
#include <async_task_library.h>



extern int fnConsoleApplication1();

using namespace std;



int main()
{
	fnConsoleApplication1();

	while (true)
	{
		cout << "L";
		this_thread::sleep_for(100ms);
	}

	return 0;
}