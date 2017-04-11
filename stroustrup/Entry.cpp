#include "stdafx.h"

#include "Entry.hpp"

namespace stroustrup
{

	namespace tutorial
	{
		
		std::ostream& operator<<(std::ostream& os, const Entry& entry)
		{
			os << entry.name << " : " << entry.number << std::endl;
			return os;
		}

		std::istream& operator>>(std::istream& is, Entry& entry)
		{
			char c, c2;
			if (is >> c && c == '{' && is >> c2 && c2 == '"')
			{
				std::string name;
				while (is.get(c) && c != '"')
				{
					name += c;
				}

				if (is >> c && c == ',')
				{
					int number = 0;
					if (is >> number >> c && c == '}')
					{
						entry = { name, number };
						return is;
					}
				}
			}
			is.setf(std::ios_base::failbit);
			return is;
		}

	} // namespace tutorial
	
} // namespace stroustrup