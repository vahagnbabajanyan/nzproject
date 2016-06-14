#include "stdafx.h"

int main()
{
	{
		std::vector<int> v = { 12, 5, 8, 1, 6, 4, 25, 3, 35, 14, 7, 9 };
		std::uint32_t inversions = 0;
		cormen::problems::chapter_2::naive_calculate_inversions(v, inversions);
		std::cout << "naive : " << inversions << std::endl;
	}

	{
		std::vector<int> v = { 12, 5, 8, 1, 6, 4, 25, 3, 35, 14, 7, 9 };
		std::uint32_t inversions = 0;
		cormen::problems::chapter_2::calculate_inversions(v, 0, static_cast<std::uint32_t>(v.size() - 1), inversions);
		std::cout << inversions << std::endl;
	}
}