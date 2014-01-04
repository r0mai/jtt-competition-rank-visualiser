
#include "gumboUtil.hpp"

#include <sstream>

std::string GumboNodeToString(GumboNode *node, int indent) {
	if (node->type != GUMBO_NODE_ELEMENT) {
		return "";
	}

	std::stringstream ss;

	ss << std::string(indent*4, ' ') << "<" << gumbo_normalized_tagname(node->v.element.tag) << ">" << '\n';

	GumboVector *children = &node->v.element.children;
	for (int i = 0; i < children->length; ++i) {
		GumboNode *child = static_cast<GumboNode*>(children->data[i]);
		ss << GumboNodeToString(child, indent + 1);
	}

	ss << std::string(indent*4, ' ') << "</" << gumbo_normalized_tagname(node->v.element.tag) << ">" << '\n';

	return ss.str();
}

GumboNode *findTag(GumboNode *node, GumboTag tag) {
	if (node->type != GUMBO_NODE_ELEMENT) {
		return nullptr;
	}

	if (node->v.element.tag == tag) {
		return node;
	}

	GumboVector *children = &node->v.element.children;
	for (int i = 0; i < children->length; ++i) {
		GumboNode *result = findTag(static_cast<GumboNode*>(children->data[i]), tag);
		if (result) {
			return result;
		}
	}
	return nullptr;
}

StringMatrix htmlTableToStringMatrix(GumboNode *table) {
	return StringMatrix{};
}

