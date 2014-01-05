
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>
#include <ostream>
#include <boost/date_time.hpp>

typedef boost::posix_time::ptime Date;

Date parseDate(const std::string& dateString);

struct Event {
	Event() = default;

	std::string player;
	std::string map;
	std::string lapTime;
	Date date;
};

std::ostream& operator<<(std::ostream& os, const Event& event);

#endif

