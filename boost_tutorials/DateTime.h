#ifndef DATE_TIME_TUTORIAL_H_20160611_1805
#define DATE_TIME_TUTORIAL_H_20160611_1805

#include <boost/date_time/posix_time/ptime.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/posix_time/time_formatters.hpp>

namespace boost_tutorial
{

	namespace date_time
	{
		inline void test_ptime_creations()
		{
			boost::posix_time::ptime(boost::gregorian::date(1982, 4, 26), boost::posix_time::time_duration(4, 5, 6) + boost::posix_time::microsec(123456));


			boost::posix_time::ptime t = boost::posix_time::second_clock::universal_time();

			auto today = boost::posix_time::ptime(boost::posix_time::second_clock::universal_time().date(), boost::posix_time::hours(0) + boost::posix_time::milliseconds(0));

			std::cout << boost::posix_time::to_iso_extended_string(today) << std::endl;
		}
	}

}

#endif//DATE_TIME_TUTORIAL_H_20160611_1805