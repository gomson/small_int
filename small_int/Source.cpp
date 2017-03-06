#include "small_int.h"
#include <iostream>

using namespace std;

template<long long max, long long min = 0>
void print_small_int()
{
	cout << "(max=" << max << ", min=" << min << ") -> " << typeid(small_int<max, min>::v).name() << " " << sizeof(small_int<max, min>) << endl;
}

template<unsigned long long max>
void print_small_uint()
{
	cout << "max=" << max << " -> " << typeid(small_int<max>::v).name() << " " << sizeof(small_int<max>) << endl;
}

#define PRINT_TYPE_UINT(type) cout << "(" << #type << ") "; print_small_uint<numeric_limits<type>::max()>()
#define PRINT_TYPE_INT(type) cout << "(" << #type << ") "; print_small_int<numeric_limits<type>::max(), numeric_limits<type>::min()>()

int main()
{
	// unsigned
	cout << endl << "unsigned:" << endl;
	print_small_uint<1>();
	PRINT_TYPE_UINT(unsigned char);
	PRINT_TYPE_UINT(unsigned short);
	PRINT_TYPE_UINT(unsigned int);
	PRINT_TYPE_UINT(unsigned long);
	//PRINT_TYPE_UINT(unsigned long long);	// Too big for max_value

	// signed
	cout << endl << "signed:" << endl;
	print_small_int<-1, -2>();
	print_small_int<0, -1>();
	print_small_int<1, -1>();
	PRINT_TYPE_INT(char);
	PRINT_TYPE_INT(short);
	PRINT_TYPE_INT(int);
	PRINT_TYPE_INT(long);
	PRINT_TYPE_INT(long long);

	// access
	cout << endl << "access:" << endl;
	unsigned char t = 1;
	small_int<100> x(t);
	small_int<100> y = 2;
	auto z = x + y;
	cout << z << endl;

	constexpr unsigned ce = 10;
	small_int<ce> a = ce;
}