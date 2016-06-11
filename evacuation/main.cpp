#include "stdafx.h"

int main()
{
	std::vector<int> coefficients = {2, 4, 5, 1};
	int x = 3;
	if (cormen::problems::polynomial_naive_calculation(coefficients, x) == cormen::problems::polynomial_horners_calculation(coefficients, x))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "DUMMY" << std::endl;
	}

}