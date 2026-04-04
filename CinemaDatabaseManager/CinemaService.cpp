#include "CinemaService.h"

#include <iostream>

bool CinemaService::validate(const Cinema& c) {
	if (c.getName().empty() || c.getCity().empty() || c.getPostalCode().empty() || c.getHouseNumber().empty()) {
		std::cerr << "Fields cannot be empty" <<std::endl;
		return false;
	}

	return true;
}

std::vector<Cinema> CinemaService::sort(std::vector<Cinema> items, const std::string& field, bool ascending) {
	auto cmp = [&](const Cinema& a, const Cinema& b) {
		bool result = false;

		if (field == "name") result = a.getName() < b.getName();
		else if (field == "city") result = a.getCity() < b.getCity();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
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