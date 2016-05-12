#include "stdafx.h"

#include "ExercisesChapter_2.h"

namespace
{
	namespace ex3_2
	{
		template <typename Container>
		void merge(std::int32_t b, std::int32_t m, std::int32_t e, Container& c)
		{
			Container leftc(m - b + 1);
			Container rightc(e - m);

			std::copy(c.begin() + b, c.begin() + m + 1, leftc.begin());
			std::copy(c.begin() + m + 1, c.begin() + e + 1, rightc.begin());

			std::int32_t li = 0, ri = 0;

			Container *cp = nullptr;
			int ic = -1;
			int ec = -2;

			for (int k = b; k <= e; ++k)
			{
				if (li <= m - b + 1 && ri <= e - b)
				{
					if (leftc[li] < rightc[ri])
					{
						c[k] = leftc[li];
						++li;
					}
					else
					{
						c[k] = rightc[ri];
						++ri;
					}
				}
				else if (li <= m - b + 1)
				{
					cp = &rightc;
					ic = ri;
					ec = m - b + 1;
					break;
				}
				else
				{
					cp = &leftc;
					ic = li;
					ec = e - m;
					break;
				}
			}
			for (int k = ic; k <= ec; ++k)
			{
				c[k] = (*cp)[ic];
			}
		}

		template <typename Container>
		void merge_sort(std::int32_t beg, std::int32_t end, Container& c)
		{
			if (beg >= end)
			{
				auto mid = (beg + end) / 2;
				merge_sort(beg, mid, c);
				merge_sort(mid + 1, end, c);
				merge(beg, mid, end, c);
			}
		}

	} // namespace ex3_2

} // anonymous namespace

namespace cormen
{

	namespace execrises
	{

		namespace chapter_2
		{
			
			void Paragraf3::Ex3_2()
			{
				std::vector<int> v = { 1, 4, 3, 7, 2, 9, 6, 3, 8, 5, 1, 5, 3, 7, 8 };
				
				ex3_2::merge_sort(0, v.size() - 1, v);

				std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
			}

		} //namespace chapter_2

	} // namespace exercises

} // namespace cormen