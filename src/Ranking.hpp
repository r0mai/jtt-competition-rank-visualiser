
#ifndef RANKING_HPP_
#define RANKING_HPP_

#include <map>

#include "Player.hpp"
#include "Date.hpp"
#include "Map.hpp"
#include "LapTime.hpp"

class RankRow {
public:
	RankRow() = default;
	RankRow(const Player& player);

	LapTime getTotalLapTime() const;
	void setPlayer(const Player& player);
	const Player& getPlayer() const;
	void addLapTime(const Map& map, const LapTime& lapTime);
private:
	Player player;
	std::map<Map, LapTime> lapTimes;
};

typedef std::vector<RankRow> Ranking;

#endif

