#include <iostream>


using namespace std;

class A
{

public:

	int value;

	A()
	{
		cout << "Constructor!" << endl;
	}

	~A()
	{
		cout << "Destructor!" << endl;
	}

	A(const A& c)
	{
		cout << "Copy constructor!" << endl;
	}
};


A bar()
{
	A a;
	a.value = 10;
	return a;
}


A foo(int c, int d)
{
	A a = A();
	A b = A();

	if (c < d)
		return a;

	return b;
}


int main()
{
	// RVO : only a constructor and destructor call
	A d = bar();

	// no RVO:: not possible for compiler
	A e = foo(100, 200);
	return 0;
}

