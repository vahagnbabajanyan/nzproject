#include "stdafx.h"

int main()
{
	std::vector<int> v = {1, 4, 7, 2, 9, 3, 7, 3, 8, 4, 1};

	cormen::sorting::merge_sort(0, v.size() - 1, v);

	auto result = cormen::searching::binary_search(v.begin(), v.end(), 4);

	std::cout << *result << std::endl;

}