#ifndef CORMEN_SEARCHING_H_20160516_1127
#define CORMEN_SEARCHING_H_20160516_1127

#include "stdafx.h"
#include <iostream>

namespace cormen
{

	namespace searching
	{

		/*
		*  ----------- Binary Search : Begin ------------------
		*/

		template <typename ForwardIterator, typename ValueType>
		ForwardIterator binary_search(ForwardIterator begin, ForwardIterator end, const ValueType& value)
		{
			auto mid = end;

			while (begin < end)
			{
				mid = begin + std::distance(begin, end) / 2;
				if (*mid == value)
				{
					return mid;
				}
				else
				{
					if (value > *mid)
					{
						begin = mid;
					}
					else
					{
						end = mid;
					}
				}
			}

			return end;
		}

		template <typename Conteiner>
		int binary_search(const Conteiner& cont, const typename Conteiner::value_type& key)
		{
			int first = 0;
			int last = static_cast<int>(cont.size() - 1);
			while (first <= last)
			{
				auto mid = (first + last) / 2;
				if (cont[mid] == key)
				{
					return mid;
				}
				if (cont[mid] < key)
				{
					first = mid + 1;
				}
				else
				{
					last = mid - 1;
				}
			}
			return -1;
		}
		
		/*
		* ------------ Binary Search Sort : End ----------------------
		*/

	} // namespace sorting

} // namespace sorting

#endif // CORMEN_SEARCHING_H_20160516_1127

