
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

struct Event {
	Event() = default;

	std::string player;
	std::string map;
	std::string time;
	std::string date;
};

#endif
