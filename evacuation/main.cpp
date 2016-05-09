#include <iostream>
#include <vector>
#include <iterator>

#include <cormen/Sorting.h>

int main()
{
	std::cout << "Evacuation Main" << std::endl;

	std::vector<int> v{10, 4, 7, 2, 8, 3, 12, 42, 5, 6, 82, 12, 22};
	cormen::sorting::merge_sort(0, v.size() - 1, v);

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}