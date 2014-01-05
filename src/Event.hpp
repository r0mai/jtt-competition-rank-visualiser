
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <ostream>

#include "Player.hpp"
#include "Map.hpp"
#include "LapTime.hpp"
#include "Date.hpp"

struct Event {
	Event() = default;

	Player player;
	Map map;
	LapTime lapTime;
	Date date;
};

bool operator<(const Event& lhs, const Event& rhs);

std::ostream& operator<<(std::ostream& os, const Event& event);

#endif

