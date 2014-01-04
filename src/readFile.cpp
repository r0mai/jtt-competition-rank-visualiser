
#include "readFile.hpp"

#include <fstream>

std::string readFile(const std::string& fileName) {
	std::ifstream in(fileName);
	std::string result;
	std::string line;
	while (std::getline(in, line)) {
		result += line + '\n';
	}
	return result;
}

