#include "stdafx.h"
#include <functional>
#include <boost_tutorials/DateTime.h>
#include <typeinfo>

#include <stroustrup/ch_2_3_1.hpp>
#include <cormen/ExCh2.hpp>

void runner(std::function<void()> func)
{
	func();
}

class test
{
private:
	friend std::ostream& operator<<(std::ostream&, const test&);

public:
	explicit test(int init) : _memb(init) {}

	test& operator+=(const test& other)
	{
		_memb += other._memb;
		return *this;
	}
private:
	int _memb;
};

std::ostream& operator<<(std::ostream& os, const test& obj)
{
	return os << obj._memb;
}

template <int N>
void print(const std::array<bool, N>& arr)
{
	for (auto v: arr)
	{
		std::cout << v;
	}
	std::cout << std::endl;
}

class TestA
{
public:
	virtual ~TestA()
	{
		
	}
};

TestA copyTestA()
{
	TestA a;
	return a;
}

int main()
{
	//{
	//	std::array<bool, 1> a1 = { 1 };
	//	std::array<bool, 1> a2 = { 1 };
	//	auto c = cormen::execrises::chapter_2::Adding_N_BIT_Numbers::sum(a1, a2);
	//	print(a1);
	//	print(a2);
	//	print(c);
	//}
	//
	//{
	//	std::array<bool, 2> a1 = { 0, 1 };
	//	std::array<bool, 2> a2 = { 1, 0 };
	//	auto c = cormen::execrises::chapter_2::Adding_N_BIT_Numbers::sum(a1, a2);
	//	print(a1);
	//	print(a2);
	//	print(c);
	//}
	//
	//{
	//	std::array<bool, 3> a1 = { 1, 0, 1 };
	//	std::array<bool, 3> a2 = { 1, 0, 1 }; //        1010
	//	auto c = cormen::execrises::chapter_2::Adding_N_BIT_Numbers::sum(a1, a2);
	//	print(a1);
	//	print(a2);
	//	print(c);
	//}

	auto a = copyTestA();

}