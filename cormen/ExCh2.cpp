#include "stdafx.h"
#include "ExCh2.hpp"

namespace cormen
{

	namespace execrises
	{

		namespace chapter_2
		{
			template void InsertionSort_NonIncreasing::InsertionSort(std::vector<int>& cont);

			template <typename Cont>
			void InsertionSort_NonIncreasing::InsertionSort(Cont& cont)
			{
				for (int i = 1; i < cont.size(); ++i)
				{
					auto key = cont[i];
					auto j = i - 1;
					while (j >= 0 && key > cont[j])
					{
						cont[j + 1] = cont[j];
						--j;
					}
					cont[j + 1] = key;
				}
			}

		} // namespace chapter_2

	} // namespace exercises

} // namespace cormen