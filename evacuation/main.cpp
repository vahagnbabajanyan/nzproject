#include "stdafx.h"
#include <functional>
#include <boost_tutorials/DateTime.h>

#include <stroustrup/ch_2_3_1.hpp>

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

int main()
{
	// std::cout << "Tests Change" << std::endl;
	//concurrency::basics::launching_threads();
	//boost_tutorial::date_time::test_ptime_creations();

	//stroustrup::chapter2::a2_3_1::read_and_sum(10);

	test x(10);
	(x += test(10)) += test(100);
	std::cout << x << std::endl;

}