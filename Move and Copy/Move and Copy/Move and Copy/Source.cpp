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

int main()
{
	// both constructor called
	B b;


	// Copy constructor of B and Constructor of A
	B bb = b;


	// Both constructor called
	C c;



	// Both copy constructor called, cause in default copy cosntructor compiler add code to call the copy constructor of A with ref.a
	C cc = c;

	getchar();
	return 0;
}
