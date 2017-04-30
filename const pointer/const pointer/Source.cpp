#include <iostream>


using namespace std;


char* const str = "Hello";

const char* const str2 = "hell";

char* const str2 = "hell";

int main()
{
	str[0] = 'L';

	char* bb = "kkk";

	str = bb;

	return 0;
}