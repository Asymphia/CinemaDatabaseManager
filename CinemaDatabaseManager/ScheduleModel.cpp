#include "ScheduleModel.h"

#include <sstream>

Schedule::Schedule(int id, int roomId, int movieId,
	const std::string& date, const std::string& time)
	: id_(id), roomId_(roomId), movieId_(movieId), date_(date), time_(time) {}

int Schedule::getId() const {
	return id_;
}

std::string Schedule::getTableName() const {
	return "Schedule";
}

std::string Schedule::toString() const {
	std::ostringstream oss;

	oss << "[" << id_ << "] " << date_ << " " << time_ << " | MovieId: " << movieId_ << " | RoomId: " << roomId_;

	return oss.str();
}

int Schedule::getRoomId() const {
	return roomId_;
}

int Schedule::getMovieId() const {
	return movieId_;
}

std::string Schedule::getDate() const {
	return date_;
}

std::string Schedule::getTime() const {
	return time_;
}

void Schedule::setRoomId(int id) {
	roomId_ = id;
}

void Schedule::setMovie(int movieId) {
	movieId_ = movieId;
}

void Schedule::setDate(const std::string& date) {
	date_ = date;
}

void Schedule::setTime(const std::string& time) {
	time_ = time;
}