
#include "Date.hpp"

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

