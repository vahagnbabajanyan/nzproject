#ifndef CORMEN_SORTING_H_20160507_1124
#define CORMEN_SORTING_H_20160507_1124

#include "stdafx.h"
#include <iostream>

namespace cormen
{

	namespace sorting
	{

		/*
		*  ----------- Merge Sort : Begin ------------------
		*/
		template <typename Container>
		void merge(int beg, int mid, int end, Container& c)
		{

		}

		template <typename Container>
		void merge_sort(int beg, int end, Container& c)
		{
			if (beg < end)
			{
				int mid = (beg + end) / 2;
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

