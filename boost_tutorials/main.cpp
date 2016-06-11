#include <iostream>

#include <boost/date_time.hpp>

int main()
{
	boost::posix_time::ptime(boost::gregorian::date(200, 4, 26), boost::posix_time::time_duration(4, 5, 6) + boost::posix_time::microsec(123456));
}