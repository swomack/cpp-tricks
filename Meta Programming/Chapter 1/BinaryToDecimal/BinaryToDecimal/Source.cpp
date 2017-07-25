#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template<unsigned long N>
class binary_to_decimal
{
public:
	static const unsigned long value = (binary_to_decimal<N / 10>::value << 1) + (N % 10);
};

template<>
class binary_to_decimal<0>
{
public:
	static const unsigned long value = 0;
};

int main()
{
	constexpr int value = binary_to_decimal<101>::value;

	static_assert(value == 5, "mismatched");

	return 0;
}