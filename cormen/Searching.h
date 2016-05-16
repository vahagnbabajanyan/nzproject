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
			auto fail = end;
			auto result = end;

			while (begin < end)
			{
				result = begin + std::distance(begin, end) / 2;
				if (*result == value) 
				{
					return result; 
				}
				else
				{
					if (value > *result)
					{
						begin = result;
					}
					else
					{
						end = result; 
					}
				}
			}

			return end;
		}

		template <typename Container>
		typename Container::iterator binary_search(const Container& c, const typename Container::value_type& val)
		{
			return nullptr;
		}
		
		/*
		* ------------ Binary Search Sort : End ----------------------
		*/

	} // namespace sorting

} // namespace sorting

#endif // CORMEN_SEARCHING_H_20160516_1127

