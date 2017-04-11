#ifndef STR_ENTRY_HPP
#define STR_ENTRY_HPP

#include <string>

namespace stroustrup
{

	namespace tutorial
	{
		struct Entry
		{
			std::string name;
			int number;
		};

		std::ostream& operator<<(std::ostream& os, const Entry& entry);

		std::istream& operator>>(std::istream& is, const Entry& entry);

	} // namespace tutorial

} // namespace stroustrup

#endif // STR_ENTRY_HPP