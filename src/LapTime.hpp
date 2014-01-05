
#ifndef LAPTIME_HPP_
#define LAPTIME_HPP_

#include <string>

#include <boost/date_time.hpp>

typedef boost::posix_time::time_duration LapTime;

LapTime parseLapTime(const std::string& lapTimeString);

#endif

