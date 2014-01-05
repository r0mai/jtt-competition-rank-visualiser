
#include "Event.hpp"

#include <locale>
#include <sstream>

Date parseDate(const std::string& dateString) {
	std::locale myDateLocale(std::locale::classic(), new boost::posix_time::time_input_facet("%d %B %Y %H:%M"));

	std::stringstream ss(dateString);
	ss.imbue(myDateLocale);

	Date date;
	if ( !(ss >> date) ) {
		std::cerr << "Can't parse date \"" << dateString << "\"" << std::endl;
	}
	return date;
}

LapTime parseLapTime(const std::string& lapTimeString) {
	return LapTime(boost::posix_time::duration_from_string("00:" + lapTimeString));
}

bool operator<(const Event& lhs, const Event& rhs) {
	return lhs.date < rhs.date;
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
	os << "Player: " << event.player << "; Map: " << event.map << "; Date: " << event.date << "; LapTime: " << event.lapTime;
	return os;
}

