#ifndef CORMENLIB_PROBLEMS_CHAPTER_2_H
#define CORMENLIB_PROBLEMS_CHAPTER_2_H

#include <cstdint>
#include <algorithm>

namespace cormen
{

	namespace problems
	{

		namespace chapter_2
		{

			// Number of inversions in O(nlgn)
			template <typename Container>
			void calculate_inversions(Container& c, std::int32_t p, std::int32_t q, std::int32_t r, std::uint32_t& inversions)
			{
				std::uint32_t left_size = q - p + 1;

				Container leftc(q - p + 1);
				Container rightc(r - q);

				std::copy(c.begin() + p, c.begin() + q + 1, leftc.begin());
				std::copy(c.begin() + q + 1, c.begin() + r + 1, rightc.begin());

				leftc.push_back(std::numeric_limits<typename Container::value_type>::max());
				rightc.push_back(std::numeric_limits<typename Container::value_type>::max());

				int li = 0;
				int ri = 0;

				int count = 0;
				for (std::uint32_t k = p; k < r + 1u; ++k)
				{
					if (rightc[ri] < leftc[li])
					{
						c[k] = rightc[ri];
						if (leftc[li] != std::numeric_limits<typename Container::value_type>::max()) 
						{
							++count;
						}
						++ri;
					}
					else
					{
						c[k] = leftc[li];
						inversions += count * (left_size - li);
						++li;
						count = 0;
					}
				}
			}

			template <typename Container>
			void calculate_inversions(Container& c, std::int32_t p, std::int32_t r, std::uint32_t& inversions)
			{
				if (p < r)
				{
					auto q = (p + r) / 2;
					calculate_inversions(c, p, q, inversions);
					calculate_inversions(c, q + 1, r, inversions);
					calculate_inversions(c, p, q, r, inversions);
				}
			}


			// Number of inversions in O(n * n)
			template <typename Container>
			void naive_calculate_inversions(const Container& c, std::uint32_t& inversions)
			{
				for (std::uint32_t i = 0; i < c.size() - 1; ++i)
				{
					for (auto j = i + 1; j < c.size(); ++j)
					{
						if (c[i] > c[j]) inversions++;
					}
				}
			}

		} // namespace chapter_2

	} // namespace problems

} // namespace cormen

#endif//CORMENLIB_PROBLEMS_CHAPTER_2_H