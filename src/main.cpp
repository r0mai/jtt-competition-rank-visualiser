
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "Event.hpp"

int main() {
	std::string line;

	std::vector<Event> events;

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
		e.lapTime = elements[2];
		e.date = parseDate(elements[3]);

		events.push_back(e);
		std::cout << e << std::endl;
	}

	std::cout << events.size() << std::endl;
}

