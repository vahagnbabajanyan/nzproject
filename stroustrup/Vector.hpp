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
			explicit Vector(int size);
			Vector(std::initializer_list<double>);

			Vector(const Vector& other);
			Vector& operator=(const Vector& other);

			// && means rvalue reference
			Vector(Vector&& other);
			Vector& operator=(Vector&& other);

			void push_back(double);

		private:
			double* _elems;
			int _size;
		};

	} // namespace tutorial

} // namespace stroustrup

#endif