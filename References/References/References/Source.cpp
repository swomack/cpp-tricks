#include <iostream>


using namespace std;


class A
{
public:
	A(int k) : x(k)
	{

	}

	void change(int a)
	{
		x = a;
	}

	int x;
};


class B
{
public:

	B()
	{

	}

	void copy(A& a)
	{
		a.change(10);
	}
};

int main()
{
	B b;

	// passing r-value in a l-value reference in visual studio update-2 is valid
	b.copy(A(20));
	return 0;
}