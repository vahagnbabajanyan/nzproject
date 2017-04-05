#include "stdafx.h"

#include "ExercisesChapter_2.h"
#include "Sorting.h"
#include "Searching.h"

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

			int k = b;
			for (k = b; k <= e; ++k)
			{
				if (li <= m - b && ri <= e - m - 1)
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
				else if (li <= m - b)
				{
					cp = &leftc;
					ic = li;
					break;
				}
				else
				{
					cp = &rightc;
					ic = ri;
					break;
				}
			}
			for (; k <= e; ++k)
			{
				auto z = (*cp)[ic];
				c[k] = (*cp)[ic];
				++ic;
			}
		}

		// http://clrs.skanev.com/ solution
		template<typename Container>
		void merge_2(int p, int q, int r, Container& c)
		{
			int i, j, k;

			int n1 = q - p + 1;
			int n2 = r - q;

			int L[n1];
			int R[n2];

			for (i = 0; i < n1; i++)
				L[i] = c[p + i];
			for (j = 0; j < n2; j++)
				R[j] = c[q + j + 1];

			for (i = 0, j = 0, k = p; k <= r; k++) {
				if (i == n1) {
					c[k] = R[j++];
				}
				else if (j == n2) {
					c[k] = L[i++];
				}
				else if (L[i] <= R[j]) {
					c[k] = L[i++];
				}
				else {
					c[k] = R[j++];
				}
			}
		}

		template <typename Container>
		void merge_sort(std::int32_t beg, std::int32_t end, Container& c)
		{
			if (beg < end)
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
			/*
			* merge sort with no sentinel
			*/
			void Paragraf3::Ex3_2()
			{
				std::vector<int> v = { 1, 4, 3, 7, 2, 9, 6, 3, 8, 5, 1, 5, 3, 7, 8 };

				std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
				std::cout << std::endl;
				
				ex3_2::merge_sort(0, static_cast<int>(v.size()) - 1, v);

				std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
				std::cout << std::endl;
			}

			std::pair<int, int> ex_3_7(std::vector<int>& vec, int x)
			{
				cormen::sorting::merge_sort(vec, 0, vec.size() - 1);
				for (int i = 0; i < vec.size(); ++i)
				{
					auto key = x - vec[i];
					auto indx = cormen::searching::binary_search(vec, key);
					if (indx != i && indx != -1)
					{
						return std::make_pair(i, indx);
					}
				}
				return std::make_pair(-1, -1);
			}

		} //namespace chapter_2

	} // namespace exercises

} // namespace cormen