#ifndef CORMEN_SORTING_H_20160507_1124
#define CORMEN_SORTING_H_20160507_1124

#include "stdafx.h"
#include <iostream>

namespace cormen
{

	namespace sorting
	{

		/*
		* ---------- Bubble Sort : Begin ----------------
		*/

		template <typename Container>
		void bubble_sort(Container& c)
		{
			auto size = c.size();

			for (std::uint32_t i = 0; i < size - 1; ++i)
			{
				for (std::uint32_t j = 0; j < size - 1 - i; ++j)
				{
					if (c[j] > c[j + 1])
					{
						typename Container::value_type tmp = c[j];
						c[j] = c[j + 1];
						c[j + 1] = tmp;
					}
				}
			}
		}

		/*
		* -----------  Bubble Sort : End ----------------
		*/


		/*
		* ---------- Insertion Sort : Begin ----------------
		*/
		template <typename Container>
		void insertion_sort(Container& c)
		{
			for (int i = 1; i < c.size(); ++i)
			{
				int key = c[i];
				int j = i - 1;

				while (j >= 0 && key < c[j])
				{
					c[j + 1] = c[j];
					--j;
				}
				c[j + 1] = key;
			}
		}
		/*
		* ---------- Insertion Sort : end ------------------
		*/





		/*
		*  ----------- Merge Sort : Begin ------------------
		*/
		template <typename Container>
		void merge(std::uint32_t beg, std::uint32_t mid, std::uint32_t end, Container& c)
		{
			Container leftc(mid - beg + 2);
			Container rightc(end - mid + 1);

			std::copy(c.begin() + beg, c.begin() + mid + 1, leftc.begin());
			std::copy(c.begin() + mid + 1, c.begin() + end + 1, rightc.begin());

			leftc[leftc.size() - 1] = std::numeric_limits<typename Container::value_type>::max();
			rightc[rightc.size() - 1] = std::numeric_limits<typename Container::value_type>::max();

			int li = 0;
			int ri = 0;
			for (std::uint32_t i = beg; i <= end; ++i)
			{
				if (leftc[li] < rightc[ri])
				{
					c[i] = leftc[li];
					++li;
				}
				else
				{
					c[i] = rightc[ri];
					++ri;
				}
			}

		}

		template <typename Container>
		void merge_sort(std::uint32_t beg, std::uint32_t end, Container& c)
		{
			if (beg < end)
			{
				std::uint32_t mid = (beg + end) / 2;
				merge_sort(beg, mid, c);
				merge_sort(mid + 1, end, c);
				merge(beg, mid, end, c);
			}
		}
		/*
		* ----------- Merge Sort : End ----------------------
		*/






	} // namespace sorting

} // namespace sorting

#endif

