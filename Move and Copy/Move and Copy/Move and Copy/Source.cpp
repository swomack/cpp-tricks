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

	A(A&& other)
	{
		cout << "Move constructor: A" << endl;
	}
};

class B 
{
public:

	A a;

	B()
	{
		cout << "Constructor: B" << endl;
	}

	B(const B& ref) : a(ref.a)
	{
		cout << "Copy constructor: B" << endl;
	}

	// important: we need to use move here
	B(B&& other) : a(move(other.a))
	{
		cout << "Move constructor: B" << endl;
	}

};

B get_object()
{
	B b;
	return b;
}

int main()
{
	// constructor of A and B
	B b;

	// copy constructor of A and B
	B bb = b;

	// There is a move constructor of B, so it will be called
	// From there, the move constructor of A will be called
	B bbb = move(b);


	// There is a move constructor of B, so it will be called
	// From there, the move constructor of A will be called
	B bbbb = get_object();

	getchar();
	return 0;
}
