
#ifndef DATE_HPP_
#define DATE_HPP_

#include <string>

#include <boost/date_time.hpp>

typedef boost::posix_time::ptime Date;

Date parseDate(const std::string& dateString);

#endif

