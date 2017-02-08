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

	/*B(const B& ref)
	{
		cout << "Copy constructor: B" << endl;
	}*/

	/*B(B&& other)
	{
		cout << "Move constructor: B" << endl;
	}*/

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

	// If there is no copy constructor, then defualt move constructor of B will be called
	// which will call the move constructor A
	B bbb = move(b);


	// If there is no copy constructor then move constructor of B will be called 
	// which will call the move constructor of A
	B bbbb = get_object();

	getchar();
	return 0;
}
