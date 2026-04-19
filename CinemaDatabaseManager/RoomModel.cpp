#include <sstream>
#include "RoomModel.h"

Room::Room(int id, int seatsNum, int cinemaId)
	: id_(id), seatsNum_(seatsNum), cinemaId_(cinemaId) {}

int Room::getId() const {
	return id_;
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