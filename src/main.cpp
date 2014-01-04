
#include "parser.hpp"

int main(int argc, char **argv) {
	for ( int i = 1; i < argc; ++i ) {
		parseFile(argv[i]);
	}
}

