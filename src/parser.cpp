
#include "parser.hpp"
#include "readFile.hpp"

#include <iostream>

void parseFile(const std::string& fileName) {
	const std::string& fileContents = readFile(fileName);
	std::cout << fileContents << std::endl;
}

