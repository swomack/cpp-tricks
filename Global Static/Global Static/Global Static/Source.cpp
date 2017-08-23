#include <iostream>

using namespace std;


// static object get destroyed after exiting the program
// even if the static object is a class member and the parent object gets destroyed way earlier 

class AA
{
	int x;
public:

	AA()
	{
		x = 10;
		cout << "Constructor A" << endl;
	}

	~AA()
	{
		cout << "Destructor A" << endl;
	}

	int get_val()
	{
		return x;
	}

};



class B
{
	static AA a;

public:

	B()
	{
		cout << "Constructor B" << endl;
	}


	~B()
	{
		cout << "Destructor B" << endl;
	}

	static void print()
	{
		cout << a.get_val() << endl;
	}
};

AA B::a = AA();


void nothing()
{
	B b;
	b.print();
}

int main()
{
	nothing();
	return 0;
}