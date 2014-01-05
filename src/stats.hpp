
#ifndef STATS_HPP_
#define STATS_HPP_

#include <set>

#include "Events.hpp"
#include "Ranking.hpp"

typedef std::set<Map> MapSet;

MapSet getMaps(const Events& events);
Ranking getRankings(const Events& events, const Date& date = Date(boost::posix_time::pos_infin));

#endif

