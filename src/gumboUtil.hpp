
#ifndef GUMBO_UTIL_HPP_
#define GUMBO_UTIL_HPP_

#include <gumbo.h>
#include <string>
#include <vector>

std::string GumboNodeToString(GumboNode *node, int indent = 0);

GumboNode *findTag(GumboNode *node, GumboTag tag);

typedef std::vector<std::vector<std::string>> StringMatrix;
StringMatrix htmlTableToStringMatrix(GumboNode *table);

#endif

