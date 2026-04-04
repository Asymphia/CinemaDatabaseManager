#include "RoomService.h"
#include <iostream>

bool RoomService::validate(const Room& r) {
	if (r.getSeatsNum() <= 0 || r.getSeatsNum() > 500) {
		std::cerr << "Enter valid number of seats (from 0 to 500)" << std::endl;
		return false;
	}

	if (r.getCinemaId() <= 0) {
		std::cerr << "Invalid cinama ID" << std::endl;
		return false;
	}

	return true;
}

std::vector<Room> RoomService::sort(std::vector<Room> items, const std::string& field, bool ascending) {
	auto cmp = [&](const Room& a, const Room& b) {
		bool result = false;

		if (field == "seats") result = a.getSeatsNum() < b.getSeatsNum();
		else if (field == "cinamaId") result = a.getCinemaId() < b.getCinemaId();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
}

std::vector<Room> RoomService::getAll() {
	return repo_.getAll();
}

std::vector<Room> RoomService::getByCinemaId(int cinemaId) {
	return repo_.getByCinemaId(cinemaId);
}

Room RoomService::getById(int id) {
	return repo_.getById(id);
}

bool RoomService::add(const Room& r) {
	if (!validate(r)) return false;

	return repo_.add(r);
}

bool RoomService::update(const Room& r) {
	if (!validate(r)) return false;

	return repo_.update(r);
}

bool RoomService::remove(int id) {
	return repo_.remove(id);
}