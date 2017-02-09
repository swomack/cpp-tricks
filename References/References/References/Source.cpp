#include <iostream>
#include <memory>


using namespace std;


class A
{
public:
	A()
	{
		cout << "Ctor: A" << endl;
	}

	A(const A&)
	{
		cout << "Copy Ctor: A" << endl;
	}

	~A()
	{
		cout << "Dtor: A" << endl;
	}
};


class B
{
public:

	B(A& arg) : a(arg)
	{
		cout << "Ctor: B" << endl;
	}

	B(const B&)
	{
		cout << "Copy Ctor: B" << endl;
	}

	~B()
	{
		cout << "Dtor: B" << endl;
	}


	A a;
};


template<typename T, typename Arg>
shared_ptr<T> factory(Arg arg)
{
	return shared_ptr<T>(new T(arg));
}

int main()
{
	shared_ptr<B> b = factory<B>(A());


	getchar();

	return 0;
}