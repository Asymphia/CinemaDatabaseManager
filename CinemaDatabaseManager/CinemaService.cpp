#include "CinemaService.h"

#include <iostream>

bool CinemaService::validate(const Cinema& c) {
	if (c.getName().empty() || c.getCity().empty() || c.getPostalCode().empty() || c.getHouseNumber().empty()) {
		std::cerr << "Fields cannot be empty" <<std::endl;
		return false;
	}

	return true;
}

std::vector<Cinema> CinemaService::getAll() {
	return repo_.getAll();
}

Cinema CinemaService::getById(int id) {
	return repo_.getById(id);
}

bool CinemaService::add(const Cinema& c) {
	if (!validate(c)) return false;
	return repo_.add(c);
}

bool CinemaService::update(const Cinema& c) {
	if (!validate(c)) return false;
	return repo_.update(c);
}

bool CinemaService::remove(int id) {
	return repo_.remove(id);
}