#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
	boost::posix_time::ptime(boost::gregorian::date(200, 4, 26), boost::posix_time::time_duration(4, 5, 6) + boost::posix_time::microsec(123456));
	
	
	boost::posix_time::ptime t = boost::posix_time::second_clock::universal_time();
	
	auto today = boost::posix_time::ptime(boost::posix_time::second_clock::universal_time().date(), boost::posix_time::hours(0) + boost::posix_time::milliseconds(0));
	
	std::cout << boost::posix_time::to_iso_extended_string(today) << std::endl;
}