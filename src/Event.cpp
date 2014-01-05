
#include "Event.hpp"

#include <locale>
#include <sstream>

bool operator<(const Event& lhs, const Event& rhs) {
	return lhs.date < rhs.date;
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
	os << "Player: " << event.player << "; Map: " << event.map << "; Date: " << event.date << "; LapTime: " << event.lapTime;
	return os;
}

