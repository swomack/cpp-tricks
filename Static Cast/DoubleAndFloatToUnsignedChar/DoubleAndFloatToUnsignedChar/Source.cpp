#include <iostream>

using namespace std;


int main()
{
	double value_d = 1.0;

	unsigned char value_uc_d = (unsigned char)(255.0 * value_d);


	float value_f = 1.0;
	unsigned char value_uc_f = (unsigned char)(255.0 * value_f);

	printf("%d %d\n", value_uc_d, value_uc_f);

	return 0;
}