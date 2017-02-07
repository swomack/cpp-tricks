#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class copy_cls
{
public:

	char* str;
	string sstr;

	copy_cls()
	{
		str = new char[10];
		strcpy(str, "Hello");
		sstr = "Hello";
		cout << "Constructor called" << endl;
	}

	void print_string()
	{
		cout << str << endl;
	}

	void print_sstr()
	{
		cout << sstr << endl;
	}
};

int main()
{
	copy_cls a;

	// Only the default copy constructor will be called
	// default copy constructor does a member wise copy
	// so a pointer will be copied, not the contents

	// string will be copied since it is a STL class and it has its own copy constructor which will be called during memberwise copy
	// in its copy constructor, it copies content
	copy_cls b = a;

	cout << "Before Modification:" << endl;
	
	// char string
	a.print_string();
	b.print_string();

	// string
	a.print_sstr();
	b.print_sstr();
	
	// both class a.str and b.str content will be modified.
	a.str[0] =  'L';

	// b's vector wont be modified 
	a.sstr[0] = 'L';

	cout << "After Modification:" << endl;
	
	// string
	a.print_string();
	b.print_string();

	// string
	a.print_sstr();
	b.print_sstr();


	getchar();
	return 0;
}
