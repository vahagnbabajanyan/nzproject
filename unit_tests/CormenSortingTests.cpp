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
		return vec;
	}

	/*
	* vec should have at least 2 elements
	* TODO reimplement
	*/
	bool is_sorted(const std::vector<int>& vec)
	{
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < vec[i - 1])
			{
				return false;
			}
		}
		return true;
	}

	void print_vector(const std::vector<int>& vec)
	{
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
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
	print_vector(vec);
	cormen::sorting::merge_sort(vec, 0, static_cast<int>(vec.size()) - 1);
	print_vector(vec);
	BOOST_REQUIRE_EQUAL(is_sorted(vec), true);
}

BOOST_AUTO_TEST_CASE(MergeSortTestWithoutSentinels)
{
	auto vec = createRandomVector(20);
	print_vector(vec);
	cormen::sorting::merge_sort_no_sentinels(vec, 0, static_cast<int>(vec.size()) - 1);
	print_vector(vec);
	BOOST_REQUIRE_EQUAL(is_sorted(vec), true);
}

BOOST_AUTO_TEST_SUITE_END()
