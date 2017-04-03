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
		void merge(Container& cont, int p, int q, int r)
		{
			int nl = q - p + 1;
			int nr = r - q;
			Container left(nl + 1);
			Container right(nr + 1);

			for (int i = 0; i < nl; ++i)
			{
				left[i] = cont[p + i];
			}
			left[nl] = std::numeric_limits<typename Container::value_type>::max();

			for(int i = 0; i < nr; ++i)
			{
				right[i] = cont[q + 1 + i];
			}
			right[nr] = std::numeric_limits<typename Container::value_type>::max();

			int indx_l = 0;
			int indx_r = 0;
			for (int i = p; i <= r; ++i)
			{
				if (left[indx_l] < right[indx_r])
				{
					cont[i] = left[indx_l];
					++indx_l;
				}
				else
				{
					cont[i] = right[indx_r];
					++indx_r;
				}
			}
		}

		/*
		* !Container reference to be sort in place
		* !int p begin of container
		* !int r end of container
		*/
		template <typename Container>
		void merge_sort(Container& cont, int p, int r)
		{
			if (p < r)
			{
				int q = (p + r) / 2;
				merge_sort(cont, p, q);
				merge_sort(cont, q + 1, r);
				merge(cont, p, q, r);
			}
		}


		template <typename Container>
		void merge_no_sentinels(Container& cont, int p, int q, int r)
		{
			int nl = q - p + 1;
			int nr = r - q;
			Container left(nl);
			Container right(nr);

			for (int i = 0; i < nl; ++i)
			{
				left[i] = cont[p + i];
			}
			for (int i = 0; i < nr; ++i)
			{
				right[i] = cont[q + 1 + i];
			}

			int indx_l = 0;
			int indx_r = 0;
			for (int i = p; i <= r; ++i)
			{
				if (indx_l >= nl)
				{
					cont[i] = right[indx_r];
					++indx_r;
				}
				else if (indx_r >= nr)
				{
					cont[i] = left[indx_l];
					++indx_l;
				}
				else if (left[indx_l] < right[indx_r])
				{
					cont[i] = left[indx_l];
					++indx_l;
				}
				else
				{
					cont[i] = right[indx_r];
					++indx_r;
				}
			}
		}

		/*
		* !Container reference to be sort in place
		* !int p begin of container
		* !int r end of container
		*/
		template <typename Container>
		void merge_sort_no_sentinels(Container& cont, int p, int r)
		{
			if (p < r)
			{
				int q = (p + r) / 2;
				merge_sort_no_sentinels(cont, p, q);
				merge_sort_no_sentinels(cont, q + 1, r);
				merge_no_sentinels(cont, p, q, r);
			}
		}















		//template <typename Container>
		//void merge(std::uint32_t beg, std::uint32_t mid, std::uint32_t end, Container& c)
		//{
		//	Container leftc(mid - beg + 2);
		//	Container rightc(end - mid + 1);
		//
		//	std::copy(c.begin() + beg, c.begin() + mid + 1, leftc.begin());
		//	std::copy(c.begin() + mid + 1, c.begin() + end + 1, rightc.begin());
		//
		//	leftc[leftc.size() - 1] = std::numeric_limits<typename Container::value_type>::max();
		//	rightc[rightc.size() - 1] = std::numeric_limits<typename Container::value_type>::max();
		//
		//	int li = 0;
		//	int ri = 0;
		//	for (std::uint32_t i = beg; i <= end; ++i)
		//	{
		//		if (leftc[li] < rightc[ri])
		//		{
		//			c[i] = leftc[li];
		//			++li;
		//		}
		//		else
		//		{
		//			c[i] = rightc[ri];
		//			++ri;
		//		}
		//	}
		//
		//}
		//
		//template <typename Container>
		//void merge_sort(std::uint32_t beg, std::uint32_t end, Container& c)
		//{
		//	if (beg < end)
		//	{
		//		std::uint32_t mid = (beg + end) / 2;
		//		merge_sort(beg, mid, c);
		//		merge_sort(mid + 1, end, c);
		//		merge(beg, mid, end, c);
		//	}
		//}
		/*
		* ----------- Merge Sort : End ----------------------
		*/






	} // namespace sorting

} // namespace sorting

#endif

