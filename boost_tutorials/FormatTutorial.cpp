#include "stdafx.h"

#include "FormatTutorial.h"

namespace boost_tutorial
{

	namespace format_tutorial
	{

		void tutorial_one()
		{
			auto format = boost::format("%|-|%|20|%|20|");

			format % "Hello" % 15 % 30;

			std::cout << format.str() << std::endl;
		}

	} // format_tutorial

} // namespace boost_tutorial