#ifndef CORMENLIB_EXERCISES_CH2_H
#define CORMENLIB_EXERCISES_CH2_H

namespace cormen
{

	namespace execrises
	{

		namespace chapter_2
		{

			class InsertionSort_NonIncreasing
			{
			public:
				template <typename Cont>
				static void InsertionSort(Cont& cont);

				
			};

			class Adding_N_BIT_Numbers
			{
			public:
				template <int N>
				static std::array<bool, N + 1> sum(const std::array<bool, N>& a1, const std::array<bool, N>& a2)
				{
					std::array<bool, N + 1> c;

					bool k = 0;

					for (int i = a1.size() - 1; i >= 0; --i)
					{
						c[i + 1] = (a1[i] ^ a2[i]) ^ k;
						k = (a2[i] & k) | (a1[i] & (a2[i] | k));
					}
					c[0] = k;

					return c;
				}
			};

		} // namespace chapter_2

	} // namespace execrises

} // namespace cormen

#endif