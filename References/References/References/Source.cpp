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

	B(B& a)
	{
		cout << "Copy constructor" << endl;
	}

	void copy(A& a)
	{
		a.change(10);
	}
};


B get_bb()
{
	B b;
	return b;
}

int main()
{
	B b;

	// passing r-value in a l-value reference in visual studio update-2 is valid
	b.copy(A(20));

	// both of the case the copy constructor is called, r-value and l-value case
	B bb = get_bb();
	B bbb = b;

	getchar();

	return 0;
}