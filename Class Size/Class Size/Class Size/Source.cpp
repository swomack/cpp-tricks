#include <iostream>

using namespace std;


class X
{
public:

	X() {}

	virtual ~X() {}

private:

	
	char b;
	
	
	int c;

	char a;
	
};


int main()
{
	X x;

	cout << sizeof(x) << endl;

	return 0;
}