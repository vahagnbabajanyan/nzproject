#include <iostream>

namespace stroustrup
{
	namespace chapter2
	{
		namespace a2_3_1
		{
			struct Vector
			{
				int sz;
				double * elem;
			};

			inline void vector_init(Vector& vec, int size)
			{
				vec.elem = new double[size];
				vec.sz = size;
			}

			inline double read_and_sum(int size)
			{
				Vector vec;
				vector_init(vec, size);
				for (int i = 0; i < size; ++i)
				{
					std::cin >> vec.elem[i];
				}

				double sum = 0;
				for (int i = 0; i != size; ++i)
				{
					std::cout << vec.elem[i] << std::endl;
					sum += vec.elem[i];
				}

				return sum;
			}

			enum Color
			{
				red
			};

			inline void foo()
			{
				int x = red;
			}
		}
	}
}