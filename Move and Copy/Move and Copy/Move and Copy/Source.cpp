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
		s = "Hello";
	}

	A(const A& ref)
	{
		cout << "Copy constructor: A" << endl;
		s = ref.s;
	}

	A(A&& other)
	{
		cout << "Move constructor: A" << endl;
		s = move(other.s);
	}

	string s;
};



int main()
{
	A a;

	// call the copy constructor
	A aa = a;

	cout << a.s << endl;
	a.s[0] = 'L';
	cout << aa.s << endl;

	// call the move constructor if there is any
	// if there is no move constructor, copy constructor will be called
	A aaa = move(a);
	cout << aaa.s << endl;
	// after move, 'a' will be unusable(empty)
	a.s[0] = 'H';
	cout << a.s << endl;

	getchar();
	return 0;
}
