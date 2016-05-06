#include <iostream>
#include <vector>

#include <cormen/Sorting.h>

int main()
{
	std::cout << "Evacuation Main" << std::endl;

	std::vector<int> v;
	cormen::sorting::merge_sort(0, v.size(), v);
}