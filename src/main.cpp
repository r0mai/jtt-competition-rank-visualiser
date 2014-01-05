
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "Event.hpp"
#include "Events.hpp"
#include "stats.hpp"

int main() {
	std::string line;

	Events events;

	while (std::getline(std::cin, line)) {
		std::vector<std::string> elements;
		boost::split(elements, line, boost::is_any_of("/"));
		if (elements.size() != 4) {
			std::cerr << "Warning: elements.size() != 4" << std::endl;
			continue;
		}
		Event e;
		e.player = elements[0];
		e.map = elements[1];
		e.lapTime = parseLapTime(elements[2]);
		e.date = parseDate(elements[3]);

		events.push_back(e);
	}

	std::cout << "Number of events: " << events.size() << std::endl;

	std::sort(events.begin(), events.end());

	std::cout << "Last event: " << events.back() << std::endl;

	Ranking ranking = getRankings(events, Date());
	for ( unsigned i = 0; i < 20 && i < ranking.size(); ++i ) {
		std::cout << i+1 << ".: " << ranking[i].getPlayer() << ", Time: " << ranking[i].getTotalLapTime() << std::endl;
	}

	std::cout << "Current leader = " << ranking[0].getTotalLapTime() << std::endl;
}

