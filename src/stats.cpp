
#include "stats.hpp"

MapSet getMaps(const Events& events) {
	MapSet mapSet;
	for ( const Event& event : events ) {
		mapSet.insert(event.map);
	}
	return mapSet;
}

Ranking getRankings(const Events& events, const Date& date) {
	//do filtering

	MapSet maps = getMaps(events);
	LapTime defaultTime = parseLapTime("02:30.000");

	typedef std::map<Player, RankRow> RankMap;
	RankMap rankMap;
	for ( const Event& event : events ) {
		auto it = rankMap.find(event.player);
		if ( it == rankMap.end() ) {
			RankRow row(event.player);
			for ( const Map& map : maps ) {
				row.addLapTime(map, defaultTime);
			}
			rankMap.insert(RankMap::value_type(event.player, row));
		}
		rankMap[event.player].addLapTime(event.map, event.lapTime);
	}

	Ranking ranking;
	for ( const auto& rank : rankMap ) {
		ranking.push_back(rank.second);
	}
	std::sort(ranking.begin(), ranking.end(), [](const RankRow& lhs, const RankRow& rhs) { return lhs.getTotalLapTime() < rhs.getTotalLapTime(); });

	return ranking;
}

