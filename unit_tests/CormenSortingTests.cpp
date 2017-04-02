#include "stdafx.h"

namespace
{
	std::vector<int> createRandomVector(std::uint16_t size)
	{
		std::vector<int> vec;
		return vec;
	}

	bool is_sorted(const std::vector<int>& vec)
	{
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] > vec[i - 1])
			{
				return false;
			}
		}
		return true;
	}

	bool is_reverse_sorted(const std::vector<int>& vec)
	{
		return false;
	}
}

BOOST_AUTO_TEST_SUITE(CormenSortingTests)

BOOST_AUTO_TEST_CASE(MergeSortTest)
{
	auto vec = createRandomVector(20);
	cormen::sorting::merge_sort(vec, 0, static_cast<int>(vec.size()) - 1);
	BOOST_REQUIRE_EQUAL(is_sorted(vec), true);
}

BOOST_AUTO_TEST_SUITE_END()
