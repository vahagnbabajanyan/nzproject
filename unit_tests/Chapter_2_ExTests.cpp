#include "stdafx.h"

namespace
{
	std::vector<int> createRandomVector(std::uint16_t size)
	{
		std::vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			vec.push_back(20 - i);
		}
		vec[5] = 50;
		vec[10] = 25;
		vec[14] = 50;
		vec[15] = 130;
		// 130, 50, 25, 20, 19, 18, 17, 16, 50, 14, 13, 12 , 11, 9, 8, 7, 4, 3, 2, 1
		return vec; 
	}
}

BOOST_AUTO_TEST_SUITE(Chepter_2_Ex_Tests)

BOOST_AUTO_TEST_CASE(Ex_2_3_7)
{
	auto vec = createRandomVector(20);
	auto pp = cormen::execrises::chapter_2::ex_3_7(vec, 9);
	BOOST_REQUIRE_EQUAL(0, pp.first);
	BOOST_REQUIRE_EQUAL(5, pp.second);
	BOOST_REQUIRE_EQUAL(vec[pp.first] + vec[pp.second], 9);
}

BOOST_AUTO_TEST_SUITE_END()
