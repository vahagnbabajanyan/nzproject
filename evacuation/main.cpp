#include "stdafx.h"

int main()
{
	std::vector<int> v = {1, 4, 7, 2, 9, 3, 7, 3, 8, 4, 1};

	cormen::sorting::insertion_sort(v);

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

}