
#include "Ranking.hpp"

#include <algorithm>

RankRow::RankRow(const Player& player) : player(player) {}

LapTime RankRow::getTotalLapTime() const {
	LapTime total(0, 0, 0, 0);
	for ( const auto& mapTime : lapTimes ) {
		total += mapTime.second;
	}
	return total;
}

void RankRow::setPlayer(const Player& playerName) {
	this->player = playerName;
}

const Player& RankRow::getPlayer() const {
	return player;
}

void RankRow::addLapTime(const Map& map, const LapTime& lapTime) {
	if ( lapTimes.find(map) == lapTimes.end() || lapTimes[map] > lapTime ) {
		lapTimes[map] = lapTime;
	}
}

