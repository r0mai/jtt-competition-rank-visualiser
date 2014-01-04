
#include "parser.hpp"

#include <iostream>
#include <gumbo.h>

#include "readFile.hpp"
#include "gumboUtil.hpp"


void parseFile(const std::string& fileName) {
	const std::string& fileContents = readFile(fileName);
	GumboOutput *output = gumbo_parse(fileContents.c_str());

	GumboNode *table = findTag(output->root, GUMBO_TAG_TABLE);

	StringMatrix stringMatrix = htmlTableToStringMatrix(table);

	gumbo_destroy_output(&kGumboDefaultOptions, output);
}

