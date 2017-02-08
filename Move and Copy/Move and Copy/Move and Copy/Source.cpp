#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class A 
{
public:
	A()
	{
		cout << "Constructor: A" << endl;
	}

	A(const A& ref)
	{
		cout << "Copy constructor: A" << endl;
	}
};


class B
{
public:
	B()
	{
		cout << "Constructor: B" << endl;
	}

	B(const B& ref)
	{
		cout << "Copy constructor: B" << endl;
	}

	A a;
};

class C
{
public:

	C()
	{
		cout << "Constructor: C" << endl;
	}


	A a;
};


B get_b_object()
{
	B b;
	return b;
}

C get_c_object()
{
	C c;
	return c;
}

int main()
{
	// Copy constructor calls is recusrive from default copy constructor

	// copy constructor and constructor behavior when return from function
	B b = get_b_object();

	// copy constructor and constructor behavior when return from function
	C c = get_c_object();

	getchar();
	return 0;
}
