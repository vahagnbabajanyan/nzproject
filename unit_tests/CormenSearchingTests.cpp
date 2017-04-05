#include "stdafx.h"

namespace
{
	std::vector<int> createSortedVector(std::uint16_t size)
	{
		std::vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			vec.push_back(i * 2);
		}
		return vec;
	}

	void print_vector(const std::vector<int>& vec)
	{
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE(CormenSearchingTests)

BOOST_AUTO_TEST_CASE(BinarySearchTest)
{
	auto vec = createSortedVector(20);
	auto indx = cormen::searching::binary_search(vec, 10);
	BOOST_REQUIRE_EQUAL(5, indx);

	auto indx1 = cormen::searching::binary_search(vec, 20);
	BOOST_REQUIRE_EQUAL(10, indx1);

	auto indx2 = cormen::searching::binary_search(vec, 100);
	BOOST_REQUIRE_EQUAL(-1, indx2);

	auto indx3 = cormen::searching::binary_search(vec, 15);
	BOOST_REQUIRE_EQUAL(-1, indx3);
}

BOOST_AUTO_TEST_SUITE_END()
