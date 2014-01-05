
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>
#include <ostream>
#include <boost/date_time.hpp>

typedef boost::posix_time::ptime Date;
typedef boost::posix_time::time_duration LapTime;

Date parseDate(const std::string& dateString);
LapTime parseLapTime(const std::string& lapTimeString);

struct Event {
	Event() = default;

	std::string player;
	std::string map;
	LapTime lapTime;
	Date date;
};

std::ostream& operator<<(std::ostream& os, const Event& event);

#endif

