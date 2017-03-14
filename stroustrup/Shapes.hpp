#ifndef STR_SHAPES_HPP
#define STR_SHAPES_HPP

#include <initializer_list>

namespace stroustrup
{

	namespace tutorial
	{
		class Point{};

		class Shape
		{
		public:
			virtual Point center() const = 0;

			virtual void move(Point to) = 0;

			virtual void draw() = 0;

			virtual void rotate(int angle) = 0;

			virtual ~Shape()
			{}
		};

	} // namespace tutorial

} // namespace stroustrup

#endif // STR_SHAPES_HPP