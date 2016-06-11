#ifndef CORMEN_HORNERS_RULE_H_20160611_1447
#define CORMEN_HORNERS_RULE_H_20160611_1447

#include <cstdint>

namespace cormen
{

	namespace problems
	{
		// Horner's rule polynomial evaluation. Worst case TETTA(n)
		int polynomial_horners_calculation(const std::vector<int>& coefficients, int x)
		{
			int result = 0;
			for (int i = static_cast<int>(coefficients.size() - 1); i >= 0; --i)
			{
				result = coefficients[i] + result * x;
			}

			return result;
		}

		// Naive polynomial evaluation worst case TETTA(n * n)
		int polynomial_naive_calculation(const std::vector<int>& coefficients, int x)
		{
			int result = 0;
			for (std::uint32_t i = 0; i < coefficients.size(); ++i)
			{
				int exp = coefficients[i];
				for (std::uint32_t j = 0; j < i; ++j)
				{
					exp *= x;
				}
				result += exp;
			}

			return result;
		}
	}

}

#endif//CORMEN_HORNERS_RULE_H_20160611_1447