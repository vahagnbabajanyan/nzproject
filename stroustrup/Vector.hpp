#ifndef STR_VECTOR_H
#define STR_VECTOR_H

#include <initializer_list>

namespace stroustrup
{

	namespace tutorial
	{

		class Vector
		{
		public:
			Vector(std::initializer_list<double>);

			void push_back(double);

		private:
			double* _elems;
			int _size;
		};

	} // namespace tutorial

} // namespace stroustrup

#endif