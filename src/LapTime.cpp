
#include "LapTime.hpp"

LapTime parseLapTime(const std::string& lapTimeString) {
	return LapTime(boost::posix_time::duration_from_string("00:" + lapTimeString));
}

