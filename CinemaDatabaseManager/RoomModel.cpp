#include <sstream>
#include "RoomModel.h"

Room::Room(int id, int seatsNum, int cinemaId)
	: id_(id), seatsNum_(seatsNum), cinemaId_(cinemaId) {}

int Room::getId() const {
	return id_;
}

std::string Room::getTableName() const {
	return "Room";
}

std::string Room::toString() const {
	std::ostringstream oss;

	oss << "[" << id_ << "] Room | Number of seats: " << seatsNum_ << " | CinemaId: " << cinemaId_;

	return oss.str();
}

int Room::getSeatsNum() const {
	return seatsNum_;
}

int Room::getCinemaId() const {
	return cinemaId_;
}

void Room::setSeatsNum(int seatsNum) {
	seatsNum_ = seatsNum;
}

void Room::setCinemaId(int cinemaId) {
	cinemaId_ = cinemaId;
}