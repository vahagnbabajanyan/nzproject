#include "stdafx.h"
#include <functional>
#include <boost_tutorials/DateTime.h>

void runner(std::function<void()> func)
{
	func();
}

int main()
{
	// std::cout << "Tests Change" << std::endl;
	//concurrency::basics::launching_threads();
	boost_tutorial::date_time::test_ptime_creations();

}